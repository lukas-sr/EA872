#include "json.hpp"
#include <fstream>
#include <iostream>

using nlohmann::json;

int main() {
  json j;
  int i = 50;
  j["teste"] = i;

  std::ofstream f;
  f.open("teste.json");
  f << j;
  f.close();


  json j2;
  std::ifstream f2;
  f2.open("teste.json");
  f2 >> j2;
  f2.close();

  std::cout << j2 << std::endl;

  int i2 = j2["teste"];
  std::cout << i2 << std::endl;

  return 0;


}
