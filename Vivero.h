#ifndef VIVERO_H
#define VIVERO_H

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

#define MAX 50

class Vivero {
private:
    Planta inventarioPlantas[MAX];
    Maceta inventarioMacetas[MAX];
    Cliente listaClientes[MAX];

    int contadorPlantas;
    int contadorMacetas;
    int contadorClientes;

public:
    Vivero();
    void agregarPlanta(Planta p);
    void agregarMaceta(Maceta m);
    void registrarCliente(Cliente c);
    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indicePlanta);
};

Vivero::Vivero() {
    contadorPlantas = 0;
    contadorMacetas = 0;
    contadorClientes = 0;
}

void Vivero::agregarPlanta(Planta p) {
    if (contadorPlantas < MAX) {
        inventarioPlantas[contadorPlantas] = p;
        contadorPlantas++; 
    } else {
        cout << "Inventario Lleno." << endl;
    }
}

void Vivero::agregarMaceta(Maceta m) {
    if (contadorMacetas < MAX) {
        inventarioMacetas[contadorMacetas] = m;
        contadorMacetas++;
    } else {
        cout << "Inventario Lleno." << endl;
    }
}

void Vivero::registrarCliente(Cliente c) {
    if (contadorClientes < MAX) {
        listaClientes[contadorClientes] = c;
        contadorClientes++;
    } else {
        cout << "Lista de Clientes Llena." << endl;
    }
}

void Vivero::mostrarInventario() {
    cout << "===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas ---" << endl;
    for (int i = 0; i < contadorPlantas; i++) {
        inventarioPlantas[i].mostrar();
    }

    cout << "--- Clientes ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        listaClientes[i].mostrar();
    }
    cout << "==========================" << endl;
}

void Vivero::realizarVenta(int indiceCliente, int indicePlanta) {
    if (indiceCliente < contadorClientes && indicePlanta < contadorPlantas) {
        
        Cliente elCliente = listaClientes[indiceCliente];
        Planta laPlanta = inventarioPlantas[indicePlanta];

        cout << "\nIntento de venta: " << elCliente.getNombre() << " quiere " << laPlanta.getNombre() << endl;

        if (laPlanta.getStock() > 0) {
            if (elCliente.comprar(laPlanta.getPrecio())) {
                
                laPlanta.actualizarStock(-1);
                cout << ">> Venta Exitosa!" << endl;

                listaClientes[indiceCliente] = elCliente;
                inventarioPlantas[indicePlanta] = laPlanta;

            } else {
                cout << ">> Saldo insuficiente." << endl;
            }
        } else {
            cout << ">> No hay stock." << endl;
        }
    }
}

#endif
