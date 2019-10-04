#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <unordered_map>
#include "Lists.h"
#include "Randomizer.h"

class RenderMain {
public:

	bool insideB1 = true;
	bool Button1IsDefault = false;
	bool Button1Hovering = false;
	bool Button1Clicked = false;

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

	SDL_Color Grey = { 38,38,38 };
	SDL_Color LightGrey = { 87,86,86 };
	SDL_Color DarkGold = { 140,122,3 };
	SDL_Color DarkGrey = { 8,8,8 };

	const SDL_Rect Button1{ 612,50,174,84 };

	const SDL_Rect Button1Border{ 612,50,174,84 };

	const SDL_Rect Button1Message{ 627,65,138,54 };

	void DrawScreen(SDL_Renderer* renderer);

	void ReplaceInnerWindow(SDL_Renderer* renderer);

	void DrawLordResult(SDL_Renderer* renderer, std::string lord);

	void DrawButton(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message);

	void DrawButtonHover(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message);

	void DrawButtonClicked(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message);

	void CheckMousePositionButton1(SDL_Event event, SDL_Renderer* renderer);

	const SDL_Rect Button2{ 612,234,174,84 };

	const SDL_Rect Button2Border{ 612,234,174,84 };

	const SDL_Rect Button2MessageRect{ 635,252,125,45 };

	const SDL_Rect Button2DropDown{ 769,234,17,84 };

	const SDL_Rect Button2DropDownB{ 769,234,17,84 };

	const SDL_Rect DropDownV{ 772,270,10,17 };

	const SDL_Rect DropDownBox1{612,318,157,50};

	const SDL_Rect DropDownBox1Border{612,318,157,50};

	const SDL_Rect DropDownBox2{ 612,368,157,50 };

	const SDL_Rect DropDownBox2Border{ 612,368,157,50 };

	const SDL_Rect DropDownBox3{ 612,418,157,50 };

	const SDL_Rect DropDownBox3Border{ 612,418,157,50 };

	const SDL_Rect DropDownBox4{ 612,468,157,50 };

	const SDL_Rect DropDownBox4Border{ 612,468,157,50 };

	const SDL_Rect DropDownBox5{ 612,518,157,50 };

	const SDL_Rect DropDownBox5Border{ 612,518,157,50 };

	const SDL_Rect DropDownBox6{ 612, 568,157,50 };

	const SDL_Rect DropDownBox6Border{ 612,568,157,50 };

	const SDL_Rect DropDownBox7{ 612, 618,157,50 };

	const SDL_Rect DropDownBox7Border{ 612,618,157,50 };

	const SDL_Rect DropDownBox8{ 612, 668,157,50 };

	const SDL_Rect DropDownBox8Border{ 612,668,157,50 };

	const SDL_Rect DropDownBox9{ 612, 718,157,50 };

	const SDL_Rect DropDownBox9Border{ 612,718,157,50 };

	const SDL_Rect DropDownBox10{ 769, 318,157,50 };

	const SDL_Rect DropDownBox10Border{ 769,318,157,50 };

	const SDL_Rect DropDownBox11{ 769, 368,157,50 };

	const SDL_Rect DropDownBox11Border{ 769,368,157,50 };

	const SDL_Rect DropDownBox12{ 769, 418,157,50 };

	const SDL_Rect DropDownBox12Border{ 769,418,157,50 };

	const SDL_Rect DropDownBox13{ 769, 468,157,50 };

	const SDL_Rect DropDownBox13Border{ 769,468,157,50 };

	const SDL_Rect DropDownBox14{ 769, 518,157,50 };

	const SDL_Rect DropDownBox14Border{ 769,518,157,50 };

	const SDL_Rect DropDownBox15{ 769, 518,157,50 };

	const SDL_Rect DropDownBox15Border{ 769,518,157,50 };

	const SDL_Rect SubmitButton{ 819,234,157,84 };

	const SDL_Rect SubmitButtonBorder{ 819,234,157,84 };

	const SDL_Rect SubmitButtonMessage{842, 252, 125, 45};

