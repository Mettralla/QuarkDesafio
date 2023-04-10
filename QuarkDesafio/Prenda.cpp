#include "Prenda.h"

Prenda::~Prenda()
{

};

string Prenda::getNombre()
{
	return this->nombre;
};

void Prenda::setNombre(string nuevoNombre)
{
	this->nombre = nuevoNombre;
};

string Prenda::getCalidad()
{
	return this->calidad;
};

void Prenda::setCalidad(string nuevaCalidad)
{
	this->nombre = nuevaCalidad;
};

double Prenda::getPrecioUnitario()
{
	return this->precioUnitario;
};

void Prenda::setPrecioUnitario(double nuevoPrecio)
{
	this->precioUnitario = nuevoPrecio;
};

int Prenda::getUnidades()
{
	return this->unidades;
};

void Prenda::setUnidades(int nuevasUnidades)
{
	this->unidades = nuevasUnidades;
};