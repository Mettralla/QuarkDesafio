#include "Camisa.h"

Camisa::Camisa()
{

}

Camisa::~Camisa()
{

}

string Camisa::getCuello()
{
	return this->cuello;
}

void Camisa::setCuello(int eleccion)
{
	if (eleccion == 1)
	{
		this->cuello = "Cuello Mao";
	}
	else 
	{
		this->cuello = "Cuello Comun";
	}
		
}

string Camisa::getManga()
{
	return this->manga;
}

void Camisa::setManga(int eleccion)
{
	if (eleccion == 1)
	{
		this->manga = "Manga Corta";
	}
	else
	{
		this->manga = "Manga Larga";
	}

}