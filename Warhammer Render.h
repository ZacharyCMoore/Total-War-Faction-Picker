#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <unordered_map>
#include "Randomizer.h"

class RenderWarhammer {
public:
	bool RenderingWarhammer = true;
	bool MedievalSelected = false;
	bool ShogunSelected = false;
	bool RomeSelected = false;

	bool insideB1 = true;
	bool Button1IsDefault = false;
	bool Button1Hovering = false;
	bool Button1Clicked = false;

	bool insideB2 = true;
	bool Button2IsDefault = false;
	bool Button2Hovering = false;
	bool Button2Clicked = false;

	bool insideVortex = true;
	bool VortexIsDefault = false;
	bool VortexHovering = false;
	bool VortexClicked = false;

	bool insideMortal = true;
	bool MortalIsDefault = false;
	bool MortalHovering = false;
	bool MortalClicked = false;

	bool VortexSelected = false;
	bool MortalSelected = true;

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

	bool insideDropDown5 = true;
	bool DropDown5IsDefault = false;
	bool DropDown5Hovering = false;

	bool insideDropDown6 = true;
	bool DropDown6IsDefault = false;
	bool DropDown6Hovering = false;

	bool insideDropDown7 = true;
	bool DropDown7IsDefault = false;
	bool DropDown7Hovering = false;

	bool insideDropDown8 = true;
	bool DropDown8IsDefault = false;
	bool DropDown8Hovering = false;

	bool insideDropDown9 = true;
	bool DropDown9IsDefault = false;
	bool DropDown9Hovering = false;

	bool insideDropDown10 = true;
	bool DropDown10IsDefault = false;
	bool DropDown10Hovering = false;

	bool insideDropDown11 = true;
	bool DropDown11IsDefault = false;
	bool DropDown11Hovering = false;

	bool insideDropDown12 = true;
	bool DropDown12IsDefault = false;
	bool DropDown12Hovering = false;

	bool insideDropDown13 = true;
	bool DropDown13IsDefault = false;
	bool DropDown13Hovering = false;

	bool insideDropDown14 = true;
	bool DropDown14IsDefault = false;
	bool DropDown14Hovering = false;

	bool insideMedieval = true;
	bool MedievalIsDefault = false;
	bool MedievalHovering = false;

	bool insideShogun = true;
	bool ShogunIsDefault = false;
	bool ShogunHovering = false;

	bool insideRome = true;
	bool RomeIsDefault = false;
	bool RomeHovering = false;

	SDL_Rect ShogunButton{ 1600,144,174,84 };

	SDL_Rect ShogunMessage{ 1615,159,138,54 };

	SDL_Rect MedievalButton{ 1600,50,174,84 };

	SDL_Rect MedievalMessage{ 1615,65,138,54 };

	SDL_Rect RomeButton{ 1600,238,174,84 };

	SDL_Rect RomeMessage{ 1615,253,138,54 };

	SDL_Color Grey = { 38,38,38 };
	SDL_Color LightGrey = { 87,86,86 };
	SDL_Color DarkGold = { 140,122,3 };
	SDL_Color DarkGrey = { 8,8,8 };
	SDL_Color Red = { 255,0,0 };
	SDL_Color DarkRed = { 163,0,0 };
	SDL_Color Gold = { 252,186,3 };

	SDL_Rect Button1{ 1012,50,174,84 };

	SDL_Rect Button1Message{ 1027,65,138,54 };

	SDL_Rect Vortex{ 1225,50,174,84 };

	SDL_Rect VortexMessage{ 1240,65,138,54 };

	SDL_Rect Mortal{ 1400,50,174,84 };

	SDL_Rect MortalMessage{ 1415,65,138,54 };

	void DrawVortexButton(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage);

	void DrawVortexButtonHover(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage);

	void DrawVortexButtonClicked(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage);

	void DrawMortalButton(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage);

	void DrawMortalButtonHover(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage);

	void DrawMortalButtonClicked(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage);

	void DrawScreen(SDL_Renderer* renderer);

	void ReplaceInnerWindow(SDL_Renderer* renderer);

	void DrawLordResult(SDL_Renderer* renderer, std::string lord);

	void DrawButton(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Message);

	void DrawButtonHover(SDL_Renderer* renderer, SDL_Rect Button1,  SDL_Rect Button1Message);

	void DrawButtonClicked(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Message);

