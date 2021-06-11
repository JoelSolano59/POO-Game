#ifndef Arma_h
#define Arma_h
#include "Item.h"

class Arma: public Item{
    public: 
    // Constructores
    Arma();
    Arma(int, int, std::string, std::string); // int daño, int numUsos, string nombre, string descripción

    // Getters y Setters
    int getDanio() const;
    void setDanio(int);

    // Métodos
    std::string mostrar();

    private:
    int danio;
};

// Constructores
Arma :: Arma(){
    danio = 0;
}

Arma :: Arma(int dan, int usos, std::string name, std::string desc): Item(usos, name, desc){
    danio = dan;
}

// Getters y Setters
int Arma :: getDanio() const{return danio;}
void Arma :: setDanio(int dan){danio = dan;}


// Métodos

std::string Arma :: mostrar(){
    std::string mensaje, a;
    a = Item::mostrar();
    mensaje = a + "| Daño del arma: " + std::to_string(getDanio());
    return mensaje;
}

#endif