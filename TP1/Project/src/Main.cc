// #include "../include/Base.hpp"
// #include <fstream>
// #include <iostream>
// #include <string>

// int main(int argc, char *argv[]) {

//   std::string arqMapa = std::string(argv[1]);
//   std::string arqComandos = argv[2];

//   std::string command = "";
//   int x = -1, y = -1, robot = -1;

//   Base b(arqMapa);

//   std::fstream f(arqComandos);
//   while (f >> command) {
//     f >> robot;
//     if (command == "MOVER" || command == "*MOVER") {
//       std::string temp;
//       std::getline(f, temp, '(');
//       f >> x;
//       std::getline(f, temp, ',');
//       f >> y;
//       std::getline(f, temp);
//       b.sendOrder(command, robot, x, y);
//     } else {
//       b.sendOrder(command, robot);
//     }
//   }
//   b.relatorioFinal();
//   return 0;
// }