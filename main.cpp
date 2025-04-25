#include <iostream>
#include "ArchivoPostulante.h"

using namespace std;

int main()
{
    ArchivoPostulante pa;
        
    
    Postulante *postulantes = new Postulante[pa.getCantidadRegistros()]; 
    pa.leerPostulantes(postulantes, pa.getCantidadRegistros());
    
    for (int i = 0; i < pa.getCantidadRegistros(); i++) {
        cout << postulantes[i].getNombre() << " " << postulantes[i].getApellido() << endl;
    }

    system("pause");
    delete[] postulantes;
    return 0;
}
