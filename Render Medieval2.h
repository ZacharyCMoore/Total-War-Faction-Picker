#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <thread>
#include "Randomizer.h"

class RenderMedieval {
public:
	bool RenderingMedieval = false;
	bool WarhammerSelected = false;
	bool ShogunSelected = false;
	bool RomeSelected = false;

	bool insidePickAll = true;
	bool PickAllIsDefault = false;
	bool PickAllHovering = false;
	bool PickAllClicked = false;

	bool insideB2 = true;
	bool Button2IsDefault = false;
	bool Button2Hovering = false;
	bool Button2Clicked = false;

	bool StartDropDown = false;

	bool insideSubmit = true;
	bool SubmitIsDefault = false;
	bool SubmitHovering = false;
	bool SubmitClicked = false;

	bool insideDropDown1 = true;
	bool DropDown1IsDefault = false;
	bool DropDown1Hovering = false;

	bool insideDropDown2 = true;
	bool DropDown2IsDefault = false;
	bool DropDown2Hovering = false;

	bool insideDropDown3 = true;
	bool DropDown3IsDefault = false;
	bool DropDown3Hovering = false;

	bool insideDropDown4 = true;
	bool DropDown4IsDefault = false;
	bool DropDown4Hovering = false;

	bool insideWarhammer = true;
	bool WarhammerIsDefault = false;
	bool WarhammerHovering = false;

	bool insideShogun = true;
	bool ShogunIsDefault = false;
	bool ShogunHovering = false;

	bool insideRome = true;
	bool RomeIsDefault = false;
	bool RomeHovering = false;

	SDL_Rect ShogunButton{ 1600,144,174,84 };

	SDL_Rect ShogunMessage{ 1615,159,138,54 };

	SDL_Rect WarhammerButton{ 1600,50,174,84 };

	SDL_Rect WarhammerMessage{ 1615,65,138,54 };

	SDL_Rect RomeButton{ 1600,238,174,84 };

	SDL_Rect RomeMessage{ 1615,253,138,54 };

	void DrawScreen(SDL_Renderer* renderer);

	void DrawMedieval(SDL_Renderer* renderer);

	SDL_Color Silver = { 184,198,219 };
	SDL_Color Grey = { 38,38,38 };
	SDL_Color DarkGrey = { 8,8,8 };
	SDL_Color LightGrey = { 86,86,86 };
	SDL_Color Red = { 255,0,0 };
	SDL_Color DarkRed = { 163,0,0 };
	SDL_Color Gold = { 252,186,3 };

	SDL_Rect PickAll{ 1012,50,174,84 };

	SDL_Rect PickAllMessage{ 1027,65,138,54 };

	SDL_Rect Button2{ 1012,234,174,84 };

	SDL_Rect Button2MessageRect{ 1035,252,125,45 };

	SDL_Rect Button2DropDown{ 1169,234,17,84 };

	SDL_Rect DropDownV{ 1172,270,10,17 };

	SDL_Rect DropDownBox1{ 1012,318,157,50 };

	SDL_Rect DropDownBox2{ 1012,368,157,50 };

	SDL_Rect DropDownBox3{ 1012,418,157,50 };

	SDL_Rect DropDownBox4{ 1012,468,157,50 };

	SDL_Rect SubmitButton{ 1219,234,157,84 };

	SDL_Rect SubmitButtonMessage{ 1242, 252, 125, 45 };

	SDL_Rect RandomByCampaign{ 1053, 165, 250, 60 };

	SDL_Rect RandomByCampaignMessage{ 1073,175,200,45 };

	void DrawPickAll(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void DrawPickAllHover(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void DrawPickAllClicked(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage);

	void CheckMousePositionPickAll(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void DrawRandomByCampaign(SDL_Renderer* renderer, SDL_Rect RandomByCampaign, SDL_Rect RandomByCampaignMessage);
	
	void ReplaceInnerWindow(SDL_Renderer* renderer);

	void ReplaceRightSide(SDL_Renderer* renderer);

	void DrawFactionResult(SDL_Renderer* renderer, std::vector<std::string> FactionResults);

	void DrawFactionResultSingle(SDL_Renderer* renderer, std::string FactionResult);

	void DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void CheckMousePositionButton2(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown1(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown2(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown3(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown4(SDL_Event event, SDL_Renderer* renderer);

	void DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1);

	void DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2);

	void DrawDropDownBox3(SDL_Renderer* renderer, SDL_Rect DropDownBox3);

	void DrawDropDownBox4(SDL_Renderer* renderer, SDL_Rect DropDownBox4);

	void DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1);

	void DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2);

	void DrawDropDownBox3Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox3);

	void DrawDropDownBox4Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox4);

	void DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage);

