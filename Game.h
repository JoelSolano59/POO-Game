#ifndef Game_h
#define Game_h
// CLases
#include "Arma.h"
#include "Medkit.h"
#include "Llave.h"
#include "Vacuna.h"
#include "Inventario.h"
#include "Personaje.h"
class Game{
private:
    std::string posicionJugador; //0 [Sala principal] - 1 [Oficina] - 2 [Seguridad] - 3 [Enfermeria] - 4 [Time Machine]
    bool luz; //false - Apagado, true - Encendido
    bool puerta[5]; //false - Cerrada, true - Abierta
    Item *inventario[10]; // Arreglo de inventario, polimórfico
    int vidaPer, vidaEne; //0 - 100 HP 
public:
    Game();
    Game(std::string, bool, bool, int, int);

    // Getters y Setters
    std::string getPosicionJugador() const;
    bool getLuz() const;
    bool getPuerta(int) const;
    int getVidaPer() const;
    int getVidaEne() const;
    void setPosicionJugador(std::string);
    void setLuz(bool);
    void setPuerta(int, bool);
    void setVidaPer(int);
    void setVidaEne(int);

    // Habitaciones
    void salaPrincipal(); //Acceder a la habitacion Sala Principal.
    void oficina(); //Acceder a la habitacion Oficina.
    bool seguridad(); //Acceder a la habitacion Seguridad.
    bool enfermeria(); //Acceder a la habitacion Enfermeria.
    bool timeMachine(); //Habitacion final del juego (Salida).

    // Métodos
    int posicionDesocupadoInv();
    void revisarLlave(std::string, int);
    bool revisarArma();
    bool revisarMedkit();
    bool revisarVacuna();
    void mostrarInventario();
    // Estos métodos ingresan un objeto hija de Item dentro del inventario
    void ingresarLlave(std::string, int, std::string, std::string);
    void ingresarArma(int, int, std::string, std::string);
    void ingresarMedkit(int, int, std::string, std::string);
    void ingresarVacuna(int, int, std::string, std::string);

};

Game::Game(){
    posicionJugador = "Sala principal"; //Empieza en la sala principal.
    luz = false; //Empieza con la luz apagada.
    puerta[0] = true; //Empieza la puerta[0] cerrada.
    puerta[1] = true; //Empieza la puerta[1] cerrada.
    puerta[2] = false; //Empieza la puerta[2] cerrada.
    puerta[3] = false;
    puerta[4] = false;
    // Declaramos un new Item en nuestro inventario, para tenerlo vacio.
    // Por una razón, en el private el arreglo no se encuentra con 10
    // Items.
    for(int i=0; i<10; i++){
        inventario[i] = new Item(0, "--", "----");
    }
    vidaPer = 100; //Empieza con 100 HP el personaje
    vidaEne = 100; //Empieza con 100 HP el enemigo
}

Game::Game(std::string pj, bool l, bool p, int vp, int ve){
    posicionJugador = pj;
    luz = l;
    puerta[0] = p;
    puerta[1] = p;
    puerta[2] = p;
    puerta[3] = p;
    puerta[4] = p;
    vidaPer = vp;
    vidaEne = ve;
}

// Getters y Setters
std::string Game::getPosicionJugador() const {return posicionJugador;}
void Game::setPosicionJugador(std::string pj){posicionJugador = pj;}
bool Game::getLuz() const {return luz;}
int Game::getVidaPer() const {return vidaPer;}
int Game::getVidaEne() const {return vidaEne;}
void Game::setLuz(bool l){luz = l;}
bool Game::getPuerta(int np) const {return puerta[np];}
void Game::setPuerta(int np, bool p){puerta[np] = p;}
void Game::setVidaPer(int vp){vidaPer = vp;}
void Game::setVidaEne(int ve){vidaEne = ve;}

