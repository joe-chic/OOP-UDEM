#include <iostream>
#include <string>
#include "HORA.h"
using namespace std;

class Reserva
{
    string claveServicio;
    int idCliente;
    Hora horaInicio;
    int duracion;

    public:
        Reserva();
        Reserva(string argClave, int argID, Hora argHora, int argDuracion);

        string getClaveServicio() const;
        void setClaveServicio(const string& value);

        int getIdCliente() const;
        void setIdCliente(int value);

        Hora getHoraInicio() const;
        void setHoraInicio(const Hora& value);

        int getDuracion() const;
        void setDuracion(int value);

        Hora calculaHoraFinReservacion();
};

Reserva::Reserva()
{
    claveServicio = "";
    idCliente = 0;
    horaInicio;
    duracion = 0;
}
        
Reserva::Reserva(string argClave, int argID, Hora argHora, int argDuracion)
{
    claveServicio = argClave;
    idCliente = argID;
    horaInicio = argHora;
    duracion = argDuracion;
}

string Reserva::getClaveServicio() const 
{
    return claveServicio;
}

void Reserva::setClaveServicio(const string& value) 
{
    claveServicio = value;
}

int Reserva::getIdCliente() const 
{
    return idCliente;
}

void Reserva::setIdCliente(int value) 
{
    idCliente = value;
}

Hora Reserva::getHoraInicio() const 
{
    return horaInicio;
}

void Reserva::setHoraInicio(const Hora& value) 
{
    horaInicio = value;
}

int Reserva::getDuracion() const 
{
    return duracion;
}

void Reserva::setDuracion(int value)
{
    duracion = value;
}

Hora Reserva::calculaHoraFinReservacion()
{
   Hora resHora;
   resHora = horaInicio + duracion;
   return resHora;
}