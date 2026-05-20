#ifndef VIVERO_H_
#define VIVERO_H_

#include <iostream>
#include "Productos.h"
#include "Cliente.h"

using namespace std;

// Constante para el tamaño máximo de los arreglos
#define MAX_INVENTARIO 50

/*
 * Clase Vivero: Clase Gestora (Manager Class).
 */
class Vivero {
private:
    // Atributos colecciones
    Planta InventarioPlantas[MAX_INVENTARIO];
    Maceta InventarioMacetas[MAX_INVENTARIO];
    Cliente ListaClientes[MAX_INVENTARIO];

    // Contadores
    int contadorPlantas;
    int contadorMacetas;
    int contadorClientes;

public:
    // --- Declaraciones de Constructores ---
    Vivero();
    Vivero(int contP, int contM, int contC);
    
    // --- Declaraciones de Métodos ---
    void crearPlanta(string nombre, double precio, int stock);
    void crearMaceta(string nombre, string material, string color, 
                     double precio, bool esColgante);

    void registrarCliente(Cliente c);

    void mostrarInventario();
    void realizarVenta(int indiceCliente, int indicePlanta);
    void realizarVentaMaceta(int indiceCliente, int indiceMaceta);
};


/**
 * Constructor por Defecto: Inicializa el Vivero vacío.
 *
 * @param Ninguno
 * @return Objeto Vivero
 */
Vivero::Vivero() {
    cout << ">> Vivero creado (Vacio)." << endl;
    contadorPlantas = 0;
    contadorMacetas = 0;
    contadorClientes = 0;
}

/**
 * Constructor con Parámetros: Inicializa los contadores.
 *
 * @param int contP: Contador inicial de plantas.
 * @param int contM: Contador inicial de macetas.
 * @param int contC: Contador inicial de clientes.
 * @return Objeto Vivero
 */
Vivero::Vivero(int contP, int contM, int contC) {
    cout << ">> Vivero creado con contadores iniciales." << endl;
    contadorPlantas = contP;
    contadorMacetas = contM;
    contadorClientes = contC;
}

/**
 * Método para crear y agregar una Planta al inventario.
 *
 * @param string nombre: Nombre de la planta.
 * @param double precio: Precio de la planta.
 * @param int stock: Stock inicial.
 * @return void
 */
void Vivero::crearPlanta(string nombre, double precio, int stock) {
    if (contadorPlantas < MAX_INVENTARIO) {
        InventarioPlantas[contadorPlantas] = 
            Planta(nombre, precio, stock);
        contadorPlantas++;
        cout << ">> Planta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Método para crear y agregar una Maceta al inventario.
 *
 * @param string nombre: Nombre de la maceta.
 * @param string material: Material de la maceta.
 * @param string color: Color de la maceta.
 * @param double precio: Precio de la maceta.
 * @param bool esColgante: Si la maceta es colgante.
 * @return void
 */
void Vivero::crearMaceta(string nombre, string material, string color, 
                         double precio, bool esColgante) {
    if (contadorMacetas < MAX_INVENTARIO) {
        InventarioMacetas[contadorMacetas] = 
            Maceta(nombre, material, color, precio, esColgante);
        contadorMacetas++;
        cout << ">> Maceta creada y agregada exitosamente." << endl;
    } else {
        cout << "Error: Inventario lleno." << endl;
    }
}

/**
 * Método para registrar un Cliente.
 *
 * @param Cliente c: Objeto Cliente a registrar.
 * @return void
 */
void Vivero::registrarCliente(Cliente c) {
    if (contadorClientes < MAX_INVENTARIO) {
        ListaClientes[contadorClientes] = c;
        contadorClientes++;
        cout << ">> Cliente registrado exitosamente." << endl;
    } else {
        cout << "Error: Lista de clientes llena." << endl;
    }
}

/**
 * Método para mostrar el inventario completo y la lista de clientes.
 *
 * @param Ninguno
 * @return void
 */
void Vivero::mostrarInventario() {
    cout << "\n===== REPORTE VIVERO =====" << endl;
    
    cout << "--- Plantas (" << contadorPlantas << ") ---" << endl;
    for (int i = 0; i < contadorPlantas; i++) {
        cout << i << ". "; 
        InventarioPlantas[i].mostrar();
    }

    cout << "--- Macetas (" << contadorMacetas << ") ---" << endl;
    for (int i = 0; i < contadorMacetas; i++) {
        cout << i << ". ";
        InventarioMacetas[i].mostrar();
    }

    cout << "--- Clientes (" << contadorClientes << ") ---" << endl;
    for (int i = 0; i < contadorClientes; i++) {
        cout << i << ". ";
        ListaClientes[i].mostrar();
    }
    cout << "==========================" << endl;
}

/**
 * Realiza la venta de una Planta y actualiza el stock/saldo.
 *
 * @param int indiceCliente: Índice del cliente.
 * @param int indicePlanta: Índice de la planta.
 * @return void
 */
void Vivero::realizarVenta(int indiceCliente, int indicePlanta) {
    // Validación de índices...
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indicePlanta >= 0 && indicePlanta < contadorPlantas) {
        
        Cliente elCliente = ListaClientes[indiceCliente];
        Planta laPlanta = InventarioPlantas[indicePlanta];

        cout << "\nIntento de venta: " << elCliente.getNombre() << 
            " quiere " << laPlanta.getNombre() << endl;

        if (laPlanta.getStock() > 0) {
            if (elCliente.comprar(laPlanta.getPrecio())) {
                laPlanta.actualizarStock(-1); 
                cout << ">> Venta Exitosa!" << endl;

                // Guardar los objetos modificados
                ListaClientes[indiceCliente] = elCliente;
                InventarioPlantas[indicePlanta] = laPlanta;
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

/**
 * Realiza la venta de una Maceta.
 *
 * @param int indiceCliente: Índice del cliente.
 * @param int indiceMaceta: Índice de la maceta.
 * @return void
 */
void Vivero::realizarVentaMaceta(int indiceCliente, int indiceMaceta) {
    // Validación de índices...
    if (indiceCliente >= 0 && indiceCliente < contadorClientes && 
        indiceMaceta >= 0 && indiceMaceta < contadorMacetas) {
        
        Cliente elCliente = ListaClientes[indiceCliente];
        Maceta laMaceta = InventarioMacetas[indiceMaceta];

        cout << "\nIntento de venta: " << elCliente.getNombre() << 
            " quiere " << laMaceta.getNombre() << endl;

        if (elCliente.comprar(laMaceta.getPrecio())) {
            cout << ">> Venta Exitosa! Maceta eliminada del inventario." << endl;
            
            ListaClientes[indiceCliente] = elCliente;
            
            // Eliminar Maceta (Desplazamiento de elementos)
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
