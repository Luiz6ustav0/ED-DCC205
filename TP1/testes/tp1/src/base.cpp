#include "base.h"
#include "comandos.h"
#include "cell.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

base::base()
{
	mapa = NULL;
	mi = 0;
	mj = 0;
	recursos = 0;
	aliens = 0;
}

void base::setmapa(char** m, int i, int j)
{
	mapa = new char* [i];
	for (int s = 0; s < i; s++)
		mapa[s] = new char[j];
	for (int s = 0; s < i; s++) {
		for (int k = 0; k < j; k++) {
			mapa[s][k] = m[s][k];
		}
	}
	mi = i;
	mj = j;
}

void base::printmapa()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << mapa[i][j];
		cout << "\n";
	}
}

char** base::getmapa()
{
	return mapa;
}

char base::getitem(int x, int y)
{
	char c = mapa[x][y];
	return c;
}

void base::atualiza(int a, int r)
{
	aliens = aliens + a;
	recursos = recursos + r;
}

void base::relatoriogeral()
{
	cout << "BASE: TOTAL DE ALIENS " << aliens << " RECURSOS " << recursos << "\n";
}
