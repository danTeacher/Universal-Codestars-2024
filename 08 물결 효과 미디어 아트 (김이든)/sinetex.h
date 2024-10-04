#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <math.h>
using namespace std;

void SineTex(SDL_Renderer* renderer,SDL_Surface* surf,SDL_Texture* ret,int angle,int increment,SDL_Rect source,SDL_Rect dest)
{
	SDL_RenderClear(renderer);
	
	for (int o = 0; o <= 255; o++)
	{
		source.x = 18+(sin(angle+(o/10))*increment);
		source.y = o;
		dest.y = o;
		ret = SDL_CreateTextureFromSurface(renderer,surf);
		SDL_SetTextureBlendMode(ret,SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(ret,255);
		SDL_RenderCopy(renderer,ret,&source,&dest);
		SDL_DestroyTexture(ret);
	}
}
