#ifndef IREPRODUCIBLE_H
#define IREPRODUCIBLE_H

class IReproducible
{
public:
  virtual ~IReproducible() = default;
  virtual void reproducir() = 0;
  virtual void mostrarInfo() = 0;
};

#endif // IREPRODUCIBLE_H