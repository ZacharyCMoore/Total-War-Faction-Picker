#include "Render.h"

void RenderMain::DrawScreen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 135, 10, 1, 255);
	SDL_Rect RSide{ 600, 0, 400, 800 };
	SDL_RenderFillRect(renderer, &RSide);

	SDL_Rect LSide{ 0, 0, 5, 800 };
	SDL_RenderFillRect(renderer, &LSide);

	SDL_Rect Bottom{ 0, 750, 1000, 200 };
	SDL_RenderFillRect(renderer, &Bottom);

	SDL_SetRenderDrawColor(renderer, 74, 14, 10, 255);
	SDL_Rect WBorder{0, 0, 1000, 800 };
	SDL_RenderDrawRect(renderer, &WBorder);

	SDL_Rect SWBorder{ 5, 0, 595, 750 };
	SDL_RenderDrawRect(renderer, &SWBorder);
}

void RenderMain::ReplaceInnerWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect ReplaceInnerWindow{ 5,0,595,750 };
	SDL_RenderFillRect(renderer, &ReplaceInnerWindow);
}

void RenderMain::DrawLordResult(SDL_Renderer* renderer, std::string lord) {
	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 41);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	int w, h;
	if (TTF_SizeText(font, lord.c_str(), &w, &h)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_SetRenderDrawColor(renderer, 140, 3, 3, 255);
	SDL_Rect LordRect{ 133,40, w, h };
	SDL_RenderFillRect(renderer, &LordRect);

	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_Rect LordRectBorder{ 133, 40, w, h };
	SDL_RenderDrawRect(renderer, &LordRectBorder);

	SDL_Rect LordResultRect{ 133,40,w,h };
	SDL_Surface* LordR = TTF_RenderText_Blended(font, lord.c_str(), DarkGold);
	SDL_Texture* LordRM = SDL_CreateTextureFromSurface(renderer, LordR);
	SDL_RenderCopy(renderer, LordRM, NULL, &LordResultRect);

	TTF_CloseFont(font);
	SDL_FreeSurface(LordR);
}

void RenderMain::DrawButton(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button1Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* RAll = TTF_RenderText_Blended(font, "Random All", Grey);
	SDL_Texture* RAllM = SDL_CreateTextureFromSurface(renderer, RAll);
	SDL_RenderCopy(renderer, RAllM, NULL, &Button1Message);

	TTF_CloseFont(font);
	SDL_FreeSurface(RAll);

	RenderMain::Button1IsDefault = true;
	RenderMain::Button1Hovering = false;
	RenderMain::Button1Clicked = false;
}

void RenderMain::DrawButtonHover(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button1Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* RandALLHover = TTF_RenderText_Blended(font, "Random All", LightGrey);
	SDL_Texture* RandAllHoverM = SDL_CreateTextureFromSurface(renderer, RandALLHover);
	SDL_RenderCopy(renderer, RandAllHoverM, NULL, &Button1Message);

	TTF_CloseFont(font);
	SDL_FreeSurface(RandALLHover);

	RenderMain::Button1IsDefault = false;
	RenderMain::Button1Hovering = true;
	RenderMain::Button1Clicked = false;
};

void RenderMain::DrawButtonClicked(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Border, SDL_Rect Button1Message) {
		SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
		SDL_RenderFillRect(renderer, &Button1);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &Button1Border);

		TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
		if (!font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* RandAllClick = TTF_RenderText_Blended(font, "Random All", DarkGrey);
		SDL_Texture* RandAllClickM = SDL_CreateTextureFromSurface(renderer, RandAllClick);
		SDL_RenderCopy(renderer, RandAllClickM, NULL, &Button1Message);

		TTF_CloseFont(font);
		SDL_FreeSurface(RandAllClick);

		RenderMain::Button1IsDefault = false;
		RenderMain::Button1Hovering = false;
		RenderMain::Button1Clicked = true;
};

void RenderMain::CheckMousePositionButton1(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideB1 = true;

	//Check if mouse is left of the button
	if (x < Button1Leftposition.x) insideB1 = false;
	//Check if mouse is right of the button
	if (x > Button1Rightposition.x) insideB1 = false;
	//Check if mouse is above the button
	if (y < Button1Topposition.y) insideB1 = false;
	//Check if mouse is below the button
	if (y > Button1Bottomposition.y) insideB1 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideB1 == true) {
		if (Button1Hovering == true) DrawButtonClicked(renderer, Button1, Button1Border, Button1Message);
		std::string result = randomizer.RandomPickAll();
		ReplaceInnerWindow(renderer);
		DrawLordResult(renderer, result);
	};

	if (event.type == SDL_MOUSEBUTTONUP && Button1Clicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		Button1Clicked = false;
	}

	if (insideB1 == true && Button1Hovering == false && Button1Clicked == false) DrawButtonHover(renderer, Button1, Button1Border, Button1Message);

	else if (insideB1 == false && Button1IsDefault == false) {
		DrawButton(renderer, Button1, Button1Border, Button1Message);
	};
}

