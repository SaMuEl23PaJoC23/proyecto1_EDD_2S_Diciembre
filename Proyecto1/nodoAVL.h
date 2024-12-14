#include "lib_globales.h"

class NodoAVL{
    private:
        string ID_activo, nomActivo, descActivo;
        int diasParaRentar;
        bool disponible;
        NodoAVL *izqAVL, *drchaAVL;
        int altura;

    public:
        NodoAVL(string ID_activo, string nomActivo, 
        string descActivo, int diasParaRentar, bool disponible);

        string getID_activo();
        string getNomActivo();
        string getDescActivo();
        int getDiasParaRentar();
        bool getDisponible();
        NodoAVL* getIzqAVL();
        NodoAVL* getDrchaAVL();
        NodoAVL* getHijoUnico();
        int getAltura();

        void setID_activo(string ID_activo);
        void setNomActivo(string nomActivo);
        void setDescActivo(string descActivo);
        void setDiasParaRentar(int diasParaRentar);
        void setDisponible(bool disponible);
        void setIzqAVL(NodoAVL* izqAVL);
        void setDrchaAVL(NodoAVL* drchaAVL);
        void setAltura(int altura);

        bool esHoja();
        bool tieneUnHijo();
        bool tieneDosHijos();
};