#include "estacionservicio.h"
EstacionServicio::EstacionServicio(string nom, int cod, string ger, std::string reg, double coordGPS[2], TanqueCentral tanque, int capacidad)
    : nombre(nom), codigoIdentificador(cod), gerente(ger), region(reg), tanqueCentral(tanque), numeroSurtidores(0), capacidadSurtidores(capacidad) {
    coordenadasGPS[0] = coordGPS[0];
    coordenadasGPS[1] = coordGPS[1];
    surtidores = new Surtidor*[capacidadSurtidores];
}

EstacionServicio::~EstacionServicio() {
    for (int i = 0; i < numeroSurtidores; ++i) {
        delete surtidores[i];
    }
    delete[] surtidores;
}

void EstacionServicio::agregarSurtidor(Surtidor* surtidor) {
    if (numeroSurtidores < capacidadSurtidores) {
        surtidores[numeroSurtidores] = surtidor;
        numeroSurtidores++;
    } else {
        std::cout << "Capacidad de surtidores alcanzada.\n";
    }
}

void EstacionServicio::registrarVenta(int codigoSurtidor, const string& fecha, const string& hora, double cantidad, const string& categoriaCombustible, const string& metodoPago, const string& numeroDocumentoCliente) {
    for (int i = 0; i < numeroSurtidores; ++i) {
        if (surtidores[i]->codigoIdentificador == codigoSurtidor) {
            surtidores[i]->registrarVenta(fecha, hora, cantidad, categoriaCombustible, metodoPago, numeroDocumentoCliente, tanqueCentral);
            return;
        }
    }
    std::cout << "Surtidor no encontrado.\n";
}

void EstacionServicio::mostrarEstadoTanque() {
    tanqueCentral.mostrarEstado();
}
