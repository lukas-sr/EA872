
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
  std::ofstream arquivo1;
  arquivo1.open("teste.txt");
  arquivo1 << "Meu teste funciona!" << std::endl;
  arquivo1.close();

  std::ifstream arquivo2;
  std::stringstream s;
  arquivo2.open("teste.txt");
  if (arquivo2.is_open() ) {
    s << arquivo2.rdbuf();
    std::cout << s.str();
    arquivo2.close();
  } else {
    std::cout << "Algo deu errado!" << std::endl;
  }

  return 0;
}