	void DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV);

	void DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV);

	void DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV);

	void DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1, SDL_Rect DropDownBox1Border);

	void DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2, SDL_Rect DropDownBox2Border);

	void DrawDropDownBox3(SDL_Renderer* renderer, SDL_Rect DropDownBox3, SDL_Rect DropDownBox3Border);

	void DrawDropDownBox4(SDL_Renderer* renderer, SDL_Rect DropDownBox4, SDL_Rect DropDownBox4Border);

	void DrawDropDownBox5(SDL_Renderer* renderer, SDL_Rect DropDownBox5, SDL_Rect DropDownBox5Border);

	void DrawDropDownBox6(SDL_Renderer* renderer, SDL_Rect DropDownBox6, SDL_Rect DropDownBox6Border);

	void DrawDropDownBox7(SDL_Renderer* renderer, SDL_Rect DropDownBox7, SDL_Rect DropDownBox7Border);

	void DrawDropDownBox8(SDL_Renderer* renderer, SDL_Rect DropDownBox8, SDL_Rect DropDownBox8Border);

	void DrawDropDownBox9(SDL_Renderer* renderer, SDL_Rect DropDownBox9, SDL_Rect DropDownBox9Border);

	void DrawDropDownBox10(SDL_Renderer* renderer, SDL_Rect DropDownBox10, SDL_Rect DropDownBox10Border);

	void DrawDropDownBox11(SDL_Renderer* renderer, SDL_Rect DropDownBox11, SDL_Rect DropDownBox11Border);

	void DrawDropDownBox12(SDL_Renderer* renderer, SDL_Rect DropDownBox12, SDL_Rect DropDownBox12Border);

	void DrawDropDownBox13(SDL_Renderer* renderer, SDL_Rect DropDownBox13, SDL_Rect DropDownBox13Border);

	void DrawDropDownBox14(SDL_Renderer* renderer, SDL_Rect DropDownBox14, SDL_Rect DropDownBox14Border);

	void DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1, SDL_Rect DropDownBox1Border);

	void DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2, SDL_Rect DropDownBox2Border);

	void DrawDropDownBox3Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox3, SDL_Rect DropDownBox3Border);

	void DrawDropDownBox4Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox4, SDL_Rect DropDownBox4Border);

	void DrawDropDownBox5Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox5, SDL_Rect DropDownBox5Border);

	void DrawDropDownBox6Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox6, SDL_Rect DropDownBox6Border);

	void DrawDropDownBox7Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox7, SDL_Rect DropDownBox7Border);

	void DrawDropDownBox8Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox8, SDL_Rect DropDownBox8Border);

	void DrawDropDownBox9Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox9, SDL_Rect DropDownBox9Border);

	void DrawDropDownBox10Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox10, SDL_Rect DropDownBox10Border);

	void DrawDropDownBox11Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox11, SDL_Rect DropDownBox11Border);

	void DrawDropDownBox12Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox12, SDL_Rect DropDownBox12Border);

	void DrawDropDownBox13Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox13, SDL_Rect DropDownBox13Border);

	void DrawDropDownBox14Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox14, SDL_Rect DropDownBox14Border);

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

	void DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage);

	void DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage);

	void DrawSubmitButtonClicked(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage);

	void CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer);
