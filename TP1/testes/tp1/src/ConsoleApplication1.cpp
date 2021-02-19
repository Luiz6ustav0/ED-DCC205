#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "comandos.h"
#include "cell.h"
#include "base.h"

#define ROBOSQNT 50

using namespace std;


int main(int argc, char* argv[]) {
    //receber mapa e passar para uma matriz
    //R - Recurso | O - Obstaculo | H - Alien | . - região vazia | (i,j) - indice | (0,0) - B - Base
    //50 robos por base
    int i=0, j=0;
    char** mapa;
    comandos robo[ROBOSQNT];
    base base1;

    fstream mapafile(argv[1]);
    if (mapafile.is_open())
    {
        
        mapafile >> i >> j;
        char c;
        mapa = new char *[i];
        for (int s = 0; s < i; s++)
            mapa[s] = new char[j];
        while (!mapafile.eof()){
            for (int s = 0; s < i; s++) {
                for (int k = 0; k < j; k++) {
                    mapafile >> c;
                    mapa[s][k] = c;
                }
            }
            mapafile >> c;
        }
        base1.setmapa(mapa, i, j);
        mapafile.close();
    }
    else cout << "Unable to open mapafile";

    char** m1 = base1.getmapa();

    fstream comandosfile(argv[2]);
    if (comandosfile.is_open())
    {
        while (!comandosfile.eof()) {
            string s, buff;
            int idRobo, Rx=0, Ry=0, prioridade = 0;
            comandosfile >> s;
            if (s[0] == '*') {
                s.erase(0,1);
                prioridade = 1;
            }
            if (s == "ATIVAR") {
                comandosfile >> idRobo;
                robo[idRobo].ativar(idRobo);
            }
            else if (s == "EXECUTAR") {
                comandosfile >> idRobo;
                robo[idRobo].executar(idRobo, m1, i, j);
            }
            else if (s == "RELATORIO") {
                comandosfile >> idRobo;
                robo[idRobo].relatorio();
            }
            else if (s == "RETORNAR") {
                comandosfile >> idRobo;
                robo[idRobo].retornar();
                base1.atualiza(robo[idRobo].get_Balien(), robo[idRobo].get_Brecursos());
            }
            else if (s == "MOVER") {
                comandosfile >> idRobo;
                char c; comandosfile >> c;
                getline(comandosfile, buff, ','); Rx = stoi(buff);
                getline(comandosfile, buff, ')'); Ry = stoi(buff);
                robo[idRobo].cache(s, prioridade, Rx, Ry);
            }
            else if (s == "COLETAR") {
                comandosfile >> idRobo;
                robo[idRobo].cache(s, prioridade);
            }
            else if (s == "ELIMINAR") {
                comandosfile >> idRobo;
                robo[idRobo].cache(s, prioridade);
            }
            prioridade = 0;
        }
        base1.relatoriogeral();
        comandosfile.close();
    }
    else cout << "Unable to open comandosfile";



   
}