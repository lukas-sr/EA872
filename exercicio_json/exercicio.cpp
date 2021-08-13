
#include <iostream>

class Contador {
  private:
    int contagem;

  public:
    Contador() { contagem=0; }
    void contar() { contagem++; }
    int get_contagem() { return contagem; }
};

int main() {
  Contador c;

  std::cout << "Este programa executou: " << c.get_contagem() << " vezes " << std::endl;

  return 0;
}
