#ifndef LLAVE_h
#define LLAVE_h
#include "Llave.h"

class Llave: public Item{
    public:
    // Constructores
    Llave();
    Llave(char);

    // Getters y Setters
    char getColor() const;
    void setColor(char);

    private:
    char color[1];

};

// Constructores
Llave::Llave(){
    color = "-";
}

Llave::Llave(char c, int usos, std::string name, std::string desc): Item(usos, name, desc){
    color = c;
}

// Getters y Setters
char Llave::getColor() const{return color;}
void Llave::setColor(char c){color = c;}

#endif