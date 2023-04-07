#pragma once
#include "Prenda.h"

class Camisa : public Prenda {
private:
	string manga;
	string cuello;
public:
	Camisa();
	~Camisa();
	string getManga();
	void setManga(int eleccion);
	string getCuello();
	void setCuello(int eleccion);
};

