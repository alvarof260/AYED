#include <iostream>
using namespace std;
typedef int Auto;

typedef struct Nodo {
  Auto dato;
  struct Nodo *siguiente;
} Nodo;

typedef struct Cochera {
  int max;
  Nodo *autos;
  int libres;
} Cochera;

Cochera *CocheraVacia(int max) {
  Cochera *nuevo = new Cochera;
  nuevo->max = max;
  nuevo->autos = nullptr;
  nuevo->libres = max;
  return nuevo;
}

Nodo *CrearNodo(Auto d) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = d;
  nuevo->siguiente = nullptr;
  return nuevo;
}

Cochera *Estacionar(Cochera *cochera, Auto a) {
  if (cochera->libres == 0) {
    return nullptr;
  } else {
    Nodo *nuevo = CrearNodo(a);
    cochera->libres--;
    if (cochera->autos == nullptr) {
      cochera->autos = nuevo;
    } else {
      nuevo->siguiente = cochera->autos;
      cochera->autos = nuevo;
    }
    return cochera;
  }
}

Cochera *QuitarUltimo(Cochera *cochera) {
  if (cochera->autos == nullptr) {
    return cochera;
  }
  Nodo *aux = cochera->autos;
  cochera->autos = cochera->autos->siguiente;
  cochera->libres++;
  delete aux;
  return cochera;
}

Cochera *Salir(Cochera *cochera, Auto a) {
  if (cochera->autos == nullptr) {
    return cochera;
  }

  Nodo *aux = cochera->autos;
  while (aux->siguiente != nullptr) {
    if (aux->siguiente->dato == a) {
      aux->siguiente = aux->siguiente->siguiente;
      cochera->libres++;
      return cochera;
    }
    aux = aux->siguiente;
  }
  return cochera;
}

bool EstaVacio(Cochera *cochera) { return cochera->autos == nullptr; }

int Capacidad(Cochera *cochera) { return cochera->max; }

int libres(Cochera *cochera) { return cochera->libres; }

bool Estacionado(Cochera *cochera, Auto a) {
  if (cochera->autos == nullptr) {
    return false;
  }
  Nodo *aux = cochera->autos;
  while (aux != nullptr) {
    if (aux->dato == a) {
      return true;
    }
    aux = aux->siguiente;
  }
  return false;
}

void Mostrar(Cochera *cochera) {
  if (cochera->autos == nullptr) {
    return;
  }
  Nodo *aux = cochera->autos;
  while (aux) {
    cout << aux->dato << " ";
    aux = aux->siguiente;
  }
  cout << endl;
}
