#ifndef SURTIDOR_H
#define SURTIDOR_H
#include "TanqueCentral.h"
class Surtidor
{
public:
    int codigoIdentificador;
    string modelo;
    double ventasCantidadRegular;
    double ventasCantidadPremium;
    double ventasCantidadEcoExtra;
    int numeroVentas;
    string* fechas;
    string* horas;
    double* cantidades;
    string* categoriasCombustible;
    string* metodosPago;
    string* numerosDocumentoCliente;
    double* totalesDinero;

    Surtidor(int codigo, const string& mod);
    ~Surtidor();

    void registrarVenta(const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente, TanqueCentral& tanque);
    void mostrarVentas();
};

#endif // SURTIDOR_H