void RenderMain::DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2 = TTF_RenderText_Blended(font, list.Races[0].c_str(), Grey);
	SDL_Texture* B2M = SDL_CreateTextureFromSurface(renderer, B2);
	SDL_RenderCopy(renderer, B2M, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDownB);

	TTF_Font* font2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BV = TTF_RenderText_Blended(font2, "V", Grey);
	SDL_Texture* BVM = SDL_CreateTextureFromSurface(renderer, BV);
	SDL_RenderCopy(renderer, BVM, NULL, &DropDownV);


	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	SDL_FreeSurface(B2);
	SDL_FreeSurface(BV);

	RenderMain::Button2IsDefault = true;
	RenderMain::Button2Hovering = false;
	RenderMain::Button2Clicked = false;
}

void RenderMain::DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2 = TTF_RenderText_Blended(font, list.Races[0].c_str(), LightGrey);
	SDL_Texture* B2M = SDL_CreateTextureFromSurface(renderer, B2);
	SDL_RenderCopy(renderer, B2M, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDownB);

	TTF_Font* font2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BV = TTF_RenderText_Blended(font2, "V", Grey);
	SDL_Texture* BVM = SDL_CreateTextureFromSurface(renderer, BV);
	SDL_RenderCopy(renderer, BVM, NULL, &DropDownV);


	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	SDL_FreeSurface(B2);
	SDL_FreeSurface(BV);

	RenderMain::Button2IsDefault = false;
	RenderMain::Button2Hovering = true;
	RenderMain::Button2Clicked = false;
};

void RenderMain::DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2Border, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect Button2DropDownB, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2 = TTF_RenderText_Blended(font, list.Races[0].c_str(), DarkGrey);
	SDL_Texture* B2M = SDL_CreateTextureFromSurface(renderer, B2);
	SDL_RenderCopy(renderer, B2M, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDownB);

	TTF_Font* font2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BV = TTF_RenderText_Blended(font2, "V", Grey);
	SDL_Texture* BVM = SDL_CreateTextureFromSurface(renderer, BV);
	SDL_RenderCopy(renderer, BVM, NULL, &DropDownV);


	TTF_CloseFont(font);
	TTF_CloseFont(font2);
	SDL_FreeSurface(B2);
	SDL_FreeSurface(BV);

	RenderMain::Button2IsDefault = false;
	RenderMain::Button2Hovering = false;
	RenderMain::Button2Clicked = true;
}

void RenderMain::CheckMousePositionButton2(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideB2 = true;

	//Check if mouse is left of the button
	if (x < Button2Leftposition.x) insideB2 = false;
	//Check if mouse is right of the button
	if (x > Button2Rightposition.x) insideB2 = false;
	//Check if mouse is above the button
	if (y < Button2Topposition.y) insideB2 = false;
	//Check if mouse is below the button
	if (y > Button2Bottomposition.y) insideB2 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideB2 == true) {
		if (Button2Hovering == true) DrawButton2Clicked(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawDropDownBox1(renderer, DropDownBox1, DropDownBox1Border);
		DrawDropDownBox2(renderer, DropDownBox2, DropDownBox2Border);
		DrawDropDownBox3(renderer, DropDownBox3, DropDownBox3Border);
		DrawDropDownBox4(renderer, DropDownBox4, DropDownBox4Border);
		DrawDropDownBox5(renderer, DropDownBox5, DropDownBox5Border);
		DrawDropDownBox6(renderer, DropDownBox6, DropDownBox6Border);
		DrawDropDownBox7(renderer, DropDownBox7, DropDownBox7Border);
		DrawDropDownBox8(renderer, DropDownBox8, DropDownBox8Border);
		DrawDropDownBox9(renderer, DropDownBox9, DropDownBox9Border);
		DrawDropDownBox10(renderer, DropDownBox10, DropDownBox10Border);
		DrawDropDownBox11(renderer, DropDownBox11, DropDownBox11Border);
		DrawDropDownBox12(renderer, DropDownBox12, DropDownBox12Border);
		DrawDropDownBox13(renderer, DropDownBox13, DropDownBox13Border);
		DrawDropDownBox14(renderer, DropDownBox14, DropDownBox14Border);
		StartDropDown = true;
	};

	if (event.type == SDL_MOUSEBUTTONUP && Button2Clicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		Button2Clicked = false;
	}

	if (insideB2 == true && Button2Hovering == false && Button2Clicked == false) DrawButton2Hover(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);

	else if (insideB2 == false && Button2IsDefault == false) {
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
	};
}

void RenderMain::DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1, SDL_Rect DropDownBox1Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1 = TTF_RenderText_Blended(font, list.Races[1].c_str(), Grey);
	SDL_Texture* Drop1M = SDL_CreateTextureFromSurface(renderer, Drop1);
	SDL_RenderCopy(renderer, Drop1M, NULL, &DropDownBox1);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop1);

	RenderMain::DropDown1IsDefault = true;
	RenderMain::DropDown1Hovering = false;
}

