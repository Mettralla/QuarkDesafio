#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "Presenter.h"

using namespace std;

/*  Esta clase representa la vista */
class View
{
private:
	Presenter* presenter = new Presenter; // Instancia del presentador
public:
	View();
	~View();
	
	// Muestra el menu principal
	void menuPrincipal();

	// El usuario ingresa una opcion y asigna el tipo de prenda
	void asignarEleccion(bool* opcion);

	// Realiza la cotizacion mostrando ventanas y recibiendo las opciones
	void realizarCotizacion();

	// Asigna el tipo de prenda Camisa - Pantalon
	void cotizarPsUno(bool* esCamisa);

	// Asigna el tipo de manga Corta - Larga
	void cotizarPsDosA(bool* esMangaCorta);

	// Asigna el tipo de cuello Mao - Comun
	void cotizarPsDosB(bool* esCuelloMao);

	// Asigna el tipo de pantalon Chupin - Comun
	void cotizarPsDosC(bool* esChupin);

	// Asigna la calidad Standard - Premium
	void cotizarPsTres(bool* esStandard);

	// Asigna el precio
	void cotizarPsCuatro();

	// Asigna la cantidad de unidades
	void cotizarPsCinco(int stock);

	// Imprime la cotizacion generada
	void resultadoCotizacion();

	// Muestra el historial de cotizaciones
	void verHistorial();

	// ASCII GUI - VENTANAS
	 
	// Header del menu principal
	void menuPrincipalHeader();

	// Header del submenu 
	void subMenuCotizarHeader();

	// Ventana seleccionar prenda
	void subMenuCotizarPasoUno();

	// Ventana seleccionar manga
	void subMenuCotizarPasoDosA();

	// Ventana seleccionar cuello
	void subMenuCotizarPasoDosB();

	// Ventana seleccionar tipo de pantalon
	void subMenuCotizarPasoDosC();

	// Ventana seleccionar calidad
	void subMenuCotizarPasoTres();

	// Ventana ingresar precio unitario
	void subMenuCotizarPasoCuatro();

	// Ventana ingresar cantidad
	void subMenuCotizarPasoCinco(int stock);

	// Header del historial
	void subMenuHistorialHeader();

	// Footer de la ventana
	void subMenuFooter();
};

