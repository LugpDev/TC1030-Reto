#include "../include/GestorContenidos.h"
#include "../include/Pelicula.h"
#include "../include/Serie.h"
#include "../include/Juego.h"
#include "../include/Temporada.h"
#include "../include/Episodio.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

static string trim(const string &s)
{
  size_t start = s.find_first_not_of(" \t\r");
  size_t end = s.find_last_not_of(" \t\r");
  return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

static vector<string> split(const string &s, char delim)
{
  vector<string> tokens;
  stringstream ss(s);
  string token;
  while (getline(ss, token, delim))
    tokens.push_back(trim(token));
  return tokens;
}

static Genero parseGenero(const string &s)
{
  if (s == "ACCION") return ACCION;
  if (s == "COMEDIA") return COMEDIA;
  if (s == "DRAMA") return DRAMA;
  if (s == "FANTASIA") return FANTASIA;
  return CIENCIA_FICCION;
}

static Dificultad parseDificultad(const string &s)
{
  if (s == "FACIL") return Dificultad::FACIL;
  if (s == "MEDIA") return Dificultad::MEDIA;
  return Dificultad::DIFICIL;
}

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

void GestorContenidos::cargarDesdeArchivo(string ruta)
{
  ifstream archivo(ruta);
  if (!archivo.is_open())
    throw runtime_error("ERROR: No se pudo abrir el archivo " + ruta);

  vector<string> lineas;
  string linea;
  while (getline(archivo, linea))
    lineas.push_back(linea);
  archivo.close();

  int i = 0;
  int total = (int)lineas.size();

  while (i < total)
  {
    string l = trim(lineas[i]);

    if (l.empty() || l[0] == '#') { i++; continue; }

    if (l == "PELICULA")
    {
      i++;
      while (i < total && (trim(lineas[i]).empty() || trim(lineas[i])[0] == '#')) i++;
      if (i >= total) break;

      auto p = split(lineas[i], '|');
      agregarContenido(new Pelicula(p[0], p[1], parseGenero(p[2]), stoi(p[3]), stoi(p[4])));
      i++;
    }
    else if (l == "SERIE")
    {
      i++;
      while (i < total && (trim(lineas[i]).empty() || trim(lineas[i])[0] == '#')) i++;
      if (i >= total) break;

      auto p = split(lineas[i], '|');
      Serie *serie = new Serie(p[0], p[1], parseGenero(p[2]), stoi(p[3]));
      i++;

      while (i < total)
      {
        string ll = trim(lineas[i]);
        if (ll.empty() || ll[0] == '#') { i++; continue; }
        if (ll == "PELICULA" || ll == "SERIE" || ll == "JUEGO") break;

        if (ll.substr(0, 9) == "TEMPORADA")
        {
          Temporada *temp = new Temporada(stoi(ll.substr(9)));
          i++;

          while (i < total)
          {
            string lll = trim(lineas[i]);
            if (lll.empty() || lll[0] == '#') { i++; continue; }
            if (lll.substr(0, 8) != "EPISODIO") break;

            string epParte = lll.substr(9);
            size_t pos = epParte.rfind('|');
            string epTitulo = trim(epParte.substr(0, pos));
            int epDuracion = stoi(trim(epParte.substr(pos + 1)));
            temp->agregarEpisodio(new Episodio(epTitulo, epDuracion));
            i++;
          }

          serie->agregarTemporada(temp);
        }
        else { break; }
      }

      agregarContenido(serie);
    }
    else if (l == "JUEGO")
    {
      i++;
      while (i < total && (trim(lineas[i]).empty() || trim(lineas[i])[0] == '#')) i++;
      if (i >= total) break;

      auto p = split(lineas[i], '|');
      agregarContenido(new Juego(p[0], p[1], parseGenero(p[2]),
                                 stoi(p[3]) != 0, stoi(p[4]) != 0,
                                 parseDificultad(p[5])));
      i++;
    }
    else { i++; }
  }
}