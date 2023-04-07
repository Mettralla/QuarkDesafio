#pragma once
#include <string>
#include <list>

using namespace std;

class Tienda {
private:
	string nombre;
	string direccion;
public:
	Tienda(string nombre, string direccion);

	string getNombre();
	void setNombre(string nuevoNombre);

	string getDireccion();
	void setDireccion(string nuevoDireccion);
};

