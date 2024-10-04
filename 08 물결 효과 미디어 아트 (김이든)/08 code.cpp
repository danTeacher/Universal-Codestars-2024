#include "sinetex.h"
using namespace std;
const int SCREEN_W = 255;
const int SCREEN_H = 255;
const int TEXTURE_W = 255;
const int TEXTURE_H = 255;
float rhoma = 0;
float sancta = 0;
float swirla = 0;
float zigzaga = 0;
int sptr = 0;
bool rhomb = true;
bool sanctb = false;
bool swirlb = false;
bool zigzagb = false;
int rhomi = 1;
int sancti = 1;
int swirli = 1;
int zigzagi = 1;

float angleman(float angle);

int main()
{
	//Declarations
	SDL_Init(SDL_INIT_EVERYTHING);
	//window
	SDL_Window* window = SDL_CreateWindow("Earthbound Background Generator",640,640,SCREEN_W*4,SCREEN_H*4,0);
	//renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,0);
	SDL_RenderSetScale(renderer,4,4);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	//events
	SDL_Event event;
	bool quit = false;
	//rect
	//surfaces
	SDL_Surface* rhom  = IMG_Load("/home/yiden/stuff/rhom.png");
	SDL_Surface* sanct = IMG_Load("/home/yiden/stuff/sanct.png");
	SDL_Surface* swirl = IMG_Load("/home/yiden/stuff/swirl.png");
	SDL_Surface* zigzag = IMG_Load("/home/yiden/stuff/zigzag.png");
	//stuff
	SDL_Texture* tex = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,TEXTURE_W,TEXTURE_H/255);
	SDL_Rect source{18,0,TEXTURE_W-36,1};
	SDL_Rect dest{0,0,255,1};	
	
	//Set default background
	SDL_SetRenderDrawColor(renderer,0,0,0,255);

	//Main Loop
	while(!quit)
	{
		//Event Handling
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				quit = true;
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_1:	if(rhomb) rhomb = false; else rhomb = true; sptr = 1; break;
					case SDLK_2:	if(sanctb) sanctb = false; else sanctb = true; sptr = 2; break;
					case SDLK_3:	if(swirlb) swirlb = false; else swirlb = true; sptr = 3; break;
					case SDLK_4:	if(zigzagb) zigzagb = false; else zigzagb = true; sptr = 4; break;
					case SDLK_UP:
							if(sptr == 1){rhomi++;} if(sptr == 2){sancti++;} if(sptr == 3){swirli++;} if(sptr == 4){zigzagi++;} break;
					case SDLK_DOWN:	
							if(sptr == 1){rhomi--;} if(sptr == 2){sancti--;} if(sptr == 3){swirli--;} if(sptr == 4){zigzagi--;} break;
				}
			}
		}
		
		//Check and load textures

		if (rhomb)
			SineTex(renderer,rhom,tex,rhoma,rhomi,source,dest);
		if (sanctb)
			SineTex(renderer,sanct,tex,sancta,sancti,source,dest);
		if (swirlb)
			SineTex(renderer,swirl,tex,swirla,swirli,source,dest);
		if (zigzagb)
			SineTex(renderer,zigzag,tex,zigzaga,zigzagi,source,dest);
		if (rhomb == false&& sanctb == false&& swirlb == false && zigzagb == false)
			SDL_RenderClear(renderer);

		//Angle manager
		rhoma = angleman(rhoma);
		sancta = angleman(sancta);
		swirla = angleman(swirla);
		zigzaga = angleman(zigzaga);
		cout << rhomi << " " << sancti << " " << swirli << " " << zigzagi << endl;
		
		//Render
		SDL_RenderPresent(renderer);
		SDL_Delay(5);
	
	}	
	
	//Mandatory mr. return 0;
	return 0;
}

float angleman(float angle)
{
	if (angle == 360)
		angle = 0;
	else
		angle += 1;
	return angle;	
}