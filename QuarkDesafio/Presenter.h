#pragma once
#include "Vendedor.h"
#include "Tienda.h"
#include "Camisa.h"
#include "Pantalon.h"
#include <iostream>
#include <conio.h>

/*  Esta clase es el presentador. */
class Presenter {
public:
	Tienda* tienda; // Tienda
	Vendedor* vendedor; // Vendedor

	Presenter();
	~Presenter();

	// Inicializa la instania de tienda y vendedor que usara la clase.
	void inicializarTienda();

	// Da al usuario la posibilidad de ingresar una opcion entre 1 - 3 y la regresa
	int getEleccion();

	// Regresa la prenda elegida
	bool elegirPrenda(int eleccion);

	// Busca en stock la cantidad de la prenda seleccionada y la regresa
	int getStock(bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, bool esStandard);
	
	// Crea una cotizacion y la ingresa a la lista
	void crearCotizacion(bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, bool esStandard, double precioUnitario, int cantContizar);
};

