#pragma once
#include "PrendaFactory.h"

class CamisaFactory : public PrendaFactory {
public:
	Prenda* crear() { return new Camisa(); };
};