void RenderMain::DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2, SDL_Rect DropDownBox2Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2 = TTF_RenderText_Blended(font, list.Races[2].c_str(), Grey);
	SDL_Texture* Drop2M = SDL_CreateTextureFromSurface(renderer, Drop2);
	SDL_RenderCopy(renderer, Drop2M, NULL, &DropDownBox2);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop2);

	RenderMain::DropDown2IsDefault = true;
	RenderMain::DropDown2Hovering = false;
}

void RenderMain::DrawDropDownBox3(SDL_Renderer* renderer, SDL_Rect DropDownBox3, SDL_Rect DropDownBox3Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox3);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox3Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop3 = TTF_RenderText_Blended(font, list.Races[3].c_str(), Grey);
	SDL_Texture* Drop3M = SDL_CreateTextureFromSurface(renderer, Drop3);
	SDL_RenderCopy(renderer, Drop3M, NULL, &DropDownBox3);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop3);

	RenderMain::DropDown3IsDefault = true;
	RenderMain::DropDown3Hovering = false;
}

void RenderMain::DrawDropDownBox4(SDL_Renderer* renderer, SDL_Rect DropDownBox4, SDL_Rect DropDownBox4Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox4Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop4 = TTF_RenderText_Blended(font, list.Races[4].c_str(), Grey);
	SDL_Texture* Drop4M = SDL_CreateTextureFromSurface(renderer, Drop4);
	SDL_RenderCopy(renderer, Drop4M, NULL, &DropDownBox4);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop4);

	RenderMain::DropDown4IsDefault = true;
	RenderMain::DropDown4Hovering = false;
}

void RenderMain::DrawDropDownBox5(SDL_Renderer* renderer, SDL_Rect DropDownBox5, SDL_Rect DropDownBox5Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox5);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox5Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop5 = TTF_RenderText_Blended(font, list.Races[5].c_str(), Grey);
	SDL_Texture* Drop5M = SDL_CreateTextureFromSurface(renderer, Drop5);
	SDL_RenderCopy(renderer, Drop5M, NULL, &DropDownBox5);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop5);

	RenderMain::DropDown5IsDefault = true;
	RenderMain::DropDown5Hovering = false;
}

void RenderMain::DrawDropDownBox6(SDL_Renderer* renderer, SDL_Rect DropDownBox6, SDL_Rect DropDownBox6Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox6);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox6Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop6 = TTF_RenderText_Blended(font, list.Races[6].c_str(), Grey);
	SDL_Texture* Drop6M = SDL_CreateTextureFromSurface(renderer, Drop6);
	SDL_RenderCopy(renderer, Drop6M, NULL, &DropDownBox6);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop6);

	RenderMain::DropDown6IsDefault = true;
	RenderMain::DropDown6Hovering = false;
}

void RenderMain::DrawDropDownBox7(SDL_Renderer* renderer, SDL_Rect DropDownBox7, SDL_Rect DropDownBox7Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox7);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox7Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop7 = TTF_RenderText_Blended(font, list.Races[7].c_str(), Grey);
	SDL_Texture* Drop7M = SDL_CreateTextureFromSurface(renderer, Drop7);
	SDL_RenderCopy(renderer, Drop7M, NULL, &DropDownBox7);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop7);

	RenderMain::DropDown7IsDefault = true;
	RenderMain::DropDown7Hovering = false;
}

void RenderMain::DrawDropDownBox8(SDL_Renderer* renderer, SDL_Rect DropDownBox8, SDL_Rect DropDownBox8Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox8);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox8Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop8 = TTF_RenderText_Blended(font, list.Races[8].c_str(), Grey);
	SDL_Texture* Drop8M = SDL_CreateTextureFromSurface(renderer, Drop8);
	SDL_RenderCopy(renderer, Drop8M, NULL, &DropDownBox8);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop8);

	RenderMain::DropDown8IsDefault = true;
	RenderMain::DropDown8Hovering = false;
}

void RenderMain::DrawDropDownBox9(SDL_Renderer* renderer, SDL_Rect DropDownBox9, SDL_Rect DropDownBox9Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox9);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox9Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop9 = TTF_RenderText_Blended(font, list.Races[9].c_str(), Grey);
	SDL_Texture* Drop9M = SDL_CreateTextureFromSurface(renderer, Drop9);
	SDL_RenderCopy(renderer, Drop9M, NULL, &DropDownBox9);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop9);

	RenderMain::DropDown9IsDefault = true;
	RenderMain::DropDown9Hovering = false;
}

void RenderMain::DrawDropDownBox10(SDL_Renderer* renderer, SDL_Rect DropDownBox10, SDL_Rect DropDownBox10Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox10);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox10Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop10 = TTF_RenderText_Blended(font, list.Races[10].c_str(), Grey);
	SDL_Texture* Drop10M = SDL_CreateTextureFromSurface(renderer, Drop10);
	SDL_RenderCopy(renderer, Drop10M, NULL, &DropDownBox10);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop10);

	RenderMain::DropDown10IsDefault = true;
	RenderMain::DropDown10Hovering = false;
}

