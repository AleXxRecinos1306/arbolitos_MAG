#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

struct Arbol {
  int dato;
  Arbol* derecha;
  Arbol* izquierda;
  Arbol* padre;
};
    
void Menu();
Arbol* CrearNodo(int n, Arbol* padre);
bool Existe(Arbol* arbol, int n);
void InsertarNodo(Arbol*& arbol, int n);
void Insertar(Arbol*& arbol, int n, Arbol* padre);
void MostrarArbol(Arbol* arbol, int contador);
bool Buscar(Arbol* arbol, int n);
bool BuscarArbol(Arbol* arbol, int n);
void InOrden(Arbol* arbol);
void Eliminar(Arbol *&arbol, int n);
void EliminarAB(Arbol *&arbol, int n);
bool Modificar(Arbol* arbol, int valor_viejo, int valor_nuevo);
void LiberarMemoria(Arbol* arbol);
void ReInsertar(Arbol *&raiz, Arbol *&sub_arbol);

#endif