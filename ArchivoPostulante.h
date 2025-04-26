#pragma once
#include <string>
#include "Archivo.h"
#include "Postulante.h"

class ArchivoPostulante : public Archivo{
    public:
        ArchivoPostulante(std::string nombreArchivo = "Postulantes.dat");

        void guardarPostulante(Postulante postulante);
        Postulante leer(int posicion);
        void leerPostulantes(Postulante postulantes[], int cantidad);
        int getCantidadRegistros();
        int getNuevoId();

};