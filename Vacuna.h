#ifndef Vacuna_h
#define Vacuna_h
#include "Item.h"

class Vacuna: public Item{
    public:
    // Constructores
    Vacuna();
    Vacuna(int, int, std::string, std::string); // int magnitud, int numUsso, string nombre, string descripción

    // Getters y Setters
    int getMagnitud() const;
    void setMagnitud(int);
    bool getEstado() const;
    void setEstado(bool);

    // Métodos
    std::string mostrar();

    private:
    int magnitud;
    bool estado;
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
std::string Vacuna :: mostrar(){
    std::string mensaje, a;
    a = Item::mostrar();
    mensaje = a + "| Magnitud: " + std::to_string(getMagnitud());
    return mensaje;
}

#endif