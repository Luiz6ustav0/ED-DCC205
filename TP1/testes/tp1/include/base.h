#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "comandos.h"
#include "cell.h"

using namespace std;

class base
{
	public:
		base();
		void setmapa(char** m, int i, int j);
		void printmapa();
		char** getmapa();
		char getitem(int x, int y);
		void atualiza(int a, int r);
		void relatoriogeral();
	private:
		char** mapa;
		int mi, mj;
		int recursos;
		int aliens;

		friend class comandos;
};

#endif