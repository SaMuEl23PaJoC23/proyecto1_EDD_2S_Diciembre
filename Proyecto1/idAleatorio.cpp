#include "lib_globales.h"

class idAleatorio{

    public:
        string ID_random(){//metodo que permite generar ID aleatoriamente
            string cadena = "";
            int letraAleatoria = 0;
            string simbolos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";// 62 caracteres
            //numAleatorio = 1 (rand() % 9);// devuelve numeros aleatorios entre 1 - 9, sin el 1 serian de 0 - 9.

            for(int i = 0; i < 15; i++){
                letraAleatoria = rand() % (62);
                cadena += simbolos[letraAleatoria];    
            }
            return cadena;
        }
};