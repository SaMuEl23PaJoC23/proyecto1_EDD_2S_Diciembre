#include "matriz.h"
int cantI, cantJ = 0;
//-------------------------------------------------------------------
Matriz::Matriz(){//Al crear la matriz, se genera con el nodo origen/ADMIN
    this->raiz = new Nodo(-1, -1, "admin_i","admin_j");
}
//-------------------------------------------------------------------
Matriz::~Matriz(){
    Nodo *temp = raiz;
    Nodo *aux;

    while(temp != nullptr){
        Nodo *tempFila = temp;
        Nodo *auxFila;

        aux = temp->getAbajo();

        while(tempFila != nullptr){
            auxFila = tempFila->getDcha();
            delete tempFila;
            tempFila = auxFila;
        }

        temp = aux;
    }
}
//-------------------------------------------------------------------
void Matriz::insert(string i_dep, string j_empresa, string nomUsu, string password, string nomCompleto){
    Nodo *nuevo = new Nodo(0, 0, i_dep, j_empresa, nomUsu, password, nomCompleto);//Se crea nuevo Nodo para datos en matriz

    if(!this->existeNodo(nuevo)){//Si el dato ya existe, se elimina nodo nuevo en metodo "existeNodo"
        Nodo *columna = buscarColumna(i_dep);//Se busca si nueva columna (DEPARTAMENTO) existe
        Nodo *fila = buscarFila(j_empresa);//Se busca si nueva fila (EMPRESA) existe

        if(columna == nullptr){ columna = insertarEncabezadoColumna(i_dep);}
        if(fila == nullptr){ fila = insertarEncabezadoFila(j_empresa);}

        insertarEnColumna(nuevo, fila);
        insertarEnFila(nuevo, columna);
    }
}
//-------------------------------------------------------------------
bool Matriz::existeNodo(Nodo *nuevo){
    Nodo *encabezadoFila = this->raiz;
    short PosNuevoNodo = 0;
    bool nomUsuExistente = true;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJempresa() == nuevo->getJempresa()){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getIdep() == nuevo->getIdep()){ //hasta aca, misma EMPRESA y DEPARTAMENTO

                    Nodo * auxColumna = columna;
                    while (auxColumna->getNomUsu() != nuevo->getNomUsu()){//Se recorrera la lista hacia atras, para verificar si el nombre de USUARIO No existe
                        auxColumna = auxColumna->getAtras();
                        if(auxColumna == nullptr){
                            nomUsuExistente = false;
                            break;
                        }
                    }

                    if(!nomUsuExistente){//Si no existe mismo nombre de USUARIO, se agrega
                        //inserta nodo -nuevo- en "lista" usando los punteros: adelante,atras
                        cout<<"\nDeberia colocarse:";//Unicamente se mostrara cuando ya se haya insertado un nodo
                        do{
                            cout<<"\n1) Adelante\n";
                            cout<<"2) Atras\n";
                            cout<<"3) CANCELAR\n";
                            cout<<">> de: "<<columna->getNomUsu()<<" <<\n";//Muestra nodo -primero-
                            cout<<"Opcion: ";//  >>El nodo -primero-, es el primer nodo insertado en esta "lista"<<
                            cin >> PosNuevoNodo;
                            
                            switch (PosNuevoNodo){
                                case 1:{//Las llaves {} permiten que las variables inicializadas en su interior
                                    //Unicamente tengan este ambito (limitan su uso a este -case-) y evitar ERROR de compilacion
                                    
                                    //inserta ADELANTE
                                    if(columna->getAtras()==nullptr){//Si puntero ATRAS de nodo -primero- es nulo, insercion sencilla
                                        columna->setAtras(nuevo);
                                        nuevo->setAdelante(columna);
                                    }
                                    else{
                                        //Se inserta el nodo nuevo -atras- de nodo -primero-, despues se realizara intercambio de datos entre ambos nodos, primero-> y <-nuevo
                                        nuevo->setAtras(columna->getAtras());
                                        nuevo->setAdelante(columna);
                                        columna->getAtras()->setAdelante(nuevo);
                                        columna->setAtras(nuevo);
                                    }
                                    //Se realiza copia del nodo 'primero'
                                    Nodo *auxNodo = new Nodo(columna->getI(), columna->getJ(), columna->getIdep(), columna->getJempresa(), columna->getNomUsu(), columna->getPassword(), columna->getNomCompleto());
                                    
                                    //Se actualiza datos de nodo -primero-
                                    //Unicamente: NomUsu, Password, NomCompleto. Dado que los demas datos se mantienen igual en toda la 'lista'
                                    columna->setNomUsu(nuevo->getNomUsu());
                                    columna->setPassword(nuevo->getPassword());
                                    columna->setNomCompleto(nuevo->getNomCompleto());

                                    //Se actualizan datos de nodo -atras de primero- 'exNuevo', con datos de 'exPrimero' ubicados temporalmente en auxNodo
                                    nuevo->setNomUsu(auxNodo->getNomUsu());
                                    nuevo->setPassword(auxNodo->getPassword());
                                    nuevo->setNomCompleto(auxNodo->getNomCompleto());

                                    //Se elimina nodo auxiliar, dado que se completo el intercambio de datos
                                    delete auxNodo;
                                    PosNuevoNodo = 3;
                                    break;
                                }
                                
                                case 2:
                                    //Si puntero ATRAS es nulo, insercion sencilla
                                    if(columna->getAtras()==nullptr){
                                        columna->setAtras(nuevo);
                                        nuevo->setAdelante(columna);
                                    }
                                    else{
                                        //sino insercion con intercambio de punteros entre nodo -primero-, nodo -nuevo-, nodo -primero.atras-
                                        nuevo->setAtras(columna->getAtras());
                                        nuevo->setAdelante(columna);
                                        columna->getAtras()->setAdelante(nuevo);
                                        columna->setAtras(nuevo);
                                    }
                                    PosNuevoNodo = 3;
                                    break;

                                case 3:
                                    delete nuevo;//Elimina el nodo nuevo, dado que se cancela insercion
                                    break;
                                
                                default:
                                    if(PosNuevoNodo !=3){
                                        if(cin.fail()){//Captura el error
                                            cin.clear();//Limpia el estado del error
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');//Ignora la entrada incorrecta
                                        }
                                        cout<<"\n*!!********************************!!*\n";
                                        cout << ">> Opcion invalida\n\n";
                                        system("pause");
                                        cout<<"*!!********************************!!*";
                                    }
                                    break;
                            }
                        }while(PosNuevoNodo != 3);
                    }
                    else{//Cuando tiene mismo nombre de usuario
                        delete nuevo;//Elimina el Nodo nuevo, dado que YA existe
                        cout<<"\nUsuario Ya existente...!\n";
                        system("pause");
                    }
                    return true;//para no insertar nuevo nodo en Area de MATRIZ
                }
                columna = columna->getDcha();
            }  
            return false; 
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
    return false;
}
//-------------------------------------------------------------------
Nodo* Matriz::buscarColumna(string i_dep){
    Nodo *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getIdep() == i_dep){
            return temp;
        }
        temp = temp->getDcha();
    }
    return nullptr;
}
//-------------------------------------------------------------------
Nodo* Matriz::buscarFila(string j_empresa){
    Nodo *temp = this->raiz;

    while(temp != nullptr){
        if(temp->getJempresa() == j_empresa){
            return temp;
        }
        temp = temp->getAbajo();
    }
    return nullptr;
}
//-------------------------------------------------------------------
Nodo* Matriz:: insertarEncabezadoColumna(string i_dep){
    Nodo *nuevoEncabezadoColumna = new Nodo(cantI, -1, i_dep, "admin_j");

    Nodo *temp = this->raiz;
    while(temp->getDcha() != nullptr){//se avanza al nodo columna siguieten, hasta encontrar el final
        temp = temp->getDcha();
    }

    temp->setDcha(nuevoEncabezadoColumna);
    nuevoEncabezadoColumna->setIzq(temp);

    cantI++;
    return nuevoEncabezadoColumna;
}
//-------------------------------------------------------------------
Nodo* Matriz:: insertarEncabezadoFila(string j_empresa){
    Nodo *nuevoEncabezadoFila = new Nodo(-1, cantJ,"admin_i", j_empresa);

    Nodo *temp = this->raiz;
    while(temp->getAbajo() != nullptr){
        temp = temp->getAbajo();
    }

    temp->setAbajo(nuevoEncabezadoFila);
    nuevoEncabezadoFila->setArriba(temp);

    cantJ++;
    return nuevoEncabezadoFila;
}
//-------------------------------------------------------------------
void Matriz::insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila){
    Nodo *temp = encabezadoFila;
    Nodo *auxTemp;
    auxTemp = raiz;

    while (auxTemp->getDcha() != nullptr){
        if(auxTemp->getDcha()->getIdep() == nuevo->getIdep()){
            nuevo->setI(auxTemp->getDcha()->getI());//Se asigna NODO nuevo cordenada  'i' correspondiente
            break;
        }
        auxTemp = auxTemp->getDcha();
    }

    while(temp->getDcha() != nullptr){
        if(nuevo->getI() < temp->getDcha()->getI()){//Si el dato a ingresarse tiene cordenada menor, se ajustan los punteros para que quede cabecera COLUMNA ordenada de menor a mayor (dado que ademas poseen coordenadas i,j)
            nuevo->setDcha(temp->getDcha());
            nuevo->setIzq(temp);
            temp->getDcha()->setIzq(nuevo);
            temp->setDcha(nuevo);
            break;
        }
        temp = temp->getDcha();
    }

    if(temp->getDcha() == nullptr){
        temp->setDcha(nuevo);
        nuevo->setIzq(temp);
    }
}
//-------------------------------------------------------------------
void Matriz::insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna){
    Nodo *temp = encabezadoColumna;
    Nodo *auxTemp;
    auxTemp = raiz;

    while (auxTemp->getAbajo() != nullptr){
        if(auxTemp->getAbajo()->getJempresa() == nuevo->getJempresa()){
            nuevo->setJ(auxTemp->getAbajo()->getJ());//Se asigna NODO nuevo cordenada  'j' correspondiente
            break;
        }
        auxTemp = auxTemp->getAbajo();
    }

    while(temp->getAbajo() != nullptr){
        if(nuevo->getJ() < temp->getAbajo()->getJ()){//Si el dato a ingresarse tiene cordenada menor, se ajustan los punteros para que quede cabecera FILA ordenada de menor a mayor (dado que ademas poseen coordenadas i,j)
            nuevo->setAbajo(temp->getAbajo());
            nuevo->setArriba(temp);
            temp->getAbajo()->setArriba(nuevo);
            temp->setAbajo(nuevo);
            break;
        }
        temp = temp->getAbajo();
    }

    if(temp->getAbajo() == nullptr){
        temp->setAbajo(nuevo);
        nuevo->setArriba(temp);
    }
}
//-------------------------------------------------------------------
void Matriz::graphMatriz(){
    ofstream outfile ("matriz.dot");
    Nodo *aux_fila = raiz;
    Nodo *aux_columna;
    string dec_nodo;
    string conexion;

    outfile << "digraph G {" << endl;
    outfile << "    node[shape=\"box\"] \n" << endl;
    
    while(aux_fila != nullptr){
        string rank = "{rank=same";
        aux_columna = aux_fila;

        while(aux_columna != nullptr){
            string i_coord = to_string(aux_columna->getI() + 1);
            string j_coord = to_string(aux_columna->getJ() + 1);
            string nombre = "Nodo"+i_coord+"_"+j_coord;//Se crea nodo para DOT

            if(aux_columna->getI() == -1 && aux_columna->getJ() == -1){//Para nodo raiz
                dec_nodo = nombre + "[label = \"raiz\", group = \""+i_coord+"\"]";
            
            }else if(aux_columna->getI() == -1){//Para nodo cabecera Fila (j)
                dec_nodo = nombre + "[label = \""+(aux_columna->getJempresa())+"\"";
                dec_nodo += ", group = \""+i_coord+"\"]";
            
            }else if(aux_columna->getJ() == -1){//Para nodo cabecera Columna (i)
                dec_nodo = nombre + "[label = \""+(aux_columna->getIdep())+"\"";
                dec_nodo += ", group = \""+i_coord+"\"]";
            }
            // Para nodos -No Cabezeras/
            else{
                dec_nodo = nombre + "[label = \""+aux_columna->getNomUsu()+"\"";
                dec_nodo += ", group = \""+i_coord+"\"]";
            }

            outfile << dec_nodo << endl;

            if(aux_columna->getDcha() != nullptr){//Se enlaza el nodo hacia DERECHA
                conexion = nombre + "->Nodo"+to_string(aux_columna->getDcha()->getI() + 1);//para que la coneccion no sea tan extendida se escribe en dos lineas
                conexion += "_"+to_string(aux_columna->getDcha()->getJ() + 1);

                outfile << conexion << endl;
                outfile << conexion << "[dir = back] \n"<< endl;
            }

            if(aux_columna->getAbajo() != nullptr){//Se enlaza el nodo hacia ABAJO
                conexion = nombre + "->Nodo"+to_string(aux_columna->getAbajo()->getI() + 1);
                conexion += "_"+to_string(aux_columna->getAbajo()->getJ() + 1);

                outfile << conexion << endl;
                outfile << conexion << "[dir = back] \n" << endl;
            }

            rank+=";"+nombre;
            aux_columna = aux_columna->getDcha();
        }

        rank+="}\n\n";
        outfile << rank << endl;
        
        aux_fila = aux_fila->getAbajo();
    }
    outfile << "}" << endl;
    outfile.close();
    int returnCode = system("dot -Tpng ./matriz.dot -o ./matriz.png");

    if(returnCode == 0){cout << "Comando ejecutado exitosamente !!! :)" << endl;}
    else{cout << "Ejecucion del comando fallida..." << returnCode << endl;}
}
//-------------------------------------------------------------------
void Matriz::print(){
    Nodo *auxfila1 = raiz->getAbajo();
    while (auxfila1 != nullptr){
        Nodo *auxColumna = auxfila1->getDcha();
        while (auxColumna != nullptr){
            Nodo *auxNodo = auxColumna;
            cout<<">"<<auxNodo->getIdep()<<" "<<auxNodo->getJempresa()<<"\n";
            while(auxNodo != nullptr){
                cout<<auxNodo->getNomUsu()<<"\n";
                auxNodo = auxNodo->getAtras();
            }
            cout<<"============\n\n";
            auxColumna = auxColumna->getDcha();
        }
        auxfila1 = auxfila1->getAbajo();
    }
}
//-------------------------------------------------------------------
void Matriz::insertActivos(string i_dep, string j_empresa, string nomUsu, string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible){
    Nodo *encabezadoFila = this->raiz;
    bool nomUsuExistente = true;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJempresa() == j_empresa){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getIdep() == i_dep){ //hasta aca, misma EMPRESA y DEPARTAMENTO

                    Nodo * auxColumna = columna;
                    while (auxColumna != nullptr){//Se recorrera la lista hacia atras, para verificar si el nombre de USUARIO existe
                        if(auxColumna->getNomUsu() == nomUsu){
                            auxColumna->getAVL()->insertarAVL(ID_activo, nomActivo, descActivo, diasParaRentar, disponible);
                            return;
                        }
                        auxColumna = auxColumna->getAtras();
                    }
                }
                columna = columna->getDcha();
            }  
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
}
//-------------------------------------------------------------------
void Matriz::printActivos(string i_dep, string j_empresa, string nomUsu){
    Nodo *encabezadoFila = this->raiz;
    bool nomUsuExistente = true;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJempresa() == j_empresa){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getIdep() == i_dep){ //hasta aca, misma EMPRESA y DEPARTAMENTO

                    Nodo * auxColumna = columna;
                    while (auxColumna != nullptr){//Se recorrera la lista hacia atras, para verificar si el nombre de USUARIO existe
                        if(auxColumna->getNomUsu() == nomUsu){
                            auxColumna->getAVL()->PrintAVL();
                            auxColumna->getAVL()->graphAVL();
                            return;
                        }
                        auxColumna = auxColumna->getAtras();
                    }
                }
                columna = columna->getDcha();
            }  
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
}
//-------------------------------------------------------------------
void Matriz::eliminarActivo(string i_dep, string j_empresa, string nomUsu, string id_activo){
    Nodo *encabezadoFila = this->raiz;
    bool nomUsuExistente = true;

    while(encabezadoFila != nullptr){
        if(encabezadoFila->getJempresa() == j_empresa){
            Nodo *columna = encabezadoFila;

            while(columna != nullptr){
                if(columna->getIdep() == i_dep){ //hasta aca, misma EMPRESA y DEPARTAMENTO

                    Nodo * auxColumna = columna;
                    while (auxColumna != nullptr){//Se recorrera la lista hacia atras, para verificar si el ID activo existe
                        if(auxColumna->getNomUsu() == nomUsu){
                            auxColumna->getAVL()->delNodoAVL(id_activo);
                            return;
                        }
                        auxColumna = auxColumna->getAtras();
                    }
                }
                columna = columna->getDcha();
            }  
        }
        encabezadoFila = encabezadoFila->getAbajo();
    }
}


