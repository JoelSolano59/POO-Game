#ifndef Item_h
#define Item_h

#include <string>
#include <iostream>

class Item{
    public:
    // Constructores y destructor
    Item();
    Item(int, std::string, std::string); // int numUsos, string nombre, string descripcion

    // Setters y Getters
    int getNumUsos() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    void setNumUsos(int);
    void setNombre(std::string);
    void setDescripcion(std::string);

    // Métodos
    virtual std::string mostrar(); // Regresa un string de todos los atributos

    private:
    int numUsos;
    std::string nombre, descripcion;
};

// Constructores
Item :: Item(){
    numUsos = 0;
    nombre = "----";
    descripcion = "----";
}

Item :: Item(int usos, std::string name, std::string desc){
    numUsos = usos;
    nombre = name;
    descripcion = desc;
}

// Setters y Getters
int Item :: getNumUsos() const{return numUsos;}
std::string Item :: getNombre() const{return nombre;}
std::string Item :: getDescripcion() const{return descripcion;}
void Item :: setNumUsos(int usos){numUsos = usos;}
void Item :: setNombre(std::string name){nombre = name;}
void Item :: setDescripcion(std::string desc){descripcion = desc;}

// Métodos
std::string Item :: mostrar(){
    std::string mensaje;
    mensaje = "Nombre: " + getNombre() + ". Usos faltantes: " + std::to_string(getNumUsos()) + ". Descripcion: " + getDescripcion();
    return mensaje;
}
#endif