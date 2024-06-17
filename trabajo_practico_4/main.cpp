#include "Cochera.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Cochera *cochera = CocheraVacia(100);
  cochera = Estacionar(cochera, 10);
  cochera = Estacionar(cochera, 20);
  cochera = Estacionar(cochera, 30);
  cochera = Estacionar(cochera, 40);
  cochera = Estacionar(cochera, 50);
  Mostrar(cochera);
  cochera = QuitarUltimo(cochera);
  Mostrar(cochera);
  cout << "Capacidad: " << Capacidad(cochera) << endl;
  cout << "Libres: " << libres(cochera) << endl;
  if (Estacionado(cochera, 10)) {
    cout << "10 estacionado" << endl;
  } else {
    cout << "10 no estacionado" << endl;
  }
  return 0;
}
