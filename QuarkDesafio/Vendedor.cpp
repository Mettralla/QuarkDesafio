#include "Vendedor.h"
#include<iostream>

Vendedor::Vendedor(string nombre, string apellido, string codigoVendedor)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->codigoVendedor = codigoVendedor;
};

Vendedor::~Vendedor()
{
    if (historial.empty() == false)
    {
        for (Cotizacion* const& i : historial) 
        {
            delete i;
        }
    }
}

void Vendedor::setNombre(string nuevoNombre)
{
    this->nombre = nuevoNombre;
};

string Vendedor::getNombre()
{
    return this->nombre;
};

string Vendedor::getNombreCompleto()
{
    return this->nombre + " " + this->apellido;
}

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

void Vendedor::imprimirHistorial()
{
    for (Cotizacion* const& i : historial) {
        /*cout << " Numero de identificacion: " << i->getId() << endl; 
        cout << " Fecha y Hora de la cotizacion: " << i->getFechaHora() << endl;
        cout << " Codigo del Vendedor: " << i->getCodigoVendedor() << endl;
        cout << " Prenda Cotizada: " << i->getCaracteristicas() << endl;
        cout << " Precio unitario: " << i->getPrenda()->getPrecioUnitario() << endl;
        cout << " Cantidad de unidades cotizadas: " << i->getPrenda()->getUnidades() << endl;
        cout << " Precio Final: " << i->getTotalCotizacion() << endl;*/
        i->imprimirCotizacion();
        cout << endl;
        cout << endl;
    }
}
