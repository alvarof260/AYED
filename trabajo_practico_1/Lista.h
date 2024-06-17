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

Nodo *PrimerElemento(Nodo *lista)
{
  if(EsListaVacia(lista))
  {
    return nullptr;
  }
  else 
  {
    return lista;
  }
}

Nodo *borrar(Nodo **lista)
{
  if(EsListaVacia(*lista))
  {
    return nullptr;
  }

  Nodo *aux = *lista;
  *lista = (*lista)->siguiente;
  delete aux;
  return *lista;
}

int Longitud(Nodo *lista)
{
  if(EsListaVacia(lista))
  {
    return 0;
  }
  else
  {
    return 1 + Longitud(lista->siguiente);
  }
}

bool Pertenece(Nodo *lista, Item d)
{
  if(EsListaVacia(lista))
  {
    return false;
  }
  else 
  {
    if(lista->dato == d)
    {
      return true;
    }
    else 
    {
      return Pertenece(lista->siguiente, d);
    }
  }
}

Nodo *InsertarK(Nodo **lista, Item d, int k)
{
  // insertar en la posicion k
  Nodo *nuevo = CrearNodo(d);
  if(k == 0)
  {
    nuevo->siguiente = *lista;
    *lista = nuevo;
  }
  else
  {
    Nodo *aux = *lista;
    for(int i = 0; i < k - 1; i++)
    {
      aux = aux->siguiente;
    }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
  }
  return *lista;
}
