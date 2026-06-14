#ifndef PELICULA_H
#define PELICULA_H

#include "./Contenido.h"
#include "./ITemporal.h"

class Pelicula : public Contenido, public ITemporal
{
private:
  int anio;
  int duracion; // Duración en minutos
public:
  Pelicula(string _id, string _titulo, Genero _genero, int _anio, int _duracion);
  int calcularDuracionTotal();
  void mostrarInfo();
  void reproducir();
};

#endif // PELICULA_H