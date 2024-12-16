#include "lib_globales.h"
#include "matriz.h"
#include "circularDoble.h"

int main(int argc, char const *argv[]){

    string LOG_usuario, LOG_password, LOG_departamento, LOG_empresa = "";
    string Nusuario, NnomCompleto, Npassword, Ndepartamento, Nempresa = "";
    string N_id_activo, NnomActivo, NdescActivo = "";
    int NdiasRenta = 0;
    string ID_eliminar, ID_editar = "";
    string Rent_departamento, Rent_empresa, Rent_nomUsu, RentID_activo, RentFecha = "";
    int Rent_dias = 0;


    string tempID, tempIDtransaccion = "";

    char opS_N = ' ';
    short opMenuAdmin, opMenuUsu = 0;
    bool esADMIN = false;

    Matriz m;
    CircularDoble listaCircular;

    //>> datos quemados <<
    //USUARIOS
    //m.insert(Ndepartamento, Nempresa, Nusuario, Npassword, NnomCompleto);
    m.insert("guatemala", "pinulito", "ale01", "123", "samuel alejandro");
    m.insert("peten", "max", "sam123", "s321", "pajoc raymundo");
    m.insert("jalapa", "wallmart", "linda12", "2@2", "linda cristal");

    //ACTIVOS
    //m.insertActivos(LOG_departamento, LOG_empresa, LOG_usuario, tempID, NnomActivo, NdescActivo, NdiasRenta, true);
    m.insertActivo("guatemala", "pinulito", "ale01", "id131", "mesas pequenas", "mesas de 2 personas", 20, true);
    m.insertActivo("guatemala", "pinulito", "ale01", "id1", "sillas", "sillas de jardin", 17, true);
    m.insertActivo("guatemala", "pinulito", "ale01", "id13", "sombrillas", "sombrillas para mesa", 21, true);
    m.insertActivo("guatemala", "pinulito", "ale01", "id132", "botes de basura", "botes grands", 22, true);

    m.insertActivo("peten", "max", "sam123", "id12", "sillas grandes", "sillas de oficina", 32, true);
    m.insertActivo("peten", "max", "sam123", "id5", "mostradores", "mostradores redondos", 13, true);
    m.insertActivo("peten", "max", "sam123", "id21", "estantes", "estantes de metal", 18, true);
    

    m.insertActivo("jalapa", "wallmart", "linda12", "id122", "laptops", "ordenadores portatiles pequenos", 15, true);
    m.insertActivo("jalapa", "wallmart", "linda12", "id100", "extenciones", "extenciones de 15 mt", 20, true);
    m.insertActivo("jalapa", "wallmart", "linda12", "id150", "antenas", "antenas para trafico de datos", 34, true);

while(true){
    //------------------------------- Iniciar Secion -------------------------------
    cout <<"\n\n======== [ Renta de Activos ] ========\n";
    cout <<"************ >> Login << ************\n\n";
    cout <<">> Usuario: ";
    cin >> LOG_usuario;
    cout <<">> Password: ";
    cin >> LOG_password;

    if(LOG_usuario == "admin" && LOG_password == "admin"){
        esADMIN=true;
    }
    else{
        cout <<">> Departamento: ";
        cin >> LOG_departamento;

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout <<">> Empresa: ";
        getline(cin, LOG_empresa);
        
        esADMIN=false;
    }
    
    //Si la cuenta es admin, muestra menu ADMIN
    if(esADMIN){
        //----------------------------------- Admin -----------------------------------
        do{
            cout<<"\n\n____________________________________________\n";
            cout << "____________ Menu Administrador ____________\n";
            cout << "1. Registrar Usuario\n";
            cout << "  2. Reporte matriz Dispersa\n";
            cout << "  3. >>(PRINT)<< Reporte Activos Disponibles de: un Departamento\n";
            cout << "  4. Reporte Activos Disponibles de: una Empresa\n";
            cout << "  5. Reporte Transacciones\n";
            cout << "  6. Reporte activos de un usuario\n";
            cout << "7. Activos rentados por un usuario\n";
            cout << "8. Ordenar Transacciones\n";
            cout << "9. Salir\n\n";
            cout << "Opcion:";
            cin >> opMenuAdmin;

            switch (opMenuAdmin){
                case 1:
                    cout << "\n---------- [ Nuevo Usuario ] ---------\n";
                    cout << "Nombre Usuario: ";
                    cin >> Nusuario;
                    //Permite limpiar el buffer de entrada, para que -getline- funcione
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout <<"Nombre Completo: ";
                    getline(cin, NnomCompleto);
                    cout << "Password: ";
                    cin >> Npassword;
                    cout << "Departamento: ";
                    cin >> Ndepartamento;
                    cout << "Empresa: ";
                    cin >> Nempresa;
                    //--> OPCIONAL: modificar la verificacion de usuario
                    m.insert(Ndepartamento, Nempresa, Nusuario, Npassword, NnomCompleto);
                    break;
                
                case 2:
                    //reporte matriz dispersa
                    cout<<"Graficando matriz...\n";
                    m.graphMatriz();
                    cout<<"\n Se grafico matriz Dispersa...!\n";
                    system("pause");
                    break;
                
                case 3:
                m.print();
                    //reporte
                    break;
                
                case 4:
                    //reporte
                    break;
                case 5:
                    //reporte
                    break;
                
                case 6:
                    //reporte
                    break;

                case 7:
                    //reporte
                    break;

                case 8:
                    //reporte
                    break;

                default:
                    if(opMenuAdmin != 9){
                        if(cin.fail()){//Captura el error
                            cin.clear();//Limpia el estado del error
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');//limpia el buffer de entrada, hasta el caracter (\n)
                        }

                        cout<<"\n*!!********************************!!*\n";
                        cout << ">> Opcion invalida\n\n";
                        system("pause");
                        cout<<"*!!********************************!!*";
                    }
                    break;
            }
        }while(opMenuAdmin != 9);
        cout<<"\n*!!******* ADMIN *********!!*\n";
        cout << "Secion Finalizada...\n\n";
        esADMIN=false;
        system("pause");
        cout<<"*!!****************!!*";
    }
    else{
    //----------------------------------- Usuario -----------------------------------
    //Se verificara que el usuario exista
    do{
        //muestra menu USUARIO
        cout<<"\n\n ~ -=-=-=-=-=-= ( Menu Usuario ) -=-=-=-=-= ~\n";
        cout<<"1. Agregar Activo\n";
        cout<<" 2. Eliminar Activo\n";
        cout<<"  3. Modificar Activo\n";
        cout<<"   4. Rentar Activo\n";
        cout<<"    5. Activos Rentados\n";
        cout<<"     6. Cerrar Sesion\n\n";
        cout<<"Opcion: ";
        cin>>opMenuUsu;

        switch (opMenuUsu){
            case 1:
                cout << "\n---------- >>> Agregar Activo <<< ----------\n";
                //Se debe crear un ID del nuevo activo, de forma automatica y aleatoria.
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Nombre del Activo: ";
                getline(cin, NnomActivo);
                cout << "Descripcion: ";
                getline(cin, NdescActivo);
                cout << "Dias disponibles para rentar: ";
                cin >> NdiasRenta;
                cout << "temp ID:";
                cin >> tempID;

                //Se crea nuevo nodo de AVL
                m.insertActivo(LOG_departamento, LOG_empresa, LOG_usuario, tempID, NnomActivo, NdescActivo, NdiasRenta, true);
                //insertarAVL(string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible)
                break;

            case 2:
                cout << "\n---------- >>> Eliminar Activo <<< ----------\n";
                //Muestra en lista ID y Nombre de activos pertenecientes a USUARIO logeado, antes de ELIMINAR
                m.printActivos(LOG_departamento, LOG_empresa, LOG_usuario);

                cout <<"ID de Activo a Eliminar: ";
                cin >> ID_eliminar;
                if(m.ID_existente(LOG_departamento, LOG_empresa, LOG_usuario, ID_eliminar, "ELIMINAR")){
                    cout << "\n-------------- > Eliminado < --------------\n";
                    m.eliminarActivo(LOG_departamento, LOG_empresa, LOG_usuario, ID_eliminar);
                }                
                break;
            
            case 3:
                cout << "\n---------- >>> Editar Activo <<< ----------\n";
                //Muestra lista: ID y Nombre de activos pertenecientes USUARIO logeado, antes de EDITAR
                m.printActivos(LOG_departamento, LOG_empresa, LOG_usuario);

                cout <<"ID de Activo a Editar: ";
                cin >> ID_editar;
                if(m.ID_existente(LOG_departamento, LOG_empresa, LOG_usuario, ID_editar, "EDITAR")){
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "\"Nueva\" Descripcion: ";
                    getline(cin, NdescActivo);

                    cout << "\n-------------- >! Editando !< --------------\n";
                    //Luego muestra datos del activo Modificado
                    //los datos se muestran dentro de la funcion -activosEditar-, dentro del metodo del AVL
                    m.editActivo(LOG_departamento, LOG_empresa, LOG_usuario, ID_editar, NdescActivo);
                    system("pause");
                }
                break;

            case 4:
                //Renta de Activos
                cout << "\n############ ( Catalogo de Activos ) ############\n";
                //Muestra todos los activos DISPONIBLES
                m.printActivosMatriz(LOG_departamento, LOG_empresa, LOG_usuario);//Datos para excluir al USUARIO y mostrar el resto de activos
                
                cout << "Rentar algun activo (s/n)?";
                cin >> opS_N;
                if(opS_N =='s' || opS_N == 'S'){
                    //string Rent_departamento, Rent_empresa, Rent_nomUsu, RentID_activo = "";
                    cout<<"ID Activo a Rentar: ";
                    cin >> RentID_activo;
                    cout<<"--->>> Para agilizar el proceso, se le pediran datos extra\n";
                    system("pause");
                    cout<<"\nUsuario (owner): ";
                    cin >> Rent_nomUsu;
                    cout<<"Departamento (owner): ";
                    cin >> Rent_departamento;
                    cout<<"Empresa (owner): ";
                    cin >> Rent_empresa;
                    if(m.ID_existente(Rent_departamento, Rent_empresa, Rent_nomUsu, RentID_activo, "RENTAR")){//Se verifica que los datos sea correctos
                        cout<<"Dias por Rentar: ";
                        cin >> Rent_dias;

                        if(m.rentarActivo(Rent_departamento, Rent_empresa, Rent_nomUsu, RentID_activo, Rent_dias)){
                            //Muestra datos del activo a Rentar
                            //ID, NOMBRE, DESCRIPCION

                            cout<<"Fecha: ";
                            cin >> RentFecha;
                            //ID_TRANSACCION debe generarse automatico
                            //se agrega TRANSACCION a lista DOBLE
                            listaCircular.append(tempIDtransaccion, RentID_activo, LOG_usuario, LOG_departamento, LOG_empresa, RentFecha, Rent_dias);
                        }
                        system("pause");
                    }
                }
                else{cout<<"No se encontro, en matriz dispersa...\n";}
                break;

            case 5:
                //Activos Rentados
                cout << "\n############ ( Activos Rentados ) ############\n";
                //Muestra todos los activos RENTADOS si los hay

                cout << "Devolver algun activo (s/n)?";
                cin >> opS_N;
                if(opS_N =='s' || opS_N == 'S'){
                    cout<<"ID Activo a devolver: ";
                    //Muestra datos del activo DEVUELTO
                    //ID, NOBRE, DESCRIPCION
                }            
                break;
            
            default:
                if(opMenuUsu != 6){
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
    }while (opMenuUsu != 6);
    cout<<"\n*!!******* USUARIO *********!!*\n";
    cout << "Secion Finalizada...\n\n";
    system("pause");
    cout<<"*!!****************!!*";
    }    
}
return 0;
}