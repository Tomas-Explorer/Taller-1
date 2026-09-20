#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Sistema.h"
using namespace std;
Sistema* sistema = new Sistema();

void leerArchivo() {
    ifstream arch("pacientes.txt");
    string linea;

    while(getline(arch, linea)){
        stringstream ss(linea);
        string id, nombre, stringEdad, servicio;
        
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, stringEdad, ';');
        getline(ss, servicio, ';');

        int edad = stoi(stringEdad);
        if(!sistema->verificarSiExisteServicio(servicio)) {sistema->crearServicio(servicio);}   
        sistema->crearPaciente(id, nombre, edad, servicio);
        cout << linea << endl;
    }
}

void mostrarPacientes() {
    cout << sistema->recorrerListaPacientes() << endl;
}

void mostrarServicios() {
    cout << sistema->recorrerHospital() << endl;
}

int main() {
    
    leerArchivo();
    mostrarPacientes();
    mostrarServicios();
}

