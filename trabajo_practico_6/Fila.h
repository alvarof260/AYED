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

void Mostrar(Fila *Fila) {
  if (Fila->frente == nullptr) {
    return;
  }
  Nodo *aux = Fila->frente;
  while (aux) {
    cout << aux->dato << " ";
    aux = aux->siguiente;
  }
  cout << endl;
}

int Longitud(Fila *Fila) { return Fila->longitud; }

Fila *DeFila(Fila *Fila) {
  if (Fila->frente == nullptr) {
    return Fila;
  }
  Nodo *aux = Fila->frente;
  Fila->frente = Fila->frente->siguiente;
  Fila->longitud--;
  delete aux;
  return Fila;
}

bool Pertenece(Fila *Fila, Item dato) {
  if (Fila->frente == nullptr) {
    return false;
  }
  Nodo *aux = Fila->frente;
  while (aux != nullptr) {
    if (aux->dato == dato) {
      return true;
    }
    aux = aux->siguiente;
  }
  return false;
}

Fila *MezclarRecursiva(Fila *l1, Fila *l2, Fila *fAux) {
  if (EsFilaVacia(l1) && EsFilaVacia(l2)) {
    return fAux;
  } else {
    if (EsFilaVacia(l1)) {
      fAux = EnFila(fAux, Frente(l2));
      l2 = DeFila(l2);
    } else {
      if (EsFilaVacia(l2)) {
        fAux = EnFila(fAux, Frente(l1));
        l1 = DeFila(l1);
      } else {
        if (l1->frente->dato <= l2->frente->dato) {
          fAux = EnFila(fAux, Frente(l1));
          l1 = DeFila(l1);
        } else {
          fAux = EnFila(fAux, Frente(l2));
          l2 = DeFila(l2);
        }
      }
    }
    return MezclarRecursiva(l1, l2, fAux);
  }
}

Fila *Mezclar(Fila *l1, Fila *l2) {
  Fila *fAux = FilaVacia();
  fAux = MezclarRecursiva(l1, l2, fAux);
  return fAux;
}
