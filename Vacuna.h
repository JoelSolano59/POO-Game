#ifndef Vacuna_h
#define Vacuna_h
#include "Item.h"

class Vacuna: public Item{
    public:
    // Constructores
    Vacuna();
    Vacuna(int, int, std::string, std::string);

    // Getters y Setters
    int getMagnitud() const;
    void setMagnitud(int);

    // Métodos
    void usarVacuna();

    private:
    int magnitud;
};

// Constructores
Vacuna :: Vacuna(){
    magnitud = 0;
}

Vacuna :: Vacuna(int mag, int usos, std::string name, std::string desc): Item(usos, name, desc){
    magnitud = mag;
}

// Getters y setters
int Vacuna :: getMagnitud() const{return magnitud;}
void Vacuna :: setMagnitud(int mag){magnitud = mag;}

// Métodos
void Vacuna :: usarVacuna(){
    // Cada vez que el usario use la vacuna, este le restara al número de usos.
    int cantUsos = Item::getNumUsos();
    cantUsos -= 1;
    Item::setNumUsos(cantUsos);
    // Tendrá que realizar su efecto a un personaje
    //
    //
    if(cantUsos <= 0){
        // Destruir Item
        //Item::~Item();
    }
}

#endif