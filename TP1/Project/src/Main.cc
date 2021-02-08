// #include "../include/Base.hpp"
// #include <fstream>
// #include <iostream>
// #include <sstream>
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
//       std::string chars = " (";
//       std::string temp;
//       std::getline(f, temp);
//       temp.erase(0, temp.find_first_not_of(chars));
//       temp.replace(temp.begin(), temp.end(), ',', ' ');
//       std::stringstream ss(temp);
//       ss >> x;
//       ss >> y;
//       b.sendOrder(command, robot, x, y);
//     } else {
//       b.sendOrder(command, robot);
//     }
//   }
//   b.relatorioFinal();
//   return 0;
// }