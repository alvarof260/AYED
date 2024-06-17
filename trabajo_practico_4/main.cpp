#include "Cochera.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Cochera *cochera = CocheraVacia(100);
  cochera = Estacionar(cochera, 10);
  cochera = Estacionar(cochera, 20);
  cochera = Estacionar(cochera, 30);
  Mostsrar(cochera);
  return 0;
}
