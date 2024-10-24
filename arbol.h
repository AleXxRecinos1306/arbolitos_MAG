#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

// se crea la estructura
struct Arbol {
  int dato;
  Arbol *izquierda = nullptr;
  Arbol *derecha = nullptr;

  // con ayuda del constructor se crea un nuevo arbol
  Arbol(int valor) : dato(valor) {}
};

void Insertar(Arbol *&arbol, int n) {
  // No existe nada
  if (arbol == nullptr) {
    arbol = new Arbol(n);
    // Si existe
  } else {
    // Si el valor es par
    if (n % 2 == 0) {
      Insertar(arbol->derecha, n);
      // Si es mayor se inserta a la derecha
    } else {
      Insertar(arbol->izquierda, n);
    }
  }
}

bool Buscar(Arbol *arbol, int n) {
  if (arbol == nullptr) {
    return false;
  } else if (arbol->dato == n) {
    return true;
  } else if (n < arbol->dato) {
    return Buscar(arbol->izquierda, n);
  } else {
    return Buscar(arbol->derecha, n);
  }
}

bool Modificar(Arbol *arbol, int valorAntiguo, int valorNuevo) {
  // Valor no encontrado
  if (arbol == nullptr) {
    return false;
  }
  // si coiciden se modifica el valor antiguo
  if (arbol->dato == valorAntiguo) {
    arbol->dato = valorNuevo;
    return true;
  }
  // recursividad con modificar para buscar en arbol anterior y siguiente
  return Modificar(arbol->izquierda, valorAntiguo, valorNuevo) ||
         Modificar(arbol->derecha, valorAntiguo, valorNuevo);
}

#endif