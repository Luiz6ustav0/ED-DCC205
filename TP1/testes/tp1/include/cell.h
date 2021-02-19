#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <string>

using namespace std;

class cell
{
	public:
		cell();
	private:
		string s;
		int Rx;
		int Ry;
		cell* prox;

	friend class comandos;
};

#endif