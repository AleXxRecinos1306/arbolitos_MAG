#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

// se crea la estructura
struct Arbol {
  int dato;
  Arbol* derecha = nullptr;
  Arbol* izquierda = nullptr;
  Arbol* padre = nullptr;

  // con ayuda del constructor se crea un nuevo arbol
  Arbol(int valor) : dato(valor) {}
};

bool Modificar(Arbol* nodo, int valor_antiguo, int valor_nuevo) {
  // Valor no encontrado
  if (nodo == nullptr) {
    return false;
  }
  // si coiciden se modifica el valor antiguo
  if (nodo->dato == valor_antiguo) {
    nodo->dato = valor_nuevo;
    return true;
  }
  // recursividad con modificar para buscar en arbol izquierda y sigguiente
  return Modificar(nodo->izquierda, valor_antiguo, valor_nuevo) ||
         Modificar(nodo->derecha, valor_antiguo, valor_nuevo);
}

// ¡SOLO MANDAR A LLAMAR ESTA FUNCION AL MOMENTO DE USARLA!
// Funcion para eliminar un nodo del arbol
void Eliminar(Arbol* arbol, int entero) {
  if (arbol == nullptr) {
    std::cout << "El arbol esta vacio." << std::endl;
    return;
  }

  // Mostrar si es mayor o menor que la raiz
  if (entero < arbol->dato) {
    Eliminar(arbol->izquierda, entero);
  } else if (entero > arbol->dato) {
    Eliminar(arbol->derecha, entero);
  } else {
    // Nodo encontrado
    EliminarNodo(arbol);
  }
}

// Funcion para determinar el nodo mas izquierdo posible
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

// Funcion para reemplazar 2 nodos
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

// Funcion para eliminar el nodo encontrado
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

// Funcion para borrar un nodo flotante o desconectado
void BorrarNodo(Arbol* nodo) {
  nodo->izquierda = nullptr;
  nodo->derecha = nullptr;

  delete nodo;
}

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

// Funcion para mostrar el recorrido InOrder del arbol
void InOrder(Arbol* arbol) {
  if (arbol == nullptr) {
    return;

  } else {
    InOrder(arbol->izquierda);

    std::cout << arbol->dato << " - ";

    InOrder(arbol->derecha);
  }
}

void LiberarMemoria(Arbol* arbol) {
  if (arbol != nullptr) {
    LiberarMemoria(arbol->izquierda);
    LiberarMemoria(arbol->derecha);
    delete arbol;
  }
}

#endif