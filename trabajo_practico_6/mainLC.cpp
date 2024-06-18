#include "ListaCircular.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ListaCircular *lc = LCVacia();
  if (EsLCVacia(lc)) {
    cout << "Lista vacía" << endl;
  }

  lc = LCInsertar(lc, 10);
  lc = LCInsertar(lc, 20);
  lc = LCInsertar(lc, 30);
  lc = LCInsertar(lc, 40);
  lc = LCInsertar(lc, 50);
  LCImprimir(lc);
  lc = LCBorrar(lc);
  LCImprimir(lc);
  lc = LCRotar(lc);
  LCImprimir(lc);

  return 0;
}
