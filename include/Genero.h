#ifndef GENERO_H
#define GENERO_H

#include <string>

enum Genero
{
  ACCION,
  COMEDIA,
  DRAMA,
  FANTASIA,
  CIENCIA_FICCION
};

inline std::string generoToString(Genero genero)
{
  switch (genero)
  {
  case ACCION:
    return "ACCION";
  case COMEDIA:
    return "COMEDIA";
  case DRAMA:
    return "DRAMA";
  case FANTASIA:
    return "FANTASIA";
  case CIENCIA_FICCION:
    return "CIENCIA_FICCION";
  }

  return "DESCONOCIDO";
}

#endif // GENERO_H