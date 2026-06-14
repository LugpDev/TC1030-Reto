#include "include/GestorContenidos.h"

#include <iostream>

using namespace std;

int main()
{
  GestorContenidos gestor;
  gestor.cargarDesdeArchivo("contenidos.txt");

  cout << "=== Catálogo de contenidos ===" << endl;
  gestor.listarContenidos();

  return 0;
}
