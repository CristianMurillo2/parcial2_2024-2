#include "surtidor.h"

Surtidor::Surtidor(int codigo, const string& mod) :
    codigoIdentificador(codigo), modelo(mod), ventasCantidadRegular(0.0), ventasCantidadPremium(0.0), ventasCantidadEcoExtra(0.0), numeroVentas(0) {
    fechas = new string[100];
    horas = new string[100];
    cantidades = new double[100];
    categoriasCombustible = new string[100];
    metodosPago = new string[100];
    numerosDocumentoCliente = new string[100];
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

void Surtidor::registrarVenta(const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente, TanqueCentral& tanque) {
    if (numeroVentas < 100) {
        if (categoriaCombustible == "Regular" && tanque.disponibleRegular >= cantidad) {
            tanque.actualizarCombustible(categoriaCombustible, cantidad);
            ventasCantidadRegular += cantidad;
        } else if (categoriaCombustible == "Premium" && tanque.disponiblePremium >= cantidad) {
            tanque.actualizarCombustible(categoriaCombustible, cantidad);
            ventasCantidadPremium += cantidad;
        } else if (categoriaCombustible == "EcoExtra" && tanque.disponibleEcoExtra >= cantidad) {
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
        numeroVentas++;
    }
}

void Surtidor::mostrarVentas() {
    for (int i = 0; i < numeroVentas; ++i) {
        std::cout << "Fecha: " << fechas[i] << ", Hora: " << horas[i]
                  << ", Cantidad: " << cantidades[i] << " litros, Categoria: " << categoriasCombustible[i]
                  << ", Metodo de Pago: " << metodosPago[i] << ", Documento: " << numerosDocumentoCliente[i]
                  << ", Total Dinero: $" << totalesDinero[i] << "\n";
    }
}
