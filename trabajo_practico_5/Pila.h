#include <iostream>

using namespace std;
typedef int Item;

const Item indefinido = -9999;

typedef struct Nodo {
  Item dato;
  struct Nodo *siguiente;
} Nodo;

typedef struct {
  Nodo *cabecera;
  int altura;
} Pila;

Pila *PilaVacia() {
  Pila *nuevo = new Pila;
  nuevo->cabecera = nullptr;
  nuevo->altura = 0;
  return nuevo;
}

bool EsPilaVacia(Pila *pila) { return pila->cabecera == nullptr; }

Item Top(Pila *pila) {
  if (EsPilaVacia(pila)) {
    return indefinido;
  } else {
    return pila->cabecera->dato;
  }
}

Pila *Pop(Pila *pila) {
  if (EsPilaVacia(pila)) {
    return pila;
  } else {
    Nodo *aux = pila->cabecera;
    pila->cabecera = pila->cabecera->siguiente;
    pila->altura--;
    delete aux;
    return pila;
  }
}

Nodo *CrearNodo(Item d) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = d;
  nuevo->siguiente = nullptr;
  return nuevo;
}

Pila *Push(Pila *pila, Item d) {
  Nodo *nuevo = CrearNodo(d);
  if (EsPilaVacia(pila)) {
    pila->cabecera = nuevo;
  } else {
    nuevo->siguiente = pila->cabecera;
    pila->cabecera = nuevo;
  }
  pila->altura++;
  return pila;
}
