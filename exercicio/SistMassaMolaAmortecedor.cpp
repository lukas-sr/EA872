/* @EA872 - Exercício 2
 * 
 * Lukas Silva da Rosa  RA:183167
 * 
 * SISTEMA MASSA MOLA AMORTECEDOR
 * EDO: y'' + b/m y'' + k/m y = F(t)
 * y(t) = A*e^(w1*t) + B*e^(w2*t) = x0
 * y'(t) = w1*A*e^(w1*t)+w2*B*e^(w2*t) = v0
 * y”(t) = [w1²]*A*e^(w1*t) + [w2²]*B*e^(w2*t) = a0
 */

#include <iostream>
#include <math.h>
#include <memory>

/* Model */
class Model{
    private:
        /* Massa, constantes da mola e amortecedor */
        float m, k, b;
        /* Posição em x, velocidade em x e aceleração em x*/
        float pos_x, vel_x, acc_x;
        /* Condições em t=0 */
        float x0, v0, a0;
        /* Variaveis auxiliares */
        float A, B;
    public:
        Model();
        void set_consts(float new_m, float new_k, float new_b, float new_x0, float new_v0, float new_a0);
        void set_params(float new_pos_x, float new_vel_x, float new_acc_x);
        float get_m() { return m; };
        float get_b() { return b; };
        float get_k() { return k; };
        float get_pos_x() { return pos_x; };
        float get_vel_x() { return vel_x; };
        float get_acc_x() { return acc_x; };
        //float get_params();
};

Model::Model(){
    m = k = b = 1;
    pos_x = vel_x = acc_x = 0;
    x0 = v0 = a0 = 0;
    A = B = 0;
}

void Model::set_consts(float new_m, float new_k, float new_b, float new_x0, float new_v0, float new_a0){
    m = new_m;
    k = new_k;
    b = new_b;
    x0 = new_x0;
    v0 = new_v0;
    a0 = new_a0;
}   

void Model::set_params(float new_pos_x, float new_vel_x, float new_acc_x){
    pos_x = new_pos_x;
    vel_x = new_vel_x;
    acc_x = new_acc_x;
}

/* View */
class  View{
    private:
    public:
};
/* Controller */
class Controller{
    private:
        Model M;
    public:
        Controller();
        /* passo da simulação */
        float step_simulation();
};

Controller::Controller(){
    /* m = 50
     * k = 100
     * b = 1
     * x0 = 1
     * v0 = 0
     * a0 = 0
     * */
    M.set_consts(50, 100, 1, 1, 0, 0);
    //M.set_params();
}

float Controller::step_simulation(){
    float m = M.get_m();
    float b = M.get_b();
    float k = M.get_k();
    float x = M.get_pos_x();
    float v = M.get_vel_x();
    float a = M.get_acc_x();
    float new_x, w, ww, alpha, delta=0.1;
    
    ww = k/m;
    w = sqrt(ww);
    alpha = b/(m*2*w);

    /*
    x_new = (x*(-ww*delta*delta+2)+(x_old')*(alpha*delta*w-1))/(1+delta*alpha*w);
    vx_new = (x_new-x_old)/2;
    x_old = x;
    x = x_new;
    vx = vx_new;
    return x_new
    */
    x += v*delta;
    new_x += (x*(-ww*delta*delta+2)+(x*alpha*delta*w-1))/(1+delta*alpha*w);
    v += (new_x-x)/2;
    
    x = new_x;

    M.set_params(x, v, a);

    return new_x;
    }

    /* Main */
    int main(){
        Model modelo;
        Controller controle;
        float posicao;
        
    for (int i = 0 ; i < 100 ; i++){
        posicao = controle.step_simulation();
        std::cout << posicao << std::endl;
    }
    
    return 0;
}
