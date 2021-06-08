#ifndef Medkit_h
#define Medkit_h
#include "Item.h"

class Medkit: public Item{
    public:
    // Constructores
    Medkit();
    Medkit(int, int, std::string, std::string); // int magnitud, int numUsos, string nombre, string descripción

    // Getters y Setters
    int getMagnitud() const;
    void setMagnitud(int);

    // Métodos
    void usarMedkit();

    private:
    int magnitud;

};

// Constructores
Medkit :: Medkit(){
    magnitud = 0;
}

Medkit :: Medkit(int mag, int usos, std::string name, std::string desc): Item(usos, name, desc){
    magnitud = mag;
}

// Getters y Setters
int Medkit :: getMagnitud() const{return magnitud;}
void Medkit :: setMagnitud(int mag){magnitud = mag;}

// Métodos
void Medkit :: usarMedkit(){
    // Cada vez que el usario use un medkit, este le restara al número de usos.
    int cantUsos = Item::getNumUsos();
    cantUsos -= 1;
    Item::setNumUsos(cantUsos);
    // Tendrá que curar al personaje
    //
    //
    if(cantUsos <= 0){
        // Destruir Item
        //Item::~Item();
    }
}

#endif