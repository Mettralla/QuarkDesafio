#pragma once
#include "Prenda.h"

/*  Esta clase representa una camisa. */
class Camisa : public Prenda {
private:
	string manga; // Tipo de manga
	string cuello; // Tipo de cuello
public:
	Camisa(string manga, string cuello, string calidad, double precioUnitario, int unidades);
	~Camisa();

	// GETTERS & SETTERS

	// Regresar tipo de manga
	string getManga();

	// Asigna tipo de manga
	void setManga(int eleccion);
	
	// Regresar tipo de manga
	string getCuello();
	
	// Asigna cuello de camisa
	void setCuello(int eleccion);



	string getTipo() { return "-1"; };
};

