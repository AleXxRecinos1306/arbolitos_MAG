#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

//se crea la estructura
struct Arbol {
    int dato;
    Arbol *izquierda=nullptr;
    Arbol *derecha=nullptr;

    //con ayuda del constructor se crea un nuevo arbol
    Arbol(int valor) : dato(valor) {}
};

bool Modificar(Arbol* arbol, int valorAntiguo, int valorNuevo) {
    // Valor no encontrado
    if (arbol == nullptr) {
        return false; 
    }
    // si coiciden se modifica el valor antiguo
    if (arbol->dato == valorAntiguo) {
        arbol->dato = valorNuevo; 
        return true;
    }
    // recursividad con modificar para buscar en arbol anterior y sigguiente
    return Modificar(arbol->izquierda, valorAntiguo, valorNuevo) || Modificar(arbol->derecha, valorAntiguo, valorNuevo);
}


#endif