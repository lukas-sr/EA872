/* @EA872 - Exercício 2
 * 
 * Lukas Silva da Rosa  RA:183167
 * 
 * SISTEMA MASSA MOLA AMORTECEDOR
 * 
 * EDO: x'' + b/m x' + k/m x = F(t) 
 */

#include <iostream>
#include <memory>

/* Model */
<<<<<<< HEAD
class Bloco{
    private:
        /*Massa, posição, velocidade e aceleração*/
        float m, p, v, a;

    public:
        Bloco();
        void bloco_set_params(float new_m);
};

class Mola{
    private:
        float k;
    public:
        Mola();
        void mola_set_params(float new_k);
}

class Amortecedor{
    private:
        float b;
    public:
        Amortecedor();
        void amort_set_params(float new_b);
}

/* Controller */
class Simulacao{
    private:
        std::shared_ptr<Params> constantes;
    public:
        Simulacao();
        void run(int n_passos);
};


/* Definição dos métodos em Controler */
Simulacao::Simulacao(){
    std::cout<<"Classe Simulação Construída"<<std::endl;
}

void Simulacao::run(int n_passos){
    /* -> x''+ b/m x' + k/m x = F(t)
     * -> x''+ b/m x' + k/m x = 0
     * -> l^2 + b/m l + k/m = 0
     * -> Delta = (b/m)^2 - 4*(k/m)
     * l1 = (-b/m + sqrt(Delta))/2
     * l2 = (-b/m - sqrt(Delta))/2
     * x(t) = A*e^(l1*t) + B*e^(l2*t)
     * */
    float x, t, delta, lambda1, lambda2;

    for (int i = 0; i < 10; i++){
        std::cout<<"doideira";
    }
}

/* Main */
int main(){
    Params p;
    p.set_params(10.5, 5.5, 3.9);
    p.return_params();

    return 0;
}
