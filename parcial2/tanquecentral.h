#ifndef TANQUECENTRAL_H
#define TANQUECENTRAL_H
#include <string>
#include <iostream>

using namespace std;

class TanqueCentral
{
private:
    double capacidadRegular;
    double capacidadPremium;
    double capacidadEcoExtra;
    double disponibleRegular;
    double disponiblePremium;
    double disponibleEcoExtra;

public:
    TanqueCentral(double capReg, double capPrem, double capEco);

    double getCapacidadRegular() const;
    double getCapacidadPremium() const;
    double getCapacidadEcoExtra() const;
    double getDisponibleRegular() const;
    double getDisponiblePremium() const;
    double getDisponibleEcoExtra() const;
    void setDisponibleRegular(double cantidad);
    void setDisponiblePremium(double cantidad);
    void setDisponibleEcoExtra(double cantidad);
    void actualizarCombustible(const string& categoria, double cantidad);
    double obtenerDisponible(const string& categoria);
    void mostrarEstado() const;
    friend ostream& operator<<(ostream& os, const TanqueCentral& tanque);

};

#endif // TANQUECENTRAL_H
