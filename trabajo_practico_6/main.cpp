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
  Fila *fila2 = FilaVacia();
  fila2 = EnFila(fila2, 15);
  fila2 = EnFila(fila2, 25);
  fila2 = EnFila(fila2, 35);
  fila2 = EnFila(fila2, 45);
  fila2 = EnFila(fila2, 55);
  fila2 = EnFila(fila2, 65);
  Mostrar(fila2);

  Fila *fila3 = FilaVacia();
  fila3 = Mezclar(fila, fila2);
  Mostrar(fila3);
  return 0;
}
