#pragma once
#include <string>
#include <list>

using namespace std;

/*  Esta clase representa a la tienda. */
class Tienda {
private:
	string nombre; // Nombre de la tienda
	string direccion; // Direccion de la tienda

	// MATRICES PARALELAS DE STOCK
	
	// Nombre de las prendas
	string prendas[11][2] = {
		{"Camisas", "Pantalones"},

		{"Manga Corta", "Manga Larga"},

		{"Manga Corta Mao", "Manga Corta Comun"},
		{"MC Mao Standard", "MC Mao Premium"},
		{"MC Comun Standard", "MC Comun Premium"},

		{"Manga Larga Mao", "Manga Larga Comun"},
		{"ML Mao Standard", "ML Mao Premium"},
		{"ML Comun Standard", "ML Comun Premium"},

		{"Chupines", "Comunes"},
		{"Chupin Standard", "Chupin Premium"},
		{"Comun Standard", "Comun Premium"}
	};

	// Cantidades de prendas
	int stock[11][2] = {
		{1000, 2000},

		{500, 500},

		{200, 300},
		{100, 100},
		{150, 150},

		{150, 350},
		{75, 75},
		{175, 175},

		{1500, 500},
		{750, 750},
		{250, 250}
	};
public:
	Tienda(string nombre, string direccion);

	// GETTERS & SETTERS

	// Regresa el nombre de la tienda
	string getNombre();
	
	// Asigna el nombre a la tienda
	void setNombre(string nuevoNombre);

	// Regresa la direccion de la tienda
	string getDireccion();

	// Asigna la direccion de la tienda
	void setDireccion(string nuevoDireccion);

	// STOCK

	// Regresa la cantidad de una prenda especifica
	int getStock(int row, int col);

};

