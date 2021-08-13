#pragma once

#include "model.hpp"
#include "view.hpp"

  /*! \brief Classe para o controller
   *
   *  Esta é a classe do controller.
   *  O controller sabe quem é o model e quem é o view.
   *  Ele também tem uma variável interna.
   *
   */

class Controller {
 private:
    Model model; /*!< Model (alocado previamente) */
    View view; /*!< View (alocado previamente) */
    int variavel_interna; /*!< Variavel interna */

  public:
    /*! \brief Construtor do controller
     *
     * Deve receber um model e um view previamente
     * alocados.
     *
     * \param model Um Model
     * \param view Um View
     * \return Nada (este é um construtor!)
     * */
    Controller(Model &model, View &view);

    /*! \brief Destrutor
     *
     * Acredito que possa ser vazio... */
    ~Controller();

    /*! \brief Executa o calculo de um passo
     *
     * Deve ser chamado dentro de um loop caso queira
     * executar a simulação várias vezes */
    void step();
};
