#include <stdbool.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_mixer.h>

int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
    Mix_Music *m = NULL;

	// Check args
	if (argc != 2)
	{
		printf("Usage: sdl_mixer_vgm_test <filename>\n");
		goto bail;
	}

	// Init SDL
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		printf("SDL_Init error: %s\n", SDL_GetError());
		goto bail;
	}

	// Load music from file
	m = Mix_LoadMUS(argv[1]);
	if (m == NULL)
	{
		printf("Failed to load music from file %s: %s\n", argv[1], SDL_GetError());
		goto bail;
	}

	window = SDL_CreateWindow(
		argv[1], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		100, 100, 0);
	if (window == NULL)
	{
		printf("Failed to create window: %s\n", SDL_GetError());
		goto bail;
	}

    // Play the music
    if (Mix_PlayMusic(m, 0) == -1)
    {
		printf("Failed to play music: %s\n", SDL_GetError());
		goto bail;
    }

	// Wait for keypress to exit
	bool quit = false;
	while (!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_Delay(100);
	}


bail:
    Mix_FreeMusic(m);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
