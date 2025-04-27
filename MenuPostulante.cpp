#include <string>
#include <iostream>
#include "MenuPostulante.h"
#include "Menu.h"

using namespace std;

MenuPostulante::MenuPostulante(){
    int cantOpciones = 5;
    setCantidadOpciones(cantOpciones);

    const string opciones[] = {
        "1. Cargar postulante", 
        "2. Listar postulantes", 
        "3. Buscar postulante", 
        "5. Eliminar postulante", 
        "6. Salir"
    };

    setOpciones(opciones);
    setMedidas();
    setPosicionCentro();
}

MenuPostulante::MenuPostulante(int x, int y){
    setCantidadOpciones(5);

    const string opciones[] = {
        "1. Cargar postulante", 
        "2. Listar postulantes", 
        "3. Buscar postulante", 
        "5. Eliminar postulante", 
        "6. Salir"
    };

    setOpciones(opciones);
    setMedidas();
    setPosicion(x, y);
}

void MenuPostulante::aparecer(){
    int opcion = seleccion();
    switch (opcion) {
        case 1:
            ///_postulanteManager.cargarPostulante();
            break;
        case 2:
            ///_postulanteManager.listarPostulantes();
            break;
        case 3:
            ///_postulanteManager.buscarPostulante();
            break;
        case 4:
            ///_postulanteManager.modificarPostulante();
            break;
        case 5:
            ///_postulanteManager.eliminarPostulante();
            break;
        case 6:
            system("cls");
            cout << "Saliendo del menu de postulantes..." << endl;
            return;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
    }
}