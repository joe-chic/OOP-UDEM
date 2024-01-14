#include "COMPUTADORA.h"
#include "LABORATORIO.h"
#include "SALON.h"
#include "EDIFICIO.h"

void displayComputadoraInfo(Computadora pc, string locationType, string locationName) 
{
    cout << "PC ID: " << pc.getID()
         << " CAPACIDAD: " << pc.getRAM()
         << " LOCALIZADA EN: " << locationType
         << " NOMBRE: " << locationName << endl;
}

void displayAllComputersInfo(Edificio* buildings, int numBuildings) 
{
    for (int i = 0; i < numBuildings; i++) {

        for (int j = 0; j < buildings[i].getQTOLABS(); j++) 
        {
            Laboratorio lab = buildings[i].getLSTLABS()[j];
            Computadora pc = lab.getPC(); 
            displayComputadoraInfo(pc, "LABORATORIO", lab.getNAME());
        }

        for (int k = 0; k < buildings[i].getQTOSALONES(); k++) 
        {
            Salon salon = buildings[i].getLSTSALONES()[k];
            Computadora pc = salon.getPC(); 
            displayComputadoraInfo(pc, "SALON", salon.getNAME());
        }
    }
}

void displayComputersInBuilding(Edificio* buildings, int numBuildings, int targetBuildingID,bool& pass) {
   
    for (int i = 0; i < numBuildings; i++) 
    {
        if (buildings[i].getID() == targetBuildingID) 
        {

            cout << "COMPUTADORS EN LABORATORIOS:\n";
            for (int j = 0; j < buildings[i].getQTOLABS(); j++) 
            {
                Laboratorio lab = buildings[i].getLSTLABS()[j];
                Computadora pc = lab.getPC(); 
                std::cout << "LABORATORIO: " << lab.getNAME() 
                          << " COMPUTADORA ID: " << pc.getID() 
                          << " CAPACIDAD: " << pc.getRAM() << endl;
            }

            cout << "COMPUTADORAS EN SALONES:\n";
            for (int k = 0; k < buildings[i].getQTOSALONES(); k++) 
            {
                Salon salon = buildings[i].getLSTSALONES()[k];
                Computadora pc = salon.getPC(); 
                cout << "SALON: " << salon.getNAME() 
                          << ", COMPUTADORA ID: " << pc.getID() 
                          << ", CAPACIDAD: " << pc.getRAM() << endl;
            }

            pass = false;
            return; 
        }
    }

    cout << "NINGUN EDIFICIO FUE ENCONTRADO CON SU ID: " << targetBuildingID << endl;
}

bool displayComputerLocation(Edificio* buildings, int numBuildings, int targetComputerID,bool& pass) 
{
    for (int i = 0; i < numBuildings; i++) {
        
        for (int j = 0; j < buildings[i].getQTOLABS(); j++) 
        {
            Laboratorio lab = buildings[i].getLSTLABS()[j];
            if (lab.getPC().getID() == targetComputerID) 
            {
                cout << "COMPUTADORA ENCONTRADA EN:\n"
                        << "NO. DE EDIFICIO: " << i+1 
                        << "\nLABORATORIO ID: " << lab.getID()
                        << "\nNOMBRE DEL LABORATORIO: " << lab.getNAME() << endl;
                pass = true; 
                return true;
            }
        }

        for (int k = 0; k < buildings[i].getQTOSALONES(); k++) 
        {
            Salon salon = buildings[i].getLSTSALONES()[k];
            if (salon.getPC().getID() == targetComputerID) 
            {
                    cout  << "COMPUTADORA ENCONTRADA EN:\n"
                          << "NO. DE EDIFICIO: " << i+1 
                          << "\nSALON ID: " << salon.getID()
                          << "\nNOMBRE DEL SALON: " << salon.getNAME() << endl;
                pass = true;
                return true;
            }
        }
    }

    cout << "EL ID NO FUE ENCONTRADO PARA NINGUNA COMPUTADORA: " << targetComputerID << "\n";
    return false;
}

