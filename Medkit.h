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
    std::string mostrar();

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
std::string Medkit :: mostrar(){
    std::string mensaje, a;
    a = Item::mostrar();
    mensaje = a + "| Restablece " + std::to_string(getMagnitud()) + " de vida.";
    return mensaje;
}

#endif