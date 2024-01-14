#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Computadora
{
    int id, RAM;
    string BRAND;

    public:
        Computadora();
        Computadora(int argRAM, int id, string brand);

        void setRAM(int argRAM);
        int getRAM();

        void setID(int ID);
        int getID();

        void setBRAND(string brand);
        string getBRAND();

        void MUESTRA();      
};

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
