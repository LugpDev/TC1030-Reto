#include "../include/Contenido.h"

Contenido::Contenido(string _id, string _titulo, string _genero)
{
  id = _id;
  titulo = _titulo;
  genero = _genero;
}

string Contenido::getId()
{
  return id;
}

string Contenido::getTitulo()
{
  return titulo;
}

string Contenido::getGenero()
{
  return genero;
}