/*
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
P.O.O | Situación Problema, Videojuego "Time Paradox"

Autores:
- Joel Isaias Solano Ocampo | A01639289
- Jeshua Nava Avila | A01639282

Matería y profesor:
- Programación Orientada a Objetos (Gpo11)
- Fabiola Uribe Plata

Fecha de entrega:
- 11/06/2021
Fecha de última actualización:
- 07/06/2021
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*/

// Librerías
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
using namespace std;
// Clases hijas que agregan a las clases padres
#include "Arma.h"
#include "Medkit.h"
#include "Llave.h"
#include "Vacuna.h"
#include "Inventario.h"
#include "Personaje.h"

/*
La primera función que se llama al momento de correr el juego.
Este avisa al usuario de como debe de quedar la pantalla.
*/
void AjustePantalla(){
    system("cls");
    ifstream archivo;
    string linea;
    archivo.open("AjustePantalla.txt");
    while(getline(archivo, linea)){
        cout << linea << endl;
    }
    system("Pause");
    system("cls");
}


/*
Función que carga la portada del juego, este es llamado después 
de la función AjustePantalla()
*/
void cargarPortada(){
    ifstream archivo;
    string linea;
    archivo.open("Portada.txt");

    for(int i=1; i<26; i++){
        getline(archivo, linea);
        if(i<10){
            cout << linea << endl;
            Sleep(350);
        } else{
            cout << linea << endl;
            Sleep(50);
        }
    }
    system("Pause");
    system("cls");
}

int main() {
    system("Title Time Paradox");
    system("Color 4a");
    system("cls");
    system("pause");
    return 0;
}