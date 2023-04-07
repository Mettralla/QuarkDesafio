#include "Pantalon.h"

Pantalon::Pantalon()
{

};

Pantalon::~Pantalon()
{

};

string Pantalon::getTipo()
{
	return this->tipo;
};

void Pantalon::setTipo(int eleccion)
{
	if (eleccion == 1)
	{
		this->tipo = "Comun";
	}
	else
	{
		this->tipo = "Chupin";
	}
}