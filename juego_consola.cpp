// Juego de movimiento en consola
// Un pequeño programa en C++ que dibuja un escenario rectangular 
// y permite mover un personaje usando el teclado.

#include <iostream>

int main()
{
    int filas = 5;     // altura del escenario (filas)
    int columnas = 10; // ancho del escenario (columnas)
    int posX = 4;      // posición horizontal del personaje
    int posY = 3;      // posición vertical del personaje

    // mantiene el juego en ejecución hasta que el ususario decida salir
    while (true)
    {
        // dibuja el escenario fila por fila y columna por columna
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                // comprueba si la posición actual corresponde a la del personaje
                if (j == posX && i == posY)
                {
                    std::cout << "@";
                }
                else if (i == 0 || i == filas - 1 ||
                         j == 0 || j == columnas - 1)
                {
                    std::cout << "#";
                }
                else
                {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }

        // muestra las teclas para mover al personaje y salir
        std::cout << "w(arriba), s(abajo), a(izquierda), d(derecha) o q(salir) \n";
        char tecla;
        std::cin >> tecla;

        // actualiza la posición del personaje según la tecla introducida
        if (tecla == 'w')
        {
            if (!(posY==1)) // verifica que el personaje no atraviese la pared
            {
                posY--; // resta una fila entonces sube al personaje
            }
        }
        else if (tecla == 's')
        {
            if (!(posY==filas-2)) // verifica que el personaje no atraviese la pared
            {
                posY++; // suma una fila entonces baja el personaje
            }
        }
        else if (tecla == 'a')
        {
            if (!(posX==1)) // verifica que el personaje no atraviese la pared
            {
                posX--; // resta una columna entonces mueve a la izquierda el personaje
            }
        }
        else if (tecla == 'd')
        {
            if (!(posX==columnas-2)) // verifica que el personaje no atraviese la pared
            {
                posX++; // suma una columna entonces mueve a la derecha al personaje
            }
        }
        else if (tecla == 'q')
        {
            std::cout << "Cerrando juego. . .";
            break; // cierra el programa
        }
    }
    return 0;
}
