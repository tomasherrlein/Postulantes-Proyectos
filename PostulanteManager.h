#pragma once
#include "ArchivoPostulante.h"

class PostulanteManager {
    public:
        void cargarPostulante();
        void mostrarPostulantes();
    private:
        void mostrarPostulante(Postulante postulante);
};

