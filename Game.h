#ifndef Game_h
#define Game_h

class Game{
private:
    std::string posicionJugador; //1[Sala principal] - 2[Oficina] - 3[Seguridad] - 4[Enfermeria] - 5[Time Machine]
    bool luz; //false - Apagado, true - Encendido
    bool puerta[3]; //false - Cerrada, true - Abierta
    std::string objetivo; //Objetivo actual del jugador
public:
    Game();
    Game(std::string, bool, bool, std::string);
    ~Game();

    std::string getPosicionJugador() const;
    bool getLuz() const;
    bool getPuerta(int) const;
    std::string getObjetivo() const;

    void setPosicionJugador(std::string);
    void setLuz(bool);
    void setPuerta(int, bool);
    void setObjetivo(std::string);

    void salaPrincipal(); //Acceder a la habitacion Sala Principal.
    void oficina(); //Acceder a la habitacion Oficina.
    void seguridad(); //Acceder a la habitacion Seguridad.
    void enfermeria(); //Acceder a la habitacion Enfermeria.
    void timeMachine(); //Habitacion final del juego (Salida).

    void programas(); //Acceder a Computadora > Programas.
    void mensajes(); //Acceder a Computadora > Mensajes.
    void correo(); //Acceder a Computadora > Correo.
    void navegador(); //Acceder a Computadora > Navegador.
};

Game::Game(){
    posicionJugador = "Sala principal"; //Empieza en la sala principal.
    luz = false; //Empieza con la luz apagada.
    puerta[0] = false; //Empieza la puerta[0] cerrada.
    puerta[1] = false; //Empieza la puerta[1] cerrada.
    puerta[2] = false; //Empieza la puerta[2] cerrada.
    objetivo = "-"; //Empieza sin ningun objetivo.
}

Game::Game(std::string pj, bool l, bool p, std::string o){
    posicionJugador = pj;
    luz = l;
    puerta[0] = p;
    puerta[1] = p;
    puerta[2] = p;
    objetivo = o;
}

Game::~Game(){}

std::string Game::getPosicionJugador() const {
    return posicionJugador;
}

void Game::setPosicionJugador(std::string pj){
    posicionJugador = pj;
}

bool Game::getLuz() const {
    return luz;
}

void Game::setLuz(bool l){
    luz = l;
}

bool Game::getPuerta(int np) const {
    return puerta[np];
}

void Game::setPuerta(int np, bool p){
    puerta[np] = p;
}

std::string Game::getObjetivo() const {
    return objetivo;
}

void Game::setObjetivo(std::string o){
    objetivo = o;
}

void Game::salaPrincipal(){

}

void Game::oficina(){

}

void Game::seguridad(){

}

void Game::enfermeria(){

}

void Game::timeMachine(){

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