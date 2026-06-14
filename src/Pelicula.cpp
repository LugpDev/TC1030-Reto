#include "../include/Pelicula.h"

#include <iostream>

using namespace std;

Pelicula::Pelicula(string _id, string _titulo, string _genero, int _anio, int _duracion)
    : Contenido(_id, _titulo, _genero)
{
  anio = _anio;
  duracion = _duracion;
}

int Pelicula::calcularDuracionTotal()
{
  return duracion;
}

void Pelicula::mostrarInfo()
{
  cout << "ID: " << id << endl;
  cout << "Título: " << titulo << endl;
  cout << "Género: " << genero << endl;
  cout << "Año: " << anio << endl;
  cout << "Duración: " << calcularDuracionTotal() << " minutos" << endl;
}

void Pelicula::reproducir()
{
  cout << "Reproduciendo película: " << titulo << " (" << anio << ")" << endl;
}