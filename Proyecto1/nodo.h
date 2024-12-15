#include "lib_globales.h"
#include "avl.h"//esto permite la coneccion entre estructuras

class Nodo{

    private:
    string nomUsu, password, nomCompleto = "";
    string i_dep, j_empresa;
    int i, j;

    Nodo *arriba, *abajo;
    Nodo *izq, *dcha;
    Nodo *adelante, *atras;
    AVL *arbol_AVL;//esto permite la coneccion entre estructuras

    public:
    Nodo(int i, int j, string i_dep, string j_empresa);//Nodo cabecera
    Nodo(int i, int j, string i_dep, string j_empresa, string nomUsu, string password, string nomCompleto);//Nodo con datos em matriz

    void setIdep(string i_dep);
    void setJempresa(string j_empresa);
    void setI(int i);
    void setJ(int j);
    void setNomUsu(string nomUsu);
    void setPassword(string password);
    void setNomCompleto(string nomCompleto);

    void setArriba(Nodo *arriba);
    void setAbajo(Nodo *abajo);
    void setIzq(Nodo *izq);
    void setDcha(Nodo *dcha);
    void setAdelante(Nodo *adelante);
    void setAtras(Nodo *atras);

    string getIdep();
    string getJempresa();
    int getI();
    int getJ();
    string getNomUsu();
    string getPassword();
    string getNomCompleto();

    Nodo* getArriba();
    Nodo* getAbajo();
    Nodo* getIzq();
    Nodo* getDcha();
    Nodo* getAdelante();
    Nodo* getAtras();

    //esto permite la coneccion entre estructuras
    AVL* getAVL();
};