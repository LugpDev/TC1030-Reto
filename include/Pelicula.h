#ifndef PELICULA_H
#define PELICULA_H

#include "./Contenido.h"

class Pelicula : public Contenido
{
private:
  int anio;
  int duracion; // Duración en minutos
public:
  Pelicula(string _id, string _titulo, string _genero, int _anio, int _duracion);
  int calcularDuracionTotal();
  void mostrarInfo();
  void reproducir();
};

#endif // PELICULA_H