#define SDL_MAIN_HANDLED
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>
#include <thread>
#include "Render.h"
#include "Lists.h"
#include "Randomizer.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

bool running = true;

int main(int argc, char argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	if (TTF_Init() < 0) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Total War Faction Picker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	RenderMain screen;
	Randomizer randomizer;

	

	screen.DrawScreen(renderer);
	screen.DrawButton(renderer, screen.Button1, screen.Button1Border, screen.Button1Message);
	screen.DrawButton2(renderer, screen.Button2, screen.Button2Border, screen.Button2MessageRect, screen.Button2DropDown, screen.Button2DropDownB, screen.DropDownV);
	screen.DrawSubmitButton(renderer, screen.SubmitButton, screen.SubmitButtonBorder, screen.SubmitButtonMessage);

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
				screen.CheckMousePositionButton1(event, renderer);
				screen.CheckMousePositionButton2(event, renderer);
				screen.CheckMousePositionDropDown1(event, renderer);
				screen.CheckMousePositionDropDown2(event, renderer);
				screen.CheckMousePositionDropDown3(event, renderer);
				screen.CheckMousePositionDropDown4(event, renderer);
				screen.CheckMousePositionDropDown5(event, renderer);
				screen.CheckMousePositionDropDown6(event, renderer);
				screen.CheckMousePositionDropDown7(event, renderer);
				screen.CheckMousePositionDropDown8(event, renderer);
				screen.CheckMousePositionDropDown9(event, renderer);
				screen.CheckMousePositionDropDown10(event, renderer);
				screen.CheckMousePositionDropDown11(event, renderer);
				screen.CheckMousePositionDropDown12(event, renderer);
				screen.CheckMousePositionDropDown13(event, renderer);
				screen.CheckMousePositionDropDown14(event, renderer);
				screen.CheckMousePositionSubmitButton(event, renderer);
			}
			//update screen
			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
}