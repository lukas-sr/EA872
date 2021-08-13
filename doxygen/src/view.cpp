#include <iostream>

#include "view.hpp"


View::View() {
  width = 640;
  height = 480;
}

void View::render(float x, float y)
{
  std::cout << x << "\t" << y << std::endl;
}

View::~View() { }