	void DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage);

	void CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void CheckMousePositionWarhammer(SDL_Event event, SDL_Renderer* renderer);

	void DrawWarhammerButton(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage);

	void DrawWarhammerButtonHover(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage);

	void PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester);

	void CheckMousePositionShogun(SDL_Event event, SDL_Renderer* renderer);

	void DrawShogunButton(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void DrawShogunButtonHover(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void DrawRomeButton(SDL_Renderer* renderer, SDL_Rect RomeButton, SDL_Rect RomeMessage);

	void DrawRomeButtonHover(SDL_Renderer* renderer, SDL_Rect RomeButton, SDL_Rect RomeMessage);

	void CheckMousePositionRome(SDL_Event event, SDL_Renderer* renderer);
private:
	//Gives access to randomizer and lists
	Randomizer randomizer;

	//Pick All button coordinates
	SDL_Point PickAllLeftPosition{ 1012,50 };
	SDL_Point PickAllRightPosition{ 1186,50 };
	SDL_Point PickAllTopPosition{ 1012,50 };
	SDL_Point PickAllBottomPosition{ 1186,133 };

	//Random By Campaign button coordinates
	SDL_Point Button2Leftposition{ 1012,234 };
	SDL_Point Button2Rightposition{ 1186,234 };
	SDL_Point Button2Topposition{ 1012,234 };
	SDL_Point Button2Bottomposition{ 1186,318 };

	//Drop Down 1 button coordinates
	SDL_Point DropDown1Leftposition{ 1012,318 };
	SDL_Point DropDown1Rightposition{ 1169,318 };
	SDL_Point DropDown1Topposition{ 1012,318 };
	SDL_Point DropDown1Bottomposition{ 1169,368 };

	//Drop Down 2 button coordinates
	SDL_Point DropDown2Leftposition{ 1012,368 };
	SDL_Point DropDown2Rightposition{ 1169,368 };
	SDL_Point DropDown2Topposition{ 1012,368 };
	SDL_Point DropDown2Bottomposition{ 1169,418 };

	//Drop Down 3 button coordinates
	SDL_Point DropDown3Leftposition{ 1012,418 };
	SDL_Point DropDown3Rightposition{ 1169,418 };
	SDL_Point DropDown3Topposition{ 1012,418 };
	SDL_Point DropDown3Bottomposition{ 1169,468 };

	//Drop Down 4 button coordinates
	SDL_Point DropDown4Leftposition{ 1012,468 };
	SDL_Point DropDown4Rightposition{ 1169,468 };
	SDL_Point DropDown4Topposition{ 1012,468 };
	SDL_Point DropDown4Bottomposition{ 1169,518 };

	//Submit Button coordinates
	SDL_Point SubmitLeftposition{ 1219,234 };
	SDL_Point SubmitRightposition{ 1376,234 };
	SDL_Point SubmitTopposition{ 1219,234 };
	SDL_Point SubmitBottomposition{ 1376,318 };

	//Warhammer Button coordinates
	SDL_Point WarhammerLeftposition{ 1600,50 };
	SDL_Point WarhammerRightposition{ 1774,50 };
	SDL_Point WarhammerTopposition{ 1600,50 };
	SDL_Point WarhammerBottomposition{ 1600,134 };

	//Shogun Button coordinates
	SDL_Point ShogunLeftPosition{ 1600,144 };
	SDL_Point ShogunRightPosition{ 1774,144 };
	SDL_Point ShogunTopPosition{ 1600,144 };
	SDL_Point ShogunBottomPosition{ 1600,228 };

	//Rome Button coordinates
	SDL_Point RomeLeftposition{ 1600, 238 };
	SDL_Point RomeRightposition{ 1774,50 };
	SDL_Point RomeTopposition{ 1600,238 };
	SDL_Point RomeBottomposition{ 1600,322 };
};
