#include "View.h"

View::View() {
	
}

View::~View() {
	delete presenter;
}

void View::menuPrincipal()
{
	system("cls");
	int eleccion = 0;
	while (eleccion == 0)
	{
		system("cls");
		menuPrincipalHeader();
		eleccion = presenter->getEleccion();
		switch (eleccion)
		{
		case 1:
			verHistorial();
			eleccion = 0;
			break;
		case 2:
			realizarCotizacion();
			eleccion = 0;
			break;
		case 3:
			break;
		}
	}
}

void View::verHistorial()
{
	int eleccion = 0;
	system("cls");
	subMenuCotizarHeader();
	if (presenter->vendedor->getHistorial().empty())
	{
		cout << "|                                                        |" << endl;
		cout << "| OOPS! TODAVIA NO HA REALIZADO NINGUNA COTIZACION.      |" << endl;
		cout << "|                                                        |" << endl;
	}
	else
	{
		cout << endl;
		cout << endl;
		presenter->vendedor->imprimirHistorial();
	}
	subMenuFooter();
	while (eleccion != 3)
	{
		while (true)
		{
			cout << "Ingresar 3 para volver: ";
			cin >> eleccion;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Valor invalido, por favor intente otra vez" << endl;
				cout << "Enter para continuar --->" << endl;
				_getch();
				continue;
			}
			else break;
		}
	}
}

void View::realizarCotizacion()
{
	bool esCamisa = false;
	bool esMangaCorta = false;
	bool esCuelloMao = false;
	bool esChupin = false;
	bool esStandard = false;
	double precioUnitario = 0;
	int stock = 0;
	int cantCotizar = 0;
	
	// Elige la prenda
	cotizarPsUno(&esCamisa);

	if (esCamisa)
	{
		// Es manga corta?
		cotizarPsDosA(&esMangaCorta);
		// Es cuello mao?
		cotizarPsDosB(&esCuelloMao);
	}
	else
	{
		// Es chupin?
		cotizarPsDosC(&esChupin);
	}

	// Es standard?
	cotizarPsTres(&esStandard);

	// Precio Unitario
	cotizarPsCuatro();
	while (true)
	{
		cout << "Ingresar precio: ";
		cin >> precioUnitario;
		if (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Valor invalido, por favor intente otra vez" << endl;
			cout << "Enter para continuar --->" << endl;
			_getch();
			continue;
		}
		else break;
	}
	if (precioUnitario == 3)
	{
		menuPrincipal();
	}

	// Stock
	stock = presenter->getStock(esCamisa, esMangaCorta, esCuelloMao, esChupin, esStandard);

	while (true)
	{
		cotizarPsCinco(stock);
		while (true)
		{
			cout << "Ingresar cantidad de unidades: ";
			cin >> cantCotizar;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Valor invalido, por favor intente otra vez" << endl;
				cout << "Enter para continuar --->" << endl;
				_getch();
				continue;
			}
			else break;
		}
		if (cantCotizar == 3)
		{
			menuPrincipal();
		}
		if (stock >= cantCotizar)
		{
			break;
		}
		else
		{
			cout << "No se puede realizar una cotizacion sobre una cantidad de stock no disponible." << endl;
			cout << "Enter para continuar --->";
			_getch();
		}

	} 

	// Crear Cotizacion
	presenter->crearCotizacion(esCamisa, esMangaCorta, esCuelloMao, esChupin, esStandard, precioUnitario, cantCotizar);
	resultadoCotizacion();
}

void View::asignarEleccion(bool* opcion)
{
	int eleccion = presenter->getEleccion();
	if (eleccion == 1 || eleccion == 2)
	{
		*opcion = presenter->elegirPrenda(eleccion);
	}
	else
	{
		menuPrincipal();
	}
}

void View::cotizarPsUno(bool* esCamisa)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoUno();
	asignarEleccion(esCamisa);
}

void View::cotizarPsDosA(bool* esMangaCorta)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoDosA();
	asignarEleccion(esMangaCorta);
}

void View::cotizarPsDosB(bool* esCuelloMao)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoDosB();
	asignarEleccion(esCuelloMao);
}

void View::cotizarPsDosC(bool* esChupin)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoDosC();
	asignarEleccion(esChupin);
}