void validateAndDisplayBrandComputers(Edificio buildings[], int numBuildings, Computadora computers[], int numComputers, bool& pass) 
{
    string desiredBrand;
    cout << "INTRODUZCA LA MARCA BUSCADA: ";
    cin >> desiredBrand;

    for (int i = 0; i < numBuildings; i++) 
    {
        int countComputersInBuilding = 0;
        int countComputersInLabs = 0;
        int countComputersInSalones = 0;

        for (int j = 0; j < buildings[i].getQTOLABS(); j++) 
        {
            Laboratorio lab = buildings[i].getLSTLABS()[j];
            int computerId = lab.getPC().getID();
            if (computers[computerId - 1].getBRAND() == desiredBrand) 
            {
                countComputersInBuilding++;
                countComputersInLabs++;
                cout << endl << "EDIFICIO: " << buildings[i].getNAME() << "\nNOMBRE DE LABORATORIO: " << lab.getNAME() << " ID COMPUTADORA: " << computerId << " CAPACIDAD: " << lab.getPC().getRAM() << endl;
                pass = false;
            }
        }

        for (int k = 0; k < buildings[i].getQTOSALONES(); k++) 
        {
            Salon salon = buildings[i].getLSTSALONES()[k];
            int computerId = salon.getPC().getID();
            if (computers[computerId - 1].getBRAND() == desiredBrand) 
            {
                countComputersInBuilding++;
                countComputersInSalones++;
                cout << endl << "EDIFICIO: " << buildings[i].getNAME() << "\nNOMBRE DE SALON: " << salon.getNAME() << " ID COMPUTADORA: " << computerId << " CAPACIDAD: " << salon.getPC().getRAM() << endl;
                pass = false;
            }
        }
    
        cout << "EN EDIFICIO " << buildings[i].getNAME() << ", HAY " << countComputersInBuilding << " COMPUTADORAS DE MARCA " << desiredBrand << ". " << countComputersInLabs << " EN LABORATORIOS Y " << countComputersInSalones << " EN SALONES." << endl;
    }
}