void RenderMain::DrawDropDownBox11(SDL_Renderer* renderer, SDL_Rect DropDownBox11, SDL_Rect DropDownBox11Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox11);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox11Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop11 = TTF_RenderText_Blended(font, list.Races[11].c_str(), Grey);
	SDL_Texture* Drop11M = SDL_CreateTextureFromSurface(renderer, Drop11);
	SDL_RenderCopy(renderer, Drop11M, NULL, &DropDownBox11);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop11);

	RenderMain::DropDown11IsDefault = true;
	RenderMain::DropDown11Hovering = false;
}

void RenderMain::DrawDropDownBox12(SDL_Renderer* renderer, SDL_Rect DropDownBox12, SDL_Rect DropDownBox12Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox12);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox12Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop12 = TTF_RenderText_Blended(font, list.Races[12].c_str(), Grey);
	SDL_Texture* Drop12M = SDL_CreateTextureFromSurface(renderer, Drop12);
	SDL_RenderCopy(renderer, Drop12M, NULL, &DropDownBox12);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop12);

	RenderMain::DropDown12IsDefault = true;
	RenderMain::DropDown12Hovering = false;
}

void RenderMain::DrawDropDownBox13(SDL_Renderer* renderer, SDL_Rect DropDownBox13, SDL_Rect DropDownBox13Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox13);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox13Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop13 = TTF_RenderText_Blended(font, list.Races[13].c_str(), Grey);
	SDL_Texture* Drop13M = SDL_CreateTextureFromSurface(renderer, Drop13);
	SDL_RenderCopy(renderer, Drop13M, NULL, &DropDownBox13);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop13);

	RenderMain::DropDown13IsDefault = true;
	RenderMain::DropDown13Hovering = false;
}

void RenderMain::DrawDropDownBox14(SDL_Renderer* renderer, SDL_Rect DropDownBox14, SDL_Rect DropDownBox14Border) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox14);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox14Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop14 = TTF_RenderText_Blended(font, list.Races[14].c_str(), Grey);
	SDL_Texture* Drop14M = SDL_CreateTextureFromSurface(renderer, Drop14);
	SDL_RenderCopy(renderer, Drop14M, NULL, &DropDownBox14);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop14);

	RenderMain::DropDown14IsDefault = true;
	RenderMain::DropDown14Hovering = false;
}

void RenderMain::DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1, SDL_Rect DropDownBox1Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1 = TTF_RenderText_Blended(font, list.Races[1].c_str(), LightGrey);
	SDL_Texture* Drop1M = SDL_CreateTextureFromSurface(renderer, Drop1);
	SDL_RenderCopy(renderer, Drop1M, NULL, &DropDownBox1);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop1);

	RenderMain::DropDown1IsDefault = false;
	RenderMain::DropDown1Hovering = true;
}

void RenderMain::DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2, SDL_Rect DropDownBox2Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2 = TTF_RenderText_Blended(font, list.Races[2].c_str(), LightGrey);
	SDL_Texture* Drop2M = SDL_CreateTextureFromSurface(renderer, Drop2);
	SDL_RenderCopy(renderer, Drop2M, NULL, &DropDownBox2);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop2);

	RenderMain::DropDown2IsDefault = false;
	RenderMain::DropDown2Hovering = true;
}

void RenderMain::DrawDropDownBox3Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox3, SDL_Rect DropDownBox3Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox3);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox3Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop3 = TTF_RenderText_Blended(font, list.Races[3].c_str(), LightGrey);
	SDL_Texture* Drop3M = SDL_CreateTextureFromSurface(renderer, Drop3);
	SDL_RenderCopy(renderer, Drop3M, NULL, &DropDownBox3);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop3);

	RenderMain::DropDown3IsDefault = false;
	RenderMain::DropDown3Hovering = true;
}

void RenderMain::DrawDropDownBox4Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox4, SDL_Rect DropDownBox4Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox4Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop4 = TTF_RenderText_Blended(font, list.Races[4].c_str(), LightGrey);
	SDL_Texture* Drop4M = SDL_CreateTextureFromSurface(renderer, Drop4);
	SDL_RenderCopy(renderer, Drop4M, NULL, &DropDownBox4);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop4);

	RenderMain::DropDown4IsDefault = false;
	RenderMain::DropDown4Hovering = true;
}

void RenderMain::DrawDropDownBox5Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox5, SDL_Rect DropDownBox5Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox5);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox5Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop5 = TTF_RenderText_Blended(font, list.Races[5].c_str(), LightGrey);
	SDL_Texture* Drop5M = SDL_CreateTextureFromSurface(renderer, Drop5);
	SDL_RenderCopy(renderer, Drop5M, NULL, &DropDownBox5);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop5);

	RenderMain::DropDown5IsDefault = false;
	RenderMain::DropDown5Hovering = true;
}

