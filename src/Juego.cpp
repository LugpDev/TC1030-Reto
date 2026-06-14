#include "../include/Juego.h"

#include <iostream>

using namespace std;

Juego::Juego(string _id, string _titulo, Genero _genero, bool _offline, bool _multijugador, Dificultad _dificultad) : Contenido(_id, _titulo, _genero)
{
  offline = _offline;
  multijugador = _multijugador;
  dificultad = _dificultad;
}

void Juego::mostrarInfo()
{
  cout << "ID: " << id << endl;
  cout << "Titulo: " << titulo << endl;
  cout << "Genero: " << generoToString(genero) << endl;
  cout << "Offline: " << (offline ? "Si" : "No") << endl;
  cout << "Multijugador: " << (multijugador ? "Si" : "No") << endl;
  cout << "Dificultad: ";
  switch (dificultad)
  {
  case Dificultad::FACIL:
    cout << "Facil";
    break;
  case Dificultad::MEDIO:
    cout << "Medio";
    break;
  case Dificultad::DIFICIL:
    cout << "Dificil";
    break;
  }
  cout << endl;
}

void Juego::reproducir()
{
  cout << "Reproduciendo juego: " << titulo << endl;
}