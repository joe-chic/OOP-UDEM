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
}