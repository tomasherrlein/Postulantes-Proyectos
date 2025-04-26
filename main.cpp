#include <iostream>
#include "ArchivoPostulante.h"

using namespace std;

int main()
{
    ArchivoPostulante pa;

    int cantidadRegistros = pa.getCantidadRegistros();
    if (cantidadRegistros <= 0) {
        cout << "No hay registros disponibles." << endl;
        return 0;
    }
        
    cout << "Cantidad de registros: " << cantidadRegistros << endl; 
    Postulante *postulantes = new Postulante[cantidadRegistros]; 
    pa.leerPostulantes(postulantes, cantidadRegistros);
    
    for (int i = 0; i < cantidadRegistros; i++) {
        cout << postulantes[i].getNombre() << " " << postulantes[i].getApellido() << endl;
    }

    system("pause");
    delete[] postulantes;
    return 0;
}
