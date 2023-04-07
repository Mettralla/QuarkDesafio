#include "Prenda.h"

Prenda::~Prenda()
{

};

string Prenda::getNombre()
{
	return this->nombre;
};

string Prenda::getCalidad()
{
	return this->calidad;
};

double Prenda::getPrecioUnitario()
{
	return this->precioUnitario;
};

int Prenda::getStock()
{
	return this->stock;
};