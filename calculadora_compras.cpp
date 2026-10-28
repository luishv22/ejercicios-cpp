// Programa de consola que organiza una lista de productos según un presupuesto disponible.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Define los datos de un producto
struct producto
{
    std::string nombre;
    double precio;
    int cantidad;
};

int main()
{
    // Lista de productos
    std::vector<producto> listaProductos = {
        {"Desodorante", 69.90, 1},
        {"Rastrillo", 10.00, 3},
        {"Queso", 160.00, 1},
        {"Crema de leche", 96.00, 1},
        {"Chocolate", 81.00, 1}
    };

    double total = 0.0;
    std::vector<producto> listCompra;
    std::vector<producto> listDesc;
    
    // Pide el presupuesto inicial
    double presu;
    std::cout << "Ingresa el presupuesto: ";
    std::cin >> presu;

    // Recorre cada producto en la lista
    for (int i = 0; i < listaProductos.size(); i++) 
    {
        // Comprueba si el producto cabe en el presupuesto restante
        double costo = listaProductos[i].precio
                * listaProductos[i].cantidad;
        if (total + costo <= presu)
        {
            total += costo;
            listCompra.push_back(listaProductos[i]);
        }
        else 
        {
            listDesc.push_back(listaProductos[i]);
        }
    }

    // Muestra la lista de productos comprados 
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Productos comprados:\n";
    for (int i = 0; i < listCompra.size(); i++)
    {
    std::cout << listCompra[i].nombre
              << " - Precio: " << listCompra[i].precio
              << " - Cantidad: " << listCompra[i].cantidad
              << "\n";
    }

    // Muestra la lista de productos descartados 
    std::cout << "Lista de descartados:\n";
    for (int i = 0; i < listDesc.size(); i++)
    {
    std::cout << listDesc[i].nombre
              << " - Precio: " << listDesc[i].precio
              << " - Cantidad: " << listDesc[i].cantidad
              << "\n";
    }

    // Muestra el resumen final de la compra
    std::cout << "Presupuesto inicial: " << presu << "\n";
    std::cout << "Total de la compra: " << total << "\n"; 
    double diferencia = presu - total;
        if (diferencia > 0)
        { 
            std::cout << "Dinero sobrante: " << diferencia << "\n";
        }
        else 
        {
            std::cout << "Utilizaste todo el presupuesto. \n";
        }
return 0;
}
