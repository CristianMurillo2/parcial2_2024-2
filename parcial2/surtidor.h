#ifndef SURTIDOR_H
#define SURTIDOR_H
#include "TanqueCentral.h"
#include <fstream>
class Surtidor
{
private:
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

public:
    Surtidor(int codigo, const string& mod);
    ~Surtidor();
    int getCodigoIdentificador() const;
    string getModelo() const;
    double getVentasCantidadRegular() const;
    double getVentasCantidadPremium() const;
    double getVentasCantidadEcoExtra() const;
    int getNumeroVentas() const;
    void setVentasCantidadRegular(double cantidad);
    void setVentasCantidadPremium(double cantidad);
    void setVentasCantidadEcoExtra(double cantidad);
    void incrementarNumeroVentas();    
    void registrarVenta(const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente, TanqueCentral& tanque);
    void mostrarVentas() const;
    friend ostream& operator<<(ostream& os, const Surtidor& surtidor);

private:
    void guardarVentaEnArchivo(const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente, double totalDinero);
};

#endif // SURTIDOR_H
