#include "../include/Serie.h"

#include <iostream>

using namespace std;

Serie::Serie(string _id, string _titulo, string _genero, int _anio) : Contenido(_id, _titulo, _genero)
{
  anio = _anio;
}

void Serie::agregarTemporada(Temporada *t)
{
  temporadas.push_back(t);
}

void Serie::operator+(Temporada *t)
{
  agregarTemporada(t);
}

int Serie::calcularDuracionTotal()
{
  int duracionTotal = 0;
  for (Temporada *t : temporadas)
  {
    duracionTotal += t->calcularDuracionTotal();
  }
  return duracionTotal;
}

void Serie::mostrarInfo()
{
  cout << "ID: " << id << endl;
  cout << "Título: " << titulo << endl;
  cout << "Género: " << genero << endl;
  cout << "Año: " << anio << endl;
  cout << "Duración total: " << calcularDuracionTotal() << " minutos" << endl;
}

void Serie::reproducir()
{
  cout << "Reproduciendo serie: " << titulo << " temporada " << temporadas[0]->getNumTemporada() << " episodio " << temporadas[0]->getEpisodios()[0]->getTitulo() << endl;
}