#include <iostream>
#include <conio.h>
#include <string>
#include "Menu.h"
#include "rlutil.h"

using namespace std;

Menu::Menu() 
: _alto(0), _ancho(0), _x(0), _y(0), _cantOpciones(0), _opciones(nullptr) {
    // Constructor por defecto
}

Menu::Menu(int cantOpciones, const string opciones[]){

    if(!setCantidadOpciones(cantOpciones)){
        return;
    }
    setOpciones(opciones);
    setMedidas();
    setPosicionCentro();
}

Menu::Menu(int cantOpciones, const string opciones[], int x, int y){

    if(!setCantidadOpciones(cantOpciones)){
        return;
    }
    setOpciones(opciones);
    setMedidas();
    setPosicion(x, y);
}

Menu::~Menu(){
    delete[] _opciones;
}

int Menu::seleccion(){

    char tecla;
    int opcion = 0;

    while(true){
        imprimirMarco();

        for(int i=0; i<_cantOpciones; i++){
            rlutil::locate(_x + 1, _y + (i + 1));

            if (i == opcion){
                cout << " > " << _opciones[i] << " < " << endl;
            }
            else{
                cout << "   " << _opciones[i] << "   " << endl;
            }
        }

        ///getch envia primero un codigo si la tecla es especial
        ///en este caso windows para las flechas retorna -32
        tecla = _getch();
        if (tecla == -32 || tecla == 0) {
            tecla = _getch();
            if (tecla == 72) { ///Flecha arriba
                opcion--;
                if (opcion < 0) opcion = _cantOpciones-1;
            }
            else if (tecla == 80) { ///Flecha abajo
                opcion++;
                if (opcion >= _cantOpciones) opcion = 0;
            }
        }
        else if (tecla == 13) { ///Enter
            return opcion + 1;
        }
    }
}

int Menu::getTamanioOpcionMasLarga(){
    int tamanio = 0;
    for(int i=0; i<_cantOpciones; i++){
        if (_opciones[i].size() > tamanio){
            tamanio = _opciones[i].size();
        }
    }
    return tamanio;
}

int Menu::getCantidadOpciones(){
    return _cantOpciones;
}

bool Menu::setCantidadOpciones(int cantOpciones){
    if (cantOpciones <= 0){
        return false;
    }

    _cantOpciones = cantOpciones;
    return true;
}

void Menu::setOpciones(const string opciones[]){
    _opciones = new string[_cantOpciones];
    for(int i=0; i < _cantOpciones; i++){
        _opciones[i] = opciones[i];
    }   
}

void Menu::imprimirMarco() {
    
    // Línea superior
    rlutil::locate(_x, _y);
    cout << (char)218; // Esquina superior izquierda
    for (int x = 1; x < _ancho - 1; x++) {
        cout << (char)196; // Línea horizontal
    }
    cout << (char)191; // Esquina superior derecha

    // Líneas intermedias
    for (int y = 1; y < _alto - 1; y++) {
        rlutil::locate(_x, _y + y);
        cout << (char)179; // Línea vertical izquierda
        rlutil::locate(_x + _ancho - 1, _y + y);
        cout << (char)179; // Línea vertical derecha
    }

    // Línea inferior
    rlutil::locate(_x, _y + _alto - 1);
    cout << (char)192; // Esquina inferior izquierda
    for (int x = 1; x < _ancho - 1; x++) {
        cout << (char)196; // Línea horizontal
    }
    cout << (char)217; // Esquina inferior derecha
}

void Menu::setMedidas(){
    _ancho = getTamanioOpcionMasLarga() + 8;
    _alto = _cantOpciones + 2;
}

void Menu::setPosicion(int x, int y){
    _x= x;
    _y= y;
}

void Menu::setPosicionCentro(){
    _x = (120 - _ancho) / 2;
    _y = (30 - _alto) / 2;
}
