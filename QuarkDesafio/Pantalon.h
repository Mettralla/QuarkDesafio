#pragma once
#include "Prenda.h"

/*  Esta clase representa un pantalon. */
class Pantalon : public Prenda {
private:
	string tipo; // Tipo de pantalon
public:
	Pantalon(string tipo, string calidad, double precioUnitario, int unidades);
	~Pantalon();

	// GETTERS & SETTERS

	// Regresa el tipo de pantalon
	string getTipo();

	// Asigna el tipo de pantalon.
	void setTipo(int eleccion);


	string getManga() { return "-1"; };
	string getCuello() { return "-1"; };
};

