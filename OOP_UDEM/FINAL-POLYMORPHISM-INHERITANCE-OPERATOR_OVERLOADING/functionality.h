
void muestraDatoServicios(string clave, Servicio* bundle[20])
{
    for(int i = 0; i<20; i++)
    {
        if(clave == (bundle[i]->getClave()))
        {
            bundle[i]->muestra();
            break;
        }
    }
}

void muestraCosto(string clave, Servicio* bundle[20], int tiempo)
{
    for(int i = 0; i<20; i++)
    {
        if(clave == (bundle[i]->getClave()))
        {
            cout << bundle[i]->calculaCosto(tiempo);
            break;
        }
    }
}

bool validarServicio(string clave, Servicio* bundle1[20], Reserva bundle2[50], int const& ser) 
{
    bool ajax = false;
    for(int i = 0; i<20 ; i++)
    {
        if(clave == bundle1[i]->getClave())
        {
            for(int j = 0; j<ser; j++) //ser se usa para iterar sobre el numero correcto de reservas en total.
            {
                if(clave == bundle2[j].getClaveServicio())
                {
                    bundle1[i]->muestra();
                    cout << "Hora inicio de la reservacion: " << bundle2[j].getHoraInicio() << endl;
                    cout << "Hora fin de la reservacion: " << bundle2[j].calculaHoraFinReservacion() << endl << endl;
                    ajax = true;
                }

                if(ajax && j == ser-1)
                    return true;

                if(j == ser-1)
                {
                    cout << "No hay una reservacion hecha para la clave ingresada. Intente con otra." << endl << endl;
                    return false;
                }
            }
        }
        if(i == 19)
        {
            cout << "No hay un servicio con la clave registrada. Intente de nuevo." << endl << endl;
            return false;
        }
    }
    return false;
}

bool validarHora(Hora slot, Servicio* bundle1[20], Reserva bundle2[50], int const& ser) // el resultado en caso ideal debe ser verdadero.
{
    bool res = false;
    for(int i = 0; i < ser; i++)
    {
        if(slot <= bundle2[i].calculaHoraFinReservacion() && slot >= bundle2[i].getHoraInicio())
        {
            muestraDatoServicios(bundle2[i].getClaveServicio(),bundle1);
            cout << "Hora inicio de la reservacion: " << bundle2[i].getHoraInicio() << endl; // hora de inicio de la reservacion        
            cout << "Hora fin de la reservacion: " << bundle2[i].calculaHoraFinReservacion() << endl; // hora fin de la reservacion
            cout << endl;
            res = true;
        }
    }
    return res;
}

//horaDisponible se encarga de verificar que la hora de reserva no este dentro de ninguno de los periodos de reserva.
//tiene que regresar true.

bool horaDisponible(Hora slot, vector<Reserva> selection) // esto no esta bien.
{
   for(int i = 0; i<selection.size(); i++) 
    {
        if( !( (slot <= selection[i].getHoraInicio() || slot >= selection[i].calculaHoraFinReservacion()) && !(slot == selection[i].getHoraInicio()) ) )
            return false;
    }
    return true; // esto tiene que ocurrir siempre idealmente.
}

// checar que horarios no se sobrelapen.

bool compararHorario(Hora slot, vector<Reserva> selection, int const& periodo,int& ser,string const& user, Reserva const& Sel, fstream& carga, Servicio* TODA[20]) // variable ser permite que se despliege las reservas en el menu despues de agregas nuevas.
{
    
    for(int i = 0; i < selection.size(); i++)
    {
        if( ( (slot + periodo) <= selection[i].getHoraInicio()) && i==selection.size()-1 )
        {
            carga << Sel.getClaveServicio() << " " << slot.getHH() << " " << slot.getMM() << " " << periodo << " " << user << endl;
            ser++;
            cout << "El costo de la reserva es: ";
            muestraCosto(Sel.getClaveServicio(), TODA, periodo);
            cout << "$" << endl << endl;
            return true;
        }
        else
        {
            for(int j = 0; j < selection.size() && i==selection.size()-1 ; j++)
            {
                
                if( (slot >= selection[j].calculaHoraFinReservacion()) && j==selection.size()-1 )
                {
                    carga << Sel.getClaveServicio() << " " << slot.getHH() << " " << slot.getMM() << " " << periodo << " " << user << endl;
                    ser++;
                    cout << "El costo de la reserva es: ";
                    muestraCosto(Sel.getClaveServicio(), TODA, periodo);
                    cout << "$" << endl << endl;
                    return true;
                } 
                else
                {
                    for(int k = 0; k < selection.size()-1 && j==selection.size()-1; k++)
                    {
                        if(  ((slot+periodo) <= selection[k+1].getHoraInicio()) && (slot >= selection[k].calculaHoraFinReservacion())  )
                        {
                            
                            carga << Sel.getClaveServicio() << " " << slot.getHH() << " " << slot.getMM() << " " << periodo << " " << user << endl;
                            ser++;
                            cout << "El costo de la reserva es: ";
                            muestraCosto(Sel.getClaveServicio(), TODA, periodo);
                            cout << "$" << endl << endl;
                            return true;
                        }
                        else
                        {
                            if(k == selection.size()-2)
                            {
                                return false;
                            }
                                
                        }
                    }
                }
            }
        }    
    }
    return false;
}

