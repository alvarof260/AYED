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
  ImprimirLista(lista);
  return 0;
}
