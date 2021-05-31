#ifndef Item_h
#define Item_h

#include <string>

class Item{
    public:
    // Constructores y destructor
    Item();
    Item(int, std::string, std::string);
    ~Item();

    // Setters y Getters
    int getNumUsos() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    void setNumUsos(int);
    void setNombre(std::string);
    void setDescripcion(std::string);

    private:
    int numUsos;
    std::string nombre, descripcion;
};

// Constructores y destructor
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

Item :: ~Item(){}

// Setters y Getters
int Item :: getNumUsos() const{return numUsos;}
std::string Item :: getNombre() const{return nombre;}
std::string Item :: getDescripcion() const{return descripcion;}
void Item :: setNumUsos(int usos){numUsos = usos;}
void Item :: setNombre(std::string name){nombre = name;}
void Item :: setDescripcion(std::string desc){descripcion = desc;}

#endif