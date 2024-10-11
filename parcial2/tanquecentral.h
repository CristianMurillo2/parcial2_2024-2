#ifndef TANQUECENTRAL_H
#define TANQUECENTRAL_H
#include <string>
#include <iostream>

using namespace std;

class TanqueCentral
{
public:
    double capacidadRegular;
    double capacidadPremium;
    double capacidadEcoExtra;
    double disponibleRegular;
    double disponiblePremium;
    double disponibleEcoExtra;

    TanqueCentral(double capReg, double capPrem, double capEco);

    void actualizarCombustible(const string& categoria, double cantidad);
    double obtenerDisponible(const string& categoria);
    void mostrarEstado() const;

};

#endif // TANQUECENTRAL_H
