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
    

    int opcion;

    do {
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atención" << endl;
        cout << "4. Salir" << endl;
        cout << endl;
        cin>>opcion;

        switch(opcion) {
            case 1:
                cout << "=== PACIENTES EN ESPERA ===" << endl;
                mostrarPacientes();

                cout << "Indique la cantidad de pacientes a atender: " << endl;

                int cantidad;
                cin>>cantidad;

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                break;
        }

       

    } while(opcion != 4);
}

