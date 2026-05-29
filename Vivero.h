#ifndef VIVERO_H_
#define VIVERO_H_

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

#define MAX_INVENTARIO 50

class Vivero {
private:
    Planta* InventarioPlantas[MAX_INVENTARIO];
    Maceta* InventarioMacetas[MAX_INVENTARIO];
    Cliente* ListaClientes[MAX_INVENTARIO];

    int contadorPlantas;
    int contadorMacetas;
    int contadorClientes;

public:
    Vivero();
    Vivero(int contP, int contM, int contC);
    
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, double precio, bool esColgante);
    
    void registrarCliente(Cliente* c);

    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indicePlanta);
    void realizarVentaMaceta(int indiceCliente, int indiceMaceta);
};

Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    contadorPlantas = 0;
    contadorMacetas = 0;
    contadorClientes = 0;
}

Vivero::Vivero(int contP, int contM, int contC) {
    cout << ">> Vivero creado con contadores iniciales." << endl;
    contadorPlantas = contP;
    contadorMacetas = contM;
    contadorClientes = contC;
}

void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contadorPlantas < MAX_INVENTARIO) {
        InventarioPlantas[contadorPlantas] = new Planta(nombre, precio, stock);
        contadorPlantas++;
        cout << ">> Planta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

void Vivero::crearMaceta(string nombre, string material, string color, double precio, bool esColgante) {
    if (contadorMacetas < MAX_INVENTARIO) {
        InventarioMacetas[contadorMacetas] = new Maceta(nombre, material, color, precio, esColgante);
        contadorMacetas++;
        cout << ">> Maceta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

void Vivero::registrarCliente(Cliente* c) {
    if (contadorClientes < MAX_INVENTARIO) {
        ListaClientes[contadorClientes] = c;
        contadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas (" << contadorPlantas << ") ---" << endl;
    for (int i = 0; i < contadorPlantas; i++) {
        cout << i << ". "; 
        
        Producto* p = InventarioPlantas[i]; 
        p->mostrar();
    }

    cout << "--- Macetas (" << contadorMacetas << ") ---" << endl;
    for (int i = 0; i < contadorMacetas; i++) {
        cout << i << ". ";
        
        Producto* p = InventarioMacetas[i];
        p->mostrar();
    }

    cout << "--- Clientes (" << contadorClientes << ") ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        cout << i << ". ";
        ListaClientes[i]->mostrar();
    }
    cout << "==========================" << endl;
}

void Vivero::realizarVenta(int indiceCliente, int indicePlanta) {
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indicePlanta >= 0 && indicePlanta < contadorPlantas) {

        Cliente* elCliente = ListaClientes[indiceCliente];
        Planta* laPlanta = InventarioPlantas[indicePlanta];

        cout << "\nIntento de venta: " << elCliente->getNombre() << 
            " quiere " << laPlanta->getNombre() << endl;

        if (laPlanta->getStock() > 0) {
            if (elCliente->comprar(laPlanta->getPrecio())) {
                laPlanta->actualizarStock(-1); 
                cout << ">> Venta Exitosa!" << endl;
                
            } else {
                cout << ">> Saldo insuficiente." << endl;
            }
        } else {
            cout << ">> No hay stock." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

void Vivero::realizarVentaMaceta(int indiceCliente, int indiceMaceta) {
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indiceMaceta >= 0 && indiceMaceta < contadorMacetas) {
        
        Cliente* elCliente = ListaClientes[indiceCliente];
        Maceta* laMaceta = InventarioMacetas[indiceMaceta];

        cout << "\nIntento de venta: " << elCliente->getNombre() << 
            " quiere " << laMaceta->getNombre() << endl;

        if (elCliente->comprar(laMaceta->getPrecio())) {
            cout << ">> Venta Exitosa! Maceta eliminada del inventario." << endl;
            
            for (int i = indiceMaceta; i < contadorMacetas - 1; i++) {
                InventarioMacetas[i] = InventarioMacetas[i + 1];
            }
            contadorMacetas--;
        } else {
            cout << ">> Saldo insuficiente." << endl;
        }
    } else {
        cout << ">> Error: Indices no validos." << endl;
    }
}

#endif // VIVERO_H_
