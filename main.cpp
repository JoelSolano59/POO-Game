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


// La primera función que se llama al momento de correr el juego.
// Este avisa al usuario de como debe de quedar la pantalla.
void ajustePantalla(){
    ifstream archivo("./txt/AjustePantalla.txt");
    string linea;
    try {
        if (archivo){
            archivo.open("./txt/AjustePantalla.txt");
        } else {
            throw invalid_argument("Error, no se pudo abrir el archivo: ./txt/AjustePantalla.txt" );
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    while(getline(archivo, linea)){
        cout << linea << endl;
    }
    system("Pause");
    system("cls");
}

// Función que carga la portada del juego, este es llamado después 
// de la función AjustePantalla()
void cargarPortada(){
    ifstream archivo("./txt/Portada.txt");
    string linea;
    try {
        if (archivo){
            archivo.open("./txt/Portada.txt");
        } else {
            throw invalid_argument("Error, no se pudo abrir el archivo: ./txt/Portada.txt" );
        }
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
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

// Funcion que carga el menu principal del juego, este es llamado despues
// de la funcion cargarPortada()
void menuPrincipal(){
    int opcion = 0;
    do {
        system("cls");
        cout << "Menu principal: " << endl;
        cout << "1) Iniciar juego." << endl;
        cout << "2) Como jugar." << endl;
        cout << "3) Datos personales." << endl;
        cout << "4) Salir del juego." << endl;
        cin >> opcion;
        system("cls");
        switch (opcion) {
        case 1:
            // Iniciar juego
            break;
        case 2:
            // Como jugar
            break;    
        case 3:
            // Datos personales
            break;
        case 4:
            // Salir del juego
            break;
        default:
            // Opcion default
            cout << "Opcion no valida, vuelve a intentarlo." << endl;
            system("pause");
            break;
        }
    } while (opcion != 4);
    cout << "¡Gracias por jugar!" << endl;
    system("pause");
    system("cls");
}

int main() {
    system("cls");
    system("Title Time Paradox");
    system("Color 0a");
    ajustePantalla();
    cargarPortada();
    menuPrincipal();
    //system("cls");
    //system("pause");
    return 0;
}