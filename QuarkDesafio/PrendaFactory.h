#pragma once
#include "Prenda.h"
#include "Camisa.h"
#include "Pantalon.h"

class PrendaFactory {
public:
	virtual Prenda* crear() = 0;
};

