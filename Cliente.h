#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombreCliente;
    double presupuestoCliente;

public:
    Cliente();
    Cliente(string nombreIn, double presupuestoIn);
    
    string getNombre() const;
    bool comprar(double costoCompra);
    void mostrar();
};

Cliente::Cliente() {
    nombreCliente = "Sin Nombre";
    presupuestoCliente = 0.0;
}

Cliente::Cliente(string nombreIn, double presupuestoIn) {
    nombreCliente = nombreIn;
    presupuestoCliente = presupuestoIn;
}

string Cliente::getNombre() const {
    return nombreCliente;
}

bool Cliente::comprar(double costoCompra) {
    if (presupuestoCliente >= costoCompra) {
        presupuestoCliente = presupuestoCliente - costoCompra;
        return true;
    }
    return false;
}

void Cliente::mostrar() {
    cout << "Cliente: " << nombreCliente << " | Saldo: $" << 
        presupuestoCliente << endl;
}

#endif // CLIENTE_H_
