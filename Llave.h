#ifndef LLAVE_h
#define LLAVE_h
#include "Item.h"

class Llave: public Item{
    public:
    // Constructores
    Llave();
    Llave(std::string, int, std::string, std::string);

    // Getters y Setters
    std::string getColor() const;
    void setColor(std::string);

    private:
    std::string color;

};

// Constructores
Llave::Llave(){
    color = "--";
}

Llave::Llave(std::string c, int usos, std::string name, std::string desc): Item(usos, name, desc){
    color = c;
}

// Getters y Setters
std::string Llave::getColor() const{return color;}
void Llave::setColor(std::string c){color = c;}

#endif