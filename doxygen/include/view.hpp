
#pragma once

class View {
  private:
    int width, height;

  public:
    View();
    ~View();
    void render(float x, float y);
};


