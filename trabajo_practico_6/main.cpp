#include "Fila.h"
#include <iostream>

using namespace std;

int main() {
  Fila *fila = FilaVacia();
  if (EsFilaVacia(fila)) {
    cout << "Fila vacía" << endl;
  }

  fila = EnFila(fila, 10);
  fila = EnFila(fila, 20);
  fila = EnFila(fila, 30);
  fila = EnFila(fila, 40);
  fila = EnFila(fila, 50);
  fila = EnFila(fila, 60);
  fila = EnFila(fila, 70);
  fila = EnFila(fila, 80);
  fila = EnFila(fila, 90);
  fila = EnFila(fila, 100);
  Nodo *aux = fila->frente;
  while (aux) {
    cout << aux->dato << endl;
    aux = aux->siguiente;
  }
  cout << "Longitud: " << fila->longitud << endl;
  return 0;
}
