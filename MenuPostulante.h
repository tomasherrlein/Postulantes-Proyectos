#pragma once
#include "Menu.h"
#include "PostulanteManager.h"

class MenuPostulante : public Menu
{
    public:
        MenuPostulante();
        MenuPostulante(int x, int y);

        void aparecer();
    
    private:
        PostulanteManager _postulanteManager;
        


};