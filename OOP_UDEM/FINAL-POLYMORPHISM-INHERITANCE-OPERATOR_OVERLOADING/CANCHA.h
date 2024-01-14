#include "SERVICIO.h"

class Cancha : public Servicio
{
    double costoXHr;
    int cantMaxPers;
    string deporte; //puede tener mas de una palabra

    public:
        Cancha();
        Cancha(double argCosto, int argCantMax, string argDeporte, const string& c, int t, char T);

        double getCostoXHr();
        void setCostoXHr(double value);

        int getCantMaxPers();
        void setCantMaxPers(int value);

        string getDeporte();
        void setDeporte(const string& value);

        void muestra() override;
        double calculaCosto(int tiempo) override;
};

Cancha::Cancha() : Servicio()
{
    costoXHr = 0;
    cantMaxPers = 0;
    deporte = "";
}
Cancha::Cancha(double argCosto, int argCantMax, string argDeporte, const string& c, int t, char T) : Servicio(c,t,T)
{
    costoXHr = argCosto;
    cantMaxPers = argCantMax;
    deporte = argDeporte;
}

double Cancha::getCostoXHr()
{
    return costoXHr;
}

void Cancha::setCostoXHr(double value)
{
    costoXHr = value;
}

int Cancha::getCantMaxPers()
{
    return cantMaxPers;
}

void Cancha::setCantMaxPers(int value)
{
    cantMaxPers = value;
}

string Cancha::getDeporte()
{
    return deporte;
}

void Cancha::setDeporte(const string& value)
{
    deporte = value;
}

void Cancha::muestra() //datos que se heredan y los propios
{
    cout << "La clave es: " << clave << endl;
    cout << "El tiempo maximo es: " << tiempoMax << " min" << endl;
    
    cout << "El tipo de servicio es: ";
    if(Tipo == 'C')
        cout << "caminadora" << endl;
    else if(Tipo == 'E')
        cout << "escaladora" << endl;
    else if(Tipo == 'B')
        cout << "bicicleta" << endl;
    else if(Tipo == 'T')
        cout << "cancha de tenis" << endl;
    else if(Tipo == 'F')
        cout << "cancha de froton" << endl;
    else if(Tipo == 'V')
        cout << "cancha de volley ball" << endl;

    cout << "Costo por hora: " << costoXHr << "$" << endl;
    cout << "La cantidad maxima de personas es: " << cantMaxPers << endl;
    cout << "Deporte: " << deporte << endl;
}

double Cancha::calculaCosto(int tiempo)
{
    double ans;
    if(tiempo % 60 == 0)
        ans = costoXHr*(tiempo/60);
    else
        ans = costoXHr*(tiempo/60 + 1);
    
    return ans;
}