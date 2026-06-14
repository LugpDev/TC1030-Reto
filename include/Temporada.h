#ifndef TEMPORADA_H
#define TEMPORADA_H

#include "IReproducible.h"
#include "ITemporal.h"
#include "Episodio.h"

#include <vector>

using namespace std;

class Temporada : public IReproducible, public ITemporal
{
private:
  int numTemporada;
  vector<Episodio *> episodios;

public:
  Temporada(int _numTemporada);
  void agregarEpisodio(Episodio *e);
  int calcularDuracionTotal();
  void eliminarEpisodio(string titulo);
  void mostrarInfo();
  void operator+(Episodio *e);
  void reproducir();
};

#endif