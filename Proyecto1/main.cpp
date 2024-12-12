#include "lib_globales.h"
#include "matriz.h"

int main(int argc, char const *argv[]){

    string LOG_usuario, LOG_password, LOG_departamento, LOG_empresa = "";
    string Nusuario, NnomCompleto, Npassword, Ndepartamento, Nempresa = "";
    char opS_N = ' ';
    short opMenuAdmin, opMenuUsu = 0;
    bool esADMIN = false;

    Matriz m;

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
        cout <<">> Empresa: ";
        cin >> LOG_empresa;
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
                    cout << "\n---------- [ Nuevo usuario ] ---------\n";
                    cout << "Nombre Usuario: ";
                    cin >> Nusuario;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');//Permite limpiar el buffer de entrada, para que -getline- funcione
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
                cout << "Nombre (Usuario o Activo...?): ";
                cout << "Descripcion: ";
                break;

            case 2:
                cout << "\n---------- >>> Eliminar Activo <<< ----------\n";
                //Se debe mostrar en forma de lista el ID y Nombre de activos pertenecientes al USUARIO logeado, antes de ELIMINAR
                cout <<"ID de Activo a Eliminar: ";

                cout << "\n-------------- > Eliminado < --------------\n";
                //Muestra datos del activo eliminado
                //ID, NOMBRE, DESCRIPCION
                break;
            
            case 3:
                cout << "\n---------- >>> Editar Activo <<< ----------\n";
                //Se debe mostrar en forma de lista el ID y Nombre de activos pertenecientes al USUARIO logeado, antes de ELIMINAR
                cout <<"ID de Activo a Editar: ";

                cout << "\n-------------- >! Editando !< --------------\n";
                cout<<"Descripcion Nueva: ";

                //Luego muestra datos del activo Modificado
                //ID, NOMBRE, DESCRIPCION
                break;

            case 4:
                //Renta de Activos
                cout << "\n############ ( Catalogo de Activos ) ############\n";
                //Muestra todos los activos DISPONIBLES
                cout << "Rentar activo (s/n)?";
                cin >> opS_N;
                if(opS_N =='s' || opS_N == 'S'){
                    cout<<"ID Activo a Rentar: ";
                    //Muestra datos del activo a Rentar
                    //ID, NOMBRE, DESCRIPCION

                    cout<<"Dias por Rentar: ";
                }
                break;

            case 5:
                //Activos Rentados
                cout << "\n############ ( Activos Rentados ) ############\n";
                //Muestra todos los activos RENTADOS si los hay

                cout << "Devolver activo (s/n)?";
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