void RenderMain::DrawDropDownBox6Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox6, SDL_Rect DropDownBox6Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox6);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox6Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop6 = TTF_RenderText_Blended(font, list.Races[6].c_str(), LightGrey);
	SDL_Texture* Drop6M = SDL_CreateTextureFromSurface(renderer, Drop6);
	SDL_RenderCopy(renderer, Drop6M, NULL, &DropDownBox6);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop6);

	RenderMain::DropDown6IsDefault = false;
	RenderMain::DropDown6Hovering = true;
}

void RenderMain::DrawDropDownBox7Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox7, SDL_Rect DropDownBox7Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox7);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox7Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop7 = TTF_RenderText_Blended(font, list.Races[7].c_str(), LightGrey);
	SDL_Texture* Drop7M = SDL_CreateTextureFromSurface(renderer, Drop7);
	SDL_RenderCopy(renderer, Drop7M, NULL, &DropDownBox7);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop7);

	RenderMain::DropDown7IsDefault = false;
	RenderMain::DropDown7Hovering = true;
}

void RenderMain::DrawDropDownBox8Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox8, SDL_Rect DropDownBox8Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox8);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox8Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop8 = TTF_RenderText_Blended(font, list.Races[8].c_str(), LightGrey);
	SDL_Texture* Drop8M = SDL_CreateTextureFromSurface(renderer, Drop8);
	SDL_RenderCopy(renderer, Drop8M, NULL, &DropDownBox8);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop8);

	RenderMain::DropDown8IsDefault = false;
	RenderMain::DropDown8Hovering = true;
}

void RenderMain::DrawDropDownBox9Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox9, SDL_Rect DropDownBox9Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox9);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox9Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop9 = TTF_RenderText_Blended(font, list.Races[9].c_str(), LightGrey);
	SDL_Texture* Drop9M = SDL_CreateTextureFromSurface(renderer, Drop9);
	SDL_RenderCopy(renderer, Drop9M, NULL, &DropDownBox9);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop9);

	RenderMain::DropDown9IsDefault = false;
	RenderMain::DropDown9Hovering = true;
}

void RenderMain::DrawDropDownBox10Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox10, SDL_Rect DropDownBox10Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox10);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox10Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop10 = TTF_RenderText_Blended(font, list.Races[10].c_str(), LightGrey);
	SDL_Texture* Drop10M = SDL_CreateTextureFromSurface(renderer, Drop10);
	SDL_RenderCopy(renderer, Drop10M, NULL, &DropDownBox10);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop10);

	RenderMain::DropDown10IsDefault = false;
	RenderMain::DropDown10Hovering = true;
}

void RenderMain::DrawDropDownBox11Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox11, SDL_Rect DropDownBox11Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox11);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox11Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop11 = TTF_RenderText_Blended(font, list.Races[11].c_str(), LightGrey);
	SDL_Texture* Drop11M = SDL_CreateTextureFromSurface(renderer, Drop11);
	SDL_RenderCopy(renderer, Drop11M, NULL, &DropDownBox11);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop11);

	RenderMain::DropDown11IsDefault = false;
	RenderMain::DropDown11Hovering = true;
}

void RenderMain::DrawDropDownBox12Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox12, SDL_Rect DropDownBox12Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox12);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox12Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop12 = TTF_RenderText_Blended(font, list.Races[12].c_str(), LightGrey);
	SDL_Texture* Drop12M = SDL_CreateTextureFromSurface(renderer, Drop12);
	SDL_RenderCopy(renderer, Drop12M, NULL, &DropDownBox12);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop12);

	RenderMain::DropDown12IsDefault = false;
	RenderMain::DropDown12Hovering = true;
}

void RenderMain::DrawDropDownBox13Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox13, SDL_Rect DropDownBox13Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox13);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox13Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop13 = TTF_RenderText_Blended(font, list.Races[13].c_str(), LightGrey);
	SDL_Texture* Drop13M = SDL_CreateTextureFromSurface(renderer, Drop13);
	SDL_RenderCopy(renderer, Drop13M, NULL, &DropDownBox13);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop13);

	RenderMain::DropDown13IsDefault = false;
	RenderMain::DropDown13Hovering = true;
}

void RenderMain::DrawDropDownBox14Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox14, SDL_Rect DropDownBox14Border) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox14);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox14Border);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop14 = TTF_RenderText_Blended(font, list.Races[14].c_str(), LightGrey);
	SDL_Texture* Drop14M = SDL_CreateTextureFromSurface(renderer, Drop14);
	SDL_RenderCopy(renderer, Drop14M, NULL, &DropDownBox14);

	TTF_CloseFont(font);
	SDL_FreeSurface(Drop14);

	RenderMain::DropDown14IsDefault = false;
	RenderMain::DropDown14Hovering = true;
}

