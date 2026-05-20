#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    double presupuesto;

public:
    Cliente() {
        nombre = "Sin Nombre";
        presupuesto = 0.0;
    }

    Cliente(string p_nombre, double p_presupuesto);
    string getNombre();
    bool comprar(double costo);
    void mostrar();
};

Cliente::Cliente(string p_nombre, double p_presupuesto) {
    nombre = p_nombre;
    presupuesto = p_presupuesto;
}

string Cliente::getNombre() {
    return nombre;
}

bool Cliente::comprar(double costo) {
    if (presupuesto >= costo) {
        presupuesto = presupuesto - costo;
        return true;
    }
    return false;
}

void Cliente::mostrar() {
    cout << "Cliente: " << nombre << " | Saldo: $" << presupuesto << endl;
}

#endif
