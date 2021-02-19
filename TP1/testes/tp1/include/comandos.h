#ifndef COMANDOS_H
#define COMANDOS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "cell.h"
#include "base.h"

using namespace std;

class comandos
{
	public:
		comandos();
		~comandos();
		void cache(string s, int prioridade, int Rx = 0, int Ry = 0);
		void limpa();
		void limpa_hist();
		void ativar(int idRobo);
		void executar(int idRobo, char **m1, int i, int j);
		void relatorio();
		void retornar();
		void mover(int x, int y, char** m1, int i, int j);
		void coletar(int x, int y, char** m1);
		void eliminar(int x, int y, char** m1);
		int get_Balien();
		int get_Brecursos();
	private:
		int ID;
		int recursos;
		int aliens;
		int coord_x;
		int coord_y;
		bool ativo;
		int tamanho;
		cell* primeiro;
		cell* ultimo;
		int tamanho_hist;
		cell* primeiro_hist;
		cell* ultimo_hist;

		friend class base;
};

#endif