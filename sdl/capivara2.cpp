#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <math.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Model{
	private:
		float m,b,k;
	
	public: 
		void set_parametros(float new_m, float new_b, float new_k);
	
};

	void Model::set_parametros(float new_m, float new_b, float new_k){

	m = new_m;
	b = new_b;
	k = new_k;
	};

class Controller{
	private:
	
	public:
		float solve(Model M, float t, float T, float delta, float new_m, float new_b, float new_k, float *x_new, float *x_old, float *vx);
	};
		
float Controller::solve(Model M, float t, float T, float delta, float new_m, float new_b, float new_k, float *x_new, float *x_old, float *vx){

	float w, alpha, ww = new_k/new_m; 
	
	w = sqrt(ww);
	alpha = new_b/(new_m*2*w);
	float x, vx_new; // variaveis auxiliares
	
	M.set_parametros(new_m,new_b,new_k);
	// Atualiza a variavel auxiliar x antes de rodar o método	
	x = (*vx)*delta + (*x_old);
	//Novos valores de posição e velocidade
	*x_new = (x*(-ww*delta*delta +2) + (*x_old)*(alpha*delta*w -1))/(1 + delta*alpha*w);
	vx_new = ((*x_new)-(*x_old))/(2*delta);
	//Atualiza ponteiros	
	*x_old = x;
	x = (*x_new);
	*vx = vx_new;

	printf("%f %f\n", *x_new, *vx);
	return *x_new;
}
				
			
int main() {
  // Inicializando o subsistema de video do SDL
  if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
    std::cout << SDL_GetError();
    return 1;
  }

  // Criando uma janela
  SDL_Window* window = nullptr;
  window = SDL_CreateWindow("Demonstracao do SDL2",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  if (window==nullptr) { // Em caso de erro...
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }

  // Inicializando o renderizador
  SDL_Renderer* renderer = SDL_CreateRenderer(
      window, -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer==nullptr) { // Em caso de erro...
    SDL_DestroyWindow(window);
    std::cout << SDL_GetError();
    SDL_Quit();
    return 1;
  }
	
  Model M;
  Controller C;

  float m = 50,b = 1,k = 100;
  float T = 10;
  float t = 0, delta = T/1000;	
  float *x_new, *x_old, *vx;
  
  *x_old = 0;
  *x_new = 0;
  *vx = 5;
  
  M.set_parametros(m,b,k);
  
  // Carregando texturas
  // personagem
  SDL_Texture *texture = IMG_LoadTexture(renderer, "./capi.png");
  // fundo
  SDL_Texture *texture2 = IMG_LoadTexture(renderer, "./park.jpeg");

  // Quadrado onde a textura sera desenhada
  SDL_Rect target;
  target.x = 100;
  target.y = 100;
  SDL_QueryTexture(texture, nullptr, nullptr, &target.w, &target.h);

  // Controlador:
  bool rodando = true;

  // Variaveis para verificar eventos
  SDL_Event evento; // eventos discretos
  const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado

  // Laco principal do jogo
  while(rodando && t<T) {
    // Polling de eventos
    SDL_PumpEvents(); // atualiza estado do teclado
  
    //float solve(Model M, float t, float T, float delta, float new_m, float new_b, float new_k, float *x_new, float *x_old, float *vx);
    target.x = 50*C.solve(M,t,T,delta,m,b,k,x_new,x_old,vx);
    printf("targetX: %d\n", target.x);
    t = t+delta;
    /*
    if (state[SDL_SCANCODE_LEFT]) target.x -= 1;
    if (state[SDL_SCANCODE_RIGHT]) target.x += 1;
    if (state[SDL_SCANCODE_UP]) target.y -= 1;
    if (state[SDL_SCANCODE_DOWN]) target.y += 1;
*/

    while (SDL_PollEvent(&evento)) {
      if (evento.type == SDL_QUIT) {
        rodando = false;
      }
      // Exemplos de outros eventos.
      // Que outros eventos poderiamos ter e que sao uteis?
      //if (evento.type == SDL_KEYDOWN) {
      //}
      //if (evento.type == SDL_MOUSEBUTTONDOWN) {
      //}
    }

    // Desenhar a cena
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture2, nullptr, nullptr);
    SDL_RenderCopy(renderer, texture, nullptr, &target);
    SDL_RenderPresent(renderer);

    // Delay para diminuir o framerate
    SDL_Delay(10);
  }

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
