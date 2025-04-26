#include <string>
#include <iostream>
#include "ArchivoPostulante.h"

using namespace std;

ArchivoPostulante::ArchivoPostulante(string nombreArchivo) 
: Archivo(nombreArchivo)
{
}


void ArchivoPostulante::guardarPostulante(Postulante postulante)
{
    
    if (!abrirEscritura()){
        return;
    }

    fwrite(&postulante, sizeof(Postulante), 1, _pArchivo);
    cerrar();
}

void ArchivoPostulante::leerPostulantes(Postulante postulantes[], int cantidad)
{
    if (!abrirLectura()){
        return;
    }

    fread(postulantes, sizeof(Postulante), cantidad, _pArchivo);
    
    cerrar();
}

int ArchivoPostulante::getCantidadRegistros()
{
    if (!abrirLectura()){ 
        return 0;
    }

    fseek(_pArchivo, 0, SEEK_END);
    int cantidad = ftell(_pArchivo) / sizeof(Postulante);
    cerrar();

    return cantidad;
}
