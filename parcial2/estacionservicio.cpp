#include "estacionservicio.h"
EstacionServicio::EstacionServicio(const string& nom, const string& codigo, const string& ger, const string& reg, double latitud, double longitud, TanqueCentral* tanqueCentral, int numSurtidores)
    : nombre(nom), codigoIdentificador(codigo), gerente(ger), region(reg), tanque(tanqueCentral), numeroSurtidores(numSurtidores) {
    coordenadasGPS[0] = latitud;
    coordenadasGPS[1] = longitud;
        surtidores = new Surtidor*[numeroSurtidores];
    for (int i = 0; i < numeroSurtidores; i++) {
        surtidores[i] = nullptr;
    }
}

// Destructor
EstacionServicio::~EstacionServicio() {
    for (int i = 0; i < numeroSurtidores; i++) {
        delete surtidores[i];
    }
    delete[] surtidores;
}

string EstacionServicio::getNombre() const { return nombre; }
string EstacionServicio::getCodigoIdentificador() const { return codigoIdentificador; }
string EstacionServicio::getGerente() const { return gerente; }
string EstacionServicio::getRegion() const { return region; }
double EstacionServicio::getLatitud() const { return coordenadasGPS[0]; }
double EstacionServicio::getLongitud() const { return coordenadasGPS[1]; }
TanqueCentral* EstacionServicio::getTanque() const { return tanque; }
Surtidor** EstacionServicio::getSurtidores() const { return surtidores; }
int EstacionServicio::getNumeroSurtidores() const { return numeroSurtidores; }

void EstacionServicio::setNombre(const string& nom) { nombre = nom; }
void EstacionServicio::setCodigoIdentificador(const string& codigo) { codigoIdentificador = codigo; }
void EstacionServicio::setGerente(const string& ger) { gerente = ger; }
void EstacionServicio::setRegion(const string& reg) { region = reg; }
void EstacionServicio::setCoordenadas(double latitud, double longitud) {
    coordenadasGPS[0] = latitud;
    coordenadasGPS[1] = longitud;
}
void EstacionServicio::setTanque(TanqueCentral* tanqueCentral) { tanque = tanqueCentral; }

void EstacionServicio::agregarSurtidor(Surtidor* surtidor, int index) {
    if (index >= 0 && index < numeroSurtidores) {
        surtidores[index] = surtidor;
    }
}

void EstacionServicio::mostrarInformacion() const {
    cout << "Nombre de la Estación: " << nombre << "\n";
    cout << "Código: " << codigoIdentificador << "\n";
    cout << "Gerente: " << gerente << "\n";
    cout << "Región: " << region << "\n";
    cout << "Coordenadas: (" << coordenadasGPS[0] << ", " << coordenadasGPS[1] << ")\n";
    tanque->mostrarEstado();
    for (int i = 0; i < numeroSurtidores; i++) {
        if (surtidores[i] != nullptr) {
            cout << *surtidores[i];
        }
    }
}
EstacionServicio** EstacionServicio::eliminarEstacion(EstacionServicio** estaciones, int& numeroEstaciones, const string& codigo) {
    for (int i = 0; i < numeroEstaciones; i++) {
        if (estaciones[i]->getCodigoIdentificador() == codigo) {
            bool tieneSurtidores = false;
            for (int j = 0; j < estaciones[i]->getNumeroSurtidores(); j++) {
                if (estaciones[i]->getSurtidores()[j] != nullptr) {
                    tieneSurtidores = true;
                    break;
                }
            }
            if (tieneSurtidores) {
                cout << "Error: No se puede eliminar la estación con código " << codigo
                          << " porque aún tiene surtidores asignados.\n";
                return estaciones;
            }
            delete estaciones[i];
            EstacionServicio** nuevoArreglo = new EstacionServicio*[numeroEstaciones - 1];
            int indiceNuevo = 0;
            for (int j = 0; j < numeroEstaciones; j++) {
                if (j != i) {
                    nuevoArreglo[indiceNuevo] = estaciones[j];
                    indiceNuevo++;
                }
            }
            numeroEstaciones--;
            delete[] estaciones;
            cout << "Estación eliminada exitosamente.\n";
            return nuevoArreglo;
        }
    }
    cout << "Error: No se encontró la estación con código " << codigo << ".\n";
    return estaciones;
}

EstacionServicio** EstacionServicio::agregarEstacion(EstacionServicio** estaciones, int& numeroEstaciones, EstacionServicio* nuevaEstacion) {
    for (int i = 0; i < numeroEstaciones; i++) {
        double latitudExistente = estaciones[i]->getLatitud();
        double longitudExistente = estaciones[i]->getLongitud();
        if (nuevaEstacion->getLatitud() == latitudExistente && nuevaEstacion->getLongitud() == longitudExistente) {
            cout << "Error: Ya existe una estación en las coordenadas ("
                      << nuevaEstacion->getLatitud() << ", "
                      << nuevaEstacion->getLongitud() << ").\n";
            return estaciones;
        }
    }
        EstacionServicio** nuevoArreglo = new EstacionServicio*[numeroEstaciones + 1];
    for (int i = 0; i < numeroEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }
    nuevoArreglo[numeroEstaciones] = nuevaEstacion;
    numeroEstaciones++;
    delete[] estaciones;
    cout << "Estación agregada exitosamente.\n";
    return nuevoArreglo;
}
ostream& operator<<(ostream& os, const EstacionServicio& estacion) {
    os << "Nombre de la Estación: " << estacion.getNombre() << "\n";
    os << "Código: " << estacion.getCodigoIdentificador() << "\n";
    os << "Gerente: " << estacion.getGerente() << "\n";
    os << "Región: " << estacion.getRegion() << "\n";
    os << "Coordenadas: (" << estacion.getLatitud() << ", " << estacion.getLongitud() << ")\n";
    os << *estacion.getTanque();  // Usamos el operador << sobrecargado de TanqueCentral

    for (int i = 0; i < estacion.getNumeroSurtidores(); i++) {
        if (estacion.getSurtidores()[i] != nullptr) {
            os << *estacion.getSurtidores()[i];  // Usamos el operador << sobrecargado de Surtidor
        }
    }

    return os;
}
