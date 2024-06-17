#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
  Nodo  *lista = CrearLista();
  lista = Insertar(&lista, 1);
  lista = Insertar(&lista, 2);
  lista = Insertar(&lista, 3);
  ImprimirLista(lista);
  Nodo *primer = PrimerElemento(lista);
  cout << "Primer elemento: " << primer->dato << endl;
  lista = borrar(&lista);
  cout << "Longitud: " << Longitud(lista) << endl;
  lista = InsertarK(&lista, 4, 2);
  ImprimirLista(lista);
  if(Pertenece(lista, 4))
  {
    cout << "4 es perteneciente" << endl;
  }
  else
  {
    cout << "4 no es perteneciente" << endl;
  }
  return 0;
}
