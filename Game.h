#ifndef Game_h
#define Game_h

class Game{
private:
    int posicionJugador; //1[Sala principal] - 2[Oficina] - 3[Seguridad] - 4[Enfermeria] - 5[Time Machine]
    bool luz; //false - Apagado, true - Encendido
    bool puerta[3]; //false - Cerrada, true - Abierta
public:
    Game();
    Game(int, bool, bool);
    ~Game();

    int getPosicionJugador() const;
    bool getLuz() const;
    bool getPuerta(int) const;

    void setPosicionJugador(int);
    void setLuz(bool);
    void setPuerta(int, bool);

    void salaPrincipal(); //Acceder a la habitacion Sala Principal.
    void oficina(); //Acceder a la habitacion Oficina.
    void seguridad(); //Acceder a la habitacion Seguridad.
    void enfermeria(); //Acceder a la habitacion Enfermeria.
    void timeMachine(); //Habitacion final del juego (Salida).

    void programas(); //Acceder a Computadora > Programas.
    void mensajes(); //Acceder a Computadora > Mensajes.
    void correo(); //Acceder a Computadora > Correo.
    void navegador(); //Acceder a Computadora > Navegador.

    void objetivos(); //Muestra los objetivos a completar.
};

Game::Game(){
    posicionJugador = 1; //Empieza en la sala principal.
    luz = false; //Empieza con la luz apagada.
    puerta[0] = false; //Empieza la puerta[0] cerrada.
    puerta[1] = false; //Empieza la puerta[1] cerrada.
    puerta[2] = false; //Empieza la puerta[2] cerrada.
}

Game::Game(int pj, bool l, bool p){
    posicionJugador = pj;
    luz = l;
    puerta[0] = p;
    puerta[1] = p;
    puerta[2] = p;
}

Game::~Game(){}

int Game::getPosicionJugador() const {
    return posicionJugador;
}

void Game::setPosicionJugador(int pj){
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

void Game::Game::navegador(){

}

void Game::objetivos(){
    
}

#endif