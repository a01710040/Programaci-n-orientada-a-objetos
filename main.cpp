#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    Vivero miVivero;
    
    int opcion = -1;

    string nombreTemp, materialTemp, colorTemp;
    double precioTemp, presupuestoTemp;
    int stockTemp;
    bool esColganteTemp;
    int indiceCliente, indicePlanta, indiceMaceta;

    Cliente* clienteInicial = new Cliente("Ana Martinez", 500.0);
    miVivero.registrarCliente(clienteInicial);
    
    miVivero.crearPlanta("Rosa Roja", 150.0, 3);
    miVivero.crearMaceta("Barro", "Arcilla", "Cafe", 40.0, false);
    
    while (opcion != 0) {
        cout << "\n=== MENU PRINCIPAL VIVERO ===" << endl;
        cout << "1. Crear nueva Planta" << endl;
        cout << "2. Crear nueva Maceta" << endl;
        cout << "3. Registrar Cliente" << endl;
        cout << "4. Mostrar Reporte" << endl;
        cout << "5. Realizar Venta Planta" << endl;
        cout << "6. Realizar Venta Maceta" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Reiniciando menu." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }

        if (opcion == 1) {
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Precio: "; cin >> precioTemp;
            cout << "Stock: "; cin >> stockTemp;
            miVivero.crearPlanta(nombreTemp, precioTemp, stockTemp);
        }
        else if (opcion == 2) {
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Material: "; cin >> materialTemp;
            cout << "Color: "; cin >> colorTemp;
            cout << "Precio: "; cin >> precioTemp;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> esColganteTemp;
            miVivero.crearMaceta(nombreTemp, materialTemp, colorTemp, 
                                 precioTemp, esColganteTemp);
        }
        else if (opcion == 3) {
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Presupuesto: "; cin >> presupuestoTemp;
            // Almacenamos el cliente en Heap
            Cliente* nuevoCliente = new Cliente(nombreTemp, presupuestoTemp);
            miVivero.registrarCliente(nuevoCliente);
        }
        else if (opcion == 4) {
            miVivero.mostrarInventario();
        }
        else if (opcion == 5) {
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> indiceCliente;
            cout << "Indice de la Planta: "; cin >> indicePlanta;
            miVivero.realizarVenta(indiceCliente, indicePlanta);
        }
        else if (opcion == 6) {
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> indiceCliente;
            cout << "Indice de la Maceta: "; cin >> indiceMaceta;
            miVivero.realizarVentaMaceta(indiceCliente, indiceMaceta);
        }
        else if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        }
        else {
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } 

    return 0;
}
