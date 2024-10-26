#include "arbol.h"
#include "simple_list.h"

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

//Funcion para saber si un elemento ya existe en el arbol
Arbol* CrearNodo(int n, Arbol* padre) {
  Arbol* nuevo_nodo = new Arbol();

  nuevo_nodo->dato = n;
  nuevo_nodo->derecha = nullptr;
  nuevo_nodo->izquierda = nullptr;
  nuevo_nodo->padre = padre;

  return nuevo_nodo;
}

bool Existe(Arbol* arbol, int n) {
  // Si el árbol está vacío, el número no existe
  if (arbol == nullptr) {
    return false;
  }
  // Compara con el dato de la raíz
  if (n == arbol->dato) {
    return true;  // El número ya existe
  } else if (n < arbol->dato) {
    return Existe(arbol->izquierda, n);  // Busca en el subárbol izquierdo
  } else {
    return Existe(arbol->derecha, n);  // Busca en el subárbol derecho
  }
}

//Mandar a llamar esta funcion
void InsertarNodo(Arbol*& arbol, int n) {
  if (arbol == nullptr) {
    Arbol* nuevo_nodo = CrearNodo(n, nullptr);
    arbol = nuevo_nodo;

  } else {
    if (Existe(arbol, n)) {
      std::cout << "El numero que quiere ingresar ya existe" << std::endl;
      return;  // No insertar si el número ya existe
    }

    if (n % 2 == 0) {
      Insertar(arbol->derecha, n, arbol);
    } else {
      Insertar(arbol->izquierda, n, arbol);
    }
  }
}

void Insertar(Arbol*& arbol, int n, Arbol* padre) {
  if (arbol == nullptr) {
    Arbol* nuevo_nodo = CrearNodo(n, padre);
    arbol = nuevo_nodo;

  } else {
    int valor_raiz = arbol->dato;

    if (n > valor_raiz) {
      InsertarNodo(arbol->derecha, n);
    } else {
      InsertarNodo(arbol->izquierda, n);
    }
  }
}

//Mostrar el arbol completo
void MostrarArbol(Arbol* arbol, int contador) {
  if (arbol == nullptr) {
    return;

  } else {
    MostrarArbol(arbol->derecha, contador + 1);
    for (int i = 0; i < contador; ++i) {
      std::cout << "   ";
    }
    std::cout << arbol->dato << std::endl;
    MostrarArbol(arbol->izquierda, contador + 1);
  }
}

//Funcion para buscar un elemento en el arbol
//Mandar a llamar esta funcion
bool Buscar(Arbol* arbol, int n) {
  if (arbol == nullptr) {
    return false;
  }

  // Compara el valor ingresado con el dato del nodo actual
  if (n == arbol->dato) {
    return true;
  }

  // Determina si el número es par o impar
  if (n % 2 == 0) {
    // Buscar en el subárbol derecho para pares
    return BuscarArbol(arbol->derecha, n);
  } else {
    // Buscar en el subárbol izquierdo para impares
    return BuscarArbol(arbol->izquierda, n);
  }
}

bool BuscarArbol(Arbol* arbol, int n) {
  if (arbol == nullptr) {
    return false;

  } else if (arbol->dato == n) {
    return true;

  } else if (n < arbol->dato) {
    return BuscarArbol(arbol->izquierda, n);

  } else {
    return BuscarArbol(arbol->derecha, n);
  }
}

//Funcion para mostrar el recorrido InOrder del arbol
//Mandar a llamar esta funcion
void InOrden(Arbol* arbol) {
  if (arbol == nullptr) {
    return;

  } else {
    InOrden(arbol->izquierda);

    std::cout << arbol->dato << " - ";

    InOrden(arbol->derecha);
  }
}

//Mandar a llamar esta funcion
void Eliminar(Arbol *&arbol, int n) {
  if (arbol == nullptr) {
    std::cout << "El arbol esta vacio." << std::endl;
    return;
  }

  if (arbol->dato == n) {
    //EliminarNodo(arbol);
    arbol = nullptr;
  } else {
    if (n % 2 == 0) {
      EliminarAB(arbol->derecha, n);
    } else {
      EliminarAB(arbol->izquierda, n);
    }
  }
}

void EliminarAB(Arbol *&arbol, int n) {
  if (arbol == nullptr) {
    std::cout << "El arbol esta vacio." << std::endl;
    return;
  }

  // Mostrar si es mayor o menor que la raiz
  if (n < arbol->dato) {
    EliminarAB(arbol->izquierda, n);
  } else if (n > arbol->dato) {
    EliminarAB(arbol->derecha, n);
  } else {
    arbol = nullptr;
  }
}

//Funcion para eliminar el nodo encontrado
void EliminarNodo(Arbol* nodo_eliminar) {
  if (nodo_eliminar->izquierda && nodo_eliminar->derecha) {
    Arbol* menor = EncontrarMin(nodo_eliminar->derecha);
    nodo_eliminar->dato = menor->dato;
    EliminarNodo(menor);

  } else if (nodo_eliminar->izquierda) {
    Reemplazar(nodo_eliminar, nodo_eliminar->izquierda);
    BorrarNodo(nodo_eliminar);
  } else if (nodo_eliminar->derecha) {
    Reemplazar(nodo_eliminar, nodo_eliminar->derecha);
    BorrarNodo(nodo_eliminar);
  } else {
    Reemplazar(nodo_eliminar, nullptr);
    BorrarNodo(nodo_eliminar);
  }
}

//Funcion para determinar el nodo mas izquierdo posible
Arbol* EncontrarMin(Arbol* arbol) {
  if (arbol == nullptr) {
    return nullptr;
  }

  if (arbol->izquierda) {
    return EncontrarMin(arbol->izquierda);
  } else {
    return arbol;
  }
}

//Funcion para reemplazar 2 nodos
void Reemplazar(Arbol* arbol, Arbol* nuevo_nodo) {
  if (arbol->padre) {
    if (arbol->dato == arbol->padre->izquierda->dato) {
      arbol->padre->izquierda = nuevo_nodo;
    } else if (arbol->dato == arbol->padre->derecha->dato) {
      arbol->padre->derecha = nuevo_nodo;
    }
  }

  if (nuevo_nodo) {
    nuevo_nodo->padre = arbol->padre;
  }
}

//Funcion para borrar un nodo desconectado o flotante
void BorrarNodo(Arbol* nodo) {
  nodo->izquierda = nullptr;
  nodo->derecha = nullptr;

  delete nodo;
}

bool Modificar(Arbol* nodo, int valor_viejo, int valor_nuevo) {
  // Valor no encontrado
  if (nodo == nullptr) {
    return false;
  }
  // si coiciden se modifica el valor antiguo
  if (nodo->dato == valor_viejo) {
    nodo->dato = valor_nuevo;
    return true;
  }
  // recursividad con modificar para buscar en arbol izquierda y sigguiente
  return Modificar(nodo->izquierda, valor_viejo, valor_nuevo) ||
         Modificar(nodo->derecha, valor_viejo, valor_nuevo);
}

void LiberarMemoria(Arbol* arbol) {
  if (arbol != nullptr) {
    LiberarMemoria(arbol->izquierda);
    LiberarMemoria(arbol->derecha);
    delete arbol;
  }
}