int main()
{
    ifstream lab_file("laboratorios.txt"), salon_file("salones.txt"), pc_file("computadora.txt"), edificio_file("edificios.txt");
    
    Laboratorio LAB[20];
    Salon SALA[20];
    Computadora PC[30];
    Edificio BUILD[4];

    int ident_room,ident_pc, cap, numLAB, numSALA, IDROOM;
    string nom_room,person_build, BRA;

    for(int i = 0; pc_file >> ident_pc >> cap >> BRA; i++)
    {
        PC[i].setID(ident_pc);
        PC[i].setRAM(cap);
        PC[i].setBRAND(BRA);
    }

    for(int i = 0; lab_file >> ident_room >> nom_room >> cap >> ident_pc; i++)
    {
        LAB[i].setID(ident_room);
        LAB[i].setNAME(nom_room);
        LAB[i].getPC().setRAM(cap);
        LAB[i].getPC().setID(ident_pc);
        SALA[i].getPC().setBRAND(PC[i].getBRAND());
    }

    for(int i = 0; salon_file >> ident_room >> nom_room >> cap >> ident_pc; i++)
    {
        SALA[i].setID(ident_room);
        SALA[i].setNAME(nom_room);
        SALA[i].getPC().setRAM(cap);
        SALA[i].getPC().setID(ident_pc);
        SALA[i].getPC().setBRAND(PC[10+i].getBRAND());
    }

    for(int i = 0; edificio_file >> ident_room >> nom_room; i++)
    {
        BUILD[i].setID(ident_room);
        BUILD[i].setNAME(nom_room);
       
        edificio_file >> numLAB;

        for(int j = 0; j < numLAB; j++)
        {
            edificio_file >> IDROOM ;
            BUILD[i].setQTOLABS(numLAB);

            Laboratorio A(IDROOM, LAB[IDROOM-1].getNAME(),LAB[IDROOM-1].getPC().getRAM(),LAB[IDROOM-1].getPC());
            BUILD[i].INCLUIR(A,Salon());
        }

        edificio_file >> numSALA;

        for(int j = 0; j < numSALA; j++)
        {
            edificio_file >> IDROOM;
            BUILD[i].setQTOSALONES(numSALA);
        
            Salon B(IDROOM, SALA[IDROOM-1].getNAME(),SALA[IDROOM-1].getPC().getRAM(),SALA[IDROOM-1].getPC());
            BUILD[i].INCLUIR(Laboratorio(),B);

        }    
            getline(edificio_file,person_build);
            BUILD[i].setRESPONSABLE(person_build);
    }

    int opcion=1;
    do{
        cout << "1) Consulta de todos los laboratorios que estan en la lista" << endl;
        cout << "2) Consulta de todos los salones que estan en la lista" << endl;
        cout << "3) Consulta de todos los edificios que estan en la lista" << endl;
        cout << "4) Consulta de todas las computadoras disponibles" << endl;
        cout << "5) Consulta de computadoras por edificio" << endl;
        cout << "6) Consulta por clave de computadora" << endl;
        cout << "7) Consulta la lista de labs y salones en las que se tiene una marca de computadora" << endl;
        cout << "8) Terminar" << endl;
        cout << ">>> Ingrese opcion (numero): ";
        cin >> opcion;
        cout << endl;

        switch(opcion)
        {
            case 1: // - Consulta de todos los laboratorios que estan en la lista y los de la computadora
            {
                for(int i = 0; LAB[i].getNAME() != "" ; i++)
                {
                    cout << "ID DEL LAB: " << LAB[i].getID() << "   " << "NOMBRE DEL LAB: " << LAB[i].getNAME() << "   " << "ID DE PC: " << LAB[i].getPC().getID() << "   " << "CAPACIDAD DE PC: "  << LAB[i].getPC().getRAM() << endl;
                }
                cout << endl;

                break;
            }
            case 2: // – Consulta de todos los salones que están en la lista
            {  
                for(int i = 0; SALA[i].getNAME() != "" ; i++)
                {
                    cout << "ID DEL SALON: " << SALA[i].getID() << "   " << "NOMBRE DEL SALON: " << SALA[i].getNAME() << "   " << "ID DE PC: " << SALA[i].getPC().getID() << "   " << "CAPACIDAD DE PC: "  << SALA[i].getPC().getRAM() << endl;
                }
                cout << endl;
                
                break;
            }
            case 3: // - Consulta de todos los edificios que están en la lista
            {
                for(int i = 0; BUILD[i].getNAME() != "" ; i++)
                {
                    cout << ">>> DATOS DEL EDFICIO:" << endl;
                    cout << "ID DEL EDIFICIO: " << BUILD[i].getID() << "   " << "NOMBRE DEL EDIFICIO: " << BUILD[i].getNAME() << "   " << "NOMBRE DEL RESPONSABLE: " << BUILD[i].getRESPONSABLE() << endl;
                    
                    if(BUILD[i].getQTOLABS() > 0)
                    {
                        cout << ">>> DATOS DE LABORATORIOS DENTRO:" << endl;
                        for(int j = 0; j < BUILD[i].getQTOLABS(); j++)
                        {
                            cout << "ID DEL LAB: " << BUILD[i].getLSTLABS()[j].getID() << "   " << "ID DE PC: " << BUILD[i].getLSTLABS()[j].getPC().getID() << "   " << "CAPACIDAD DE PC: "  << BUILD[i].getLSTLABS()[j].getPC().getRAM() << endl;
                        }
                    }

                    if(BUILD[i].getQTOSALONES() > 0)
                    {
                        cout << ">>> DATOS DE LOS SALONES DENTRO:" << endl;
                        for(int j = 0; j < BUILD[i].getQTOSALONES(); j++)
                        {
                            cout << "ID DEL SALON: " << BUILD[i].getLSTSALONES()[j].getID() << "   " << "ID DE PC: " << BUILD[i].getLSTSALONES()[j].getPC().getID() << "   " << "CAPACIDAD DE PC: "  << BUILD[i].getLSTSALONES()[j].getPC().getRAM() << endl;
                        }
                    }
                    cout << endl;
                }

                break;
            }
            case 4: // – Consulta de todas las computadoras disponibles
            { 
                displayAllComputersInfo(BUILD, 4);
                cout << endl;
                break;
            }
            case 5: // – Consulta de computadoras por edificio
            {
                bool pass = true; 
                do
                {
                    int targetBuildingID;
                    cout << "INGRESE EL ID DEL EDIFICIO : ";
                    cin >> targetBuildingID;
                    displayComputersInBuilding(BUILD, 4, targetBuildingID, pass);
                    cout << endl;

                    if(pass)
                        cout << "Has seleccionado un ID equivocado. Intenta de nuevo." << endl;
                    
                } while (pass);
                
                break;
            }
            case 6: // - Consulta por clave de computadora
            {
                bool pass = false;
                do
                {
                    int targetComputerID;
                    cout << "INGRESE EL ID DE LA COMPUTADORA A BUSCAR: ";
                    cin >> targetComputerID;
                    displayComputerLocation(BUILD, 4, targetComputerID,pass);
                    cout << endl;

                } while (!pass);

                break;
            }
            case 7: // - Consulta la lista de labs y salones en las que se tiene una marca de computadora
            {
                bool pass = true;
                do
                {
                    validateAndDisplayBrandComputers(BUILD, 4, PC, 22,pass);
                    cout << endl;
                    if(pass)
                        cout << "La marca que has buscado no se encuentra o se ha ingresado mal. Intente de nuevo." << endl;
                } while (pass);

                break;
            }
            case 8:
                break;
                
            default:
                cout << "Ingresaste un numero que no corresponde a ninguna opcion. Vuelve a intentar." << endl << endl;
                break;
        }
    }while(opcion!=8);

    lab_file.close();
    salon_file.close();
    pc_file.close();
    edificio_file.close();
}