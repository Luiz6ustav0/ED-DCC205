#include "comandos.h"
#include "cell.h"
#include "base.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

comandos::comandos()
{
	primeiro_hist = new cell();
	ultimo_hist = primeiro_hist;
	primeiro = new cell();
	ultimo = primeiro;
	tamanho = 0;
	tamanho_hist = 0;
	recursos = 0;
	aliens = 0;
	ativo = 0;
	coord_x = 0;
	coord_y = 0;
	ID = 0;
}

comandos::~comandos()
{
	limpa();
	delete primeiro;
	delete primeiro_hist;
}

void comandos::cache(string s, int prioridade, int Rx, int Ry)
{
	cell* nova;
	nova = new cell();
	nova->s = s;
	nova->Rx = Rx;
	nova->Ry = Ry;
	if (prioridade == 1) {
		nova->prox = primeiro->prox;
		primeiro->prox = nova;
	}
	else {
		ultimo->prox = nova;
		ultimo = nova;
	}
	tamanho++;
}

void comandos::limpa()
{
	cell* p;
	p = primeiro->prox;
	while (p != NULL) {
		primeiro->prox = p->prox;
		delete p;
		p = primeiro->prox;
	}
	ultimo = primeiro;
	tamanho = 0;
}

void comandos::limpa_hist()
{
	cell* p;
	p = primeiro_hist->prox;
	while (p != NULL) {
		primeiro_hist->prox = p->prox;
		delete p;
		p = primeiro_hist->prox;
	}
	ultimo_hist = primeiro_hist;
	tamanho_hist = 0;
}

void comandos::ativar(int idRobo)
{
	ID = idRobo;
	if (ativo == 1)
		cout << "BASE: ROBO " << idRobo << " JA ESTA EM MISSAO" << "\n";
	else {
		ativo = 1;
		cout << "BASE: ROBO " << idRobo << " SAIU EM MISSAO" << "\n";
	}
}

void comandos::executar(int idRobo, char** m1, int i, int j)
{
	if (ativo == 0) {
		cout << "BASE: ROBO " << idRobo << " NAO ESTA EM MISSAO" << "\n";
	}
	else {
		cell* p;
		p = primeiro;
		for (int i = 0; i < tamanho; i++) {
			p = p->prox;
			if (p->s == "MOVER") {
				mover(p->Rx, p->Ry, m1, i, j);
			}
			else if (p->s == "COLETAR")
				coletar(coord_x, coord_y, m1);
			else if (p->s == "ELIMINAR")
				eliminar(coord_x, coord_y, m1);
		}
		limpa();
	}
}

void comandos::relatorio()
{
	cell* p;
	p = primeiro_hist;
	for (int i = 0; i < tamanho_hist; i++) {
		p = p->prox;
		cout << p->s << "\n";
	}
}

void comandos::retornar()
{
	if (ativo == 0) {
		cout << "BASE: ROBO " << ID << " NAO ESTA EM MISSAO" << "\n";
	}
	else {
		coord_x = 0;
		coord_y = 0;
		ativo = 0;
		cout << "BASE: ROBO " << ID << " RETORNOU ALIENS " << aliens << " RECURSOS " << recursos << "\n";
	}
	limpa_hist();

}

void comandos::mover(int x, int y, char** m1, int i, int j)
{
	char c = m1[x][y];
	if (c == 'O') {
		string s = "ROBO " + to_string(ID) + ": IMPOSSIVEL MOVER PARA (" + to_string(x) + "," + to_string(y) + ")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}
	else{
		coord_x = x;
		coord_y = y;
		string s = "ROBO "+ to_string(ID) +": MOVEU PARA ("+ to_string(x) +","+ to_string(y) +")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}
}

void comandos::coletar(int x, int y, char** m1)
{
	char c = m1[x][y];
	if (c != 'R') {
		string s = "ROBO " + to_string(ID) + ": IMPOSSIVEL COLETAR RECURSOS EM (" + to_string(x) + "," + to_string(y) + ")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}
	else {
		m1[x][y] = '.';
		recursos++;
		string s = "ROBO " + to_string(ID) + ": RECURSOS COLETADOS EM (" + to_string(x) + "," + to_string(y) + ")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}

}

void comandos::eliminar(int x, int y, char** m1)
{
	char c = m1[x][y];
	if (c != 'H') {
		string s = "ROBO " + to_string(ID) + ": IMPOSSIVEL ELIMINAR ALIEN EM (" + to_string(x) + "," + to_string(y) + ")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}
	else {
		m1[x][y] = '.';
		aliens++;
		string s = "ROBO " + to_string(ID) + ": ALIEN ELIMINADO EM (" + to_string(x) + "," + to_string(y) + ")";

		cell* nova;
		nova = new cell();
		nova->s = s;
		ultimo_hist->prox = nova;
		ultimo_hist = nova;
		tamanho_hist++;
	}
}

int comandos::get_Balien()
{
	int i = aliens;
	aliens = 0;
	return i;
}

int comandos::get_Brecursos()
{
	int i = recursos;
	recursos = 0;
	return i;
}
