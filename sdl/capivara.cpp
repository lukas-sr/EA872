#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

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
		float solve(Model M, float T, float new_m, float new_b, float new_k);
		};
		
float Controller::solve(Model M, float T, float new_m, float new_b, float new_k){
		int  N;
		float delta=T/100;
		float ax = 0, t = 0;
				
		float x_new, x=0, vx_new, vx=1;
		N = int(T/delta);
	
        //M.set_parametros(1,1,1);
		//ax = (-g -k*x -b*v)/m;

        for(t=0;t<T;t=t+delta){
			vx_new = vx + ax*t;
			x_new = x + vx_new*t;
			}
		return x_new;
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

  float m=1,b=0.5,k=1;
  float T = 10;	
  M.set_parametros(m,b,k);
  Controller C;
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
  while(rodando) {
    // Polling de eventos
    SDL_PumpEvents(); // atualiza estado do teclado
  
  
    target.x -= C.solve(M,T,m,b,k);


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
