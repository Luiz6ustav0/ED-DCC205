#include "../include/Base.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::stringstream readPositionFromStringToStream(std::string &s) {
  std::string chars = " (";
  s.erase(0, s.find_first_not_of(chars));
  std::replace(s.begin(), s.end(), ',', ' ');
  std::stringstream ss(s);
  return ss;
}

int main(int argc, char *argv[]) {

  std::string arqMapa = std::string(argv[1]);
  std::string arqComandos = argv[2];

  std::string command = "";
  int x = -1, y = -1, robot = -1;

  Base b(arqMapa);

  std::fstream f(arqComandos);
  while (f >> command) {
    f >> robot;
    if (command == "MOVER" || command == "*MOVER") {
      std::string temp;
      std::getline(f, temp);
      std::stringstream ss = readPositionFromStringToStream(temp);
      ss >> x;
      ss >> y;
      b.sendOrder(command, robot, x, y);
    } else {
      b.sendOrder(command, robot);
    }
  }
  b.relatorioFinal();
  return 0;
}