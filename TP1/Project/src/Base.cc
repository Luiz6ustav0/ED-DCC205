#include "../include/Base.hpp"

Base::Base(std::string fName) : aliens(0), recursos(0) {
  this->m = new PlanetMap(fName);
  for (int i = 0; i < 50; ++i) {
    this->r[i] = Robot(this->m, i);
  }
}

Base::~Base() { delete this->m; }

PlanetMap *Base::getMapPointer() { return this->m; }

void Base::relatorioFinal() const {
  std::cout << "BASE: TOTAL DE ALIENS " << this->aliens << " RECURSOS "
            << this->recursos << std::endl;
}

void Base::sendOrder(std::string str, int robo, int x, int y) {
  if (robo < 50 && robo >= 0) {
    if (str == "ATIVAR") {
      if (this->r[robo].isActivated()) {
        std::cout << "BASE: ROBO " << robo << " JA ESTA EM MISSAO" << std::endl;
      } else {
        this->r[robo].activate();
        std::cout << "BASE: ROBO " << robo << " SAIU EM MISSAO" << std::endl;
      }
    } else if (str == " EXECUTAR") {
      if (this->r[robo].isActivated()) {
        this->r[robo].execute();
      } else
        std::cout << "BASE: ROBO " << robo << " NAO ESTA EM MISSAO"
                  << std::endl;
    } else if (str == "RELATORIO") {
      this->r[robo].printHistory();
    } else if (str == "RETORNAR") {
      if (this->r[robo].isActivated()) {
        this->r[robo].move(0, 0);
        int tempAlien = this->r[robo].getAliens();
        int tempRecursos = this->r[robo].getRecursos();
        std::cout << "BASE: ROBO " << robo << " RETORNOU ALIENS " << tempAlien
                  << " RECURSOS " << tempRecursos << std::endl;
        this->aliens += tempAlien;
        this->r[robo].setAliens(0);
        this->recursos += tempRecursos;
        this->r[robo].setRecursos(0);
        this->r[robo].cleanHistory();
      } else
        std::cout << "BASE: ROBO " << robo << " NAO ESTA EM MISSAO"
                  << std::endl;
    } else {
      this->r[robo].receiveOrder(str, x, y);
    }
  }
}