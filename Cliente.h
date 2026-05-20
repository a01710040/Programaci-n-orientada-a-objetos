#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

/*
 * Clase Cliente: Representa a los clientes del vivero.
 */
class Cliente {
private:
    string nombreCliente;
    double presupuestoCliente;

public:
    // --- Declaraciones ---
    Cliente();
    Cliente(string nombreIn, double presupuestoIn);
    
    string getNombre() const;
    
    bool comprar(double costoCompra);
    void mostrar();
};

/**
 * Constructor por defecto. Inicializa Cliente con valores base.
 *
 * @param Ninguno
 * @return Objeto Cliente
 */
Cliente::Cliente() {
    nombreCliente = "Sin Nombre";
    presupuestoCliente = 0.0;
}

/**
 * Constructor con parámetros.
 *
 * @param string nombreIn: Nombre del cliente.
 * @param double presupuestoIn: Dinero inicial del cliente.
 * @return Objeto Cliente
 */
Cliente::Cliente(string nombreIn, double presupuestoIn) {
    nombreCliente = nombreIn;
    presupuestoCliente = presupuestoIn;
}

/**
 * Método getter para obtener el nombre del cliente.
 *
 * @param Ninguno
 * @return string: Nombre del cliente.
 */
string Cliente::getNombre() const {
    return nombreCliente;
}

/**
 * Simula la compra. Verifica si hay presupuesto suficiente.
 *
 * @param double costoCompra: Precio total de la compra.
 * @return bool: true si la compra fue exitosa, false si no.
 */
bool Cliente::comprar(double costoCompra) {
    if (presupuestoCliente >= costoCompra) {
        presupuestoCliente = presupuestoCliente - costoCompra;
        return true;
    }
    return false;
}

/**
 * Método para mostrar el nombre y el saldo del cliente.
 *
 * @param Ninguno
 * @return void
 */
void Cliente::mostrar() {
    cout << "Cliente: " << nombreCliente << " | Saldo: $" << 
        presupuestoCliente << endl;
}

#endif // CLIENTE_H_
