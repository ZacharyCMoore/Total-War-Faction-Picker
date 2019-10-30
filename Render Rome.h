#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <thread>
#include "Randomizer.h"

class RenderRome {
public:
	bool RenderingRome = false;
	bool WarhammerSelected = false;
	bool MedievalSelected = false;
	bool ShogunSelected = false;

	bool insidePickAll = true;
	bool PickAllIsDefault = false;
	bool PickAllHovering = false;
	bool PickAllClicked = false;

	bool insideShogun = true;
	bool ShogunIsDefault = false;
	bool ShogunHovering = false;

	bool insideWarhammer = true;
	bool WarhammerIsDefault = false;
	bool WarhammerHovering = false;

	bool insideMedieval = true;
	bool MedievalIsDefault = false;
	bool MedievalHovering = false;

	SDL_Color Silver = { 184,198,219 };
	SDL_Color Grey = { 38,38,38 };
	SDL_Color DarkGrey = { 8,8,8 };
	SDL_Color LightGrey = { 86,86,86 };
	SDL_Color Red = { 255,0,0 };
	SDL_Color DarkRed = { 163,0,0 };
	SDL_Color Gold = { 252,186,3 };

	SDL_Rect ShogunButton{ 1600,144,174,84 };
	
	SDL_Rect ShogunMessage{ 1615,159,138,54 };

	SDL_Rect WarhammerButton{ 1600,50,174,84 };

	SDL_Rect WarhammerMessage{ 1615,65,138,54 };

	SDL_Rect MedievalButton{ 1600,238,174,84 };

	SDL_Rect MedievalMessage{ 1615,253,138,54 };

	SDL_Rect PickAll{ 1012,50,174,84 };

	SDL_Rect PickAllMessage{ 1027,65,138,54 };

	void DrawScreen(SDL_Renderer* renderer);

	void DrawRome(SDL_Renderer* renderer);

	void DrawPickAll(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void DrawPickAllHover(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void DrawPickAllClicked(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void ReplaceInnerWindow(SDL_Renderer* renderer);

	void DrawFactionResultSingle(SDL_Renderer* renderer, std::string FactionResult);

	void CheckMousePositionPickAll(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester);

	void DrawWarhammerButton(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage);

	void DrawWarhammerButtonHover(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage);

	void CheckMousePositionWarhammer(SDL_Event event, SDL_Renderer* renderer);

	void DrawShogunButton(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void DrawShogunButtonHover(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void CheckMousePositionShogun(SDL_Event event, SDL_Renderer* renderer);

	void DrawMedievalButton(SDL_Renderer* renderer, SDL_Rect MedievalButton, SDL_Rect MedievalMessage);

	void DrawMedievalButtonHover(SDL_Renderer* renderer, SDL_Rect MedievalButton, SDL_Rect MedievalMessage);
	
	void CheckMousePositionMedieval(SDL_Event event, SDL_Renderer* renderer);
private:
	//Gives access to randomizer and lists
	Randomizer randomizer;

	//PickAll button coordinates
	SDL_Point PickAllLeftPosition{ 1012,50 };
	SDL_Point PickAllRightPosition{ 1186,50 };
	SDL_Point PickAllTopPosition{ 1012,50 };
	SDL_Point PickAllBottomPosition{ 1186,133 };

	//Warhammer Button coordinates
	SDL_Rect WarhammerLeftposition{ 1600,50 };
	SDL_Rect WarhammerRightposition{ 1774,50 };
	SDL_Rect WarhammerTopposition{ 1600,50 };
	SDL_Rect WarhammerBottomposition{ 1600,134 };

	//Shogun Button coordinates
	SDL_Point ShogunLeftPosition{ 1600,144 };
	SDL_Point ShogunRightPosition{ 1774,144 };
	SDL_Point ShogunTopPosition{ 1600,144 };
	SDL_Point ShogunBottomPosition{ 1600,228 };

	//Medieval Button coordinates
	SDL_Point MedievalLeftposition{ 1600, 238 };
	SDL_Point MedievalRightposition{ 1774,50 };
	SDL_Point MedievalTopposition{ 1600,238 };
	SDL_Point MedievalBottomposition{ 1600,322 };
};