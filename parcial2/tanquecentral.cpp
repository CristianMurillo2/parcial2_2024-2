#include "tanquecentral.h"

TanqueCentral::TanqueCentral(double capReg, double capPrem, double capEco) :
    capacidadRegular(capReg), capacidadPremium(capPrem), capacidadEcoExtra(capEco),
    disponibleRegular(capReg), disponiblePremium(capPrem), disponibleEcoExtra(capEco) {}

double TanqueCentral::getCapacidadRegular() const { return capacidadRegular; }
double TanqueCentral::getCapacidadPremium() const { return capacidadPremium; }
double TanqueCentral::getCapacidadEcoExtra() const { return capacidadEcoExtra; }
double TanqueCentral::getDisponibleRegular() const { return disponibleRegular; }
double TanqueCentral::getDisponiblePremium() const { return disponiblePremium; }
double TanqueCentral::getDisponibleEcoExtra() const { return disponibleEcoExtra; }

// Setters
void TanqueCentral::setDisponibleRegular(double cantidad) { disponibleRegular = cantidad; }
void TanqueCentral::setDisponiblePremium(double cantidad) { disponiblePremium = cantidad; }
void TanqueCentral::setDisponibleEcoExtra(double cantidad) { disponibleEcoExtra = cantidad; }

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
    cout << "Combustible Regular: " << disponibleRegular << " litros\n";
    cout << "Combustible Premium: " << disponiblePremium << " litros\n";
    cout << "Combustible EcoExtra: " << disponibleEcoExtra << " litros\n";
}
ostream& operator<<(ostream& os, const TanqueCentral& tanque) {
    os << "Combustible Regular: " << tanque.disponibleRegular << " litros\n";
    os << "Combustible Premium: " << tanque.disponiblePremium << " litros\n";
    os << "Combustible EcoExtra: " << tanque.disponibleEcoExtra << " litros\n";
    return os;
}
