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
    std::string objetivo; //Objetivo actual del jugador
    Item *inventario[10]; // Arreglo de inventario, polimórfico
public:
    Game();
    Game(std::string, bool, bool, std::string);
    ~Game();

    // Getters y Setters
    std::string getPosicionJugador() const;
    bool getLuz() const;
    bool getPuerta(int) const;
    std::string getObjetivo() const;
    void setPosicionJugador(std::string);
    void setLuz(bool);
    void setPuerta(int, bool);
    void setObjetivo(std::string);

    // Habitaciones
    void salaPrincipal(); //Acceder a la habitacion Sala Principal.
    void oficina(); //Acceder a la habitacion Oficina.
    bool seguridad(); //Acceder a la habitacion Seguridad.
    bool enfermeria(); //Acceder a la habitacion Enfermeria.
    bool timeMachine(); //Habitacion final del juego (Salida).

    // Oficina
    void programas(); //Acceder a Computadora > Programas.
    void mensajes(); //Acceder a Computadora > Mensajes.
    void correo(); //Acceder a Computadora > Correo.
    void navegador(); //Acceder a Computadora > Navegador.

    // Métodos
    void revisarLlave(std::string, int);
};

Game::Game(){
    posicionJugador = "Sala principal"; //Empieza en la sala principal.
    luz = false; //Empieza con la luz apagada.
    puerta[0] = true; //Empieza la puerta[0] cerrada.
    puerta[1] = true; //Empieza la puerta[1] cerrada.
    puerta[2] = false; //Empieza la puerta[2] cerrada.
    puerta[3] = false;
    puerta[4] = false;
    objetivo = "-"; //Empieza sin ningun objetivo.
    // Declaramos un new Item en nuestro inventario, para tenerlo vacio.
    // Por una razón, en el private el arreglo no se encuentra con 10
    // Items.
    for(int i=0; i<10; i++){
        inventario[i] = new Item(0, "--", "----");
    }
}

Game::Game(std::string pj, bool l, bool p, std::string o){
    posicionJugador = pj;
    luz = l;
    puerta[0] = p;
    puerta[1] = p;
    puerta[2] = p;
    puerta[3] = p;
    puerta[4] = p;
    objetivo = o;
}

Game::~Game(){}

// Getters y Setters
std::string Game::getPosicionJugador() const {return posicionJugador;}
void Game::setPosicionJugador(std::string pj){posicionJugador = pj;}
bool Game::getLuz() const {return luz;}
void Game::setLuz(bool l){luz = l;}
bool Game::getPuerta(int np) const {return puerta[np];}
void Game::setPuerta(int np, bool p){puerta[np] = p;}
std::string Game::getObjetivo() const {return objetivo;}
void Game::setObjetivo(std::string o){objetivo = o;}

// Métodos
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

void Game::programas(){

}

void Game::mensajes(){

}

void Game::correo(){

}

void Game::navegador(){

}

#endif