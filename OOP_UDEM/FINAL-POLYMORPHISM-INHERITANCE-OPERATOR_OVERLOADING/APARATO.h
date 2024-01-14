#include "SERVICIO.h"


class Aparato : public Servicio // deben implementar los métodos abstractos	de la clase	padre (muestra, calculaCosto).
{
    double costoX30min;
    bool conInstructor;
    string descripcion; //puede tener mas de una palabra

    public:
        Aparato();
        Aparato(double argCosto, bool argConInstructor, string argDescripcion, const string& c, int t, char T);

        double getCostoX30min();
        void setCostoX30min(double value);

        bool getConInstructor();
        void setConInstructor(bool value);

        string getDescripcion();
        void setDescripcion(const string& value);

        void muestra() override;
        double calculaCosto(int tiempo) override;
};

//getters and setters, constructor def y par, deben los constructores incluir tambien los datos del servicio?

Aparato::Aparato() : Servicio()
{
    costoX30min = 0;
    conInstructor = false;
    descripcion = "";
}

Aparato::Aparato(double argCosto, bool argConInstructor, string argDescripcion, const string& c, int t, char T) : Servicio(c,t,T)
{
    costoX30min = argCosto;
    conInstructor = argConInstructor;
    descripcion = argDescripcion;
}

double Aparato::getCostoX30min()
{
    return costoX30min;
}

void Aparato::setCostoX30min(double value)
{
    costoX30min = value;
}

bool Aparato::getConInstructor()
{
    return conInstructor;
}

void Aparato::setConInstructor(bool value)
{
    conInstructor = value;
}

string Aparato::getDescripcion()
{
    return descripcion;
}

void Aparato::setDescripcion(const string& value)
{
    descripcion = value;
}

void Aparato::muestra() //datos que se heredan y los propios
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

    cout << "Costo por 30 minutos: " << costoX30min << "$" << endl;
    cout << "Hay instructor: "; 
    (conInstructor)?(cout<<"Si"<<endl):(cout<<"No"<<endl);
    cout << "Descripcion: " << descripcion << endl;
}

double Aparato::calculaCosto(int tiempo)
{       
    double ans;
    if(tiempo % 30 == 0)
        ans = costoX30min*(tiempo/30);
    else
        ans = costoX30min*(tiempo/30 + 1);
   
   return ans;
}