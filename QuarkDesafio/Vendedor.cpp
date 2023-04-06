#include "Vendedor.h"

Vendedor::Vendedor(string nombre, string apellido, string codigoVendedor)
{
    setNombre(nombre);
    setApellido(apellido);
    setCodigoVendedor(codigoVendedor);
};

void Vendedor::setNombre(string nuevoNombre)
{
    this->nombre = nuevoNombre;
};

string Vendedor::getNombre()
{
    return this->nombre;
};

void Vendedor::setApellido(string nuevoApellido)
{
    this->apellido = nuevoApellido;
};

string Vendedor::getApellido()
{
    return this->apellido;
};

void Vendedor::setCodigoVendedor(string nuevoCodigo)
{
    this->codigoVendedor = nuevoCodigo;
};

string Vendedor::getCodigoVendedor()
{
    return this->codigoVendedor;
};

void Vendedor::addCotizacion(Cotizacion* nuevaCotizacion)
{
    this->historial.push_back(nuevaCotizacion);
};

list<Cotizacion*> Vendedor::getHistorial()
{
    return this->historial;
}
