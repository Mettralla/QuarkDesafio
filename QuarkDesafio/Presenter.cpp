#include "Presenter.h"

Presenter::Presenter() {
	inicializarTienda();
}

Presenter::~Presenter() {
	delete tienda;
	delete vendedor;
}

void Presenter::inicializarTienda()
{
	this->tienda = new Tienda("Timberland", "Avellaneda 450");
	this->vendedor = new Vendedor("John", "Doe", "M-1202");
}

int Presenter::getEleccion()
{
	int eleccion = 0;
	while (eleccion == 0)
	{
		cout << "Ingresar su eleccion: "; 
		cin >> eleccion;
		if (eleccion > 0 && eleccion <= 3)
		{
			break;
		}
		else
		{
			cout << "Ingresar una opcion valida" << endl;
			eleccion = 0;
		}
	}
	return eleccion;
}

bool Presenter::elegirPrenda(int eleccion)
{
	return eleccion == 1 ? true : false;
}

int Presenter::getStock(bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, bool esStandard)
{
	if (esCamisa)
	{
		if (esMangaCorta)
		{
			if (esCuelloMao)
			{
				return esStandard ? tienda->getStock(3, 0) : tienda->getStock(3, 1);
			}
			else
			{
				return esStandard ? tienda->getStock(4, 0) : tienda->getStock(4, 1);
			}
		}
		else
		{
			if (esCuelloMao)
			{
				return esStandard ? tienda->getStock(6, 0) : tienda->getStock(6, 1);
			}
			else
			{
				return esStandard ? tienda->getStock(7, 0) : tienda->getStock(7, 1);
			}
		}
	}
	else
	{
		if (esChupin)
		{
			return esStandard ? tienda->getStock(9, 0) : tienda->getStock(9, 1);
		}
		else
		{
			return esStandard ? tienda->getStock(10, 0) : tienda->getStock(10, 1);
		}
	}
}

void Presenter::crearCotizacion(bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, bool esStandard, double precioUnitario, int cantCotizar)
{
	string manga = esMangaCorta ? "Manga Corta" : "Manga Larga";
	string cuello = esCuelloMao ? "Cuello Mao" : "Cuello Normal";
	string tipo = esChupin ? "Chupin" : "Comun";
	string calidad = esStandard ? "Standard" : "Premium";
	if (esCamisa)
	{
		Camisa* nuevaCamisa = new Camisa(manga, cuello, calidad, precioUnitario, cantCotizar);
		Cotizacion* nuevaCotizacion = new Cotizacion(vendedor->getCodigoVendedor(), nuevaCamisa, cantCotizar);
		vendedor->addCotizacion(nuevaCotizacion);
	}
	else
	{
		Pantalon* nuevoPantalon = new Pantalon(tipo, calidad, precioUnitario, cantCotizar);
		Cotizacion* nuevaCotizacion = new Cotizacion(vendedor->getCodigoVendedor(), nuevoPantalon, cantCotizar);
		vendedor->addCotizacion(nuevaCotizacion);
	}
}