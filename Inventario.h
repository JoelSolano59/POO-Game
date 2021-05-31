#ifndef Inventario_h
#define Inventario_h
#include "Item.h"

class Inventario: public Item{
    public:
    // Constructores
    Inventario();
    //Inventario(Item);

    // Getters y Setters
    //Item getInventario() const;
    //void setInventario(Item);
    

    // Métodos
    void muestra();
    void agrega(int, Item);
    void quita(int);

    private:
    Item inventory[10];
};

// Constructores
Inventario :: Inventario(){}

/*
Inventario :: Inventario(Item b){
    inventory = b;
}
*/

// Getters y Setters
//Item Inventario :: getInventario() const{return inventory;}
//void Inventario :: setInvetario(Item c){inventory = c;}

// Métodos
void Inventario :: muestra(){
    // Una impresión simple por el momento. Sujeto a cambio!
    Item objeto;
    std::cout << "-:-:-:-:-:-:- INVENTARIO -:-:-:-:-:-:-" << std::endl;
    for(int i=0; i<10; i++){
        objeto = inventory[i];
        std::cout << "Posicion " << i+1 << ": " << objeto.getNombre() << std::endl;
    }
}

#endif