#include "surtidor.h"

Surtidor::Surtidor(int codigo, const std::string& mod) :
    codigoIdentificador(codigo), modelo(mod), ventasCantidadRegular(0.0), ventasCantidadPremium(0.0), ventasCantidadEcoExtra(0.0), numeroVentas(0) {
    fechas = new std::string[100];
    horas = new std::string[100];
    cantidades = new double[100];
    categoriasCombustible = new std::string[100];
    metodosPago = new std::string[100];
    numerosDocumentoCliente = new std::string[100];
    totalesDinero = new double[100];
}

Surtidor::~Surtidor() {
    delete[] fechas;
    delete[] horas;
    delete[] cantidades;
    delete[] categoriasCombustible;
    delete[] metodosPago;
    delete[] numerosDocumentoCliente;
    delete[] totalesDinero;
}

// Getters
int Surtidor::getCodigoIdentificador() const { return codigoIdentificador; }
string Surtidor::getModelo() const { return modelo; }
double Surtidor::getVentasCantidadRegular() const { return ventasCantidadRegular; }
double Surtidor::getVentasCantidadPremium() const { return ventasCantidadPremium; }
double Surtidor::getVentasCantidadEcoExtra() const { return ventasCantidadEcoExtra; }
int Surtidor::getNumeroVentas() const { return numeroVentas; }

// Setters
void Surtidor::setVentasCantidadRegular(double cantidad) { ventasCantidadRegular = cantidad; }
void Surtidor::setVentasCantidadPremium(double cantidad) { ventasCantidadPremium = cantidad; }
void Surtidor::setVentasCantidadEcoExtra(double cantidad) { ventasCantidadEcoExtra = cantidad; }
void Surtidor::incrementarNumeroVentas() { numeroVentas++; }

void Surtidor::registrarVenta(const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente, TanqueCentral& tanque) {
    if (numeroVentas < 100) {
        if (categoriaCombustible == "Regular" && tanque.getDisponibleRegular() >= cantidad) {
            tanque.actualizarCombustible(categoriaCombustible, cantidad);
            ventasCantidadRegular += cantidad;
        } else if (categoriaCombustible == "Premium" && tanque.getDisponiblePremium() >= cantidad) {
            tanque.actualizarCombustible(categoriaCombustible, cantidad);
            ventasCantidadPremium += cantidad;
        } else if (categoriaCombustible == "EcoExtra" && tanque.getDisponibleEcoExtra() >= cantidad) {
            tanque.actualizarCombustible(categoriaCombustible, cantidad);
            ventasCantidadEcoExtra += cantidad;
        } else {
            cout << "No hay suficiente combustible disponible para completar la venta.\n";
            return;
        }

        fechas[numeroVentas] = fecha;
        horas[numeroVentas] = hora;
        cantidades[numeroVentas] = cantidad;
        categoriasCombustible[numeroVentas] = categoriaCombustible;
        metodosPago[numeroVentas] = metodoPago;
        numerosDocumentoCliente[numeroVentas] = numeroDocumentoCliente;
        totalesDinero[numeroVentas] = cantidad * 5000.0;
        incrementarNumeroVentas();
    }
}

void Surtidor::mostrarVentas() const {
    for (int i = 0; i < numeroVentas; ++i) {
        cout << "Fecha: " << fechas[i] << ", Hora: " << horas[i]
                  << ", Cantidad: " << cantidades[i] << " litros, Categoria: " << categoriasCombustible[i]
                  << ", Metodo de Pago: " << metodosPago[i] << ", Documento: " << numerosDocumentoCliente[i]
                  << ", Total Dinero: $" << totalesDinero[i] << "\n";
    }
}
ostream& operator<<(ostream& os, const Surtidor& surtidor) {
    os << "Surtidor " << surtidor.getCodigoIdentificador() << " (" << surtidor.getModelo() << "):\n";
    os << "Ventas Regular: " << surtidor.getVentasCantidadRegular() << " litros\n";
    os << "Ventas Premium: " << surtidor.getVentasCantidadPremium() << " litros\n";
    os << "Ventas EcoExtra: " << surtidor.getVentasCantidadEcoExtra() << " litros\n";
    return os;
}
