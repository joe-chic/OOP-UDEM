#include <iostream>
#include <string>
using namespace std;

#ifndef SERVICIO_H
#define SERVICIO_H

class Servicio
{
    protected:
        string clave;
        int tiempoMax;
        char Tipo;

    public:
        Servicio();
        Servicio(const string& c, int t, char T);

        string getClave() const;
        void setClave(const string& c);

        int getTiempoMax() const;
        void setTiempoMax(int t);

        char getTipo() const;
        void setTipo(char T);
        virtual void muestra() = 0;
        virtual double calculaCosto(int tiempo) = 0;
};

Servicio::Servicio()
{
    clave = "";
    tiempoMax = 0;
    Tipo = ' ';
}

Servicio::Servicio(const string& c, int t, char T)
{
    clave = c;
    tiempoMax = t;
    Tipo = T;
}

void Servicio::setClave(const string& c)
{
    clave = c;
}
string Servicio::getClave() const
{
    return clave;
}
int Servicio::getTiempoMax() const
{
    return tiempoMax;
}

void Servicio::setTiempoMax(int t)
{
    tiempoMax = t;
}

char Servicio::getTipo() const
{
    return Tipo;
}

void Servicio::setTipo(char T)
{
    Tipo = T;
}

#endif