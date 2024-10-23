#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

struct arbol {
    int dato;
    arbol *anterior=nullptr;
    arbol *siguiente=nullptr;
};
    
void Editar(struct &arbol);


#endif