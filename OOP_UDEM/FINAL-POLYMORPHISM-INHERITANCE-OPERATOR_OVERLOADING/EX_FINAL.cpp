#include <fstream>
#include <vector>
#include "RESERVA.h"
#include "APARATO.h"
#include "CANCHA.h"
#include "functionality.h"

int main()
{
    ifstream serv("Servicios.txt");
    fstream resv("Reserva.txt");

    Servicio* SERVICIOS[20];
    Reserva RESERVACIONES[50];

    string CLAVE, DETALLES;
    int TMAX, COSTOXT, PERSMAX;
    char TSERV, VERINSTRU;

    for(int i = 0; serv >> CLAVE >> TMAX >> TSERV >> COSTOXT; i++)
    {
        if(TSERV == 'C' || TSERV == 'E' || TSERV == 'B')
        {
            serv >> VERINSTRU;
            VERINSTRU = (VERINSTRU == 'T')?(true):(false);
            getline(serv,DETALLES);
            SERVICIOS[i] = new Aparato(COSTOXT, VERINSTRU, DETALLES, CLAVE, TMAX, TSERV);
        }
        else
        {
            serv >> PERSMAX;
            getline(serv,DETALLES);
            SERVICIOS[i] = new Cancha(COSTOXT, PERSMAX, DETALLES, CLAVE, TMAX, TSERV);
        }
    }
    
    int IHORA, IMIN, RESVTEMP, ID;

    int times = 0;
    for(int i = 0; resv >> CLAVE >> IHORA >> IMIN >> RESVTEMP >> ID; i++)
    {
        RESERVACIONES[i] = Reserva(CLAVE, ID, Hora(IHORA,IMIN), RESVTEMP);
        times++;
    }

    resv.close();

    int opcion;
    do
    {
        cout << "1) Consultar la lista de servicios" << endl;
        cout << "2) Consultar la lista de reservaciones" << endl;
        cout << "3) Consultar las reservaciones de un servicio dado" << endl;
        cout << "4) Consultar las reservaciones de una hora especifica" << endl;
        cout << "5) Hacer una reservacion" << endl;
        cout << "6) Terminar" << endl;
        cout << ">>> Ingrese opcion (numero): ";
        cin >> opcion;
        cout << endl;
        
        switch(opcion)
        {
            case 1:
            {
                for(Servicio* i : SERVICIOS)
                {
                    i->muestra();
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                resv.open("Reserva.txt");

                for(int i = 0; resv >> CLAVE >> IHORA >> IMIN >> RESVTEMP >> ID; i++)
                {
                    if(i == 0)
                        times = 0;

                    RESERVACIONES[i] = Reserva(CLAVE, ID, Hora(IHORA,IMIN), RESVTEMP);
                    
                    times++;
                }
                               
                for(int i = 0; i<times; i++)
                {
                    muestraDatoServicios(RESERVACIONES[i].getClaveServicio(), SERVICIOS); // clave del servicio (incluida) y datos del servicio

                    cout << "El ID del cliente es: " << RESERVACIONES[i].getIdCliente() << endl; // id del cliente
                    
                    cout << "Hora inicio de la reservacion: " << RESERVACIONES[i].getHoraInicio() << endl; // hora de inicio de la reservacion
                    
                    cout << "Hora fin de la reservacion: " << RESERVACIONES[i].calculaHoraFinReservacion() << endl; // hora fin de la reservacion
                    
                    cout << "El costo de la reservacion es: ";
                    muestraCosto(RESERVACIONES[i].getClaveServicio(), SERVICIOS, RESERVACIONES[i].getDuracion());
                    cout << "$" << endl << endl;
                }

                resv.close();
                break; 
            }
            case 3: // validar que exista el ID, si existe validar que este reservado y sino decir que no lo esta.
            {
                cin.ignore();
                bool remain; 
                do
                {
                    string input;
                    cout << "Ingrese el ID del servicio: ";
                    getline(cin,input);
                    remain = validarServicio(input,SERVICIOS,RESERVACIONES,times);
                } while(!remain);
                break;
            }
            case 4: 
            {
                bool remain; 
                do
                {
                    Hora slot;
                    cout << "Ingrese una hora de reserva, primero la hora y luego los minutos: " << endl;
                    cin >> slot;
                    cout << endl;
                    remain = validarHora(slot,SERVICIOS,RESERVACIONES,times);
                    if(!remain)
                        cout << "No hay ninguna reservacion para la hora ingresada. Intente de nuevo." << endl << endl;
                } while(!remain);
                break;
            }
            case 5:
            {
                cin.ignore();
                bool remain;


                // validar que la clave de servicio exista
                // el servicio se pueda rentar por la cantidad de tiempo que el usuario quiera
                // si no se puede, debe preguntar al usuario si quiere reservarlo por menos tiempo o cancelar la reserva
                // si el usario quiere servarlo por menos tiempo, debe pedir el tiempo en minutos hasta que el tiempo de reserva sea adecuado.
                // ademas el programa debe el costo de rentar ese servicio por el tiempo deseado.

                string user_input;
                cout << "Ingrese su ID de cliente: ";
                getline(cin,user_input);

                do
                {
                    string serv_input;
                    cout << "Ingrese el ID del servicio: ";
                    getline(cin,serv_input);
                    resv.open("Reserva.txt", ios::out | ios::app);

                    remain = rev_intimo(user_input,serv_input,resv,SERVICIOS,RESERVACIONES,times); //rev_intimo se encarga de coordinar todo el proceso.
                    resv.flush();
                    resv.close();

                } while (!remain); // do while aqui es necesario unicamente para validar que el ID del servicio exista, remain tiene que ser true.
                break;
            }
            case 6:
            {
                break;
            }
            default:
                cout << "Ingresaste un numero que no corresponde a ninguna opcion. Vuelve a intentar." << endl << endl;
                break;
        }
    } while(opcion!=6);

    resv.close();
    serv.close();
}