void RenderMain::CheckMousePositionDropDown1(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown1 = true;

	//Check if mouse is left of the button
	if (x < DropDown1Leftposition.x) insideDropDown1 = false;
	//Check if mouse is right of the button
	if (x > DropDown1Rightposition.x) insideDropDown1 = false;
	//Check if mouse is above the button
	if (y < DropDown1Topposition.y) insideDropDown1 = false;
	//Check if mouse is below the button
	if (y > DropDown1Bottomposition.y) insideDropDown1 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown1 == true && StartDropDown == true) {
		std::swap(list.Races[1], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown1 == true && DropDown1Hovering == false) DrawDropDownBox1Hover(renderer, DropDownBox1, DropDownBox1Border);

		else if (insideDropDown1 == false && DropDown1IsDefault == false) {
			DrawDropDownBox1(renderer, DropDownBox1, DropDownBox1Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown2(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown2 = true;

	//Check if mouse is left of the button
	if (x < DropDown2Leftposition.x) insideDropDown2 = false;
	//Check if mouse is right of the button
	if (x > DropDown2Rightposition.x) insideDropDown2 = false;
	//Check if mouse is above the button
	if (y < DropDown2Topposition.y) insideDropDown2 = false;
	//Check if mouse is below the button
	if (y > DropDown2Bottomposition.y) insideDropDown2 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown2 == true && StartDropDown == true) {
		std::swap(list.Races[2], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown2 == true && DropDown2Hovering == false) DrawDropDownBox2Hover(renderer, DropDownBox2, DropDownBox2Border);

		else if (insideDropDown2 == false && DropDown2IsDefault == false) {
			DrawDropDownBox2(renderer, DropDownBox2, DropDownBox2Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown3(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown3 = true;

	//Check if mouse is left of the button
	if (x < DropDown3Leftposition.x) insideDropDown3 = false;
	//Check if mouse is right of the button
	if (x > DropDown3Rightposition.x) insideDropDown3 = false;
	//Check if mouse is above the button
	if (y < DropDown3Topposition.y) insideDropDown3 = false;
	//Check if mouse is below the button
	if (y > DropDown3Bottomposition.y) insideDropDown3 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown3 == true && StartDropDown == true) {
		std::swap(list.Races[3], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown3 == true && DropDown3Hovering == false) DrawDropDownBox3Hover(renderer, DropDownBox3, DropDownBox3Border);

		else if (insideDropDown3 == false && DropDown3IsDefault == false) {
			DrawDropDownBox3(renderer, DropDownBox3, DropDownBox3Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown4(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown4 = true;

	//Check if mouse is left of the button
	if (x < DropDown4Leftposition.x) insideDropDown4 = false;
	//Check if mouse is right of the button
	if (x > DropDown4Rightposition.x) insideDropDown4 = false;
	//Check if mouse is above the button
	if (y < DropDown4Topposition.y) insideDropDown4 = false;
	//Check if mouse is below the button
	if (y > DropDown4Bottomposition.y) insideDropDown4 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown4 == true && StartDropDown == true) {
		std::swap(list.Races[4], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown4 == true && DropDown4Hovering == false) DrawDropDownBox4Hover(renderer, DropDownBox4, DropDownBox4Border);

		else if (insideDropDown4 == false && DropDown4IsDefault == false) {
			DrawDropDownBox4(renderer, DropDownBox4, DropDownBox4Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown5(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown5 = true;

	//Check if mouse is left of the button
	if (x < DropDown5Leftposition.x) insideDropDown5 = false;
	//Check if mouse is right of the button
	if (x > DropDown5Rightposition.x) insideDropDown5 = false;
	//Check if mouse is above the button
	if (y < DropDown5Topposition.y) insideDropDown5 = false;
	//Check if mouse is below the button
	if (y > DropDown5Bottomposition.y) insideDropDown5 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown5 == true && StartDropDown == true) {
		std::swap(list.Races[5], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown5 == true && DropDown5Hovering == false) DrawDropDownBox5Hover(renderer, DropDownBox5, DropDownBox5Border);

		else if (insideDropDown5 == false && DropDown5IsDefault == false) {
			DrawDropDownBox5(renderer, DropDownBox5, DropDownBox5Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown6(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown6 = true;

	//Check if mouse is left of the button
	if (x < DropDown6Leftposition.x) insideDropDown6 = false;
	//Check if mouse is right of the button
	if (x > DropDown6Rightposition.x) insideDropDown6 = false;
	//Check if mouse is above the button
	if (y < DropDown6Topposition.y) insideDropDown6 = false;
	//Check if mouse is below the button
	if (y > DropDown6Bottomposition.y) insideDropDown6 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown6 == true && StartDropDown == true) {
		std::swap(list.Races[6], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown6 == true && DropDown6Hovering == false) DrawDropDownBox6Hover(renderer, DropDownBox6, DropDownBox6Border);

		else if (insideDropDown6 == false && DropDown6IsDefault == false) {
			DrawDropDownBox6(renderer, DropDownBox6, DropDownBox6Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown7(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown7 = true;

	//Check if mouse is left of the button
	if (x < DropDown7Leftposition.x) insideDropDown7 = false;
	//Check if mouse is right of the button
	if (x > DropDown7Rightposition.x) insideDropDown7 = false;
	//Check if mouse is above the button
	if (y < DropDown7Topposition.y) insideDropDown7 = false;
	//Check if mouse is below the button
	if (y > DropDown7Bottomposition.y) insideDropDown7 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown7 == true && StartDropDown == true) {
		std::swap(list.Races[7], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown7 == true && DropDown7Hovering == false) DrawDropDownBox7Hover(renderer, DropDownBox7, DropDownBox7Border);

		else if (insideDropDown7 == false && DropDown7IsDefault == false) {
			DrawDropDownBox7(renderer, DropDownBox7, DropDownBox7Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown8(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown8 = true;

	//Check if mouse is left of the button
	if (x < DropDown8Leftposition.x) insideDropDown8 = false;
	//Check if mouse is right of the button
	if (x > DropDown8Rightposition.x) insideDropDown8 = false;
	//Check if mouse is above the button
	if (y < DropDown8Topposition.y) insideDropDown8 = false;
	//Check if mouse is below the button
	if (y > DropDown8Bottomposition.y) insideDropDown8 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown8 == true && StartDropDown == true) {
		std::swap(list.Races[8], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown8 == true && DropDown8Hovering == false) DrawDropDownBox8Hover(renderer, DropDownBox8, DropDownBox8Border);

		else if (insideDropDown8 == false && DropDown8IsDefault == false) {
			DrawDropDownBox8(renderer, DropDownBox8, DropDownBox8Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown9(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown9 = true;

	//Check if mouse is left of the button
	if (x < DropDown9Leftposition.x) insideDropDown9 = false;
	//Check if mouse is right of the button
	if (x > DropDown9Rightposition.x) insideDropDown9 = false;
	//Check if mouse is above the button
	if (y < DropDown9Topposition.y) insideDropDown9 = false;
	//Check if mouse is below the button
	if (y > DropDown9Bottomposition.y) insideDropDown9 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown9 == true && StartDropDown == true) {
		std::swap(list.Races[9], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown9 == true && DropDown9Hovering == false) DrawDropDownBox9Hover(renderer, DropDownBox9, DropDownBox9Border);

		else if (insideDropDown9 == false && DropDown9IsDefault == false) {
			DrawDropDownBox9(renderer, DropDownBox9, DropDownBox9Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown10(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown10 = true;

	//Check if mouse is left of the button
	if (x < DropDown10Leftposition.x) insideDropDown10 = false;
	//Check if mouse is right of the button
	if (x > DropDown10Rightposition.x) insideDropDown10 = false;
	//Check if mouse is above the button
	if (y < DropDown10Topposition.y) insideDropDown10 = false;
	//Check if mouse is below the button
	if (y > DropDown10Bottomposition.y) insideDropDown10 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown10 == true && StartDropDown == true) {
		std::swap(list.Races[10], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown10 == true && DropDown10Hovering == false) DrawDropDownBox10Hover(renderer, DropDownBox10, DropDownBox10Border);

		else if (insideDropDown10 == false && DropDown10IsDefault == false) {
			DrawDropDownBox10(renderer, DropDownBox10, DropDownBox10Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown11(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown11 = true;

	//Check if mouse is left of the button
	if (x < DropDown11Leftposition.x) insideDropDown11 = false;
	//Check if mouse is right of the button
	if (x > DropDown11Rightposition.x) insideDropDown11 = false;
	//Check if mouse is above the button
	if (y < DropDown11Topposition.y) insideDropDown11 = false;
	//Check if mouse is below the button
	if (y > DropDown11Bottomposition.y) insideDropDown11 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown11 == true && StartDropDown == true) {
		std::swap(list.Races[11], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown11 == true && DropDown11Hovering == false) DrawDropDownBox11Hover(renderer, DropDownBox11, DropDownBox11Border);

		else if (insideDropDown11 == false && DropDown11IsDefault == false) {
			DrawDropDownBox11(renderer, DropDownBox11, DropDownBox11Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown12(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown12 = true;

	//Check if mouse is left of the button
	if (x < DropDown12Leftposition.x) insideDropDown12 = false;
	//Check if mouse is right of the button
	if (x > DropDown12Rightposition.x) insideDropDown12 = false;
	//Check if mouse is above the button
	if (y < DropDown12Topposition.y) insideDropDown12 = false;
	//Check if mouse is below the button
	if (y > DropDown12Bottomposition.y) insideDropDown12 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown12 == true && StartDropDown == true) {
		std::swap(list.Races[12], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown12 == true && DropDown12Hovering == false) DrawDropDownBox12Hover(renderer, DropDownBox12, DropDownBox12Border);

		else if (insideDropDown12 == false && DropDown12IsDefault == false) {
			DrawDropDownBox12(renderer, DropDownBox12, DropDownBox12Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown13(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown13 = true;

	//Check if mouse is left of the button
	if (x < DropDown13Leftposition.x) insideDropDown13 = false;
	//Check if mouse is right of the button
	if (x > DropDown13Rightposition.x) insideDropDown13 = false;
	//Check if mouse is above the button
	if (y < DropDown13Topposition.y) insideDropDown13 = false;
	//Check if mouse is below the button
	if (y > DropDown13Bottomposition.y) insideDropDown13 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown13 == true && StartDropDown == true) {
		std::swap(list.Races[13], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown13 == true && DropDown13Hovering == false) DrawDropDownBox13Hover(renderer, DropDownBox13, DropDownBox13Border);

		else if (insideDropDown13 == false && DropDown13IsDefault == false) {
			DrawDropDownBox13(renderer, DropDownBox13, DropDownBox13Border);
		};
	}
}

void RenderMain::CheckMousePositionDropDown14(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideDropDown14 = true;

	//Check if mouse is left of the button
	if (x < DropDown14Leftposition.x) insideDropDown14 = false;
	//Check if mouse is right of the button
	if (x > DropDown14Rightposition.x) insideDropDown14 = false;
	//Check if mouse is above the button
	if (y < DropDown14Topposition.y) insideDropDown14 = false;
	//Check if mouse is below the button
	if (y > DropDown14Bottomposition.y) insideDropDown14 = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideDropDown14 == true && StartDropDown == true) {
		std::swap(list.Races[14], list.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown14 == true && DropDown14Hovering == false) DrawDropDownBox14Hover(renderer, DropDownBox14, DropDownBox14Border);

		else if (insideDropDown14 == false && DropDown14IsDefault == false) {
			DrawDropDownBox14(renderer, DropDownBox14, DropDownBox14Border);
		};
	}
}

void RenderMain::ReplaceRightSide(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 135, 10, 1, 255);
	SDL_Rect ReplaceRightSideRect{ 600,0,400,800 };
	SDL_RenderFillRect(renderer, &ReplaceRightSideRect);
}

void RenderMain::DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButtonBorder);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Submit = TTF_RenderText_Blended(font, "Submit", Grey);
	SDL_Texture* SubmitM = SDL_CreateTextureFromSurface(renderer, Submit);
	SDL_RenderCopy(renderer, SubmitM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(font);
	SDL_FreeSurface(Submit);

	RenderMain::SubmitIsDefault = true;
	RenderMain::SubmitHovering = false;
	RenderMain::SubmitClicked = false;
}

void RenderMain::DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButtonBorder);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* SubmitHover = TTF_RenderText_Blended(font, "Submit", LightGrey);
	SDL_Texture* SubmitHoverM = SDL_CreateTextureFromSurface(renderer, SubmitHover);
	SDL_RenderCopy(renderer, SubmitHoverM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(font);
	SDL_FreeSurface(SubmitHover);

	RenderMain::SubmitIsDefault = false;
	RenderMain::SubmitHovering = true;
	RenderMain::SubmitClicked = false;
}

void RenderMain::DrawSubmitButtonClicked(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonBorder, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButtonBorder);

	TTF_Font* font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* SubmitClicked = TTF_RenderText_Blended(font, "Submit", DarkGrey);
	SDL_Texture* SubmitClickedM = SDL_CreateTextureFromSurface(renderer, SubmitClicked);
	SDL_RenderCopy(renderer, SubmitClickedM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(font);
	SDL_FreeSurface(SubmitClicked);

	RenderMain::SubmitIsDefault = false;
	RenderMain::SubmitHovering = false;
	RenderMain::SubmitClicked = true;
}

void RenderMain::CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideSubmit = true;

	//Check if mouse is left of the button
	if (x < SubmitLeftposition.x) insideSubmit = false;
	//Check if mouse is right of the button
	if (x > SubmitRightposition.x) insideSubmit = false;
	//Check if mouse is above the button
	if (y < SubmitTopposition.y) insideSubmit = false;
	//Check if mouse is below the button
	if (y > SubmitBottomposition.y) insideSubmit = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideSubmit == true) {
		if (SubmitHovering == true) DrawSubmitButtonClicked(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
		std::string result = randomizer.RandomBySelectedRace(list.Races[0]);
		ReplaceInnerWindow(renderer);
		ReplaceRightSide(renderer);
		DrawLordResult(renderer, result);
		DrawButton(renderer, Button1, Button1Border, Button1Message);
		DrawButton2(renderer, Button2, Button2Border, Button2MessageRect, Button2DropDown, Button2DropDownB, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
	};

	if (event.type == SDL_MOUSEBUTTONUP && SubmitClicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		SubmitClicked = false;
	}

	if (insideSubmit == true && SubmitHovering == false && SubmitClicked == false) DrawSubmitButtonHover(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);

	else if (insideSubmit == false && SubmitIsDefault == false) {
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonBorder, SubmitButtonMessage);
	};
}
