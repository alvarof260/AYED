#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
  cout << "Hola Mundo" << endl;
  Nodo  *lista = CrearLista();
  lista = Insertar(&lista, 1);
  lista = Insertar(&lista, 2);
  lista = Insertar(&lista, 3);
  ImprimirLista(lista);
  return 0;
}
