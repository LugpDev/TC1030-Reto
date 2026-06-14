#include "../include/Episodio.h"

#include <iostream>

using namespace std;

Episodio::Episodio(string _titulo, int _duracion)
{
  titulo = _titulo;
  duracion = _duracion;
}

void Episodio::reproducir()
{
  cout << "Reproduciendo episodio: " << titulo << endl;
}

int Episodio::calcularDuracionTotal()
{
  return duracion;
}

void Episodio::mostrarInfo()
{
  cout << "Episodio: " << titulo << ", Duracion: " << calcularDuracionTotal() << " minutos" << endl;
}