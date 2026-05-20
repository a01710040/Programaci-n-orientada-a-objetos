#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    // Creamos el objeto principal
    Vivero miVivero;
    
    // Variable para la opción del menú
    int opcion = -1;

    // Variables temporales para la entrada del usuario
    string nombreTemp, materialTemp, colorTemp;
    double precioTemp, presupuestoTemp;
    int stockTemp;
    bool esColganteTemp;
    int indiceCliente, indicePlanta, indiceMaceta; // Indices para ventas

    // Precarga para tener datos de prueba
    Cliente clienteInicial("Ana Martinez", 500.0);
    miVivero.registrarCliente(clienteInicial);
    miVivero.crearPlanta("Rosa Roja", 150.0, 3);
    miVivero.crearMaceta("Barro", "Arcilla", "Cafe", 40.0, false);
    
    // Bucle principal del menú
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
        
        // Manejo de error de entrada
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Reiniciando menu." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; 
        }

        if (opcion == 1) {
            // Crear Planta
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Precio: "; cin >> precioTemp;
            cout << "Stock: "; cin >> stockTemp;
            miVivero.crearPlanta(nombreTemp, precioTemp, stockTemp);
        }
        else if (opcion == 2) {
            // Crear Maceta
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Material: "; cin >> materialTemp;
            cout << "Color: "; cin >> colorTemp;
            cout << "Precio: "; cin >> precioTemp;
            cout << "Es colgante? (1=Si, 0=No): "; cin >> esColganteTemp;
            miVivero.crearMaceta(nombreTemp, materialTemp, colorTemp, 
                                 precioTemp, esColganteTemp);
        }
        else if (opcion == 3) {
            // Registrar Cliente
            cout << "Nombre: "; cin >> nombreTemp;
            cout << "Presupuesto: "; cin >> presupuestoTemp;
            Cliente nuevoCliente(nombreTemp, presupuestoTemp);
            miVivero.registrarCliente(nuevoCliente);
        }
        else if (opcion == 4) {
            // Reporte
            miVivero.mostrarInventario();
        }
        else if (opcion == 5) {
            // Venta Planta
            miVivero.mostrarInventario();
            cout << "Indice del Cliente: "; cin >> indiceCliente;
            cout << "Indice de la Planta: "; cin >> indicePlanta;
            miVivero.realizarVenta(indiceCliente, indicePlanta);
        }
        else if (opcion == 6) {
            // Venta Maceta
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
