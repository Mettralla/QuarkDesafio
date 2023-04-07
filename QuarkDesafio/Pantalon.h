#pragma once
#include "Prenda.h"
class Pantalon : public Prenda {
private:
	string tipo;
public:
	Pantalon();
	~Pantalon();
	string getTipo();
	void setTipo(int eleccion);
};

