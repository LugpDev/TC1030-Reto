#ifndef EPISODIO_H
#define EPISODIO_H

#include "IReproducible.h"
#include "ITemporal.h"

#include <string>

using namespace std;

class Episodio : public IReproducible, public ITemporal
{

private:
  string titulo;
  int duracion; // En minutos
public:
  Episodio(string _titulo, int _duracion);
  void reproducir();
  void mostrarInfo();
  int calcularDuracionTotal();
};

#endif // EPISODIO_H
