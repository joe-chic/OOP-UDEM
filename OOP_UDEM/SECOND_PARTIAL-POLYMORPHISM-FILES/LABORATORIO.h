class Laboratorio
{
    int id, capacidad;
    string name;
    Computadora PC;

    public:
        Laboratorio();
        Laboratorio(int argID, string argNAME, int argCAPACIDAD, Computadora argPC);

        void setID(int argID);
        int getID();

        void setNAME(string argNAME);
        string getNAME();

        void setCAPACIDAD(int argCAPACIDAD);
        int getCAPACIDAD();

        void setPC(Computadora argPC);
        Computadora& getPC();

        void MUESTRA();
};

// Para la clase LABORATORIO
Laboratorio::Laboratorio()
{
    id = 0;
    name = "";
    capacidad = 0;
    PC;
}
Laboratorio::Laboratorio(int argID, string argNAME, int argCAPACIDAD, Computadora argPC)
{
    id = argID;
    name = argNAME;
    capacidad = argCAPACIDAD;
    PC = argPC;
}
void Laboratorio::setID(int argID)
{
    id = argID;
}
int Laboratorio::getID()
{
    return id;
}
void Laboratorio::setNAME(string argNAME)
{
    name = argNAME;
}
string Laboratorio::getNAME()
{
    return name;
}
void Laboratorio::setCAPACIDAD(int argCAPACIDAD)
{
    capacidad = argCAPACIDAD;
}
int Laboratorio::getCAPACIDAD()
{
    return capacidad;
}
void Laboratorio::setPC(Computadora argPC)
{
    PC = argPC;
}
Computadora& Laboratorio::getPC()
{
    return PC;
}
void Laboratorio::MUESTRA()
{
    cout << "ID: " << id << endl;
    cout << "NOMBRE: " << name << endl;
}