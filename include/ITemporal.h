#ifndef ITEMPORAL_H
#define ITEMPORAL_H

class ITemporal
{
public:
  virtual ~ITemporal() = default;
  virtual int calcularDuracionTotal() = 0;
};

#endif // ITEMPORAL_H