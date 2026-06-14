#include "../include/Temporada.h"

#include <iostream>

using namespace std;

Temporada::Temporada(int _numTemporada)
{
  numTemporada = _numTemporada;
}

int Temporada::getNumTemporada()
{
  return numTemporada;
}

vector<Episodio *> Temporada::getEpisodios()
{
  return episodios;
}

void Temporada::agregarEpisodio(Episodio *e)
{
  episodios.push_back(e);
}

int Temporada::calcularDuracionTotal()
{
  int duracionTotal = 0;
  for (Episodio *e : episodios)
  {
    duracionTotal += e->calcularDuracionTotal();
  }
  return duracionTotal;
}

void Temporada::eliminarEpisodio(string titulo)
{
  for (auto it = episodios.begin(); it != episodios.end(); ++it)
  {
    if ((*it)->getTitulo() == titulo)
    {
      delete *it;
      episodios.erase(it);
      break;
    }
  }

  throw runtime_error("ERROR: No se encontró el episodio con el título especificado");
}

void Temporada::mostrarInfo()
{
  cout << "Temporada " << numTemporada << ":" << endl;
  for (Episodio *e : episodios)
  {
    e->mostrarInfo();
  }
}

void Temporada::operator+(Episodio *e)
{
  agregarEpisodio(e);
}

void Temporada::reproducir()
{
  if (episodios.empty())
  {
    throw runtime_error("ERROR: No hay episodios para reproducir");
  }

  cout << "Reproduciendo Temporada " << numTemporada << "episodio " << episodios[0]->getTitulo() << endl;
}