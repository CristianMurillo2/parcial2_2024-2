#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H
#include <string>
using namespace std;
#include "TanqueCentral.h"
#include "Surtidor.h"

class EstacionServicio
{
private:
    string nombre;
    string codigoIdentificador;
    string gerente;
    string region;
    double coordenadasGPS[2];
    TanqueCentral* tanque;
    Surtidor** surtidores;
    int numeroSurtidores;

public:
    EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region, double latitud, double longitud, TanqueCentral* tanqueCentral, int numSurtidores);
    ~EstacionServicio();
    string getNombre() const;
    string getCodigoIdentificador() const;
    string getGerente() const;
    string getRegion() const;
    double getLatitud() const;
    double getLongitud() const;
    TanqueCentral* getTanque() const;
    Surtidor** getSurtidores() const;
    int getNumeroSurtidores() const;
    void setNombre(const string& nombre);
    void setCodigoIdentificador(const string& codigo);
    void setGerente(const string& gerente);
    void setRegion(const string& region);
    void setCoordenadas(double latitud, double longitud);
    void setTanque(TanqueCentral* tanqueCentral);
    static EstacionServicio** eliminarEstacion(EstacionServicio** estaciones, int& numeroEstaciones, const string& codigo);
    static EstacionServicio** agregarEstacion(EstacionServicio** estaciones, int& numeroEstaciones, EstacionServicio* nuevaEstacion);
    void agregarSurtidor(Surtidor* nuevoSurtidor);
    void eliminarSurtidor(int codigoIdentificador);
    void mostrarInformacion() const;
    friend ostream& operator<<(ostream& os, const EstacionServicio& estacion);
};

#endif // ESTACIONSERVICIO_H
