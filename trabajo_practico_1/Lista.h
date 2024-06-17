#include <iostream>
using namespace std;
typedef int Item;

typedef struct Nodo{
  Item dato; 
  struct Nodo *siguiente;
} Nodo;

Nodo *CrearLista()
{
  return nullptr;  //<- O(1)
}

bool EsListaVacia(Nodo *lista)
{
  return lista == nullptr;  //<- O(1)
}

Nodo *CrearNodo(Item d)
{
  Nodo *nuevo = new Nodo;  //<- O(1)
  nuevo->dato = d;         //<- O(1)
  nuevo->siguiente = nullptr;  //<- O(1)
  return nuevo;  //<- O(1)
}

Nodo *Insertar(Nodo **lista, Item d)
{
  Nodo *nuevo = CrearNodo(d);  //<- O(1)
  if(EsListaVacia(*lista))  //<- O(1)
  {
    *lista = nuevo;  //<- O(1)
  }
  else {       // todos O(1)
    nuevo->siguiente = *lista;  //<- O(1)
    *lista = nuevo;  //<- O(1)
  }
  return *lista;  //<- O(1)
}

void ImprimirLista(Nodo *lista)
{
  if(lista == nullptr)   // <- O(1)
  {
    cout << "Lista vacía" << endl;  //<- O(1)
    return;  //<- O(1)
  }
  Nodo *aux = lista;  //<- O(1)
  while(aux != nullptr)  //<- O(1)            O(n)
  {
    cout << aux->dato << " ";  //<- O(1)
    aux = aux->siguiente;  //<- O(1)
  }
  cout << endl;  //<- O(1)
}

Nodo *PrimerElemento(Nodo *lista) //<- O(1)
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

Nodo *Borrar(Nodo **lista) //<- O(1)
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

int Longitud(Nodo *lista) // <- O(n)
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

bool Pertenece(Nodo *lista, Item d) // <- O(n)
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

Nodo *InsertarK(Nodo **lista, Item d, int k) // <- O(n)
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

Item PosicionK(Nodo *lista, int k) // <- O(n)
{
  if(k == 0)
  {
    return PrimerElemento(lista)->dato;
  }
  else {
    Nodo *aux = lista;
    for (int i = 0; i < k-1 ; i++) {
      aux = Borrar(&aux);
    }
    if (EsListaVacia(aux))
    {
      return -9999;
    }
    else 
    {
      return aux->dato;
    }
  }
}

Item PosicionKRecursivo(Nodo *lista, int k)
{
  if (EsListaVacia(lista))
  {
    return -9999;
  }
  else 
  {
    if(k == 0)
    {
      return lista->dato;
    }
    else 
    {
      return PosicionKRecursivo(lista->siguiente, k-1);
    }
  }
}
