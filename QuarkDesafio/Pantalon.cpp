#include "Pantalon.h"

Pantalon::Pantalon(string tipo, string calidad, double precioUnitario, int unidades)
{
	setNombre("Pantalon");
	this->tipo = tipo;
	this->calidad = calidad;
	this->precioUnitario = precioUnitario;
	this->unidades = unidades;
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
