#include "tanquecentral.h"

TanqueCentral::TanqueCentral(double capReg, double capPrem, double capEco) :
    capacidadRegular(capReg), capacidadPremium(capPrem), capacidadEcoExtra(capEco),
    disponibleRegular(capReg), disponiblePremium(capPrem), disponibleEcoExtra(capEco) {}

void TanqueCentral::actualizarCombustible(const string& categoria, double cantidad) {
    if (categoria == "Regular") {
        disponibleRegular -= cantidad;
    } else if (categoria == "Premium") {
        disponiblePremium -= cantidad;
    } else if (categoria == "EcoExtra") {
        disponibleEcoExtra -= cantidad;
    }
}

double TanqueCentral::obtenerDisponible(const string& categoria) {
    if (categoria == "Regular") return disponibleRegular;
    if (categoria == "Premium") return disponiblePremium;
    if (categoria == "EcoExtra") return disponibleEcoExtra;
    return 0.0;
}

void TanqueCentral::mostrarEstado() const {
    std::cout << "Combustible Regular: " << disponibleRegular << " litros\n";
    std::cout << "Combustible Premium: " << disponiblePremium << " litros\n";
    std::cout << "Combustible EcoExtra: " << disponibleEcoExtra << " litros\n";
}
