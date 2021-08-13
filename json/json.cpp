

#include <iostream>

#include <vector>

#include "json.hpp"
using nlohmann::json;

// Solucao naive: nao faca isso!!!!
class MinhaClasse : public json  {
  public:
    int get_value() { return (*this)["i"]; };
    void set_value(int i) { (*this)["i"] = i; };
};

// Veja como definimos uma macro...
class OutraClasse {
  private:
    int i;

  public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(OutraClasse, i);
    int get_value() { return i; };
    void set_value(int i0) { i=i0; };
};

// A estrutura de arvore das suas classes vai aparecer
// no arquivo JSON...
class Conteiner {
  private:
    OutraClasse c;
  public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Conteiner, c);
    int get_value() { return c.get_value(); };
    void set_value(int i0) { c.set_value(i0); };
};

int main() {
  // Usos basicos do JSON
  json j;
  j["teste"] = 33.5;
  j["outro teste"] = 50.1;

  // json aceita vetores
  std::vector<int> v;
  v.push_back(876);
  v.push_back(872);
  j["meu vetor"] = v;

  // Posso colocar um json dentro de um json
  OutraClasse c;
  c.set_value(40);
  j["minha classe"] = c;

  // e tambem posso colocar um vetor de json
  std::vector<OutraClasse> vdmc(2);
  vdmc[0].set_value(60);
  vdmc[1].set_value(10);
  j["vdmc"] = vdmc;

  // Posso intercambiar classes, se as serializacoes forem
  // compativeis!
  OutraClasse d;
  d = j["minha classe"];
  std::cout << d.get_value() << std::endl;

  // e uma classe serializavel que agrega outra classe
  // serializavel!
  Conteiner ctnr;
  ctnr.set_value(30);
  j["conteiner"] = ctnr;

  // Quanto volto, minha estrutura esta toda de-serializada.
  Conteiner ctnr2;
  ctnr2 = j["conteiner"];
  std::cout << ctnr2.get_value() << std::endl;

  std::cout << j << std::endl;

  return 0;
}

