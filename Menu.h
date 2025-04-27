#pragma once
class Menu
{
    public:
        Menu();
        Menu(int cantOpciones, const std::string opciones[]);
        Menu(int cantOpciones, const std::string opciones[], int x, int y);
        ~Menu();
        int seleccion();
        
        protected:
        bool setCantidadOpciones(int cantOpciones);
        void setOpciones(const std::string opciones[]);
        void setMedidas();
        void setPosicionCentro();
        void setPosicion(int x, int y);
        
        private:
        void imprimirMarco();
        int getTamanioOpcionMasLarga();
        int getCantidadOpciones();
        
        int _alto;
        int _ancho;
        int _x;
        int _y;
        int _cantOpciones;	
        std::string *_opciones;
};

