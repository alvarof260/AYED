#include "Pila.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Pila *pila = PilaVacia();
  if (EsPilaVacia(pila)) {
    cout << "Pila vacía" << endl;
  }

  pila = Push(pila, 10);
  pila = Push(pila, 20);
  pila = Push(pila, 30);
  pila = Push(pila, 40);
  pila = Push(pila, 50);
  Item top = Top(pila);
  cout << "Top: " << top << endl;
  pila = Pop(pila);
  top = Top(pila);
  cout << "Top: " << top << endl;
  return 0;
}
