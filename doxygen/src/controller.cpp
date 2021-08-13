#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

Controller::Controller(Model &model, View &view) : model(model),
                                                   view(view)
{
  variavel_interna = 0;
}

void Controller::step() {
  variavel_interna ++;
  view.render(0.5, 0.2);
}

Controller::~Controller() {
  /** Esta documentacao esta no arquivo cpp
   *
   */

}
