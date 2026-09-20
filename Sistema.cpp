#include <iostream>
#include <string>
#include "Sistema.h"
#include "Hospital.h"
#include "ListaPacientes.h"
#include "NodoPaciente.h"
using namespace std;

void Sistema::crearPaciente(string id, string nombre, int edad, string servicio) {
    Paciente* paciente = new Paciente(id, nombre, edad, servicio);
    NodoPaciente* nodoPaciente = new NodoPaciente(paciente);

    if(lista->getPrimero() == nullptr) {
        lista->setPrimero(nodoPaciente);
        return;
    }

    NodoPaciente* actual = lista->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }

    actual->setSiguiente(nodoPaciente);

    return;
}

void Sistema::crearServicio(string nombre) {
    Servicio* servicio = new Servicio(nombre);

    if(hospital->getPrimero() == nullptr) {
        hospital->setPrimero(servicio);
        return;
    }

    Servicio* actual = hospital->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }

    actual->setSiguiente(servicio);
   
    return;
}

string Sistema::recorrerListaPacientes() {
    cout << endl;
    string texto;
    
    if (lista->getPrimero() == nullptr) {
        texto += "La lista está vacía.";
        return texto;
    }

    NodoPaciente* actual = lista->getPrimero();

    int contador = 1;

    while(actual->getSiguiente() != nullptr) {
        Paciente* paciente = actual->getPaciente();

        texto += to_string(contador) + ". " + paciente->getId() + " - " + paciente->getNombre() + "\n";
        contador++;
        actual = actual->getSiguiente();
    }

    return texto;
    cout << endl;
}

string Sistema::recorrerHospital() {
    string texto = "";

    if(hospital->getPrimero() == nullptr) {
        texto += "No hay servicios.";
        return texto;
    }

    Servicio* actual = hospital->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        texto += actual->getNombre() + "\n";
        actual = actual->getSiguiente();
    }

    return texto;
}

bool Sistema::verificarSiExisteServicio(string nombre) {
    if(hospital->getPrimero() == nullptr) {return false;}

    Servicio* actual = hospital->getPrimero();

    while(actual->getSiguiente() != nullptr) {
        if(actual->getNombre() == nombre) {return true;}

       actual = actual->getSiguiente();
    }

    return false;
}  

void Sistema::repletarServicios(int cantidad) {
    if(lista->getPrimero() == nullptr || hospital->getPrimero() == nullptr) {return;}

    NodoPaciente* pacienteActual = lista->getPrimero();
    Servicio* servicioActual = hospital->getPrimero();

    while(servicioActual != nullptr) {
        if(pacienteActual->getPaciente()->getServicio() == servicioActual->getNombre()) {
            ListaPacientes listaPacientes = servicioActual->getListaPacientes();

            if(listaPacientes.getPrimero() == nullptr) {
                listaPacientes.setPrimero(pacienteActual);
                break;
            } else {
                NodoPaciente* actual = listaPacientes.getPrimero();
                
                while(actual->getSiguiente() != nullptr) {
                    actual = actual->getSiguiente();
                }

                actual->setSiguiente(pacienteActual);
            }
            pacienteActual = pacienteActual->getSiguiente();
        }
        servicioActual = servicioActual->getSiguiente();
    } 

}