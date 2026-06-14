#ifndef JUEGO_H
#define JUEGO_H

#include "./Contenido.h"

enum class Dificultad
{
  FACIL,
  MEDIO,
  DIFICIL
};

class Juego : public Contenido
{
private:
  bool offline;
  bool multijugador;
  Dificultad dificultad;

public:
  Juego(string _id, string _titulo, Genero _genero, bool _offline, bool _multijugador, Dificultad _dificultad);
  void mostrarInfo();
  void reproducir();
};

#endif // JUEGO_H