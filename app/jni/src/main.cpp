#include <SDL.h>
#include <SDL_image.h>

SDL_Window*		gWindow = nullptr;
SDL_Renderer*	gRenderer = nullptr;
SDL_Rect		gScreenRect = { 0, 0, 360, 640 };

int main(int, char* [])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			SDL_Log("Warning:Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gScreenRect.w, gScreenRect.h, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			SDL_Log("PANIC: Window could not be created! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				SDL_Log("PANIC: Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					SDL_Log("PANIC: SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				}
				else
				{
					if (!SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND))
					{
						SDL_Log("Warning: SDL_SetRenderDrawBlendMode, SDL Error: %s\n", SDL_GetError());
					}

					SDL_GetWindowSize(gWindow, &gScreenRect.w, &gScreenRect.h);

					{
						SDL_Texture* texture = IMG_LoadTexture(gRenderer, "sdl2.png");
						SDL_Rect srcRect{ 0, 0, 268, 505 };
						SDL_Rect dstRect{ gScreenRect.w / 2 - srcRect.w / 2, gScreenRect.h / 2 - srcRect.h / 2, srcRect.w, srcRect.h };

						bool quit = false;
						SDL_Event e;
						while (!quit)
						{
							while (SDL_PollEvent(&e) != 0)
							{
								if (e.type == SDL_KEYDOWN)
								{
									switch (e.key.keysym.sym)
									{
									case SDLK_ESCAPE: quit = true; break;
									}
								}
								if (e.type == SDL_QUIT)
								{
									quit = true; break;
								}
							}

							if (quit)
								break;

							SDL_SetRenderDrawColor(gRenderer, 64, 128, 255, 255);
							SDL_RenderClear(gRenderer);
							SDL_RenderCopy(gRenderer, texture, &srcRect, &dstRect);
							SDL_RenderPresent(gRenderer);
						}

						if (texture) SDL_DestroyTexture(texture); texture = nullptr;
					}
				}
			}
		}
	}

	if (gRenderer) SDL_DestroyRenderer(gRenderer); gRenderer = nullptr;
	if (gWindow) SDL_DestroyWindow(gWindow); gWindow = nullptr;

	IMG_Quit();
	SDL_Quit();

	return 0;
}
