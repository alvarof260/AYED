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
} ListaCircular;

ListaCircular *LCVacia() {
  ListaCircular *nuevo = new ListaCircular;
  nuevo->cabecera = nullptr;
  nuevo->altura = 0;
  return nuevo;
}

bool EsLCVacia(ListaCircular *lc) { return lc->cabecera == nullptr; }

Nodo *CrearNodo(Item d) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = d;
  nuevo->siguiente = nullptr;
  return nuevo;
}

ListaCircular *LCInsertar(ListaCircular *lc, Item d) {
  Nodo *nuevo = CrearNodo(d);
  if (EsLCVacia(lc)) {
    nuevo->siguiente = nuevo; // Apuntamos al mismo nodo para formar el ciclo
    lc->cabecera = nuevo;
  } else {
    Nodo *temp = lc->cabecera;
    while (temp->siguiente != lc->cabecera) {
      temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    nuevo->siguiente = lc->cabecera;
    lc->cabecera = nuevo;
  }
  lc->altura++;
  return lc;
}

Item LCValor(ListaCircular *lc) {
  if (EsLCVacia(lc)) {
    return indefinido;
  } else {
    return lc->cabecera->dato;
  }
}

void LCImprimir(ListaCircular *lc) {
  if (EsLCVacia(lc)) {
    return;
  }
  Nodo *aux = lc->cabecera;
  do {
    cout << aux->dato << " ";
    aux = aux->siguiente;
  } while (aux != lc->cabecera);
  cout << endl;
}

ListaCircular *LCBorrar(ListaCircular *lc) {
  if (EsLCVacia(lc)) {
    return lc;
  }
  Nodo *aux = lc->cabecera;
  if (lc->cabecera->siguiente == lc->cabecera) {
    lc->cabecera = nullptr;
  } else {
    Nodo *temp = lc->cabecera;
    while (temp->siguiente != lc->cabecera) {
      temp = temp->siguiente;
    }
    temp->siguiente = lc->cabecera->siguiente;
    lc->cabecera = lc->cabecera->siguiente;
  }
  lc->altura--;
  delete aux;
  return lc;
}

ListaCircular *LCRotar(ListaCircular *lc) {
  if (EsLCVacia(lc)) {
    return lc;
  }
  lc->cabecera = lc->cabecera->siguiente;
  return lc;
}
