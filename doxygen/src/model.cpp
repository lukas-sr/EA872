#include "model.hpp"

Model::Model() {
  x=0;
  y=0;
}

float Model::get_x() { return x; }
float Model::get_y() { return y; }
void Model::set_x(float new_x) { x = new_x; }
void Model::set_y(float new_y) { y = new_y; }

Model::~Model() {
}
