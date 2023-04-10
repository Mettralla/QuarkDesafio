#pragma once
#include <string>
#include <list>

using namespace std;

/*  Esta clase representa una prenda. */
class Prenda {
protected:
	string nombre; // Nombre de la prensa
	string calidad; // Calidad de la prenda
	double precioUnitario; // Precio de la prenda
	int unidades; // Cantidad de prendas
public:
	virtual ~Prenda() = 0;

	// GETTERS & SETTERS

	// Regresa el nombre de la prenda
	string getNombre();

	// Asigna el nombre a la prenda
	void setNombre(string nuevoNombre);
	
	// Regresa la calidad
	string getCalidad();
	
	// Asigna la calidad de la prenda
	void setCalidad(string nuevaCalidad);
	
	// Regresa el precio
	double getPrecioUnitario();
	
	// Asigna el nombre a la prenda
	void setPrecioUnitario(double precio);
	
	// Regresa la cantidad
	int getUnidades();
	
	// Asigna la cantidad
	void setUnidades(int nuevasUnidades);
	
	// VIRTUAL

	virtual string getManga() = 0;
	virtual string getCuello() = 0;
	virtual string getTipo() = 0;
};

