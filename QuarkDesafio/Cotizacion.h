#pragma once
#include <string>
//#include <ctime>
//#include <iomanip>
#include <chrono>

using namespace std;

/*  Esta clase representa una cotizacion.
    params:
    [int] id: numero de identificacion de la cotizacion.
    [str] fechaHora: timestamp de la cotizacion se genera de forma automatica al crear.
    [str] codigo de vendedor: el codigo de identificacion del vendedor.
    [str] prenda: prenda a cotizar.
    [int] unidades: cantidad de unidades cotizadas.
    [double] totalCotizacion: resultado del calculo de la cotizacion.*/
class Cotizacion {
private:
    int id;
    string fechaHora;
    string codigoVendedor;
    string prenda;
    int unidades;
    double totalCotizacion;
public:
    Cotizacion(int id, string codigoVendedor, string prenda, int unidades, double totalCotizacion);

    // GETTERS & SETTERS

    // Asigna o cambia el id de la cotizacion.
    void setId(int nuevoId);

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
    void setPrenda(string nuevaPrenda);

    // Regresa la prenda a cotizar.
    string getPrenda();

    // Asigna o cambia la cantidad de unidades a cotizar. 
    void setUnidades(int nuevasUnidades);

    // Regresa la cantidad de unidades a cotizar.
    int getUnidades();

    // Asigna o cambia el total. 
    void setTotalCotizacion(double nuevoTotal);

    // Regresa el total.
    double getTotalCotizacion();
};

