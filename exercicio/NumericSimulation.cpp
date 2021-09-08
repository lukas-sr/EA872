#include <iostream>
#define G 10
#define T 0.1
#define alpha 0.8
/*
 * a = g = 10m/s²
 * T -> Período de amostragem || tempo total da simulação
 * delta_t = n*T, sendo n um vetor 
 * v = a*(delta_t)
 * v = a*(n*T)
 * v[n] = v[n-1]+a*T
 * x[n] = x[n-1]+v[n]*T 
 */


int main(){
    float a, v, x;
    int i=0;

    a = -G;
    x = 100;
    v = 0;
    
    while (x>0){
        printf("%d \t x=%.3f \t v=%.3f \t a=%.3f \n", i+1, x, v, a);
        v += a*T;   
        x += v*T;   
        i++;
    }
    printf("tempo de queda %f\n", i*T);
    


    return 0;
}
