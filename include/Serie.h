#ifndef SERIE_H
#define SERIE_H

#include "Contenido.h"
#include "ITemporal.h"
#include "Temporada.h"

#include <vector>

using namespace std;

class Serie : public Contenido, public ITemporal
{
private:
  vector<Temporada *> temporadas;
  int anio;

public:
  Serie(string _id, string _titulo, string _genero, int _anio);
  void agregarTemporada(Temporada *t);
  void operator+(Temporada *t);
  int calcularDuracionTotal();
  void mostrarInfo();
  void reproducir();
};

#endif // SERIE_H