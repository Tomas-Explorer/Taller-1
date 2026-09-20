#include <iostream>
#include "NodoPaciente.h"
using namespace std;
#pragma once

class ListaPacientes {
    private:
        NodoPaciente* primero;

    public: 
        ListaPacientes() {
            this->primero = nullptr;
        }
        NodoPaciente* getPrimero() {return primero;}
        void setPrimero(NodoPaciente* nuevo) {this->primero = nuevo;}
};