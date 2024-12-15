#include "nodo.h"

class Matriz{
    private:
        Nodo *raiz;

        Nodo* buscarColumna(string i_dep);
        Nodo* buscarFila(string j_empresa);
        void insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna);
        void insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila);
        Nodo* insertarEncabezadoFila(string j_empresa);
        Nodo* insertarEncabezadoColumna(string i_dep);

    public:
        Matriz();
        ~Matriz();

        void insert(string i_dep, string j_empresa, string nomUsu, string password, string nomCompleto);
        bool existeNodo(Nodo *nuevo);
        void print();
        void insertActivos(string i_dep, string j_empresa, string nomUsu, string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible);
        void printActivos(string i_dep, string j_empresa, string nomUsu);
        void editActivo(string i_dep, string j_empresa, string nomUsu, string id_activo, string NdescActivo);
        bool ID_existente(string i_dep, string j_empresa, string nomUsu, string id_activo);
        void eliminarActivo(string i_dep, string j_empresa, string nomUsu, string id_activo);
        
        //Datos que permiten buscar al USUARIO:
        //(string i_dep, string j_empresa, string nomUsu) 

        //Datos que se envian hacia AVL:
        //(string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible);
        
        
        void graphMatriz();
};