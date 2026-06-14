#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <string>
#include "Genero.h"
#include "./IReproducible.h"

using namespace std;

class Contenido : public IReproducible
{
protected:
  string id;
  string titulo;
  Genero genero;

public:
  Contenido(string _id, string _titulo, Genero _genero);
  virtual ~Contenido() = default;
  string getId();
  string getTitulo();
  Genero getGenero();
  virtual void mostrarInfo() = 0;
};

#endif // CONTENIDO_H