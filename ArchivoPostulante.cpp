#include <string>
#include <iostream>
#include "ArchivoPostulante.h"

using namespace std;

ArchivoPostulante::ArchivoPostulante(string nombreArchivo) 
: _nombreArchivo(nombreArchivo)
{
    _pArchivo = nullptr;
}

string ArchivoPostulante::getNombreArchivo()
{
    return _nombreArchivo;
}

void ArchivoPostulante::guardarPostulante(Postulante postulante)
{
    _pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    
    if (_pArchivo == nullptr) {
        return;
    }

    fwrite(&postulante, sizeof(Postulante), 1, _pArchivo);
    fclose(_pArchivo);
}

void ArchivoPostulante::leerPostulantes(Postulante postulantes[], int cantidad)
{
    _pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    
    if (_pArchivo == nullptr) {
        return;
    }

    fread(postulantes, sizeof(Postulante), cantidad, _pArchivo);
    fclose(_pArchivo);
}

int ArchivoPostulante::getCantidadRegistros()
{
    _pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    
    if (_pArchivo == nullptr) {
        return 0;
    }

    fseek(_pArchivo, 0, SEEK_END);
    int cantidad = ftell(_pArchivo) / sizeof(Postulante);
    fclose(_pArchivo);

    return cantidad;
}
