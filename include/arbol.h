#ifndef ARBOL_H_
#define ARBOL_H_

#include <iostream>

struct Arbol {
  int dato;
  Arbol* derecha = nullptr;
  Arbol* izquierda = nullptr;
  Arbol* padre = nullptr;
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
void EliminarNodo(Arbol* nodo_eliminar);
Arbol* EncontrarMin(Arbol* arbol);
void Reemplazar(Arbol* arbol, Arbol* nuevo_nodo);
void BorrarNodo(Arbol* nodo);
bool Modificar(Arbol* arbol, int valor_viejo, int valor_nuevo);
void LiberarMemoria(Arbol* arbol);

#endif