// Métodos
int Game :: posicionDesocupadoInv(){
    std::string name;
    for(int i=0; i<10; i++){
        name = inventario[i] -> getNombre();
        if(name=="--"){
            return i;
        }
    }
    return -1;
}

void Game :: revisarLlave(std::string color, int habitacion){
    std::string temp;
    // Recorrer por el inventario, para revisar si cuenta con la llave del color esp.
    for(int i=0; i<10; i++){
        //Dynamic cast por un objeto Llave
        if(Llave* c=dynamic_cast<Llave*>(inventario[i])){
            temp = c -> getColor();
            if(color == temp){
                setPuerta(habitacion, true);
            }
        }
    }
}

bool Game :: revisarArma(){
    // Recorrer por el inventario, para revisar si cuenta con una Arma.
    for(int i=0; i<10; i++){
        //Dynamic cast por un objeto Arma
        if(Arma* c=dynamic_cast<Arma*>(inventario[i])){
            return true;
        }
    }
    return false;
}

bool Game :: revisarMedkit(){
    // Recorrer por el inventario, para revisar si cuenta con un Medkit.
    for(int i=0; i<10; i++){
        //Dynamic cast por un objeto Arma
        if(Medkit* c=dynamic_cast<Medkit*>(inventario[i])){
            return true;
        }
    }
    return false;
}

bool Game :: revisarVacuna(){
    // Recorrer por el inventario, para revisar si cuenta con una Vacuna.
    for(int i=0; i<10; i++){
        //Dynamic cast por un objeto Vacuna
        if(Vacuna* c=dynamic_cast<Vacuna*>(inventario[i])){
            return true;
        }
    }
    return false;
}

void Game :: ingresarLlave(std::string color, int usos, std::string name, std::string desc){
    int pos;
    pos = posicionDesocupadoInv();
    if(pos != -1){
        inventario[pos] = new Llave(color, usos, name, desc);
    }
    // Else de un mensaje de que no se pudo ingresar al inventario la llave.
}

void Game :: ingresarArma(int dano, int usos, std::string name, std::string desc){
    int pos;
    pos = posicionDesocupadoInv();
    if(pos != -1){
        inventario[pos] = new Arma(dano, usos, name, desc);
    }
    // Else de un mensaje de que no se pudo ingresar al inventario la arma.
}

void Game :: ingresarMedkit(int magnitud, int usos, std::string name, std::string desc){
    int pos;
    pos = posicionDesocupadoInv();
    if(pos != -1){
        inventario[pos] = new Medkit(magnitud, usos, name, desc);
    }
}


void Game :: ingresarVacuna(int magnitud, int usos, std::string name, std::string desc){
    int pos;
    pos = posicionDesocupadoInv();
    if(pos != -1){
        inventario[pos] = new Vacuna(magnitud, usos, name, desc);
    }
}

// Habitaciomes
void Game::salaPrincipal(){
    setPosicionJugador("Sala Principal");
}

void Game::oficina(){
    setPosicionJugador("Oficina");
}

bool Game::seguridad(){
    if(puerta[2] == true){
        // está dentro de seguridad
        setPosicionJugador("Seguridad");
        return true;
    } else {
        std::cout << "Se encuentra cerrado. Ocupas la llave de color gris" << endl;
        return false;
    }
}

bool Game::enfermeria(){
    if(puerta[3] == true){
        // está dentro de enfermeria
        setPosicionJugador("Enfermeria");
        return true;
    } else {
        std::cout << "Se encuentra cerrado. Ocupas la llave de color rojo" << endl;
        return false;
    }
}

bool Game::timeMachine(){
    if(puerta[4] == true){
        // está dentro de time machine
        setPosicionJugador("Time Machine");
        return true;
    } else {
        std::cout << "Se encuentra cerrado. Ocupas la llave de color negro" << endl;
        return false;
    }
}

void Game :: mostrarInventario(){
    for(int i=0; i<10; i++){
        std:: cout << i << ". " << *inventario[i] << endl;
    }
}
#endif