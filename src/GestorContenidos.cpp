#include "../include/GestorContenidos.h"

#include <iostream>

using namespace std;

GestorContenidos::GestorContenidos()
{
}

void GestorContenidos::agregarContenido(Contenido *c)
{
  contenidos.push_back(c);
}

void GestorContenidos::buscarPorId(string id)
{
  for (Contenido *c : contenidos)
  {
    if (c->getId() == id)
    {
      c->mostrarInfo();
      return;
    }
  }

  throw runtime_error("ERROR: No se encontró el contenido con el ID especificado");
}

void GestorContenidos::buscarPorTitulo(string t)
{
  for (Contenido *c : contenidos)
  {
    if (c->getTitulo() == t)
    {
      c->mostrarInfo();
      return;
    }
  }

  throw runtime_error("ERROR: No se encontró el contenido con el título especificado");
}

void GestorContenidos::eliminarContenido(string id)
{
  for (auto it = contenidos.begin(); it != contenidos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      delete *it;
      contenidos.erase(it);
      return;
    }
  }

  throw runtime_error("ERROR: No se encontró el contenido con el ID especificado");
}

void GestorContenidos::listarContenidos()
{
  for (Contenido *c : contenidos)
  {
    c->mostrarInfo();
    cout << "------------------------" << endl;
  }
}

void GestorContenidos::listarContenidosPorGenero(Genero g)
{
  for (Contenido *c : contenidos)
  {
    if (c->getGenero() == g)
    {
      c->mostrarInfo();
      cout << "------------------------" << endl;
    }
  }
}

void GestorContenidos::operator+(Contenido *c)
{
  agregarContenido(c);
}