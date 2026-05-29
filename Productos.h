#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include <iostream>
#include <string>

using namespace std;

class Producto {
protected:
    string nombreProducto;
    double precioProducto;

public:
    Producto();
    Producto(string nombreIn, double precioIn);

    string getNombre() const;
    double getPrecio() const;
    void setPrecio(double nuevoPrecio);
    
    virtual void mostrar();
};

class Planta : public Producto {
private:
    int stockDisponible;

public:
    Planta();
    Planta(string nombreIn, double precioIn, int stockIn);

    int getStock() const;
    void actualizarStock(int cantidad);
    
    void mostrar();
};

class Maceta : public Producto {
private:
    string materialMaceta;
    string colorMaceta;
    bool esColgante;

public:
    Maceta();
    Maceta(string nombreIn, string materialIn, string colorIn, double precioIn, bool colganteIn);

    void mostrar();
};


Producto::Producto() {
    nombreProducto = "Sin Nombre";
    precioProducto = 0.0;
}

Producto::Producto(string nombreIn, double precioIn) {
    nombreProducto = nombreIn;
    precioProducto = precioIn;
}

string Producto::getNombre() const { return nombreProducto; }
double Producto::getPrecio() const { return precioProducto; }
void Producto::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) precioProducto = nuevoPrecio;
}

void Producto::mostrar() {
    cout << "Producto Base: " << nombreProducto << " | Precio: $" << precioProducto << endl;
}

Planta::Planta() : Producto() {
    stockDisponible = 0;
}

Planta::Planta(string nombreIn, double precioIn, int stockIn) : Producto(nombreIn, precioIn) {
    stockDisponible = stockIn;
}

int Planta::getStock() const { return stockDisponible; }

void Planta::actualizarStock(int cantidad) {
    if (stockDisponible + cantidad >= 0) {
        stockDisponible = stockDisponible + cantidad;
    } else {
        cout << "ERROR: No hay suficiente stock." << endl;
    }
}

void Planta::mostrar() {
    cout << "Planta: " << nombreProducto << " | Precio: $" << 
        precioProducto << " | Stock: " << stockDisponible << endl;
}

Maceta::Maceta() : Producto() {
    materialMaceta = "N/A";
    colorMaceta = "N/A";
    esColgante = false;
}

Maceta::Maceta(string nombreIn, string materialIn, string colorIn, double precioIn, bool colganteIn) 
    : Producto(nombreIn, precioIn) {
    materialMaceta = materialIn;
    colorMaceta = colorIn;
    esColgante = colganteIn;
}

void Maceta::mostrar() {
    string tipo = esColgante ? "Si" : "No";
    cout << "Maceta: " << nombreProducto << " | Mat: " << materialMaceta << 
        " | Colgante: " << tipo << " | Precio: $" << precioProducto << endl;
}

#endif // PRODUCTOS_H_
