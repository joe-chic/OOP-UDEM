class Edificio
{
    int id, cantLabs, cantSalones, ILA, ISA;
    Laboratorio listaLabs[10];
    Salon listaSalones[10];
    string name, responsable;

    public:
        Edificio();
        Edificio(int argID, Laboratorio argLSTLABS[], Salon argLSTSALONES[], int argQTOLABS, int argQTOSALONES, string argNAME, string argRESPONSABLE);

        void setID(int argID);
        int getID();

        void setNAME(string argNAME);
        string getNAME();

        void setRESPONSABLE(string argRESPONSABLE);
        string getRESPONSABLE();

        void setLSTLABS(Laboratorio argLSTLABS[]);
        Laboratorio (& getLSTLABS())[10];

        void setLSTSALONES(Salon argLSTSALONES[]);
        Salon (& getLSTSALONES())[10];

        void setQTOLABS(int argQTOLABS);
        int getQTOLABS();

        void setQTOSALONES(int argQTOSALONES);
        int getQTOSALONES();

        void setILA(int a);
        int getILA();
        void setISA(int a);
        int getISA();

        bool INCLUIR(Laboratorio LSTLABS, Salon LSTSALONES);
        void MUESTRA();
};


// Para la clase EDIFICIO
Edificio::Edificio()
{
    id = 0;
    name = "";
    responsable = "";
    cantLabs = 0;
    cantSalones = 0;
    ISA = 0;
    ILA = 0;
}
Edificio::Edificio(int argID, Laboratorio argLSTLABS[], Salon argLSTSALONES[], int argQTOLABS, int argQTOSALONES, string argNAME, string argRESPONSABLE)
{
    id = argID;
    name = argNAME;
    responsable = argRESPONSABLE;  
    for(int i = 0; i<argQTOLABS ; i++)
    {
        listaLabs[i] = argLSTLABS[i];
    }   
    for(int i = 0; i<argQTOSALONES; i++)
    {
        listaSalones[i] = argLSTSALONES[i];
    }
    cantLabs = argQTOLABS;
    cantSalones = argQTOSALONES;
}
void Edificio::setID(int argID)
{
    id = argID;
}
int Edificio::getID()
{
    return id;
}
void Edificio::setNAME(string argNAME)
{  
    name = argNAME;
}
string Edificio::getNAME()
{
    return name;
}
void Edificio::setRESPONSABLE(string argRESPONSABLE)
{
    responsable = argRESPONSABLE;
}
string Edificio::getRESPONSABLE()
{
    return responsable;
}
void Edificio::setQTOLABS(int argQTOLABS)
{
    cantLabs = argQTOLABS;
}
int Edificio::getQTOLABS()
{
    return cantLabs;
}
void Edificio::setQTOSALONES(int argQTOSALONES)
{
    cantSalones = argQTOSALONES;
}
int Edificio::getQTOSALONES()
{
    return cantSalones;
}
void Edificio::setLSTLABS(Laboratorio argLSTLABS[])
{
    for(int m = 0; m<getQTOLABS(); m++)
    {
        listaLabs[m] = argLSTLABS[m];
    }
}

Laboratorio (& Edificio::getLSTLABS())[10]
{
    return listaLabs;
}

void Edificio::setLSTSALONES(Salon argLSTSALONES[])
{
    for(int m = 0; m<getQTOSALONES(); m++)
    {
        listaSalones[m] = argLSTSALONES[m];
    }
}

Salon (& Edificio::getLSTSALONES())[10]
{
    return listaSalones;
}

void Edificio::setILA(int a)
{
    ILA = a;
}
int Edificio::getILA()
{
    return ILA;
}
void Edificio::setISA(int a)
{
    ISA = a;
}
int Edificio::getISA()
{
    return ISA;
}

bool Edificio::INCLUIR(Laboratorio LSTLABS, Salon LSTSALONES)
{
    bool res = false;

    if (cantLabs < 10 && cantSalones < 10) {
        if (LSTLABS.getID() != 0) {
            listaLabs[ILA] = LSTLABS;
            ILA++;
            res = true;
        }
        if (LSTSALONES.getID() != 0) {
            listaSalones[ISA] = LSTSALONES;
            ISA++;
            res = true;
        }
    }
    return res;
}

void Edificio::MUESTRA()
{
    cout << "ID: " << id << endl;
    cout << "NOMBRE: " << name << endl;
    cout << "RESPONSABLE: " << responsable << endl;
    cout << "CANT. DE SALONES: " << cantSalones << endl;
    cout << "CANT. DE LABORATORIOS: " << cantSalones << endl;
}
