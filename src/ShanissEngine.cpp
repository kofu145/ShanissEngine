// ShanissEngine.cpp : Defines the entry point for the application.
//

#include "ShanissEngine.h"
#include "src/utils/deleter.h"
#include <SDL.h>
#include <SDL_image.h>

/*
using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
*/

// ich bin leiden
// bitte, hilf mir.

namespace ShanissCore
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	std::unique_ptr<ShanissEngine, Deleter<ShanissEngine>> ShanissEngine::instance = nullptr;

	ShanissEngine* ShanissEngine::getInstance(){
		if (ShanissEngine::instance == nullptr){
            ShanissEngine::instance = std::unique_ptr<ShanissEngine, Deleter<ShanissEngine>>();

        }
    
        return ShanissEngine::instance.get();
	}

	ShanissEngine::~ShanissEngine()
	{
		
	}

	void ShanissEngine::init() 
	{
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
		{
			printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
			
		}

		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		ShanissEngine::getInstance()->window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( ShanissEngine::getInstance()->window  == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			
		}

		//Create renderer for window
		ShanissEngine::getInstance()->renderer = SDL_CreateRenderer
		(
			ShanissEngine::getInstance()->window, -1, SDL_RENDERER_ACCELERATED 
		);

		if( ShanissEngine::getInstance()->renderer == NULL )
		{
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor
			(
				ShanissEngine::getInstance()->renderer, 0xFF, 0xFF, 0xFF, 0xFF
			);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				
			}
		}

	}

	SDL_Window* ShanissEngine::getWindow()
	{
		return ShanissEngine::getInstance()->window;
	}

	SDL_Renderer* ShanissEngine::getRenderer()
	{
		return ShanissEngine::getInstance()->renderer;
	}

}
