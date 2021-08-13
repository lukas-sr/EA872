#pragma once

class Model {
  private:
    float x, y;

  public:
    Model();
    ~Model();
    float get_x();
    float get_y();
    void set_x(float new_x);
    void set_y(float new_y);
};
