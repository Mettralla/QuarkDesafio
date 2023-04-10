#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include "Prenda.h"

using namespace std;

/*  Esta clase representa una cotizacion. */
class Cotizacion {
private:
    int id; // numero de identificacion 
    string fechaHora;  // timestamp de la cotizacion
    string codigoVendedor; // codigo de identificacion del vendedor
    Prenda* prenda; // prenda a cotizar
    int unidades; // cantidad de unidades cotizadas
    double totalCotizacion; // resultado de la cotizacion
    static int contador; // contador de cotizaciones
public:
    Cotizacion(string codigoVendedor, Prenda* prenda, int unidades);

    // GETTERS & SETTERS

    // Asigna o cambia el id de la cotizacion.
    void setId();

    // Regresa el id de la cotizacion.
    int getId();

    // Asigna la timestamp de creacion.
    void setFechaHora();

    // Regresa la timestamp de creacion.
    string getFechaHora();

    // Asigna o cambia el codigo del vendedor. 
    void setCodigoVendedor(string nuevoCodigo);
    
    // Regresa el codigo del vendedor.
    string getCodigoVendedor();

    // Asigna o cambia la prenda a cotizar. 
    void setPrenda(Prenda* nuevaPrenda);

    // Regresa la prenda a cotizar.
    Prenda* getPrenda();

    // Asigna o cambia la cantidad de unidades a cotizar. 
    void setUnidades(int nuevasUnidades);

    // Regresa la cantidad de unidades a cotizar.
    int getUnidades();

    // Asigna o cambia el total. 
    void setTotalCotizacion(double precioUnitario, int unidades);

    // Regresa el total.
    double getTotalCotizacion();

    // PRENDA
     
    // Regresa las caracteristicas de la prenda en formato Nombre - Tipo - Calidad
    string getCaracteristicas();

    // COTIZACION

    // Imprime la cotizacion por consola
    void imprimirCotizacion();
};

