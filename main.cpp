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
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
// Clases
#include "Game.h"

// Función que imprime texto char por char con velocidad establecida.
void impresion(std::string texto)
{
  for (char const &c : texto)
  {
    std::cout << c;
    Sleep(10);
  }
  cout << endl;
}

// La primera función que se llama al momento de correr el juego.
// Este avisa al usuario de como debe de quedar la pantalla.
void ajustePantalla()
{
  ifstream archivo;
  string linea;
  try
  {
    if (archivo)
    {
      archivo.open("./txt/AjustePantalla.txt");
      while (getline(archivo, linea))
      {
        cout << linea << endl;
      }
      system("Pause");
      system("cls");
    }
    else
    {
      throw invalid_argument("Error, no se pudo abrir el archivo: ./txt/AjustePantalla.txt");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// Función que carga la portada del juego, este es llamado después
// de la función AjustePantalla()
void cargarPortada()
{
  ifstream archivo;
  string linea;
  try
  {
    if (archivo)
    {
      archivo.open("./txt/Portada.txt");
      for (int i = 1; i < 26; i++)
      {
        getline(archivo, linea);
        if (i < 10)
        {
          cout << linea << endl;
          Sleep(350);
        }
        else
        {
          cout << linea << endl;
          Sleep(50);
        }
      }
      system("Pause");
      system("cls");
    }
    else
    {
      throw invalid_argument("Error, no se pudo abrir el archivo: ./txt/Portada.txt");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// Carga el texto Fase1.
void cargarFase1()
{
  ifstream archivo;
  string linea;
  try
  {
    if (archivo)
    {
      archivo.open("./txt/Fase1.txt");
      for (int i = 1; i < 19; i++)
      {
        getline(archivo, linea);
        impresion(linea);
        Sleep(1200);
      }
      system("Pause");
      system("cls");
    }
    else
    {
      throw invalid_argument("Error, no se pudo abrir el archivo: ./txt/Fase1.txt");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// Función que desplega texto en como jugar.
void comoJugar()
{
  cout << "* Lee los dialogos que aparecen en consola para conocer tus objetivos." << endl;
  cout << "* Elige entre las diferentes opciones que se te dan a elegir y realiza tu propio camino hasta el final." << endl;
  cout << "* Ingresa opciones diferentes a las que se te presentan en pantalla y descubre grandes secretos :)." << endl;
  cout << "* Pelea contra enemigos y utiliza difernentes estrategias para derribarlos." << endl;
  cout << "* Busca items ocultos en las habitaciones que te ayudaran mas a delante en tu aventura." << endl;
  cout << "* Resuleve diferentes acertijos para poder avanzar en el juego." << endl;
  system("pause");
}

// Función que muestra los datos del juego.
void datosEntrega()
{
  cout << "P.O.O | Situación Problema, Videojuego Time Paradox" << endl
      << endl;
  cout << "Autores:" << endl;
  cout << "- Joel Isaias Solano Ocampo | A01639289" << endl;
  cout << "- Jeshua Nava Avila | A01639282" << endl
      << endl;
  cout << "Matería y profesor:" << endl;
  cout << "- Programación Orientada a Objetos (Gpo11)" << endl;
  cout << "- Fabiola Uribe Plata" << endl
      << endl;
  cout << "Fecha de entrega:" << endl;
  cout << "- 11/06/2021" << endl;
  cout << "Fecha de última actualización:" << endl;
  cout << "- 07/06/2021" << endl
      << endl;
  system("pause");
}

// Carga un archivo diálogo deseado.
void cargarArchivoDialogo(string path, int renglones)
{
  system("Color 0f");
  ifstream archivo;
  string linea;
  try
  {
    if (archivo)
    {
      archivo.open(path);
      for (int i = 0; i < renglones; i++)
      {
        getline(archivo, linea);
        impresion(linea);
        Sleep(1000);
      }
      system("Pause");
      system("cls");
    }
    else
    {
      throw invalid_argument("Error, no se pudo abrir el archivo:" + path);
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// Revisa si las luces están prendidas o apagadas.
// De acuerdo a esto, el texto y fondo cambia.
void revisaLuz(Game logic)
{
  if (logic.getLuz() == true)
  {
    system("Color 0f"); //Luces prendidas
    logic.setLuz(true);
  }
  else
  {
    system("Color 08"); // Luces apagadas.
    logic.setLuz(false);
  }
}

void cargarComputadora(string path)
{
  system("Color 0a");
  ifstream archivo;
  string linea;
  try
  {
    if (archivo)
    {
      archivo.open(path);
      while (getline(archivo, linea))
      {
        cout << linea << endl;
      }
      system("Pause");
      system("cls");
    }
    else
    {
      throw invalid_argument("Error, no se pudo abrir el archivo txt.");
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

// Funcion que carga el menu principal del juego, este es llamado despues
// de la funcion cargarPortada()
void menuPrincipal()
{
  Game juego; // Moví el objeto game aquí
  bool exit = false;
  int opcion = 0;
  int vac = 0;
  do
  {
    system("cls");
    cout << "Menu principal: " << endl
        << endl;
    cout << "1) Iniciar juego." << endl;
    cout << "2) Como jugar." << endl;
    cout << "3) Datos de entrega." << endl;
    cout << "4) Salir del juego." << endl;
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    case 1:
      // Iniciar juego
      char opc;
      for (size_t i = 3; i > 0; i--)
      {
        cout << "Iniciando juego... " << i << endl;
        Sleep(1000);
        system("cls");
      }
      // Iniciamos parámetros iniciales del juego, y comienza.
      //bool puertas[5] = {true, true, false, false, false}; // Habitaciones cerradas y abiertas.
      system("Color 0F");
      //cargarFase1();
      //cargarArchivoDialogo("./txt/lucesApagadas.txt", 6);
      do
      {
        revisaLuz(juego);
        system("cls");
        cout << "Actualmente te encuentras en: " << juego.getPosicionJugador() << endl;
        cout << "¿A donde quisieras ir?" << endl << endl;
        cout << "a) Sala principal." << endl;
        cout << "b) Oficina." << endl;
        cout << "c) Seguridad." << endl;
        cout << "d) Enfermeria." << endl;
        cout << "e) Maquina del tiempo." << endl;
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 'a':
          cout << "Actualmente ya te encuentras en " << juego.getPosicionJugador() << ". Creo que estas algo perdido Josh." << endl;
          system("pause");
          juego.salaPrincipal();
          break;
        case 'b':
          //Oficina
          char ofc;
          do{
            revisaLuz(juego);
            system("cls");
            juego.oficina();
            cout << "Actualmente te encuentras en: " << juego.getPosicionJugador() << endl;
            cout << "¿Que quieres hacer?" << endl
                << endl;
            cout << "a) Abrir programas." << endl;
            cout << "b) Abrir mensajes." << endl;
            cout << "c) Abrir correo." << endl;
            cout << "d) Abrir navegador." << endl;
            cout << "e) Abrir escritorio." << endl;
            cout << "f) Ir a Sala Principal." << endl;
            cin >> ofc;
            system("cls");
            switch (ofc) {
            case 'a':
              cargarComputadora("./txt/Programas.txt");
              break;
            case 'b':
              cargarComputadora("./txt/Mensajes.txt");
              break;
            case 'c':
              cargarComputadora("./txt/Correo.txt");
              break;
            case 'd':
              cargarComputadora("./txt/Navegador.txt");
              break;
            case 'e':
              cout << "*Encuentras una tarjeta de color gris.*" << endl;
              impresion("-Josh:  Esto quizá puede abrir algo...");
              juego.ingresarLlave("gris", 1, "Llave Gris", "Una llave de color gris, nada interesante, o si?");
              system("pause");
              break;
            case 'f':
              juego.salaPrincipal();
              break;
            default:
              cout << "No hay mucho en tu oficina, solo fotos, decoracion para tu escritorio, tu silla, tu computadora y una planta falsa." << endl;
              system("Pause");
              break;
            }
          } while (ofc != 'f');
          break;
        case 'c':
          //Seguridad
          char seg;
          // Si la habitación se encuentra cerrada, el juego revisará si tiene la llave
          if(juego.getPuerta(2) == false){
            juego.revisarLlave("gris", 2);
          }
          // Revisa si abrió la habitación, o si está abierta.
          if (juego.seguridad() == true){
            do {
              revisaLuz(juego);
              system("cls");
              cout << "Actualmente te encuentras en: " << juego.getPosicionJugador() << endl;
              cout << "¿Que quieres hacer?" << endl
                  << endl;
              cout << "a) Prender luz." << endl;
              cout << "b) Acceder a camaras de seguridad." << endl;
              cout << "c) Abrir almacen." << endl;
              cout << "d) Ir a Sala Principal." << endl;
              cin >> seg;
              system("cls");
              switch (seg) {
              case 'a':
                juego.setLuz(true);
                revisaLuz(juego);
                cout << "*Encendiste la luz, ahora todo en el juego sera mas visible.*" << endl;
                impresion("-Josh:  Listo, ahora puedo ver mejor");
                system("pause");
                break;
              case 'b':
                cout << "*Ves las camaras de seguridad y no vez nada sospechoso.*" << endl;
                impresion("-Josh:  Todo normal, nada fuera de lo comun, muy bien");
                system("pause");
                break;
              case 'c':
                cout << "*Encuentras un 9mm, lo guardas en tu bolsillo. También, encuentras una llave de color rojo, lo agarras.*" << endl;
                juego.ingresarLlave("rojo", 1, "Llave Roja", "Una llave de color roja, nada interesante, o si?");
                juego.ingresarArma(10, 15, "Pistola 9mm", "Una pistola de calibre 9mm, chiquita pero leta");
                system("pause");
              case 'd':
                juego.salaPrincipal();
                break;
              default:
                cout << "Seguridad, no es una habitacion cualquiera: armas, camaras de seguridad y llaves de acceso. Para entrar aqui algo no muy bueno de estar sucediendo." << endl;
                break;
              }
            } while (seg != 'd');
          } else {
            system("pause");
          }
          break;
        case 'd':
          //Enfermeria
          char enf;
          // Si la habitación se encuentra cerrada, el juego revisará si tiene la llave
          if(juego.getPuerta(3) == false){
            juego.revisarLlave("rojo", 3);
          }
          // Revisa si abrió la habitación, o si está abierta.
          if (juego.enfermeria() == true){
            do {
              revisaLuz(juego);
              system("cls");
              cout << "Actualmente te encuentras en: " << juego.getPosicionJugador() << endl;
              cout << "¿Que quieres hacer?" << endl
                  << endl;
              cout << "a) Agarrar Medkit." << endl;
              cout << "b) Agarrar vacuna." << endl;
              cout << "c) Entrar al baño." << endl;
              cout << "d) Ir a Sala Principal." << endl;
              cin >> enf;
              system("cls");
              switch (enf) {
              case 'a':
                cout << "*Observas el medkit de primeros auxilios.*" << endl;
                impresion("-Josh:  Quizá me pueda servir, lo guardo por si acaso");
                juego.ingresarMedkit(10, 1, "Medkit", "Medkit de primeros auxilios");
                system("pause");
                break;
              case 'b':
                cout << "*Te encuentras con una vacuna, con un líquido color rojo*" << endl;
                impresion("-Josh:  Recuerdo los prototipos, y que tan efectivos eran. Espero que sean mejor");
                juego.ingresarVacuna(20, 1, "Vacuna", "Esta vacuna ingrementa el daño del jugador");
                system("pause");
                break;
              case 'c':
                cout << "*Encuentras la llave negra, junto con una nota:*" << endl;
                Sleep(1000);
                impresion("Te espero en la maquina de tiempo, para explicarte algunas cosas. -J.");
                Sleep(1000);
                impresion("-Josh:  Extraño, tendré que investigar. Espero que no sea una broma de mi jefe.");
                Sleep(1000);
                cout << "*Guardas la llave negra" << endl;
                juego.ingresarLlave("negro", 1, "Llave negra", "Una llave de color negro, abre el cuarto time machien.");
              case 'd':
                juego.salaPrincipal();
                system("pause");
                break;
              default:
                cout << "Enfermeria, si estas aqui es porque posiblemente estes herido. Vaya noche tan mas larga." << endl;
                break;
              }
            } while (enf != 'd');
          } else {
            system("pause");
          }
          break;
        case 'e':
          //Maquina del tiempo
          char mt;
          int atk;
          if(juego.getPuerta(4) == false){
            juego.revisarLlave("negro", 4);
          }
          if(juego.timeMachine() == true){
            cargarArchivoDialogo("./txt/EtapaFinal.txt", 31);
            do {
              revisaLuz(juego);
              system("cls");
              cout << "Josh del futuro:   " << juego.getVidaEne() << "/100 HP" << endl;
              cout << "           Vida:   " << juego.getVidaPer() << "/100 HP" << endl << endl;
              cout << "¿Que deseas hacer?" << endl << endl;
              cout << "a) Atacar con puño." << endl;
              if (juego.revisarArma() == true){
                cout << "b) Atacar con arma." << endl;
              }
              if (juego.revisarMedkit() == true){
                cout << "c) Usar medkit (Incrementa tu vida)." << endl;
              }
              if (juego.revisarVacuna() == true){
                cout << "d) Usar vacuna (Incrementa tu daño)." << endl;
              }
              cout << "e) Ver inventario." << endl;
              cin >> mt;
              system("cls");
              switch (mt){
              case 'a':
                atk = rand() % 5 + 1;
                juego.setVidaEne(juego.getVidaEne() - atk - vac);
                cout << "Haz hecho " << atk + vac << " de daño." << endl;
                system("pause");
                break;
              case 'b':
                if (juego.revisarArma() == true){
                  atk = rand() % 10 + 5;
                  juego.setVidaEne(juego.getVidaEne() - atk);
                  cout << "Haz hecho " << atk + vac << " de daño." << endl;
                } else {
                  cout << "No tienes ninguna arma en tu inventario." << endl;
                }
                system("pause");
                break;
              case 'c':
                if (juego.revisarMedkit() == true){
                  juego.usarMedkit();
                  cout << "Haz incrementado tu vida a: +10" << endl;
                  cout << "                      Vida:   " << juego.getVidaPer() << "/100 HP" << endl;
                  juego.ingresarObjVacio("Medkit");
                }
                system("pause");
                break;
              case 'd':
                if (juego.revisarVacuna() == true){
                  vac = juego.usarVacuna();
                  cout << "Haz incrmentado tus ataques a: +" << vac << endl;
                  juego.ingresarObjVacio("Vacuna");
                }
                system("pause");
                break;
              case 'e':
                juego.mostrarInventario();
                system("pause");
                break;
              default:
                cout << "No hay escapatoria. Es vivir o morir en el intento. Mucha suerte." << endl;
                system("pause");
                break;
              }
              if (mt != 'e'){
                atk = rand() % 10 + 1;
                juego.setVidaPer(juego.getVidaPer() - atk - vac);
                for (int i = 0; i < 3; i++) {
                  system("Color 40");
                  Sleep(350);
                  system("Color 04");
                  Sleep(350);
                }
                revisaLuz(juego);
                cout << "Haz recibido " << atk << " de daño." << endl;
                system("pause");
              }
            } while (juego.getVidaPer() > 0 && juego.getVidaEne() > 0);
            system("cls");
            if (juego.getVidaPer() <= 0){
              cargarArchivoDialogo("./txt/FinalMalo.txt", 15);
              system("pause");
            } else if (juego.getVidaEne() <= 0){
              cargarArchivoDialogo("./txt/FinalBueno.txt", 36);
              system("pause");
            }
            exit = true;
          } else {
            system("pause");
          }
          break;
        default:
          cout << "Si fuera asi de facil, ya estarias durmiendo en tu casa ¿No crees?" << endl;
          system("pause");
          break;
        }
      } while (opc != 'e' || exit != true);
      break;
      system("pause");
    case 2:
      comoJugar();
      break;
    case 3:
      datosEntrega();
      break;
    case 4:
      // Salir del juego
      cout << "¡Gracias por jugar!" << endl;
      system("pause");
      break;
    case 5:
      juego.mostrarInventario();
      system("pause");
      break;
    default:
      // Opcion default
      cout << "Opcion no valida, vuelve a intentarlo." << endl;
      system("pause");
      break;
    }
  } while (opcion != 4);
  system("cls");
}

int main()
{
  setlocale(LC_CTYPE, "Spanish");
  system("cls");
  system("Title Time Paradox");
  system("Color 04");
  //ajustePantalla();
  //cargarPortada();
  menuPrincipal();
  //system("cls");
  //system("pause");
  return 0;
}