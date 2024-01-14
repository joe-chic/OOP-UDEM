#include "CLASES_PROYECTO2_dec.h"

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


// Para la clase COMPUTADORA
Computadora::Computadora()
{
    RAM = 0;
    id = 0;
    BRAND = "";
}
Computadora::Computadora(int argRAM, int ID,string brand)
{
    RAM = argRAM;
    id = ID;
    BRAND = brand;
}
void Computadora::setRAM(int argRAM)
{
    RAM = argRAM;
}
int Computadora::getRAM()
{
    return RAM;
}
void Computadora::setID(int ID)
{
    id = ID;
}
int Computadora::getID()
{
    return id;
}

void Computadora::setBRAND(string brand)
{
    BRAND = brand;
}
string Computadora::getBRAND()
{
    return BRAND;
}
void Computadora::MUESTRA()
{
    cout << "CAPACIDAD: " << RAM << endl;
    cout << "ID: " << id << endl;
    cout << "MARCA: " << BRAND << endl;
};