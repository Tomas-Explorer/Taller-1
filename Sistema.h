#include <iostream>
#include "Hospital.h"
#include "ListaPacientes.h"
#include "NodoPaciente.h"

using namespace std;

class Sistema {
    private:
        Hospital* hospital = new Hospital("");
        ListaPacientes* lista = new ListaPacientes();

    public:
        void crearPaciente(string id, string nombre, int edad, string servicio);
        void crearServicio(string nombre);
        string recorrerListaPacientes();
        string recorrerHospital();
        bool verificarSiExisteServicio(string nombre);
};