void View::cotizarPsTres(bool* esStandard)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoTres();
	asignarEleccion(esStandard);
}

void View::cotizarPsCuatro()
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoCuatro();
}

void View::cotizarPsCinco(int stock)
{
	system("cls");
	subMenuCotizarHeader();
	subMenuCotizarPasoCinco(stock);
}

void View::resultadoCotizacion()
{
	int eleccion = 0;
	system("cls");
	subMenuCotizarHeader();
	presenter->vendedor->getHistorial().back()->imprimirCotizacion();
	subMenuFooter();
	while (eleccion != 3)
	{
		while (true)
		{
			cout << "Ingresar 3 para volver: ";
			cin >> eleccion;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Valor invalido, por favor intente otra vez" << endl;
				cout << "Enter para continuar --->" << endl;
				_getch();
				continue;
			}
			else break;
		}
	}
}

void View::menuPrincipalHeader()
{
	cout << " -------------------------------------------------------- " << endl;
	cout << "|          COTIZADOR EXPRESS - MENU PRINCIPAL            |" << endl;
	cout << " -------------------------------------------------------- " << endl;
	cout << " TIENDA: " << presenter->tienda->getNombre() << " | DIRECCION: " << presenter->tienda->getDireccion() << endl;
	cout << " -------------------------------------------------------- " << endl;
	cout << " VENDEDOR: " << presenter->vendedor->getNombreCompleto() << " | CODIGO: " << presenter->vendedor->getCodigoVendedor() << endl;
	cout << " -------------------------------------------------------- " << endl;
	cout << "|                                                        |" << endl;
	cout << "| SELECCIONE UNA OPCION DEL MENU:                        |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Historial de Cotizaciones                           |" << endl;
	cout << "| 2) Realizar Cotizacion                                 |" << endl;
	cout << "| 3) Salir                                               |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}


void View::subMenuCotizarHeader()
{
	cout << " -------------------------------------------------------- " << endl;
	cout << "|              COTIZADOR EXPRESS - COTIZAR               |" << endl;
	cout << " -------------------------------------------------------- " << endl;
	cout << "| PRESIONE 3 PARA VOLVER AL MENU PRINCIPAL               |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoUno()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 1: SELECIONAR LA PRENDA QUE DESEA COTIZAR:        |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Camisa                                              |" << endl;
	cout << "| 2) Pantalon                                            |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoDosA()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 2.A: LA CAMISA A COTIZAR, ES MANGA CORTA?         |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Si                                                  |" << endl;
	cout << "| 2) No                                                  |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoDosB()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 2.B: LA CAMISA A COTIZAR, ES CUELLO MAO?          |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Si                                                  |" << endl;
	cout << "| 2) No                                                  |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoDosC()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 2: EL PANTALON A COTIZAR, ES CHUPIN?              |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Si                                                  |" << endl;
	cout << "| 2) No                                                  |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoTres()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 3: SELECCIONE LA CALIDAD DE LA PRENDA             |" << endl;
	cout << "|                                                        |" << endl;
	cout << "| 1) Standard                                            |" << endl;
	cout << "| 2) Premium                                             |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoCuatro()
{
	cout << "|                                                        |" << endl;
	cout << "| PASO 4: INGRESE EL PRECIO UNITARIO DE LA PRENDA        |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuCotizarPasoCinco(int stock)
{
	cout << "|                                                        |" << endl;
	cout << "| INFORMACION:                                           |" << endl;
	cout << "| EXISTEN " << stock << " UDS EN STOCK DE LA PRENDA SELECCIONADA     | " << endl;
	cout << "|                                                        |" << endl;
	cout << "| PASO 5: INGRESE LA CANTIDAD DE UNIDADES A COTIZAR      |" << endl;
	cout << "|                                                        |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuHistorialHeader()
{
	cout << " -------------------------------------------------------- " << endl;
	cout << "|      COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES     |" << endl;
	cout << " -------------------------------------------------------- " << endl;
	cout << "| PRESIONE 3 PARA VOLVER AL MENU PRINCIPAL               |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

void View::subMenuFooter()
{
	cout << " -------------------------------------------------------- " << endl;
	cout << "| PRESIONE 3 PARA VOLVER AL MENU PRINCIPAL               |" << endl;
	cout << " -------------------------------------------------------- " << endl;
}