bool rev_intimo(string user, string Sclave, fstream& carga, Servicio* bundle1[20], Reserva bundle2[50], int &ser)
{
    bool res = false;
    Reserva Sel; // Representa la existencia del servicio seleccionado.
    int DIFF; // representa el periodo de reserva permitido para la hora seleccionada sin que se sobrelape con otra reserva.

    for(int i = 0; i<20; i++)
    {
        if(Sclave == (bundle1[i]->getClave())) //Sclave busca que servicio tenga esa clave para luego guardar en Sel de tipo reserva la clave y la duracion.
        {
            res = true;
            Sel.setClaveServicio(bundle1[i]->getClave());
            Sel.setDuracion(bundle1[i]->getTiempoMax());
            break;
        }
    }

    if(res) // si se encontro el servicio con esa misma clave, entonces se prosigue a revisar que la cantidad de minutos que dure la reserva sea adecuado.
    {
        int su_tiempo;
        do
        {
            cout << "Ingrese la cantidad de minutos que deseas que dure la reserva: ";
            cin >> su_tiempo;
            
            if(su_tiempo <= Sel.getDuracion()) // aqui se corrobora que el tiempo de reserva sea igual o menor al permitido por los datos del texto. 
            {
                Hora slot; // para guardar la hora y minutos de reserva.
                vector<Reserva> selection; // aqui se guardan todas las reservas tomadas para el servicio seleccionado.
                
                for(int i = 0; i<20 ;i++) //obtener reservas con misma clave.
                {
                    if(bundle2[i].getClaveServicio() == Sel.getClaveServicio())
                    {
                        selection.push_back(bundle2[i]); // caso de prueba: i={1,6} para E-012
                    }
                }
                
                do
                {
                    cout << "Ingrese una hora de reserva, primero la hora y luego los minutos: " << endl;
                    cin >> slot;
                    cout << endl;

                    // la duracion del tiempo debe de tomar en cuenta los espacios entre horas de reserva y la duracion.
                    // corroborar que la hora para el aparato que busques no se sobrelape con otras reservas. Diferenciar reservas solo para el aparato.

                    res = horaDisponible(slot,selection); //horaDisponible se encarga de verificar que la hora de reserva no este dentro de ninguno de los periodos de reserva
                    // res tiene que ser true.

                    if(res == false)
                        cout << "La hora de reserva que has ingresado no se encuentra en un periodo disponible. Intente de nuevo." << endl; 
                    
                } while (!res); 

                // Luego de corroborar que la hora pueda coexistir con los otros periodos de reserva, checar que el tiempo seleccionado no se sobrelape entre reservas existentes. 
            
                res = compararHorario(slot,selection,su_tiempo,ser,user,Sel,carga,bundle1); // compararHorario se encarga de revisar que no haya sobrelapamiento en minutos.
                                
                if(!res) // si res es falso, entonces a cancelar la reserva o pedir menos tiempo
                {
                    double_escape:
                    escape: 
                        int answer;
                        cin.ignore();

                        cout << "El tiempo ingresado no corresponde al tiempo libre que hay para el servicio. Desea:" << endl;
                        cout << "1) Reservar por menos tiempo" << endl;
                        cout << "2) Cancelar la operacion" << endl;
                        cout << ">>> Ingrese opcion (numero): ";
                        cin >> answer;
                        cout << endl;

                        switch(answer)
                        {
                            case 1:
                            {
                                do
                                {
                                    cout << "Ingrese la cantidad de minutos que deseas que dure la reserva: ";
                                    cin >> su_tiempo;

                                    if( !(su_tiempo <= Sel.getDuracion()) )
                                        cout << "Ingresaste un tiempo mayor, al permitido, intenta de nuevo." << endl;
                                    
                                } while(!(su_tiempo <= Sel.getDuracion()));

                                res = compararHorario(slot,selection,su_tiempo,ser,user,Sel,carga,bundle1);
                                
                                if(res) 
                                    return true; // return true para finalizar la operacion.
                                else
                                    goto escape;
                            }
                            case 2:
                            {
                                return true; // return true para cancelar la operacion.
                            }
                            default:
                            {
                                cout << "Ha ingresado un numero incorrecto. Intente de nuevo." << endl << endl;
                                goto double_escape;
                            }
                        }
                }
                
                // al final de este if, res tiene que ser <<true>> para return y acabar la operacion.
            }
            else
            {
                res = false;
                cout << "La duracion que has ingresado excede el tiempo limite de la reserva. Intente con otro tiempo." << endl;
            }
            
            /*
                Para poder corroborar los tiempos entre reservas de un mismo aparato:
                - revisar que la duracion dada no este excediendo el limite. --- done
                - con una hora dada de inicio y su duracion, revisar que la hora final no sobrepase la de inicio de una posible siguiente reservacion.
                - primero, calcular la hora final, checar que no sea igual o mayor que la hora de una siguiente reservacion.
                - si es verdadero, entonces volver a pedir hora, si es falso, entonces revisar que 
            */

        } while (!res); 
    }
    else
        cout << "Has ingresado un ID que no pertenece a ningun servicio. Intente de nuevo." << endl;
    
    return res;
}
