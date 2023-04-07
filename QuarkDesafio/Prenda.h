#pragma once
#include <string>
#include <list>

using namespace std;

class Prenda
{
protected:
	string nombre;
	string calidad;
	double precioUnitario;
	int stock;
public:
	virtual ~Prenda() = 0;

	string getNombre();
	string getCalidad();
	double getPrecioUnitario();
	int getStock();
};

