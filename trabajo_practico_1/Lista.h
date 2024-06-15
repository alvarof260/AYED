#include <iostream>
using namespace std;
typedef int Item;

typedef struct Nodo{
  Item dato; 
  struct Nodo *siguiente;
} Nodo;

Nodo *CrearLista()
{
  return nullptr;
}

bool EsListaVacia(Nodo *lista)
{
  return lista == nullptr;
}

Nodo *CrearNodo(Item d)
{
  Nodo *nuevo = new Nodo;
  nuevo->dato = d;
  nuevo->siguiente = nullptr;
  return nuevo;
}

Nodo *Insertar(Nodo **lista, Item d)
{
  Nodo *nuevo = CrearNodo(d);
  if(EsListaVacia(*lista))
  {
    *lista = nuevo;
  }
  else {
    nuevo->siguiente = *lista;
    *lista = nuevo;
  }
  return *lista;
}

void ImprimirLista(Nodo *lista)
{
  if(lista == nullptr)
  {
    cout << "Lista vacía" << endl;
    return;
  }
  Nodo *aux = lista;
  while(aux != nullptr)
  {
    cout << aux->dato << " ";
    aux = aux->siguiente;
  }
  cout << endl;
}
