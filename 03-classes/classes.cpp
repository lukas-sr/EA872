
#include <iostream>

class MinhaClasse {
  private:
    int count;

  public:
    MinhaClasse(); // Construtor
    ~MinhaClasse(); // Destrutor
    void go();
};

void MinhaClasse::go() {
  count = count + 1;
  std::cout << count << std::endl;
}

MinhaClasse::MinhaClasse() {
  count = 0;
}

MinhaClasse::~MinhaClasse() {
  std::cout << "Adeus mundo cruel\n";
}

void escopo() {
  MinhaClasse c1;
  MinhaClasse c2;
  std::cout << "Ola, mundo\n";
  c1.go();
  c1.go();
  c2.go();
}

int main()
{
  escopo();
  return 0;
}
