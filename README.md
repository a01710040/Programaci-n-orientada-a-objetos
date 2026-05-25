# TC1030 Programación Orientada a Objetos: Sistena de Gestión de vivero

Este proyecto implementa un sistema básico de gestión de inventario y clientes para un vivero utilizando C++, desarrollado para la materia de **Pensamiento Orientado a Objetos (TC1030)**.

***

## 1. Archivos del proyecto

| Archivo | Contenido Principal |
| :--- | :--- |
| **`Vivero.h`** | Clase Gestora. Implementa Composición y Agregación. |
| **`Productos.h`** | Clases `Producto`, `Planta`, `Maceta`. Implementa Herencia. |
| **`Cliente.h`** | Clase `Cliente`. Objeto agregado por `Vivero`. |
| **`main.cpp`** | Contiene el menú de consola y la lógica de inicialización. |

---

## 2. Funcionalidad y Alcance del Sistema

### ¿Para qué sirve?

* **Administrar Inventario:** Permite dar de alta y listar el stock de **`Planta`** y **`Maceta`**.
* **Gestionar Clientes:** Permite registrar clientes y llevar un control básico de su **`PresupuestoCliente`**.
* **Simular Transacciones:** Realiza la simulación de ventas, verificando el **`StockDisponible`** y el **`PresupuestoCliente`** antes de completar la operación.

### ¿Para qué no sirve?

* **No Maneja Persistencia:** Los datos se **pierden** al cerrar la aplicación.
* **Sin Interfaz Gráfica (GUI):** Toda la interacción es a través de la **consola de comandos**.
* **Capacidad Limitada:** El tamaño de todos los inventarios y listas está limitado a **50 elementos**.

### Casos en los que no funciona

El programa incluye mensajes de error y rechaza la acción si:

* **Inventario Lleno:** Se intenta agregar más de 50 elementos.
* **Venta sin Stock:** Se intenta comprar una Planta cuyo **`StockDisponible`** es 0.
* **Venta sin Fondos:** El **`PresupuestoCliente`** es insuficiente para cubrir el **`PrecioProducto`**.
* **Índice Inválido:** El índice ingresado para una venta no existe en la lista.

---

## 3. Diagrama de clases

* **Herencia:** Las clases **`Planta`** y **`Maceta`** heredan las propiedades básicas (`NombreProducto`, `PrecioProducto`) de la clase base **`Producto`**.
* **Composición / Agregación:** La clase **`Vivero`** actúa como la clase gestora central, **conteniendo** los arreglos fijos de **`Planta`** (Composición) y **`Cliente`** (Agregación) para realizar todas las operaciones de negocio.
* **Encapsulamiento:** Se utilizan atributos privados (`private`) o protegidos (`protected`) y métodos públicos (`Getters`/`Setters`) para controlar el acceso y la modificación de datos.

 [Diagrama de clases](./diagramadeClases.png)
---

## 4. Compilación y Ejecución

Para compilar y ejecutar el programa desde la terminal, siga estos pasos:

1.  **Compilación:** Ejecute el siguiente comando para generar el ejecutable `gestor_vivero`:
    ```bash
    g++ main.cpp -o gestor_vivero
    ```
2.  **Ejecución:** Ejecute el siguiente comando:
    ```bash
    ./gestor_vivero
    ```
---
