#ifndef PERSONAJE_h
#define PERSONAJE_h

#include <string>
#include <iostream>

class Personaje{
    public:
        Personaje();
        Personaje(string, string, Inventario, int);
        string getNombre() const;
        string getDescripcion() const;
        int getVida() const;
        void setNombre(string);
        void setDescripcion(string);
        void setVida(int);
        void muestra();
        void quitaVida();
    private:
        string nombre, descripcion;
        Inventario inventory;
        int vida;
};

Personaje::Personaje(){
    nombre = "-";
    descripcion = "-";
    vida = 0;
}

Personaje::Personaje(string n, string d, Inventario i, int v):Inventario(i){
    nombre = n;
    descripcion = d;
    vida = v;
}

string Personaje::getNombre() const{
    return nombre;
}

string Personaje::getDescripcion() const{
    return descripcion;
}

int Personaje::getVida() const{
    return vida;
}

void Personaje::setNombre(string n){
    nombre = n;
}

void Personaje::setDescripcion(string d){
    descripcion = d;
}

void Personaje::setVida(int v){
    vida = v;
}

void Personaje::muestra(){
    cout << "Nombre: " << nombre << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Vida: " << vida << endl;
}

void Personaje::quitaVida(){
    try {
        vida--;
    }
    catch {
        vida = 0;
    }
}

#endif