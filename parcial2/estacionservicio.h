#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H
#include <string>
using namespace std;
#include "TanqueCentral.h"
#include "Surtidor.h"

class EstacionServicio
{
public:
    string nombre;
    int codigoIdentificador;
    string gerente;
    string region;
    double coordenadasGPS[2];
    TanqueCentral tanqueCentral;
    Surtidor** surtidores;
    int numeroSurtidores;
    int capacidadSurtidores;
    EstacionServicio(string nom, int cod, string ger, string reg, double coordGPS[2], TanqueCentral tanque, int capacidad);
    void agregarSurtidor(Surtidor* surtidor);
    void registrarVenta(int codigoSurtidor, const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente);
    void mostrarEstadoTanque();
    ~EstacionServicio();

};

#endif // ESTACIONSERVICIO_H