	void CheckMousePositionButton1(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	SDL_Rect Button2{ 1012,234,174,84 };

	SDL_Rect Button2MessageRect{ 1035,252,125,45 };

	SDL_Rect Button2DropDown{ 1169,234,17,84 };

	SDL_Rect DropDownV{ 1172,270,10,17 };

	SDL_Rect DropDownBox1{ 1012,318,157,50};

	SDL_Rect DropDownBox2{ 1012,368,157,50 };

	SDL_Rect DropDownBox3{ 1012,418,157,50 };

	SDL_Rect DropDownBox4{ 1012,468,157,50 };

	SDL_Rect DropDownBox5{ 1012,518,157,50 };

	SDL_Rect DropDownBox6{ 1012, 568,157,50 };

	SDL_Rect DropDownBox7{ 1012, 618,157,50 };

	SDL_Rect DropDownBox8{ 1012, 668,157,50 };

	SDL_Rect DropDownBox9{ 1012, 718,157,50 };

	SDL_Rect DropDownBox10{ 1169, 318,157,50 };

	SDL_Rect DropDownBox11{ 1169, 368,157,50 };

	SDL_Rect DropDownBox12{ 1169, 418,157,50 };

	SDL_Rect DropDownBox13{ 1169, 468,157,50 };

	SDL_Rect DropDownBox14{ 1169, 518,157,50 };

	SDL_Rect SubmitButton{ 1219,234,157,84 };

	SDL_Rect SubmitButtonMessage{1242, 252, 125, 45};

	void DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV);

