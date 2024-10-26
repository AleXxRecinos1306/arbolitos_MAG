#ifndef SIMPLE_LIST_H_
#define SIMPLE_LIST_H_

#include <iostream>

// Estructura para un nodo en la lista.
template <typename T>
struct Node {
  T data;
  Node<T>* next;
};

// Función para crear un nuevo nodo con el valor de 'data'.
template <typename T>
Node<T>* CreateNode(T data) {
  Node<T>* new_node = new Node<T>();
  new_node->data = data;
  new_node->next = nullptr;
  return new_node;
}

// Función para agregar un nodo al frente de la lista.
template <typename T>
void AddFront(Node<T>** head, T data) {
  Node<T>* new_node = CreateNode(data);
  new_node->next = *head;
  *head = new_node;
}

// Función para agregar un nodo al final de la lista.
template <typename T>
void AddBack(Node<T>** head, T data) {
  Node<T>* new_node = CreateNode(data);
  if (IsEmpty(*head)) {
    *head = new_node;
  } else {
    Node<T>* temp = *head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

// Función para eliminar el primer nodo de la lista.
template <typename T>
void RemoveFront(Node<T>** head) {
  if (!IsEmpty(*head)) {
    Node<T>* temp = *head;
    *head = (*head)->next;
    delete temp;
  }
}

// Función para verificar si la lista está vacía.
template <typename T>
bool IsEmpty(Node<T>* head) {
  return head == nullptr;
}

// Función para imprimir los elementos de la lista.
template <typename T>
void PrintList(Node<T>* head) {
  Node<T>* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " -> " << std::endl; ;
    temp = temp->next;
  }
  std::cout << "null" << std::endl;
}

// Función para eliminar todos los nodos en la lista.
template <typename T>
void DeleteList(Node<T>** head) {
  while (!IsEmpty(*head)) {
    RemoveFront(head);
  }
}

#endif  // SIMPLE_LIST_H_