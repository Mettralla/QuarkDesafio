#include "Cotizacion.h"
int Cotizacion::contador = 0;

Cotizacion::Cotizacion(string codigoVendedor, Prenda* prenda, int unidades)
{
    setId();
    setFechaHora();
    this->codigoVendedor = codigoVendedor;
    this->prenda = prenda;
    this->unidades = unidades;
    setTotalCotizacion(prenda->getPrecioUnitario(), unidades);
};

void Cotizacion::setId()
{
    this->id = ++contador;
};

int Cotizacion::getId()
{
    return this->id;
};

void Cotizacion::setFechaHora()
{
    // Representar el tiempo.
    time_t timer = time(0);
    // Buffer almacenamiento
    tm bt{};

    // Convierte el timer en tiempo calendario y lo guarda en bt.
    localtime_s(&bt, &timer);

    char fechaString[20];
    const string& fmt = "%d/%m/%Y %H:%M";

    this->fechaHora = { fechaString, strftime(fechaString, sizeof fechaString, fmt.c_str(), &bt) };
};

string Cotizacion::getFechaHora()
{
    return this->fechaHora;
};

void Cotizacion::setCodigoVendedor(string nuevoCodigo)
{
    this->codigoVendedor = nuevoCodigo;
};

string Cotizacion::getCodigoVendedor()
{
    return this->codigoVendedor;
};

void Cotizacion::setPrenda(Prenda* nuevaPrenda)
{
    this->prenda = nuevaPrenda;
};

Prenda* Cotizacion::getPrenda()
{
    return this->prenda;
};

void Cotizacion::setUnidades(int nuevasUnidades)
{
    this->unidades = nuevasUnidades;
};

int Cotizacion::getUnidades()
{
    return this->unidades;
};

void Cotizacion::setTotalCotizacion(double precioUnitario, int unidades)
{
    double precioProcesado = precioUnitario;
    if (this->prenda->getNombre() == "Camisa")
    {
        precioProcesado = this->prenda->getManga() == "Manga Corta" ? precioProcesado - precioProcesado * 0.1 : precioProcesado;
        precioProcesado = this->prenda->getCuello() == "Cuello Mao" ? precioProcesado + precioProcesado * 0.03 : precioProcesado;
    }
    else
    {
        precioProcesado = this->prenda->getTipo() == "Chupin" ? precioProcesado - precioProcesado * 0.12 : precioProcesado;
    }
    precioProcesado = this->prenda->getCalidad() == "Premium" ? precioProcesado + precioProcesado * 0.3 : precioProcesado;
    this->totalCotizacion = precioProcesado * unidades;
}

double Cotizacion::getTotalCotizacion()
{
    return this->totalCotizacion;
};

string Cotizacion::getCaracteristicas()
{
    string tipo = this->prenda->getNombre() == "Camisa" ? this->prenda->getManga() + " - " + this->prenda->getCuello() : this->prenda->getTipo();
    return this->prenda->getNombre() + " - " + tipo + " - " + this->prenda->getCalidad();
};

void Cotizacion::imprimirCotizacion()
{
    cout << " Numero de identificacion: " << getId() << endl;
    cout << " Fecha y Hora de la cotizacion: " << getFechaHora() << endl;
    cout << " Codigo del Vendedor: " << getCodigoVendedor() << endl;
    cout << " Prenda Cotizada: " << getCaracteristicas() << endl;
    cout << " Precio unitario: " << getPrenda()->getPrecioUnitario() << endl;
    cout << " Cantidad de unidades cotizadas: " << getPrenda()->getUnidades() << endl;
    cout << " Precio Final: " << getTotalCotizacion() << endl;
};