	void DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1);

	void DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2);

	void DrawDropDownBox3(SDL_Renderer* renderer, SDL_Rect DropDownBox3);

	void DrawDropDownBox4(SDL_Renderer* renderer, SDL_Rect DropDownBox4);

	void DrawDropDownBox5(SDL_Renderer* renderer, SDL_Rect DropDownBox5);

	void DrawDropDownBox6(SDL_Renderer* renderer, SDL_Rect DropDownBox6);

	void DrawDropDownBox7(SDL_Renderer* renderer, SDL_Rect DropDownBox7);

	void DrawDropDownBox8(SDL_Renderer* renderer, SDL_Rect DropDownBox8);

	void DrawDropDownBox9(SDL_Renderer* renderer, SDL_Rect DropDownBox9);

	void DrawDropDownBox10(SDL_Renderer* renderer, SDL_Rect DropDownBox10);

	void DrawDropDownBox11(SDL_Renderer* renderer, SDL_Rect DropDownBox11);

	void DrawDropDownBox12(SDL_Renderer* renderer, SDL_Rect DropDownBox12);

	void DrawDropDownBox13(SDL_Renderer* renderer, SDL_Rect DropDownBox13);

	void DrawDropDownBox14(SDL_Renderer* renderer, SDL_Rect DropDownBox14);

	void DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1);

	void DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2);

	void DrawDropDownBox3Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox3);

	void DrawDropDownBox4Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox4);

	void DrawDropDownBox5Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox5);

	void DrawDropDownBox6Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox6);

	void DrawDropDownBox7Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox7);

	void DrawDropDownBox8Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox8);

	void DrawDropDownBox9Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox9);

	void DrawDropDownBox10Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox10);

	void DrawDropDownBox11Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox11);

	void DrawDropDownBox12Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox12);

	void DrawDropDownBox13Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox13);

	void DrawDropDownBox14Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox14);

	void CheckMousePositionButton2(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown1(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown2(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown3(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown4(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown5(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown6(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown7(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown8(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown9(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown10(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown11(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown12(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown13(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionDropDown14(SDL_Event event, SDL_Renderer* renderer);

	void ReplaceRightSide(SDL_Renderer* renderer);

	void DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage);

	void DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage);

	void CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	SDL_Rect RandomByRace{1103, 165, 200, 60};

	SDL_Rect RandomByRaceMessage{1123,175,150,45};

	void DrawRandomByRace(SDL_Renderer* renderer, SDL_Rect RandomByRace,  SDL_Rect RandomByRaceMessage);

	void PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester);

	void CheckMousePositionVortex(SDL_Event event, SDL_Renderer* renderer);

	void CheckMousePositionMortal(SDL_Event event, SDL_Renderer* renderer);

	void DrawWarhammer(SDL_Renderer* renderer);

	void CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window);

	void CheckMousePositionMedieval(SDL_Event event, SDL_Renderer* renderer);

	void DrawMedievalButton(SDL_Renderer* renderer, SDL_Rect Medieval,  SDL_Rect MedievalMessage);

	void DrawMedievalButtonHover(SDL_Renderer* renderer, SDL_Rect Medieval,  SDL_Rect MedievalMessage);

	void CheckMousePositionShogun(SDL_Event event, SDL_Renderer* renderer);

	void DrawShogunButton(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void DrawShogunButtonHover(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage);

	void DrawRomeButton(SDL_Renderer* renderer, SDL_Rect RomeButton, SDL_Rect RomeMessage);

	void DrawRomeButtonHover(SDL_Renderer* renderer, SDL_Rect RomeButton, SDL_Rect RomeMessage);

	void CheckMousePositionRome(SDL_Event event, SDL_Renderer* renderer);
private:
	//RandomALL button Coordinates
	SDL_Point Button1Leftposition{ 1012,50};
	SDL_Point Button1Rightposition{1186,50};
	SDL_Point Button1Topposition{1012,50};
	SDL_Point Button1Bottomposition{1186,133};
	
	//Gives access to the results of the randomizer and faction lists
	Randomizer randomizer;

	//Random By Race button coordinates
	SDL_Point Button2Leftposition{ 1012,234 };
	SDL_Point Button2Rightposition{ 1186,234 };
	SDL_Point Button2Topposition{ 1012,234 };
	SDL_Point Button2Bottomposition{ 1186,318 };

	//Drop Down 1 button coordinates
	SDL_Point DropDown1Leftposition{1012,318};
	SDL_Point DropDown1Rightposition{1169,318};
	SDL_Point DropDown1Topposition{1012,318};
	SDL_Point DropDown1Bottomposition{1169,368};

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

	//Drop Down 5 button coordinates
	SDL_Point DropDown5Leftposition{ 1012,518 };
	SDL_Point DropDown5Rightposition{ 1169,518 };
	SDL_Point DropDown5Topposition{ 1012,518 };
	SDL_Point DropDown5Bottomposition{ 1169,568 };

	//Drop Down 6 button coordinates
	SDL_Point DropDown6Leftposition{ 1012,568 };
	SDL_Point DropDown6Rightposition{ 1169,568 };
	SDL_Point DropDown6Topposition{ 1012,568 };
	SDL_Point DropDown6Bottomposition{ 1169,618 };

	//Drop Down 7 button coordinates
	SDL_Point DropDown7Leftposition{ 1012,618 };
	SDL_Point DropDown7Rightposition{ 1169,618 };
	SDL_Point DropDown7Topposition{ 1012,618 };
	SDL_Point DropDown7Bottomposition{ 1169,668 };

	//Drop Down 8 button coordinates
	SDL_Point DropDown8Leftposition{ 1012,668 };
	SDL_Point DropDown8Rightposition{ 1169,668 };
	SDL_Point DropDown8Topposition{ 1012,668 };
	SDL_Point DropDown8Bottomposition{ 1169,718 };

	//Drop Down 9 button coordinates
	SDL_Point DropDown9Leftposition{ 1012,718 };
	SDL_Point DropDown9Rightposition{ 1169,718 };
	SDL_Point DropDown9Topposition{ 1012,718 };
	SDL_Point DropDown9Bottomposition{ 1169,768 };

	//Drop Down 10 button coordinates
	SDL_Point DropDown10Leftposition{ 1169,318 };
	SDL_Point DropDown10Rightposition{ 1326,318 };
	SDL_Point DropDown10Topposition{ 1169,318 };
	SDL_Point DropDown10Bottomposition{ 1326,368 };

	//Drop Down 11 button coordinates
	SDL_Point DropDown11Leftposition{ 1169,368 };
	SDL_Point DropDown11Rightposition{ 1326,368 };
	SDL_Point DropDown11Topposition{ 1169,368 };
	SDL_Point DropDown11Bottomposition{ 1326,418 };

	//Drop Down 12 button coordinates
	SDL_Point DropDown12Leftposition{ 1169,418 };
	SDL_Point DropDown12Rightposition{ 1326,418 };
	SDL_Point DropDown12Topposition{ 1169,418 };
	SDL_Point DropDown12Bottomposition{ 1326,468 };

	//Drop Down 13 button coordinates
	SDL_Point DropDown13Leftposition{ 1169,468 };
	SDL_Point DropDown13Rightposition{ 1326,468 };
	SDL_Point DropDown13Topposition{ 1169,468 };
	SDL_Point DropDown13Bottomposition{ 1326,518 };

	//Drop Down 14 button coordinates
	SDL_Point DropDown14Leftposition{ 1169,518 };
	SDL_Point DropDown14Rightposition{ 1326,518 };
	SDL_Point DropDown14Topposition{ 1169,518 };
	SDL_Point DropDown14Bottomposition{ 1326,568 };

	//Submit Button coordinates
	SDL_Point SubmitLeftposition{ 1219,234 };
	SDL_Point SubmitRightposition{ 1376,234 };
	SDL_Point SubmitTopposition{ 1219,234 };
	SDL_Point SubmitBottomposition{ 1376,318 };

	//Vortex Button coordinates
	SDL_Point VortexLeftposition{1225,50};
	SDL_Point VortexRightposition{1399,50};
	SDL_Point VortexTopposition{1225,50};
	SDL_Point VortexBottomposition{1225,133};

	//Mortal Button coordinates
	SDL_Point MortalLeftposition{ 1400,50 };
	SDL_Point MortalRightposition{ 1574,50 };
	SDL_Point MortalTopposition{ 1400,50 };
	SDL_Point MortalBottomposition{ 1400,133 };

	//Medieval Button coordinates
	SDL_Point MedievalLeftposition{ 1600,50 };
	SDL_Point MedievalRightposition{ 1774,50 };
	SDL_Point MedievalTopposition{ 1600,50 };
	SDL_Point MedievalBottomposition{ 1600,134 };

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
