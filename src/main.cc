//g++ -std=c++17 -Wall -I include .\src\*.cc -o main
#include "arbol.h"
#include "simple_list.h"

int main(int argc, char* argv[]) {
  Arbol* arbol = nullptr;
  int opcion, dato, valor_nuevo, valor_viejo;
  int contador = 0;

  do {
    Menu();
    std::cin >> opcion;
    std::cout << std::endl;

    switch (opcion) {
      case 1:
        std::cout << "Ingrese un valor: ";
        std::cin >> dato;
        InsertarNodo(arbol, dato);
        break;
      case 2:
        std::cout << "Mostrando Arbol." << std::endl;
        std::cout << std::endl;
        MostrarArbol(arbol, contador);
        std::cout << std::endl;
        break;
      case 3:
        std::cout << "Ingrese el elemento a buscar: ";
        std::cin >> dato;
        if (Buscar(arbol, dato) == true) {
          std::cout << "Elemento " << dato << " encontrado en el Arbol"
                    << std::endl;
        } else {
          std::cout << "Elemento no encontrado" << std::endl;
        }
        std::cout << std::endl;
        break;

      case 4:
        std::cout << "Recorriendo el Arbol en InOrden: ";
        InOrden(arbol);
        std::cout << std::endl;
        break;

      case 5:
        std::cout << "Ingrese un valor a eliminar: ";
        std::cin >> dato;
        Eliminar(arbol, dato);
        std::cout << std::endl;
        break;

      case 6:
        std::cout
            << "Ingrese un valor existente en el Arbol para modificarlo: ";
        std::cin >> valor_viejo;
        std::cout << "Ingrese un nuevo valor: ";
        std::cin >> valor_nuevo;
        Modificar(arbol, valor_viejo, valor_nuevo);
        std::cout << "Arbol despues de cambiar " << valor_viejo << " por "
                  << valor_nuevo << ":" << std::endl;
        InOrden(arbol);
        break;

      case 7:
        LiberarMemoria(arbol);
        std::cout << "Saliendo." << std::endl;
        system("pause");
        break;

      default:
        std::cout << "Opcion no valida." << std::endl;
        break;
    }
  } while (opcion != 7);

  return 0;
}
