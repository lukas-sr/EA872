
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"


int main()
{
  Model m;
  View v;
  Controller c (m, v);
  c.step();
  return 0;
}
