#define SDL_MAIN_HANDLED
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <cstdlib>
#include "Warhammer Render.h"
#include "Render Medieval2.h"
#include "Render Shogun.h"
#include "Render Rome.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

bool running = true;

int main() {
	SDL_Init(SDL_INIT_EVERYTHING);
	if (TTF_Init() < 0) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		return 0;
	}
	srand(time(NULL));
	SDL_Window* window = SDL_CreateWindow("Total War Faction Picker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	RenderWarhammer WarhammerScreen;
	RenderMedieval Medieval2Screen;
	RenderShogun ShogunScreen;
	RenderRome RomeScreen;
	

	WarhammerScreen.DrawWarhammer(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	while (running) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}
			else if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
				if (WarhammerScreen.RenderingWarhammer == true) {
					WarhammerScreen.CheckMousePositions(event, renderer, window);
					if (WarhammerScreen.MedievalSelected == true) {
						WarhammerScreen.RenderingWarhammer = false;
						Medieval2Screen.RenderingMedieval = true;
						Medieval2Screen.DrawMedieval(renderer);
						SDL_RenderPresent(renderer);
						WarhammerScreen.MedievalSelected = false;
					}
					else if (WarhammerScreen.ShogunSelected == true) {
						WarhammerScreen.RenderingWarhammer = false;
						ShogunScreen.RenderingShogun = true;
						ShogunScreen.DrawShogun(renderer);
						SDL_RenderPresent(renderer);
						WarhammerScreen.ShogunSelected = false;
					}
					else if (WarhammerScreen.RomeSelected == true) {
						WarhammerScreen.RenderingWarhammer = false;
						RomeScreen.RenderingRome = true;
						RomeScreen.DrawRome(renderer);
						SDL_RenderPresent(renderer);
						WarhammerScreen.RomeSelected = false;
					}
				}
				else if (Medieval2Screen.RenderingMedieval == true) {
					Medieval2Screen.CheckMousePositions(event, renderer, window);
					if (Medieval2Screen.WarhammerSelected == true) {
						Medieval2Screen.RenderingMedieval = false;
						WarhammerScreen.RenderingWarhammer = true;
						WarhammerScreen.DrawWarhammer(renderer);
						SDL_RenderPresent(renderer);
						Medieval2Screen.WarhammerSelected = false;
					}
					else if (Medieval2Screen.ShogunSelected == true) {
						Medieval2Screen.RenderingMedieval = false;
						ShogunScreen.RenderingShogun = true;
						ShogunScreen.DrawShogun(renderer);
						SDL_RenderPresent(renderer);
						Medieval2Screen.ShogunSelected = false;
					}
					else if (Medieval2Screen.RomeSelected == true) {
						Medieval2Screen.RenderingMedieval = false;
						RomeScreen.RenderingRome = true;
						RomeScreen.DrawRome(renderer);
						SDL_RenderPresent(renderer);
						Medieval2Screen.RomeSelected = false;
					}
				}
				else if (ShogunScreen.RenderingShogun == true) {
					ShogunScreen.CheckMousePositions(event, renderer, window);
					if (ShogunScreen.WarhammerSelected == true) {
						ShogunScreen.RenderingShogun = false;
						WarhammerScreen.RenderingWarhammer = true;
						WarhammerScreen.DrawWarhammer(renderer);
						SDL_RenderPresent(renderer);
						ShogunScreen.WarhammerSelected = false;
					}
					else if (ShogunScreen.MedievalSelected == true) {
						ShogunScreen.RenderingShogun = false;
						Medieval2Screen.RenderingMedieval = true;
						Medieval2Screen.DrawMedieval(renderer);
						SDL_RenderPresent(renderer);
						ShogunScreen.MedievalSelected = false;
					}
					else if (ShogunScreen.RomeSelected == true) {
						ShogunScreen.RenderingShogun = false;
						RomeScreen.RenderingRome = true;
						RomeScreen.DrawRome(renderer);
						SDL_RenderPresent(renderer);
						ShogunScreen.RomeSelected = false;
					}
				}
				else if (RomeScreen.RenderingRome == true) {
					RomeScreen.CheckMousePositions(event, renderer, window);
					if (RomeScreen.WarhammerSelected == true) {
						RomeScreen.RenderingRome = false;
						WarhammerScreen.RenderingWarhammer = true;
						WarhammerScreen.DrawWarhammer(renderer);
						SDL_RenderPresent(renderer);
						RomeScreen.WarhammerSelected = false;
					}
					else if (RomeScreen.MedievalSelected == true) {
						RomeScreen.RenderingRome = false;
						Medieval2Screen.RenderingMedieval = true;
						Medieval2Screen.DrawMedieval(renderer);
						SDL_RenderPresent(renderer);
						RomeScreen.MedievalSelected = false;
					}
					else if (RomeScreen.ShogunSelected == true) {
						RomeScreen.RenderingRome = false;
						ShogunScreen.RenderingShogun = true;
						ShogunScreen.DrawShogun(renderer);
						SDL_RenderPresent(renderer);
						RomeScreen.ShogunSelected = false;
					}
				}
			}
			//update screen
			SDL_RenderPresent(renderer);
		}
	}

	window = NULL;
	renderer = NULL;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();
	IMG_Quit();

	return 0;
}