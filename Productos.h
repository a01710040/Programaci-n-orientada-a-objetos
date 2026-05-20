#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include <iostream>
#include <string>

using namespace std;

/*
 * Clase Producto: Clase base que contiene los atributos genéricos 
 * de todo artículo vendible en el vivero. 
 */
class Producto {
protected:
    // Atributos protegidos
    string nombreProducto;
    double precioProducto;

public:
    // --- Declaraciones de Constructores ---
    Producto();
    Producto(string nombreIn, double precioIn);

    // --- Declaraciones de Métodos ---
    string getNombre() const;
    double getPrecio() const;
    void setPrecio(double nuevoPrecio);
};

/*
 * Clase Planta: Clase hija de Producto.
 */
class Planta : public Producto {
private:
    int stockDisponible;

public:
    // --- Declaraciones de Constructores ---
    Planta();
    Planta(string nombreIn, double precioIn, int stockIn);

    // --- Declaraciones de Métodos ---
    int getStock() const;
    void actualizarStock(int cantidad);
    void mostrar();
};

/*
 * Clase Maceta: Clase hija de Producto.
 */
class Maceta : public Producto {
private:
    string materialMaceta;
    string colorMaceta;
    bool esColgante;

public:
    // --- Declaraciones de Constructores ---
    Maceta();
    Maceta(string nombreIn, string materialIn, string colorIn, 
           double precioIn, bool colganteIn);

    // --- Declaraciones de Métodos ---
    void mostrar();
};

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE PRODUCTO
// ============================================================================

/**
 * Constructor por defecto de la clase Producto.
 *
 * @param Ninguno
 * @return Objeto Producto inicializado
 */
Producto::Producto() {
    nombreProducto = "Sin Nombre";
    precioProducto = 0.0;
}

/**
 * Constructor con parámetros de la clase Producto.
 *
 * @param string nombreIn: Nombre del producto.
 * @param double precioIn: Precio del producto.
 * @return Objeto Producto inicializado
 */
Producto::Producto(string nombreIn, double precioIn) {
    nombreProducto = nombreIn;
    precioProducto = precioIn;
}

/**
 * Método getter para obtener el nombre del producto.
 *
 * @param Ninguno
 * @return string: El nombre almacenado del producto.
 */
string Producto::getNombre() const {
    return nombreProducto;
}

/**
 * Método getter para obtener el precio del producto.
 *
 * @param Ninguno
 * @return double: El precio almacenado del producto.
 */
double Producto::getPrecio() const {
    return precioProducto;
}

/**
 * Método setter para actualizar el precio del producto.
 *
 * @param double nuevoPrecio: El nuevo valor a asignar.
 * @return void
 */
void Producto::setPrecio(double nuevoPrecio) {
    if (nuevoPrecio >= 0) {
        precioProducto = nuevoPrecio;
    }
}

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE PLANTA
// ============================================================================

/**
 * Constructor por defecto de Planta.
 *
 * @param Ninguno
 * @return Objeto Planta inicializado con stock 0
 */
Planta::Planta() : Producto() {
    stockDisponible = 0;
}

/**
 * Constructor con parámetros de Planta.
 *
 * @param string nombreIn: Nombre de la planta.
 * @param double precioIn: Precio de la planta.
 * @param int stockIn: Cantidad inicial en inventario.
 * @return Objeto Planta inicializado
 */
Planta::Planta(string nombreIn, double precioIn, int stockIn) 
    : Producto(nombreIn, precioIn) {
    stockDisponible = stockIn;
}

/**
 * Método getter para obtener el stock disponible.
 *
 * @param Ninguno
 * @return int: Cantidad de plantas en stock.
 */
int Planta::getStock() const { 
    return stockDisponible; 
}

/**
 * Método para actualizar la cantidad de stock disponible.
 *
 * @param int cantidad: Valor a sumar o restar.
 * @return void
 */
void Planta::actualizarStock(int cantidad) {
    if (stockDisponible + cantidad >= 0) {
        stockDisponible = stockDisponible + cantidad;
    } else {
        cout << "ERROR: No hay suficiente stock." << endl;
    }
}

/**
 * Muestra en consola los detalles de la Planta.
 *
 * @param Ninguno
 * @return void
 */
void Planta::mostrar() {
    cout << "Planta: " << nombreProducto << " | Precio: $" << 
        precioProducto << " | Stock: " << stockDisponible << endl;
}

// ============================================================================
// IMPLEMENTACIÓN DE LA CLASE MACETA
// ============================================================================

/**
 * Constructor por defecto de Maceta.
 *
 * @param Ninguno
 * @return Objeto Maceta inicializado con valores N/A
 */
Maceta::Maceta() : Producto() {
    materialMaceta = "N/A";
    colorMaceta = "N/A";
    esColgante = false;
}

/**
 * Constructor con parámetros de Maceta.
 *
 * @param string nombreIn: Nombre de la maceta.
 * @param string materialIn: Material de fabricación.
 * @param string colorIn: Color de la maceta.
 * @param double precioIn: Precio de venta.
 * @param bool colganteIn: True si es colgante, False si es de piso.
 * @return Objeto Maceta inicializado
 */
Maceta::Maceta(string nombreIn, string materialIn, string colorIn, 
               double precioIn, bool colganteIn) 
    : Producto(nombreIn, precioIn) {
    materialMaceta = materialIn;
    colorMaceta = colorIn;
    esColgante = colganteIn;
}

/**
 * Muestra en consola los detalles de la Maceta.
 *
 * @param Ninguno
 * @return void
 */
void Maceta::mostrar() {
    string tipo = esColgante ? "Si" : "No";
    cout << "Maceta: " << nombreProducto << " | Mat: " << materialMaceta << 
        " | Colgante: " << tipo << " | Precio: $" << precioProducto << endl;
}

#endif // PRODUCTOS_H_
