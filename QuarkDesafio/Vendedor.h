#pragma once
#include <string>
#include <list>
#include "Cotizacion.h"

using namespace std;

/*  Esta clase representa a un vendedor. */
class Vendedor
{
private:
    string nombre; // Nombre del vendendor
    string apellido; // Apellido del vendedor
    string codigoVendedor; // Codigo de identificacion del vendedor
    list<Cotizacion*> historial; // Lista de Cotizaciones
public:
    Vendedor(string nombre, string apellido, string codigoVendedor);

    ~Vendedor();

    // GETTERS & SETTERS

    // Asigna o cambia el nombre del vendedor.
    void setNombre(string nuevoNombre);

    // Regresa el nombre del vendedor.
    string getNombre();

    // Regresa el nombre completo del vendedor.
    string getNombreCompleto();

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

     // Imprime las cotizaciones del historial en la consola
     void imprimirHistorial();
};

