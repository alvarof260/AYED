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
  delete aux;
  return cochera;
}

void Mostsrar(Cochera *cochera) {
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
