#include <iostream>
#include "PostulanteManager.h"
#include "Postulante.h"

using namespace std;

void PostulanteManager::mostrarPostulantes(){
    ArchivoPostulante pa;

    int cantidadRegistros = pa.getCantidadRegistros();
    if (cantidadRegistros <= 0) {
        cout << "No hay registros disponibles." << endl;
        return;
    }
    
    Postulante *postulantes = new Postulante[cantidadRegistros]; 
    pa.leerPostulantes(postulantes, cantidadRegistros);
    
    for (int i = 0; i < cantidadRegistros; i++) {
        cout << "--------------------------" << endl;
        mostrarPostulante(postulantes[i]);
        cout << endl;
    }

    delete[] postulantes;
}

void PostulanteManager::mostrarPostulante(Postulante postulante) {
    cout << "Postulante " << postulante.getId() << endl;
    cout << "Nombre: " << postulante.getNombre() << endl;
    cout << "Apellido: " << postulante.getApellido() << endl;
    cout << "Puesto: " << postulante.getPuesto() << endl;
    cout << "Anios de experiencia: " << postulante.getExperiencia() << endl;
    cout << "Contratado: " << (postulante.getContratado() ? "Si" : "No") << endl;
}

void PostulanteManager::cargarPostulante() {
    ArchivoPostulante pa;
    Postulante postulante;
    int id;
    string nombre, apellido, puesto;
    int experiencia;
    char contratado;

    id = pa.getNuevoId();
    cout << "ID del postulante: " << id << endl;
    postulante.setId(id);

    cout << "Ingrese nombre del postulante: ";
    getline(cin, nombre);
    postulante.setNombre(nombre);

    cout << "Ingrese apellido del postulante: ";
    getline(cin, apellido);
    postulante.setApellido(apellido);

    cout << "Ingrese puesto al que aplica: ";
    getline(cin, puesto);
    postulante.setPuesto(puesto);

    cout << "Ingrese anios de experiencia: ";
    cin >> experiencia;
    postulante.setExperiencia(experiencia);

    cout << "¿Esta contratado? (s/n): ";
    cin >> contratado;
    postulante.setContratado(contratado == 's' || contratado == 'S');

    pa.guardarPostulante(postulante);
}