private:
	//RandomALL button Coordinates
	SDL_Point Button1Leftposition{612,50};
	SDL_Point Button1Rightposition{786,50};
	SDL_Point Button1Topposition{612,50};
	SDL_Point Button1Bottomposition{786,133};
	
	//Gives access to the results of the randomizer
	Randomizer randomizer;

	//Gives access to the list of factions and Races
	LegendaryLords list;


	//Random By Race button coordinates
	SDL_Point Button2Leftposition{ 612,234 };
	SDL_Point Button2Rightposition{ 786,234 };
	SDL_Point Button2Topposition{ 612,234 };
	SDL_Point Button2Bottomposition{ 786,318 };

	//Drop Down 1 button coordinates
	SDL_Point DropDown1Leftposition{612,318};
	SDL_Point DropDown1Rightposition{769,318};
	SDL_Point DropDown1Topposition{612,318};
	SDL_Point DropDown1Bottomposition{769,368};

	//Drop Down 2 button coordinates
	SDL_Point DropDown2Leftposition{ 612,368 };
	SDL_Point DropDown2Rightposition{ 769,368 };
	SDL_Point DropDown2Topposition{ 612,368 };
	SDL_Point DropDown2Bottomposition{ 769,418 };

	//Drop Down 3 button coordinates
	SDL_Point DropDown3Leftposition{ 612,418 };
	SDL_Point DropDown3Rightposition{ 769,418 };
	SDL_Point DropDown3Topposition{ 612,418 };
	SDL_Point DropDown3Bottomposition{ 769,468 };

	//Drop Down 4 button coordinates
	SDL_Point DropDown4Leftposition{ 612,468 };
	SDL_Point DropDown4Rightposition{ 769,468 };
	SDL_Point DropDown4Topposition{ 612,468 };
	SDL_Point DropDown4Bottomposition{ 769,518 };

	//Drop Down 5 button coordinates
	SDL_Point DropDown5Leftposition{ 612,518 };
	SDL_Point DropDown5Rightposition{ 769,518 };
	SDL_Point DropDown5Topposition{ 612,518 };
	SDL_Point DropDown5Bottomposition{ 769,568 };

	//Drop Down 6 button coordinates
	SDL_Point DropDown6Leftposition{ 612,568 };
	SDL_Point DropDown6Rightposition{ 769,568 };
	SDL_Point DropDown6Topposition{ 612,568 };
	SDL_Point DropDown6Bottomposition{ 769,618 };

	//Drop Down 7 button coordinates
	SDL_Point DropDown7Leftposition{ 612,618 };
	SDL_Point DropDown7Rightposition{ 769,618 };
	SDL_Point DropDown7Topposition{ 612,618 };
	SDL_Point DropDown7Bottomposition{ 769,668 };

	//Drop Down 8 button coordinates
	SDL_Point DropDown8Leftposition{ 612,668 };
	SDL_Point DropDown8Rightposition{ 769,668 };
	SDL_Point DropDown8Topposition{ 612,668 };
	SDL_Point DropDown8Bottomposition{ 769,718 };

	//Drop Down 9 button coordinates
	SDL_Point DropDown9Leftposition{ 612,718 };
	SDL_Point DropDown9Rightposition{ 769,718 };
	SDL_Point DropDown9Topposition{ 612,718 };
	SDL_Point DropDown9Bottomposition{ 769,768 };

	//Drop Down 10 button coordinates
	SDL_Point DropDown10Leftposition{ 769,318 };
	SDL_Point DropDown10Rightposition{ 926,318 };
	SDL_Point DropDown10Topposition{ 769,318 };
	SDL_Point DropDown10Bottomposition{ 926,368 };

	//Drop Down 11 button coordinates
	SDL_Point DropDown11Leftposition{ 769,368 };
	SDL_Point DropDown11Rightposition{ 926,368 };
	SDL_Point DropDown11Topposition{ 769,368 };
	SDL_Point DropDown11Bottomposition{ 926,418 };

	//Drop Down 12 button coordinates
	SDL_Point DropDown12Leftposition{ 769,418 };
	SDL_Point DropDown12Rightposition{ 926,418 };
	SDL_Point DropDown12Topposition{ 769,418 };
	SDL_Point DropDown12Bottomposition{ 926,468 };

	//Drop Down 13 button coordinates
	SDL_Point DropDown13Leftposition{ 769,468 };
	SDL_Point DropDown13Rightposition{ 926,468 };
	SDL_Point DropDown13Topposition{ 769,468 };
	SDL_Point DropDown13Bottomposition{ 926,518 };

	//Drop Down 14 button coordinates
	SDL_Point DropDown14Leftposition{ 769,518 };
	SDL_Point DropDown14Rightposition{ 926,518 };
	SDL_Point DropDown14Topposition{ 769,518 };
	SDL_Point DropDown14Bottomposition{ 926,568 };

	//Submit Button coordinates
	SDL_Point SubmitLeftposition{ 819,234 };
	SDL_Point SubmitRightposition{ 976,234 };
	SDL_Point SubmitTopposition{ 819,234 };
	SDL_Point SubmitBottomposition{ 976,318 };
};
