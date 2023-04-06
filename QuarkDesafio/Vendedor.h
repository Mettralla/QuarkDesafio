#pragma once
#include <string>
#include <list>
#include "Cotizacion.h"

using namespace std;

/*  Esta clase representa a un vendedor.
    params:
    [str] nombre: el nombre del vendedor.
    [str] apellido: el apellido del vendedor.
    [str] codigo de vendedor: el codigo de identificacion del vendedor. */
class Vendedor
{
private:
    string nombre;
    string apellido;
    string codigoVendedor;
    list<Cotizacion*> historial;
public:
    Vendedor(string nombre, string apellido, string codigoVendedor);

    // GETTERS & SETTERS

    // Asigna o cambia el nombre del vendedor.
    void setNombre(string nuevoNombre);

    // Regresa el nombre del vendedor.
    string getNombre();

    // Asigna o cambia el apellido del vendedor.
    void setApellido(string nuevoApellido);

    // Regresa el apellido del vendedor.
    string getApellido();

    // Asigna o cambia el codigo del vendedor.
    void setCodigoVendedor(string nuevoCodigo);

    // Regresa el codigo del vendedor.
    string getCodigoVendedor();

    // COTIZACIONES

    // Agrega una cotizacion a la lista de cotizaciones.
     void addCotizacion(Cotizacion* nuevaCotizacion);

     // Regresa el historial de cotizaciones del vendedor.
     list<Cotizacion*> getHistorial();

};

