#include <iostream>

using namespace std;

typedef int Item;
const Item indefinido = -9999;

typedef struct Nodo {
  Item dato;
  struct Nodo *siguiente;
} Nodo;

typedef struct {
  Nodo *frente;
  Nodo *final;
  int longitud;
} Fila;

Fila *FilaVacia() {
  Fila *nuevo = new Fila;
  nuevo->frente = nullptr;
  nuevo->final = nullptr;
  nuevo->longitud = 0;
  return nuevo;
}

bool EsFilaVacia(Fila *Fila) { return Fila->frente == nullptr; }

Item Frente(Fila *Fila) { return Fila->frente->dato; }

Nodo *CrearNodo(Item dato) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = dato;
  nuevo->siguiente = nullptr;
  return nuevo;
}

Fila *EnFila(Fila *Fila, Item dato) {
  Nodo *nuevo = CrearNodo(dato);
  if (Fila->frente == nullptr) {
    Fila->frente = nuevo;
    Fila->final = nuevo;
  } else {
    Fila->final->siguiente = nuevo;
    Fila->final = nuevo;
  }
  Fila->longitud++;
  return Fila;
}
