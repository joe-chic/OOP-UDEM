class Salon
{
    int id,capacidad;
    string name;
    Computadora PC;

    public:
        Salon();
        Salon(int argID, string argNAME, int argCAPACIDAD, Computadora argPC);

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

// Para la clase SALON
Salon::Salon()
{
    id = 0;
    name = "";
    capacidad = 0;
    PC;
}
Salon::Salon(int argID, string argNAME, int argCAPACIDAD, Computadora argPC)
{
    id = argID;
    name = argNAME;
    capacidad = argCAPACIDAD;
    PC = argPC;
}
void Salon::setID(int argID)
{
    id = argID;
}
int Salon::getID()
{
    return id;
}
void Salon::setNAME(string argNAME)
{
    name = argNAME;
}
string Salon::getNAME()
{
    return name;
}
void Salon::setCAPACIDAD(int argCAPACIDAD)
{
    capacidad = argCAPACIDAD;
}
int Salon::getCAPACIDAD()
{
    return capacidad;
}
void Salon::setPC(Computadora argPC)
{
    PC = argPC;
}
Computadora& Salon::getPC()
{
    return PC;
}

void Salon::MUESTRA()
{
    cout << "ID: " << id << endl;
    cout << "NOMBRE: " << name << endl;
}
