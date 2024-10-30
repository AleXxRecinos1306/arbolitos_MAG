//g++ -std=c++17 -Wall -I include .\src\*.cc -o main
#include "arbol.h"
#include "simple_list.h"

void Menu();

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
        if (Buscar(arbol, dato) != nullptr) {
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

      case 6: {
        std::cout << "Ingrese un valor existente en el Arbol para modificarlo: ";
        std::cin >> valor_viejo;
        Arbol* nodo = Buscar(arbol, valor_viejo);
        if (nodo == nullptr) {
          std::cout << "El nodo no existe";
          break;
        }
        std::cout << "Ingrese un nuevo valor: ";
        std::cin >> valor_nuevo;
        Modificar(nodo, valor_nuevo);
      } break;

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

void Menu() {
  std::cout << std::endl;
  std::cout << "Menu:" << std::endl;
  std::cout << "1. Insertar un valor." << std::endl;
  std::cout << "2. Mostrar Arbol." << std::endl;
  std::cout << "3. Buscar un elemento en el Arbol." << std::endl;
  std::cout << "4. Recorrer el arbol InOrden." << std::endl;
  std::cout << "5. Eliminar un nodo." << std::endl;
  std::cout << "6. Modificar un nodo." << std::endl;
  std::cout << "7. Salir." << std::endl;
  std::cout << "Ingrese la opcion que desea realizar: ";
}