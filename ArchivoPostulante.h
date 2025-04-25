#pragma once
#include <string>
#include "Postulante.h"

class ArchivoPostulante
{
    public:
        ArchivoPostulante(std::string nombreArchivo = "Postulantes.dat");
        std::string getNombreArchivo();

        void guardarPostulante(Postulante postulante);
        Postulante leer(int posicion);
        void leerPostulantes(Postulante postulantes[], int cantidad);
        int getCantidadRegistros();
        
    private:
        std::string _nombreArchivo;
        FILE *_pArchivo;

};