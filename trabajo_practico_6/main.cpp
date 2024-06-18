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
  Mostrar(fila);
  if (Pertenece(fila, 85)) { // <- O(n)
    cout << "85 pertenece" << endl;
  } else {
    cout << "85 no pertenece" << endl;
  }
  cout << "Longitud: " << fila->longitud << endl;
  while (fila->longitud == 0) {
    fila = DeFila(fila);
  }
  return 0;
}
