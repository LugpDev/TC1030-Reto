#ifndef GESTORCONTENIDOS_H
#define GESTORCONTENIDOS_H

#include "Contenido.h"

#include <string>
#include <vector>

using namespace std;

class GestorContenidos
{
private:
  vector<Contenido *> contenidos;

public:
  GestorContenidos();
  void agregarContenido(Contenido *c);
  void buscarPorId(string id);
  void buscarPorTitulo(string t);
  void eliminarContenido(string id);
  void listarContenidos();
  void listarContenidosPorGenero(Genero g);
  void cargarDesdeArchivo(string ruta);
  void operator+(Contenido *c);
};

#endif // GESTORCONTENIDOS_H