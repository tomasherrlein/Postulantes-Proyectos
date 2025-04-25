#include "Postulante.h"
#include <string>
#include <cstring>
using namespace std;

Postulante::Postulante() 
: _id(0), _edad(0), _experiencia(0), _contratado(false) {
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_puesto, "");
}

Postulante::Postulante(int id, string nombre, string apellido, int edad, string puesto, int experiencia, bool contratado)
{
    setId(id);
    setNombre(nombre);
    setApellido(apellido);
    setEdad(edad);
    setPuesto(puesto);
    setExperiencia(experiencia);
    setContratado(contratado);
}

int Postulante::getId() {
    return _id;
}

void Postulante::setId(int id) {
    _id = id;
}

string Postulante::getNombre() {
    return string(_nombre);
}

void Postulante::setNombre(string nombre) {
    if(nombre.size() < 25) {
        strcpy(_nombre, nombre.c_str());
    }
}

string Postulante::getApellido() {
    return _apellido;
}

void Postulante::setApellido(string apellido) {
    if(apellido.size() < 25) {
        strcpy(_apellido, apellido.c_str());
    }
}

int Postulante::getEdad() {
    return _edad;
}

void Postulante::setEdad(int edad) {
    _edad = edad;
}

string Postulante::getPuesto() {
    return _puesto;
}

void Postulante::setPuesto(string puesto) {
    if(puesto.size() < 50) {
        strcpy(_puesto, puesto.c_str());
    }
}

int Postulante::getExperiencia() {
    return _experiencia;
}

void Postulante::setExperiencia(int experiencia) {
    _experiencia = experiencia;
}

bool Postulante::getContratado() {
    return _contratado;
}

void Postulante::setContratado(bool contratado) {
    _contratado = contratado;
}
