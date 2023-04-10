#pragma once
#include "PrendaFactory.h"

class PantalonFactory : public PrendaFactory {
public:
    Prenda* crear() { return new Pantalon(); }
};
