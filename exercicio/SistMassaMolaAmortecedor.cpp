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
class Params{                               // Parametros de massa, cte da mola e cte do amortecedor
    private:
        float m, k, b;
    public:
        Params();
        void set_params(float new_m, float new_k, float new_b);
        void return_params();
};

/* Controller */
class Simulacao{
    private:
        std::shared_ptr<Params> constantes;
    public:
        Simulacao();
        void run(int n_passos);
};

/* Definição dos métodos em Model */ 
Params::Params(){
    m = 0;
    k = 0;
    b = 0;
    std::cout<<"Classe Params Construída"<<std::endl;
}

void Params::set_params(float new_m, float new_b, float new_k){
    m = new_m;
    b = new_b;
    k = new_k;
}

void Params::return_params(){
    std::cout<<"Massa: "<<m<<std::endl;
    std::cout<<"Cte B: "<<b<<std::endl;
    std::cout<<"Cte K: "<<k<<std::endl;
}

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
