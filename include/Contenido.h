#ifndef CONTENIDO_H
#define CONTENIDO_H

#include <string>

using namespace std;

class Contenido
{
protected:
  string id;
  string titulo;
  string genero;

public:
  Contenido(string _id, string _titulo, string _genero);
  string getId();
  string getTitulo();
  string getGenero();
  virtual void mostrarInfo() = 0;
};

#endif // CONTENIDO_H