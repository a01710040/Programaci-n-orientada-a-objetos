#include <iostream>
#include "Vivero.h"

using namespace std;

int main() {
    Vivero miNegocio;

    Planta p1("Orquidea", 150.0, 5);
    Planta p2("Helecho", 80.0, 2);
    
    Maceta m1("Barro", "Arcilla", "Rojo", 40.0, false);
    
    Cliente c1("Ana", 200.0);

    miNegocio.agregarPlanta(p1);
    miNegocio.agregarPlanta(p2);
    miNegocio.agregarMaceta(m1);
    miNegocio.registrarCliente(c1);

    miNegocio.mostrarInventario();

    miNegocio.realizarVenta(0, 0);

    cout << "\n--- DESPUES DE LA VENTA ---" << endl;
    miNegocio.mostrarInventario();

    return 0;
}
