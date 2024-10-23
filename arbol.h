#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

//se crea la estructura
struct Arbol {
    int dato;
    Arbol *anterior=nullptr;
    Arbol *siguiente=nullptr;

    //con ayuda del constructor se crea un nuevo arbol
    Arbol(int valor) : dato(valor) {}
};

bool Modificar(Arbol* nodo, int valorAntiguo, int valorNuevo) {
    // Valor no encontrado
    if (nodo == nullptr) {
        return false; 
    }
    // si coiciden se modifica el valor antiguo
    if (nodo->dato == valorAntiguo) {
        nodo->dato = valorNuevo; 
        return true;
    }
    // recursividad con modificar para buscar en arbol anterior y sigguiente
    return Modificar(nodo->anterior, valorAntiguo, valorNuevo) || Modificar(nodo->siguiente, valorAntiguo, valorNuevo);
}


#endif