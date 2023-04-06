#include "Cotizacion.h"

Cotizacion::Cotizacion(int id, string codigoVendedor, string prenda, int unidades, double totalCotizacion)
{
    setId(id);
    setFechaHora();
    setCodigoVendedor(codigoVendedor);
    setPrenda(prenda);
    setUnidades(unidades);
    setTotalCotizacion(totalCotizacion);
};

void Cotizacion::setId(int nuevoId)
{
    this->id = nuevoId;
};

int Cotizacion::getId()
{
    return this->id;
};

void Cotizacion::setFechaHora()
{
    // Representar el tiempo.
    time_t timer = time(0);
    // Buffer almacenamiento
    tm bt{};

    // Convierte el timer en tiempo calendario y lo guarda en bt.
    localtime_s(&bt, &timer);

    char fechaString[20];
    const string& fmt = "%d/%m/%Y %H:%M";

    this->fechaHora = { fechaString, strftime(fechaString, sizeof fechaString, fmt.c_str(), &bt) };
};

string Cotizacion::getFechaHora()
{
    return this->fechaHora;
};

void Cotizacion::setCodigoVendedor(string nuevoCodigo)
{
    this->codigoVendedor = nuevoCodigo;
};

string Cotizacion::getCodigoVendedor()
{
    return this->codigoVendedor;
};

void Cotizacion::setPrenda(string nuevaPrenda)
{
    this->prenda = nuevaPrenda;
};

string Cotizacion::getPrenda()
{
    return this->prenda;
};

void Cotizacion::setUnidades(int nuevasUnidades)
{
    this->unidades = nuevasUnidades;
};

int Cotizacion::getUnidades()
{
    return this->unidades;
};

void Cotizacion::setTotalCotizacion(double nuevoTotal)
{
    this->totalCotizacion = nuevoTotal;
}

double Cotizacion::getTotalCotizacion()
{
    return this->totalCotizacion;
};
