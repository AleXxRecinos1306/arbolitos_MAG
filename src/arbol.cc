#include "arbol.h"
#include "simple_list.h"

Arbol* CrearNodo(int n, Arbol* padre) {
  Arbol* nuevo_nodo = new Arbol();

  nuevo_nodo->dato = n;
  nuevo_nodo->derecha = nullptr;
  nuevo_nodo->izquierda = nullptr;
  nuevo_nodo->padre = padre;

  return nuevo_nodo;
}

//Funcion para saber si un elemento ya existe en el arbol
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
Arbol* Buscar(Arbol* arbol, int n) {
  if (arbol == nullptr) {
    return nullptr;
  }

  // Compara el valor ingresado con el dato del nodo actual
  if (n == arbol->dato) {
    return arbol;
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

Arbol* BuscarArbol(Arbol* arbol, int n) {
  if (arbol == nullptr) {
    return nullptr;

  } else if (arbol->dato == n) {
    return arbol;

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
    Arbol *new_arbol = nullptr;
    ReInsertar(new_arbol, arbol->izquierda);
    ReInsertar(new_arbol, arbol->derecha);
    delete arbol;
    arbol = new_arbol;
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
    Arbol *raiz = arbol;
    arbol = nullptr;
    ReInsertar(raiz->padre, raiz->izquierda);
    ReInsertar(raiz->padre, raiz->derecha);
    delete raiz;
  }
}

void ReInsertar(Arbol *&raiz, Arbol *&sub_arbol) {
  if (sub_arbol == nullptr) {
    return;
  }
  InsertarNodo(raiz,sub_arbol->dato);
  ReInsertar(raiz, sub_arbol->izquierda);
  ReInsertar(raiz, sub_arbol->derecha);
}

bool Modificar(Arbol* nodo, int valor_nuevo) {
  // ambos pares o impares
  if ((nodo->dato % 2 == 0 && valor_nuevo % 2 == 0) ||
      (nodo->dato % 2 != 0 && valor_nuevo % 2 != 0)) {
    // matiene la concistencia de mayor menor
    if ((nodo->derecha == nullptr || valor_nuevo < nodo->derecha->dato) &&
        (nodo->izquierda == nullptr || valor_nuevo > nodo->izquierda->dato)) {
      nodo->dato = valor_nuevo;
      return true;
    } else {
      std::cout << "El valor nuevo no cumple con los requisitos de mayor "
                   "o menor" << std::endl;
    }
  } else {
    std::cout << "El valor nuevo no cumple con los requisitos de par o impar" << std::endl;
  }
  return false;
}

void LiberarMemoria(Arbol* arbol) {
  if (arbol != nullptr) {
    LiberarMemoria(arbol->izquierda);
    LiberarMemoria(arbol->derecha);
    delete arbol;
  }
}