#include "Tienda.h"

Tienda::Tienda(string nombre, string direccion)
{
	setNombre(nombre);
	setDireccion(direccion);
};

void Tienda::setNombre(string nuevoNombre)
{
	this->nombre = nuevoNombre;
};

string Tienda::getNombre()
{
	return this->nombre;
};

void Tienda::setDireccion(string nuevaDireccion)
{
	this->direccion = nuevaDireccion;
};

string Tienda::getDireccion()
{
	return this->direccion;
}