#include "Warhammer Render.h"

void RenderWarhammer::DrawScreen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 135, 10, 1, 255);
	SDL_Rect RSide{ 1000, 0, 925, 1080 };
	SDL_RenderFillRect(renderer, &RSide);

	SDL_Rect LSide{ 0, 0, 5, 1080 };
	SDL_RenderFillRect(renderer, &LSide);

	SDL_Rect Bottom{ 0, 750, 1000, 480 };
	SDL_RenderFillRect(renderer, &Bottom);

	SDL_SetRenderDrawColor(renderer, 74, 14, 10, 255);
	SDL_Rect WBorder{0, 0, 1920, 1080 };
	SDL_RenderDrawRect(renderer, &WBorder);

	SDL_Rect SWBorder{ 5, 0, 995, 750 };
	SDL_RenderDrawRect(renderer, &SWBorder);
}

void RenderWarhammer::ReplaceInnerWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect ReplaceInnerWindow{ 5,0,995,750 };
	SDL_RenderFillRect(renderer, &ReplaceInnerWindow);
}

void RenderWarhammer::DrawLordResult(SDL_Renderer* renderer, std::string lord) {
	TTF_Font* Lordfont = TTF_OpenFont("darkdominion.ttf", 41);
	if (!Lordfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	int w, h;
	if (TTF_SizeText(Lordfont, lord.c_str(), &w, &h)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_Rect LordResultRect{ 125,40,w,h };
	SDL_Surface* LordR = TTF_RenderText_Blended(Lordfont, lord.c_str(), DarkGold);
	SDL_Texture* LordRM = SDL_CreateTextureFromSurface(renderer, LordR);
	SDL_RenderCopy(renderer, LordRM, NULL, &LordResultRect);

	TTF_CloseFont(Lordfont);
	SDL_FreeSurface(LordR);
	SDL_DestroyTexture(LordRM);
	Lordfont = NULL;
	LordR = NULL;
	LordRM = NULL;
}

void RenderWarhammer::DrawButton(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Message) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button1);

	TTF_Font* Button1font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Button1font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* RAll = TTF_RenderText_Blended(Button1font, "Random All", Grey);
	SDL_Texture* RAllM = SDL_CreateTextureFromSurface(renderer, RAll);
	SDL_RenderCopy(renderer, RAllM, NULL, &Button1Message);

	TTF_CloseFont(Button1font);
	Button1font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(RAll);
		SDL_DestroyTexture(RAllM);
		RAllM = NULL;
		RAll = NULL;
	}

	RenderWarhammer::Button1IsDefault = true;
	RenderWarhammer::Button1Hovering = false;
	RenderWarhammer::Button1Clicked = false;
}

void RenderWarhammer::DrawButtonHover(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Message) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button1);

	TTF_Font* Button1Hfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Button1Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* RandALLHover = TTF_RenderText_Blended(Button1Hfont, "Random All", LightGrey);
	SDL_Texture* RandAllHoverM = SDL_CreateTextureFromSurface(renderer, RandALLHover);
	SDL_RenderCopy(renderer, RandAllHoverM, NULL, &Button1Message);

	TTF_CloseFont(Button1Hfont);
	Button1Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(RandALLHover);
		SDL_DestroyTexture(RandAllHoverM);
		RandAllHoverM = NULL;
		RandALLHover = NULL;
	}

	RenderWarhammer::Button1IsDefault = false;
	RenderWarhammer::Button1Hovering = true;
	RenderWarhammer::Button1Clicked = false;
};

void RenderWarhammer::DrawButtonClicked(SDL_Renderer* renderer, SDL_Rect Button1, SDL_Rect Button1Message) {
		SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
		SDL_RenderFillRect(renderer, &Button1);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &Button1);

		TTF_Font* Button1Cfont = TTF_OpenFont("darkdominion.ttf", 43);
		if (!Button1Cfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* RandAllClick = TTF_RenderText_Blended(Button1Cfont, "Random All", DarkGrey);
		SDL_Texture* RandAllClickM = SDL_CreateTextureFromSurface(renderer, RandAllClick);
		SDL_RenderCopy(renderer, RandAllClickM, NULL, &Button1Message);

		TTF_CloseFont(Button1Cfont);
		Button1Cfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(RandAllClick);
			SDL_DestroyTexture(RandAllClickM);
			RandAllClickM = NULL;
			RandAllClick = NULL;
		}

		RenderWarhammer::Button1IsDefault = false;
		RenderWarhammer::Button1Hovering = false;
		RenderWarhammer::Button1Clicked = true;
};

void RenderWarhammer::CheckMousePositionButton1(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
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
		if (Button1Hovering == true) {
			DrawButtonClicked(renderer, Button1, Button1Message);
			std::vector<std::string> result = randomizer.RandomAll(randomizer.Warhammerlist.TotalFactions);
			std::string FilePath = randomizer.GetPictureFilepath(result[1], randomizer.Warhammerlist.WarhammerFilePaths);
			ReplaceInnerWindow(renderer);
			DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
			DrawShogunButton(renderer, ShogunButton, ShogunMessage);
			PullImage(renderer, window, FilePath);
			DrawLordResult(renderer, result[1]);
		}
	};

	if (event.type == SDL_MOUSEBUTTONUP && Button1Clicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		Button1Clicked = false;
	}

	if (insideB1 == true && Button1Hovering == false && Button1Clicked == false) DrawButtonHover(renderer, Button1, Button1Message);

	else if (insideB1 == false && Button1IsDefault == false) {
		DrawButton(renderer, Button1, Button1Message);
	};
}

void RenderWarhammer::DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2font = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Button2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2 = TTF_RenderText_Blended(Button2font, randomizer.Warhammerlist.Races[0].c_str(), Grey);
	SDL_Texture* B2M = SDL_CreateTextureFromSurface(renderer, B2);
	SDL_RenderCopy(renderer, B2M, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2font2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2font2) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BV = TTF_RenderText_Blended(Button2font2, "V", Grey);
	SDL_Texture* BVM = SDL_CreateTextureFromSurface(renderer, BV);
	SDL_RenderCopy(renderer, BVM, NULL, &DropDownV);


	TTF_CloseFont(Button2font);
	TTF_CloseFont(Button2font2);
	Button2font = NULL;
	Button2font2 = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(B2);
		SDL_FreeSurface(BV);
		SDL_DestroyTexture(B2M);
		SDL_DestroyTexture(BVM);
		B2 = NULL;
		BV = NULL;
		B2M = NULL;
		BVM = NULL;
	}

	RenderWarhammer::Button2IsDefault = true;
	RenderWarhammer::Button2Hovering = false;
	RenderWarhammer::Button2Clicked = false;
}

void RenderWarhammer::DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2Hfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Button2Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2H = TTF_RenderText_Blended(Button2Hfont, randomizer.Warhammerlist.Races[0].c_str(), LightGrey);
	SDL_Texture* B2HM = SDL_CreateTextureFromSurface(renderer, B2H);
	SDL_RenderCopy(renderer, B2HM, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2Hfont2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2Hfont2) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BVH = TTF_RenderText_Blended(Button2Hfont2, "V", Grey);
	SDL_Texture* BVHM = SDL_CreateTextureFromSurface(renderer, BVH);
	SDL_RenderCopy(renderer, BVHM, NULL, &DropDownV);


	TTF_CloseFont(Button2Hfont);
	TTF_CloseFont(Button2Hfont2);
	Button2Hfont = NULL;
	Button2Hfont2 = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(B2H);
		SDL_FreeSurface(BVH);
		SDL_DestroyTexture(B2HM);
		SDL_DestroyTexture(BVHM);
		B2H = NULL;
		BVH = NULL;
		B2HM = NULL;
		BVHM = NULL;
	}

	RenderWarhammer::Button2IsDefault = false;
	RenderWarhammer::Button2Hovering = true;
	RenderWarhammer::Button2Clicked = false;
};

void RenderWarhammer::DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2Cfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Button2Cfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2C = TTF_RenderText_Blended(Button2Cfont, randomizer.Warhammerlist.Races[0].c_str(), DarkGrey);
	SDL_Texture* B2CM = SDL_CreateTextureFromSurface(renderer, B2C);
	SDL_RenderCopy(renderer, B2CM, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2Cfont2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2Cfont2) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BVC = TTF_RenderText_Blended(Button2Cfont2, "V", Grey);
	SDL_Texture* BVCM = SDL_CreateTextureFromSurface(renderer, BVC);
	SDL_RenderCopy(renderer, BVCM, NULL, &DropDownV);


	TTF_CloseFont(Button2Cfont);
	TTF_CloseFont(Button2Cfont2);
	Button2Cfont = NULL;
	Button2Cfont2 = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(B2C);
		SDL_FreeSurface(BVC);
		SDL_DestroyTexture(B2CM);
		SDL_DestroyTexture(BVCM);
		B2C = NULL;
		BVC = NULL;
		B2CM = NULL;
		BVCM = NULL;
	}

	RenderWarhammer::Button2IsDefault = false;
	RenderWarhammer::Button2Hovering = false;
	RenderWarhammer::Button2Clicked = true;
}

void RenderWarhammer::CheckMousePositionButton2(SDL_Event event, SDL_Renderer* renderer) {
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
		if (Button2Hovering == true) DrawButton2Clicked(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawDropDownBox1(renderer, DropDownBox1);
		DrawDropDownBox2(renderer, DropDownBox2);
		DrawDropDownBox3(renderer, DropDownBox3);
		DrawDropDownBox4(renderer, DropDownBox4);
		DrawDropDownBox5(renderer, DropDownBox5);
		DrawDropDownBox6(renderer, DropDownBox6);
		DrawDropDownBox7(renderer, DropDownBox7);
		DrawDropDownBox8(renderer, DropDownBox8);
		DrawDropDownBox9(renderer, DropDownBox9);
		DrawDropDownBox10(renderer, DropDownBox10);
		DrawDropDownBox11(renderer, DropDownBox11);
		DrawDropDownBox12(renderer, DropDownBox12);
		DrawDropDownBox13(renderer, DropDownBox13);
		DrawDropDownBox14(renderer, DropDownBox14);
		StartDropDown = true;
	};

	if (event.type == SDL_MOUSEBUTTONUP && Button2Clicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		Button2Clicked = false;
	}

	if (insideB2 == true && Button2Hovering == false && Button2Clicked == false) DrawButton2Hover(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);

	else if (insideB2 == false && Button2IsDefault == false) {
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
	};
}

void RenderWarhammer::DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1);

	TTF_Font* D1font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D1font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1 = TTF_RenderText_Blended(D1font, randomizer.Warhammerlist.Races[1].c_str(), Grey);
	SDL_Texture* Drop1M = SDL_CreateTextureFromSurface(renderer, Drop1);
	SDL_RenderCopy(renderer, Drop1M, NULL, &DropDownBox1);

	TTF_CloseFont(D1font);
	D1font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop1);
		SDL_DestroyTexture(Drop1M);
		Drop1 = NULL;
		Drop1M = NULL;
	}

	RenderWarhammer::DropDown1IsDefault = true;
	RenderWarhammer::DropDown1Hovering = false;
}

void RenderWarhammer::DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2);

	TTF_Font* D2font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2 = TTF_RenderText_Blended(D2font, randomizer.Warhammerlist.Races[2].c_str(), Grey);
	SDL_Texture* Drop2M = SDL_CreateTextureFromSurface(renderer, Drop2);
	SDL_RenderCopy(renderer, Drop2M, NULL, &DropDownBox2);

	TTF_CloseFont(D2font);
	D2font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop2);
		SDL_DestroyTexture(Drop2M);
	}
	Drop2 = NULL;
	Drop2M = NULL;

	RenderWarhammer::DropDown2IsDefault = true;
	RenderWarhammer::DropDown2Hovering = false;
}

void RenderWarhammer::DrawDropDownBox3(SDL_Renderer* renderer, SDL_Rect DropDownBox3) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox3);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox3);

	TTF_Font* D3font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D3font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop3 = TTF_RenderText_Blended(D3font, randomizer.Warhammerlist.Races[3].c_str(), Grey);
	SDL_Texture* Drop3M = SDL_CreateTextureFromSurface(renderer, Drop3);
	SDL_RenderCopy(renderer, Drop3M, NULL, &DropDownBox3);

	TTF_CloseFont(D3font);
	D3font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop3);
		SDL_DestroyTexture(Drop3M);
	}
	Drop3 = NULL;
	Drop3M = NULL;

	RenderWarhammer::DropDown3IsDefault = true;
	RenderWarhammer::DropDown3Hovering = false;
}

void RenderWarhammer::DrawDropDownBox4(SDL_Renderer* renderer, SDL_Rect DropDownBox4) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox4);

	TTF_Font* D4font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D4font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop4 = TTF_RenderText_Blended(D4font, randomizer.Warhammerlist.Races[4].c_str(), Grey);
	SDL_Texture* Drop4M = SDL_CreateTextureFromSurface(renderer, Drop4);
	SDL_RenderCopy(renderer, Drop4M, NULL, &DropDownBox4);

	TTF_CloseFont(D4font);
	D4font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop4);
		SDL_DestroyTexture(Drop4M);
	}
	Drop4 = NULL;
	Drop4M = NULL;

	RenderWarhammer::DropDown4IsDefault = true;
	RenderWarhammer::DropDown4Hovering = false;
}

void RenderWarhammer::DrawDropDownBox5(SDL_Renderer* renderer, SDL_Rect DropDownBox5) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox5);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox5);

	TTF_Font* D5font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D5font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop5 = TTF_RenderText_Blended(D5font, randomizer.Warhammerlist.Races[5].c_str(), Grey);
	SDL_Texture* Drop5M = SDL_CreateTextureFromSurface(renderer, Drop5);
	SDL_RenderCopy(renderer, Drop5M, NULL, &DropDownBox5);

	TTF_CloseFont(D5font);
	D5font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop5);
		SDL_DestroyTexture(Drop5M);
	}
	Drop5 = NULL;
	Drop5M = NULL;

	RenderWarhammer::DropDown5IsDefault = true;
	RenderWarhammer::DropDown5Hovering = false;
}

void RenderWarhammer::DrawDropDownBox6(SDL_Renderer* renderer, SDL_Rect DropDownBox6) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox6);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox6);

	TTF_Font* D6font = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D6font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop6 = TTF_RenderText_Blended(D6font, randomizer.Warhammerlist.Races[6].c_str(), Grey);
	SDL_Texture* Drop6M = SDL_CreateTextureFromSurface(renderer, Drop6);
	SDL_RenderCopy(renderer, Drop6M, NULL, &DropDownBox6);

	TTF_CloseFont(D6font);
	D6font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop6);
		SDL_DestroyTexture(Drop6M);
	}
	Drop6 = NULL;
	Drop6M = NULL;

	RenderWarhammer::DropDown6IsDefault = true;
	RenderWarhammer::DropDown6Hovering = false;
}

void RenderWarhammer::DrawDropDownBox7(SDL_Renderer* renderer, SDL_Rect DropDownBox7) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox7);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox7);

		TTF_Font* D7font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D7font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop7 = TTF_RenderText_Blended(D7font, randomizer.Warhammerlist.Races[7].c_str(), Grey);
		SDL_Texture* Drop7M = SDL_CreateTextureFromSurface(renderer, Drop7);
		SDL_RenderCopy(renderer, Drop7M, NULL, &DropDownBox7);

		TTF_CloseFont(D7font);
		D7font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop7);
			SDL_DestroyTexture(Drop7M);
		}
		Drop7 = NULL;
		Drop7M = NULL;

		RenderWarhammer::DropDown7IsDefault = true;
		RenderWarhammer::DropDown7Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox8(SDL_Renderer* renderer, SDL_Rect DropDownBox8) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox8);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox8);

		TTF_Font* D8font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D8font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop8 = TTF_RenderText_Blended(D8font, randomizer.Warhammerlist.Races[8].c_str(), Grey);
		SDL_Texture* Drop8M = SDL_CreateTextureFromSurface(renderer, Drop8);
		SDL_RenderCopy(renderer, Drop8M, NULL, &DropDownBox8);

		TTF_CloseFont(D8font);
		D8font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop8);
			SDL_DestroyTexture(Drop8M);
		}
		Drop8 = NULL;
		Drop8M = NULL;

		RenderWarhammer::DropDown8IsDefault = true;
		RenderWarhammer::DropDown8Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox9(SDL_Renderer* renderer, SDL_Rect DropDownBox9) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox9);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox9);

		TTF_Font* D9font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D9font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop9 = TTF_RenderText_Blended(D9font, randomizer.Warhammerlist.Races[9].c_str(), Grey);
		SDL_Texture* Drop9M = SDL_CreateTextureFromSurface(renderer, Drop9);
		SDL_RenderCopy(renderer, Drop9M, NULL, &DropDownBox9);

		TTF_CloseFont(D9font);
		D9font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop9);
			SDL_DestroyTexture(Drop9M);
		}
		Drop9 = NULL;
		Drop9M = NULL;

		RenderWarhammer::DropDown9IsDefault = true;
		RenderWarhammer::DropDown9Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox10(SDL_Renderer* renderer, SDL_Rect DropDownBox10) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox10);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox10);

		TTF_Font* D10font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D10font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop10 = TTF_RenderText_Blended(D10font, randomizer.Warhammerlist.Races[10].c_str(), Grey);
		SDL_Texture* Drop10M = SDL_CreateTextureFromSurface(renderer, Drop10);
		SDL_RenderCopy(renderer, Drop10M, NULL, &DropDownBox10);

		TTF_CloseFont(D10font);
		D10font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop10);
			SDL_DestroyTexture(Drop10M);
		}
		Drop10 = NULL;
		Drop10M = NULL;

		RenderWarhammer::DropDown10IsDefault = true;
		RenderWarhammer::DropDown10Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox11(SDL_Renderer* renderer, SDL_Rect DropDownBox11) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox11);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox11);

		TTF_Font* D11font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D11font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop11 = TTF_RenderText_Blended(D11font, randomizer.Warhammerlist.Races[11].c_str(), Grey);
		SDL_Texture* Drop11M = SDL_CreateTextureFromSurface(renderer, Drop11);
		SDL_RenderCopy(renderer, Drop11M, NULL, &DropDownBox11);

		TTF_CloseFont(D11font);
		D11font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop11);
			SDL_DestroyTexture(Drop11M);
		}
		Drop11 = NULL;
		Drop11M = NULL;

		RenderWarhammer::DropDown11IsDefault = true;
		RenderWarhammer::DropDown11Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox12(SDL_Renderer* renderer, SDL_Rect DropDownBox12) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox12);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox12);

		TTF_Font* D12font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D12font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop12 = TTF_RenderText_Blended(D12font, randomizer.Warhammerlist.Races[12].c_str(), Grey);
		SDL_Texture* Drop12M = SDL_CreateTextureFromSurface(renderer, Drop12);
		SDL_RenderCopy(renderer, Drop12M, NULL, &DropDownBox12);

		TTF_CloseFont(D12font);
		D12font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop12);
			SDL_DestroyTexture(Drop12M);
		}
		Drop12 = NULL;
		Drop12M = NULL;

		RenderWarhammer::DropDown12IsDefault = true;
		RenderWarhammer::DropDown12Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox13(SDL_Renderer* renderer, SDL_Rect DropDownBox13) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox13);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox13);

		TTF_Font* D13font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D13font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop13 = TTF_RenderText_Blended(D13font, randomizer.Warhammerlist.Races[13].c_str(), Grey);
		SDL_Texture* Drop13M = SDL_CreateTextureFromSurface(renderer, Drop13);
		SDL_RenderCopy(renderer, Drop13M, NULL, &DropDownBox13);

		TTF_CloseFont(D13font);
		D13font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop13);
			SDL_DestroyTexture(Drop13M);
		}
		Drop13 = NULL;
		Drop13M = NULL;

		RenderWarhammer::DropDown13IsDefault = true;
		RenderWarhammer::DropDown13Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox14(SDL_Renderer* renderer, SDL_Rect DropDownBox14) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox14);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox14);

		TTF_Font* D14font = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D14font) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop14 = TTF_RenderText_Blended(D14font, randomizer.Warhammerlist.Races[14].c_str(), Grey);
		SDL_Texture* Drop14M = SDL_CreateTextureFromSurface(renderer, Drop14);
		SDL_RenderCopy(renderer, Drop14M, NULL, &DropDownBox14);

		TTF_CloseFont(D14font);
		D14font = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop14);
			SDL_DestroyTexture(Drop14M);
		}
		Drop14 = NULL;
		Drop14M = NULL;

		RenderWarhammer::DropDown14IsDefault = true;
		RenderWarhammer::DropDown14Hovering = false;
	}
}

void RenderWarhammer::DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1);

	TTF_Font* D1Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D1Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1H = TTF_RenderText_Blended(D1Hfont, randomizer.Warhammerlist.Races[1].c_str(), LightGrey);
	SDL_Texture* Drop1HM = SDL_CreateTextureFromSurface(renderer, Drop1H);
	SDL_RenderCopy(renderer, Drop1HM, NULL, &DropDownBox1);

	TTF_CloseFont(D1Hfont);
	D1Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop1H);
		SDL_DestroyTexture(Drop1HM);
	}
	Drop1H = NULL;
	Drop1HM = NULL;

	RenderWarhammer::DropDown1IsDefault = false;
	RenderWarhammer::DropDown1Hovering = true;
}

void RenderWarhammer::DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2);

	TTF_Font* D2Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D2Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2H = TTF_RenderText_Blended(D2Hfont, randomizer.Warhammerlist.Races[2].c_str(), LightGrey);
	SDL_Texture* Drop2HM = SDL_CreateTextureFromSurface(renderer, Drop2H);
	SDL_RenderCopy(renderer, Drop2HM, NULL, &DropDownBox2);

	TTF_CloseFont(D2Hfont);
	D2Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop2H);
		SDL_DestroyTexture(Drop2HM);
	}
	Drop2H = NULL;
	Drop2HM = NULL;

	RenderWarhammer::DropDown2IsDefault = false;
	RenderWarhammer::DropDown2Hovering = true;
}

void RenderWarhammer::DrawDropDownBox3Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox3) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox3);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox3);

	TTF_Font* D3Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D3Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop3H = TTF_RenderText_Blended(D3Hfont, randomizer.Warhammerlist.Races[3].c_str(), LightGrey);
	SDL_Texture* Drop3HM = SDL_CreateTextureFromSurface(renderer, Drop3H);
	SDL_RenderCopy(renderer, Drop3HM, NULL, &DropDownBox3);

	TTF_CloseFont(D3Hfont);
	D3Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop3H);
		SDL_DestroyTexture(Drop3HM);
	}
	Drop3H = NULL;
	Drop3HM = NULL;

	RenderWarhammer::DropDown3IsDefault = false;
	RenderWarhammer::DropDown3Hovering = true;
}

void RenderWarhammer::DrawDropDownBox4Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox4) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox4);

	TTF_Font* D4Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D4Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop4H = TTF_RenderText_Blended(D4Hfont, randomizer.Warhammerlist.Races[4].c_str(), LightGrey);
	SDL_Texture* Drop4HM = SDL_CreateTextureFromSurface(renderer, Drop4H);
	SDL_RenderCopy(renderer, Drop4HM, NULL, &DropDownBox4);

	TTF_CloseFont(D4Hfont);
	D4Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop4H);
		SDL_DestroyTexture(Drop4HM);
	}
	Drop4H = NULL;
	Drop4HM = NULL;

	RenderWarhammer::DropDown4IsDefault = false;
	RenderWarhammer::DropDown4Hovering = true;
}

void RenderWarhammer::DrawDropDownBox5Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox5) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox5);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox5);

	TTF_Font* D5Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D5Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop5H = TTF_RenderText_Blended(D5Hfont, randomizer.Warhammerlist.Races[5].c_str(), LightGrey);
	SDL_Texture* Drop5HM = SDL_CreateTextureFromSurface(renderer, Drop5H);
	SDL_RenderCopy(renderer, Drop5HM, NULL, &DropDownBox5);

	TTF_CloseFont(D5Hfont);
	D5Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop5H);
		SDL_DestroyTexture(Drop5HM);
	}
	Drop5H = NULL;
	Drop5HM = NULL;

	RenderWarhammer::DropDown5IsDefault = false;
	RenderWarhammer::DropDown5Hovering = true;
}

void RenderWarhammer::DrawDropDownBox6Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox6) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &DropDownBox6);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox6);

	TTF_Font* D6Hfont = TTF_OpenFont("darkdominion.ttf", 35);
	if (!D6Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop6H = TTF_RenderText_Blended(D6Hfont, randomizer.Warhammerlist.Races[6].c_str(), LightGrey);
	SDL_Texture* Drop6HM = SDL_CreateTextureFromSurface(renderer, Drop6H);
	SDL_RenderCopy(renderer, Drop6HM, NULL, &DropDownBox6);

	TTF_CloseFont(D6Hfont);
	D6Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Drop6H);
		SDL_DestroyTexture(Drop6HM);
	}
	Drop6H = NULL;
	Drop6HM = NULL;

	RenderWarhammer::DropDown6IsDefault = false;
	RenderWarhammer::DropDown6Hovering = true;
}

void RenderWarhammer::DrawDropDownBox7Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox7) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox7);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox7);

		TTF_Font* D7Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D7Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop7H = TTF_RenderText_Blended(D7Hfont, randomizer.Warhammerlist.Races[7].c_str(), LightGrey);
		SDL_Texture* Drop7HM = SDL_CreateTextureFromSurface(renderer, Drop7H);
		SDL_RenderCopy(renderer, Drop7HM, NULL, &DropDownBox7);

		TTF_CloseFont(D7Hfont);
		D7Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop7H);
			SDL_DestroyTexture(Drop7HM);
		}
		Drop7H = NULL;
		Drop7HM = NULL;

		RenderWarhammer::DropDown7IsDefault = false;
		RenderWarhammer::DropDown7Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox8Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox8) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox8);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox8);

		TTF_Font* D8Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D8Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop8H = TTF_RenderText_Blended(D8Hfont, randomizer.Warhammerlist.Races[8].c_str(), LightGrey);
		SDL_Texture* Drop8HM = SDL_CreateTextureFromSurface(renderer, Drop8H);
		SDL_RenderCopy(renderer, Drop8HM, NULL, &DropDownBox8);

		TTF_CloseFont(D8Hfont);
		D8Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop8H);
			SDL_DestroyTexture(Drop8HM);
		}
		Drop8H = NULL;
		Drop8HM = NULL;

		RenderWarhammer::DropDown8IsDefault = false;
		RenderWarhammer::DropDown8Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox9Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox9) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox9);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox9);

		TTF_Font* D9Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D9Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop9H = TTF_RenderText_Blended(D9Hfont, randomizer.Warhammerlist.Races[9].c_str(), LightGrey);
		SDL_Texture* Drop9HM = SDL_CreateTextureFromSurface(renderer, Drop9H);
		SDL_RenderCopy(renderer, Drop9HM, NULL, &DropDownBox9);

		TTF_CloseFont(D9Hfont);
		D9Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop9H);
			SDL_DestroyTexture(Drop9HM);
		}
		Drop9H = NULL;
		Drop9HM = NULL;

		RenderWarhammer::DropDown9IsDefault = false;
		RenderWarhammer::DropDown9Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox10Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox10) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox10);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox10);

		TTF_Font* D10Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D10Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop10H = TTF_RenderText_Blended(D10Hfont, randomizer.Warhammerlist.Races[10].c_str(), LightGrey);
		SDL_Texture* Drop10HM = SDL_CreateTextureFromSurface(renderer, Drop10H);
		SDL_RenderCopy(renderer, Drop10HM, NULL, &DropDownBox10);

		TTF_CloseFont(D10Hfont);
		D10Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop10H);
			SDL_DestroyTexture(Drop10HM);
		}
		Drop10H = NULL;
		Drop10HM = NULL;

		RenderWarhammer::DropDown10IsDefault = false;
		RenderWarhammer::DropDown10Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox11Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox11) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox11);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox11);

		TTF_Font* D11Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D11Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop11H = TTF_RenderText_Blended(D11Hfont, randomizer.Warhammerlist.Races[11].c_str(), LightGrey);
		SDL_Texture* Drop11HM = SDL_CreateTextureFromSurface(renderer, Drop11H);
		SDL_RenderCopy(renderer, Drop11HM, NULL, &DropDownBox11);

		TTF_CloseFont(D11Hfont);
		D11Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop11H);
			SDL_DestroyTexture(Drop11HM);
		}
		Drop11H = NULL;
		Drop11HM = NULL;

		RenderWarhammer::DropDown11IsDefault = false;
		RenderWarhammer::DropDown11Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox12Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox12) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox12);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox12);

		TTF_Font* D12Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D12Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop12H = TTF_RenderText_Blended(D12Hfont, randomizer.Warhammerlist.Races[12].c_str(), LightGrey);
		SDL_Texture* Drop12HM = SDL_CreateTextureFromSurface(renderer, Drop12H);
		SDL_RenderCopy(renderer, Drop12HM, NULL, &DropDownBox12);

		TTF_CloseFont(D12Hfont);
		D12Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop12H);
			SDL_DestroyTexture(Drop12HM);
		}
		Drop12H = NULL;
		Drop12HM = NULL;

		RenderWarhammer::DropDown12IsDefault = false;
		RenderWarhammer::DropDown12Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox13Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox13) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox13);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox13);

		TTF_Font* D13Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D13Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop13H = TTF_RenderText_Blended(D13Hfont, randomizer.Warhammerlist.Races[13].c_str(), LightGrey);
		SDL_Texture* Drop13HM = SDL_CreateTextureFromSurface(renderer, Drop13H);
		SDL_RenderCopy(renderer, Drop13HM, NULL, &DropDownBox13);

		TTF_CloseFont(D13Hfont);
		D13Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop13H);
			SDL_DestroyTexture(Drop13HM);
		}
		Drop13H = NULL;
		Drop13HM = NULL;

		RenderWarhammer::DropDown13IsDefault = false;
		RenderWarhammer::DropDown13Hovering = true;
	}
}

void RenderWarhammer::DrawDropDownBox14Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox14) {
	if (randomizer.Warhammerlist.Races.size() >= 8) {
		SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
		SDL_RenderFillRect(renderer, &DropDownBox14);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &DropDownBox14);

		TTF_Font* D14Hfont = TTF_OpenFont("darkdominion.ttf", 35);
		if (!D14Hfont) {
			std::cout << "Error: " << TTF_GetError() << std::endl;
			SDL_Quit();
			TTF_Quit();
		}
		SDL_Surface* Drop14H = TTF_RenderText_Blended(D14Hfont, randomizer.Warhammerlist.Races[14].c_str(), LightGrey);
		SDL_Texture* Drop14HM = SDL_CreateTextureFromSurface(renderer, Drop14H);
		SDL_RenderCopy(renderer, Drop14HM, NULL, &DropDownBox14);

		TTF_CloseFont(D14Hfont);
		D14Hfont = NULL;
		if (RenderingWarhammer == false) {
			SDL_FreeSurface(Drop14H);
			SDL_DestroyTexture(Drop14HM);
		}
		Drop14H = NULL;
		Drop14HM = NULL;

		RenderWarhammer::DropDown14IsDefault = false;
		RenderWarhammer::DropDown14Hovering = true;
	}
}

void RenderWarhammer::CheckMousePositionDropDown1(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[1], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown1 == true && DropDown1Hovering == false) DrawDropDownBox1Hover(renderer, DropDownBox1);

		else if (insideDropDown1 == false && DropDown1IsDefault == false) {
			DrawDropDownBox1(renderer, DropDownBox1);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown2(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[2], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown2 == true && DropDown2Hovering == false) DrawDropDownBox2Hover(renderer, DropDownBox2);

		else if (insideDropDown2 == false && DropDown2IsDefault == false) {
			DrawDropDownBox2(renderer, DropDownBox2);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown3(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[3], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown3 == true && DropDown3Hovering == false) DrawDropDownBox3Hover(renderer, DropDownBox3);

		else if (insideDropDown3 == false && DropDown3IsDefault == false) {
			DrawDropDownBox3(renderer, DropDownBox3);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown4(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[4], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown4 == true && DropDown4Hovering == false) DrawDropDownBox4Hover(renderer, DropDownBox4);

		else if (insideDropDown4 == false && DropDown4IsDefault == false) {
			DrawDropDownBox4(renderer, DropDownBox4);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown5(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[5], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown5 == true && DropDown5Hovering == false) DrawDropDownBox5Hover(renderer, DropDownBox5);

		else if (insideDropDown5 == false && DropDown5IsDefault == false) {
			DrawDropDownBox5(renderer, DropDownBox5);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown6(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[6], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown6 == true && DropDown6Hovering == false) DrawDropDownBox6Hover(renderer, DropDownBox6);

		else if (insideDropDown6 == false && DropDown6IsDefault == false) {
			DrawDropDownBox6(renderer, DropDownBox6);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown7(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[7], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown7 == true && DropDown7Hovering == false) DrawDropDownBox7Hover(renderer, DropDownBox7);

		else if (insideDropDown7 == false && DropDown7IsDefault == false) {
			DrawDropDownBox7(renderer, DropDownBox7);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown8(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[8], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown8 == true && DropDown8Hovering == false) DrawDropDownBox8Hover(renderer, DropDownBox8);

		else if (insideDropDown8 == false && DropDown8IsDefault == false) {
			DrawDropDownBox8(renderer, DropDownBox8);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown9(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[9], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown9 == true && DropDown9Hovering == false) DrawDropDownBox9Hover(renderer, DropDownBox9);

		else if (insideDropDown9 == false && DropDown9IsDefault == false) {
			DrawDropDownBox9(renderer, DropDownBox9);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown10(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[10], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown10 == true && DropDown10Hovering == false) DrawDropDownBox10Hover(renderer, DropDownBox10);

		else if (insideDropDown10 == false && DropDown10IsDefault == false) {
			DrawDropDownBox10(renderer, DropDownBox10);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown11(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[11], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown11 == true && DropDown11Hovering == false) DrawDropDownBox11Hover(renderer, DropDownBox11);

		else if (insideDropDown11 == false && DropDown11IsDefault == false) {
			DrawDropDownBox11(renderer, DropDownBox11);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown12(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[12], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown12 == true && DropDown12Hovering == false) DrawDropDownBox12Hover(renderer, DropDownBox12);

		else if (insideDropDown12 == false && DropDown12IsDefault == false) {
			DrawDropDownBox12(renderer, DropDownBox12);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown13(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[13], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown13 == true && DropDown13Hovering == false) DrawDropDownBox13Hover(renderer, DropDownBox13);

		else if (insideDropDown13 == false && DropDown13IsDefault == false) {
			DrawDropDownBox13(renderer, DropDownBox13);
		};
	}
}

void RenderWarhammer::CheckMousePositionDropDown14(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.Warhammerlist.Races[14], randomizer.Warhammerlist.Races[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawButton(renderer, Button1, Button1Message);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
		DrawVortexButton(renderer, Vortex, VortexMessage);
		DrawMortalButton(renderer, Mortal, MortalMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
		DrawRomeButton(renderer, RomeButton, RomeMessage);
		StartDropDown = false;
	}

	if (StartDropDown == true) {
		if (insideDropDown14 == true && DropDown14Hovering == false) DrawDropDownBox14Hover(renderer, DropDownBox14);

		else if (insideDropDown14 == false && DropDown14IsDefault == false) {
			DrawDropDownBox14(renderer, DropDownBox14);
		};
	}
}

void RenderWarhammer::ReplaceRightSide(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 135, 10, 1, 255);
	SDL_Rect ReplaceRightSideRect{ 1000,0,920,1080 };
	SDL_RenderFillRect(renderer, &ReplaceRightSideRect);
}

void RenderWarhammer::DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButton);

	TTF_Font* Submitfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Submitfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Submit = TTF_RenderText_Blended(Submitfont, "Submit", Grey);
	SDL_Texture* SubmitM = SDL_CreateTextureFromSurface(renderer, Submit);
	SDL_RenderCopy(renderer, SubmitM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(Submitfont);
	Submitfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(Submit);
		SDL_DestroyTexture(SubmitM);
	}
	Submit = NULL;
	SubmitM = NULL;

	RenderWarhammer::SubmitIsDefault = true;
	RenderWarhammer::SubmitHovering = false;
	RenderWarhammer::SubmitClicked = false;
}

void RenderWarhammer::DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButton);

	TTF_Font* SubmitHfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!SubmitHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* SubmitHover = TTF_RenderText_Blended(SubmitHfont, "Submit", LightGrey);
	SDL_Texture* SubmitHoverM = SDL_CreateTextureFromSurface(renderer, SubmitHover);
	SDL_RenderCopy(renderer, SubmitHoverM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(SubmitHfont);
	SubmitHfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(SubmitHover);
		SDL_DestroyTexture(SubmitHoverM);
	}
	SubmitHover = NULL;
	SubmitHoverM = NULL;

	RenderWarhammer::SubmitIsDefault = false;
	RenderWarhammer::SubmitHovering = true;
	RenderWarhammer::SubmitClicked = false;
}

void RenderWarhammer::CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
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
		if (SubmitHovering == true) {
			std::string result = "";
			std::string FilePath = "";
			if (randomizer.Warhammerlist.Races[0] == "The Empire" && VortexSelected == true) {
				result = "Markus Wulfhart";
				FilePath = randomizer.GetPictureFilepath("The Empire", result, randomizer.Warhammerlist.WarhammerFilePaths);
			}
			else result = randomizer.RandomBySelectedCampaign(randomizer.Warhammerlist.TotalFactions, randomizer.Warhammerlist.Races[0]);
			FilePath = randomizer.GetPictureFilepath(result, randomizer.Warhammerlist.WarhammerFilePaths);
			ReplaceInnerWindow(renderer);
			ReplaceRightSide(renderer);
			DrawButton(renderer, Button1, Button1Message);
			DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
			DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
			DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
			DrawVortexButton(renderer, Vortex, VortexMessage);
			DrawMortalButton(renderer, Mortal, MortalMessage);
			DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
			DrawShogunButton(renderer, ShogunButton, ShogunMessage);
			DrawRomeButton(renderer, RomeButton, RomeMessage);
			PullImage(renderer, window, FilePath);
			DrawLordResult(renderer, result);
			StartDropDown = false;
		}
	};

	if (event.type == SDL_MOUSEBUTTONUP && SubmitClicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		SubmitClicked = false;
		StartDropDown = false;
	}

	if (insideSubmit == true && SubmitHovering == false && SubmitClicked == false) DrawSubmitButtonHover(renderer, SubmitButton, SubmitButtonMessage);

	else if (insideSubmit == false && SubmitIsDefault == false) {
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
	};
}

void RenderWarhammer::DrawRandomByRace(SDL_Renderer* renderer, SDL_Rect RandomByRace, SDL_Rect RandomByRaceMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &RandomByRace);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &RandomByRace);

	TTF_Font* RBRfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!RBRfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* RandByRace = TTF_RenderText_Blended(RBRfont, "Random By Race", Grey);
	SDL_Texture* RandByRaceM = SDL_CreateTextureFromSurface(renderer, RandByRace);
	SDL_RenderCopy(renderer, RandByRaceM, NULL, &RandomByRaceMessage);

	TTF_CloseFont(RBRfont);
	RBRfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(RandByRace);
		SDL_DestroyTexture(RandByRaceM);
	}
	RandByRace = NULL;
	RandByRaceM = NULL;
}

void RenderWarhammer::PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester) {
	SDL_Surface* testScreen = NULL;
	testScreen = SDL_GetWindowSurface(window);
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedImage = IMG_Load(tester.c_str());
	if (loadedImage == NULL) {
		printf("Unable to load image %s! SDL_Image Error: %s \n", tester.c_str(), IMG_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedImage, testScreen->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", tester.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedImage);
	}

	SDL_Rect image{ 6,0,994,749 };
	SDL_Texture* TTest = SDL_CreateTextureFromSurface(renderer, optimizedSurface);
	SDL_RenderCopy(renderer, TTest, NULL, &image);

	SDL_FreeSurface(testScreen);
	SDL_FreeSurface(optimizedSurface);
	SDL_DestroyTexture(TTest);
	testScreen = NULL;
	optimizedSurface = NULL;
	loadedImage = NULL;
	TTest = NULL;
}

void RenderWarhammer::DrawVortexButton(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Vortex);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Vortex);

	TTF_Font* Vfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Vfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* VortexS = TTF_RenderText_Blended(Vfont, "Vortex", Grey);
	SDL_Texture* VortexM = SDL_CreateTextureFromSurface(renderer, VortexS);
	SDL_RenderCopy(renderer, VortexM, NULL, &VortexMessage);

	TTF_CloseFont(Vfont);
	Vfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(VortexS);
		SDL_DestroyTexture(VortexM);
	}
	VortexS = NULL;
	VortexM = NULL;

	RenderWarhammer::VortexIsDefault = true;
	RenderWarhammer::VortexHovering = false;
	RenderWarhammer::VortexClicked = false;
}

void RenderWarhammer::DrawVortexButtonHover(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Vortex);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Vortex);

	TTF_Font* VHfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!VHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* VortexHS = TTF_RenderText_Blended(VHfont, "Vortex", LightGrey);
	SDL_Texture* VortexHM = SDL_CreateTextureFromSurface(renderer, VortexHS);
	SDL_RenderCopy(renderer, VortexHM, NULL, &VortexMessage);

	TTF_CloseFont(VHfont);
	VHfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(VortexHS);
		SDL_DestroyTexture(VortexHM);
	}
	VortexHS = NULL;
	VortexHM = NULL;

	RenderWarhammer::VortexIsDefault = false;
	RenderWarhammer::VortexHovering = true;
	RenderWarhammer::VortexClicked = false;
}

void RenderWarhammer::DrawVortexButtonClicked(SDL_Renderer* renderer, SDL_Rect Vortex, SDL_Rect VortexMessage) {
	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Vortex);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Vortex);

	TTF_Font* VCfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!VCfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* VortexCS = TTF_RenderText_Blended(VCfont, "Vortex", DarkGrey);
	SDL_Texture* VortexCM = SDL_CreateTextureFromSurface(renderer, VortexCS);
	SDL_RenderCopy(renderer, VortexCM, NULL, &VortexMessage);

	TTF_CloseFont(VCfont);
	VCfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(VortexCS);
		SDL_DestroyTexture(VortexCM);
	}
	VortexCS = NULL;
	VortexCM = NULL;

	RenderWarhammer::VortexIsDefault = false;
	RenderWarhammer::VortexHovering = false;
	RenderWarhammer::VortexClicked = true;
}

void RenderWarhammer::CheckMousePositionVortex(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideVortex = true;

	//Check if mouse is left of the button
	if (x < VortexLeftposition.x) insideVortex = false;
	//Check if mouse is right of the button
	if (x > VortexRightposition.x) insideVortex = false;
	//Check if mouse is above the button
	if (y < VortexTopposition.y) insideVortex = false;
	//Check if mouse is below the button
	if (y > VortexBottomposition.y) insideVortex = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideVortex == true && VortexSelected == false) {
		if (VortexHovering == true) {
			DrawVortexButtonClicked(renderer, Vortex, VortexMessage);
			randomizer.ExcludeRandAll(randomizer.Warhammerlist.LordList, randomizer.Warhammerlist.ExcludeList);
			randomizer.ExcludeRandByRace(randomizer.Warhammerlist.Races, randomizer.Warhammerlist.ExcludeListRaces);
			ReplaceInnerWindow(renderer);
			ReplaceRightSide(renderer);
			DrawButton(renderer, Button1, Button1Message);
			DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
			DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
			DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
			DrawVortexButton(renderer, Vortex, VortexMessage);
			DrawMortalButton(renderer, Mortal, MortalMessage);
			DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
			DrawShogunButton(renderer, ShogunButton, ShogunMessage);
			DrawRomeButton(renderer, RomeButton, RomeMessage);
			VortexSelected = true;
			MortalSelected = false;
			StartDropDown = false;
		}
	};

	if (event.type == SDL_MOUSEBUTTONUP && VortexClicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		VortexClicked = false;
		StartDropDown = false;
	}

	if (insideVortex == true && VortexHovering == false && VortexClicked == false) DrawVortexButtonHover(renderer, Vortex, VortexMessage);

	else if (insideVortex == false && VortexIsDefault == false) {
		DrawVortexButton(renderer, Vortex, VortexMessage);
	};
}

void RenderWarhammer::DrawMortalButton(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Mortal);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Mortal);

	TTF_Font* Mfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!Mfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* MortalS = TTF_RenderText_Blended(Mfont, "Mortal Empires", Grey);
	SDL_Texture* MortalM = SDL_CreateTextureFromSurface(renderer, MortalS);
	SDL_RenderCopy(renderer, MortalM, NULL, &MortalMessage);

	TTF_CloseFont(Mfont);
	Mfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(MortalS);
		SDL_DestroyTexture(MortalM);
	}
	MortalS = NULL;
	MortalM = NULL;

	RenderWarhammer::MortalIsDefault = true;
	RenderWarhammer::MortalHovering = false;
	RenderWarhammer::MortalClicked = false;
}

void RenderWarhammer::DrawMortalButtonHover(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Mortal);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Mortal);

	TTF_Font* MHfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!MHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* MortalHS = TTF_RenderText_Blended(MHfont, "Mortal Empires", LightGrey);
	SDL_Texture* MortalHM = SDL_CreateTextureFromSurface(renderer, MortalHS);
	SDL_RenderCopy(renderer, MortalHM, NULL, &MortalMessage);

	TTF_CloseFont(MHfont);
	MHfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(MortalHS);
		SDL_DestroyTexture(MortalHM);
	}
	MortalHS = NULL;
	MortalHM = NULL;

	RenderWarhammer::MortalIsDefault = false;
	RenderWarhammer::MortalHovering = true;
	RenderWarhammer::MortalClicked = false;
}

void RenderWarhammer::DrawMortalButtonClicked(SDL_Renderer* renderer, SDL_Rect Mortal, SDL_Rect MortalMessage) {
	SDL_SetRenderDrawColor(renderer, 223, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Mortal);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Mortal);

	TTF_Font* MCfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!MCfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* MortalCS = TTF_RenderText_Blended(MCfont, "Mortal Empires", DarkGrey);
	SDL_Texture* MortalCM = SDL_CreateTextureFromSurface(renderer, MortalCS);
	SDL_RenderCopy(renderer, MortalCM, NULL, &MortalMessage);

	TTF_CloseFont(MCfont);
	MCfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(MortalCS);
		SDL_DestroyTexture(MortalCM);
	}
	MortalCS = NULL;
	MortalCM = NULL;

	RenderWarhammer::MortalIsDefault = false;
	RenderWarhammer::MortalHovering = false;
	RenderWarhammer::MortalClicked = true;
}

void RenderWarhammer::CheckMousePositionMortal(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideMortal = true;

	//Check if mouse is left of the button
	if (x < MortalLeftposition.x) insideMortal = false;
	//Check if mouse is right of the button
	if (x > MortalRightposition.x) insideMortal = false;
	//Check if mouse is above the button
	if (y < MortalTopposition.y) insideMortal = false;
	//Check if mouse is below the button
	if (y > MortalBottomposition.y) insideMortal = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideMortal == true && MortalSelected == false) {
		if (MortalHovering == true) {
			DrawMortalButtonClicked(renderer, Mortal, MortalMessage);
			randomizer.Reinclude(randomizer.Warhammerlist.ExcludeList, randomizer.Warhammerlist.LordList);
			randomizer.Reinclude(randomizer.Warhammerlist.ExcludeListRaces, randomizer.Warhammerlist.Races);
			ReplaceInnerWindow(renderer);
			ReplaceRightSide(renderer);
			DrawButton(renderer, Button1, Button1Message);
			DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
			DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
			DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
			DrawVortexButton(renderer, Vortex, VortexMessage);
			DrawMortalButton(renderer, Mortal, MortalMessage);
			DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
			DrawShogunButton(renderer, ShogunButton, ShogunMessage);
			DrawRomeButton(renderer, RomeButton, RomeMessage);
			VortexSelected = false;
			MortalSelected = true;
			StartDropDown = false;
		}
	};

	if (event.type == SDL_MOUSEBUTTONUP && MortalClicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		MortalClicked = false;
		StartDropDown = false;
	}

	if (insideMortal == true && MortalHovering == false && MortalClicked == false) DrawMortalButtonHover(renderer, Mortal, MortalMessage);

	else if (insideMortal == false && MortalIsDefault == false) {
		DrawMortalButton(renderer, Mortal, MortalMessage);
	};
}

void RenderWarhammer::DrawWarhammer(SDL_Renderer* renderer) {
	DrawScreen(renderer);
	DrawButton(renderer, Button1, Button1Message);
	DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
	DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
	DrawVortexButton(renderer, Vortex, VortexMessage);
	DrawMortalButton(renderer, Mortal, MortalMessage);
	DrawRandomByRace(renderer, RandomByRace, RandomByRaceMessage);
	DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
	DrawShogunButton(renderer, ShogunButton, ShogunMessage);
	DrawRomeButton(renderer, RomeButton, RomeMessage);
}

void RenderWarhammer::CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
		CheckMousePositionButton1(event, renderer, window);
		CheckMousePositionButton2(event, renderer);
		CheckMousePositionDropDown1(event, renderer);
		CheckMousePositionDropDown2(event, renderer);
		CheckMousePositionDropDown3(event, renderer);
		CheckMousePositionDropDown4(event, renderer);
		CheckMousePositionDropDown5(event, renderer);
		CheckMousePositionDropDown6(event, renderer);
		CheckMousePositionDropDown7(event, renderer);
		CheckMousePositionDropDown8(event, renderer);
		CheckMousePositionDropDown9(event, renderer);
		CheckMousePositionDropDown10(event, renderer);
		CheckMousePositionDropDown11(event, renderer);
		CheckMousePositionDropDown12(event, renderer);
		CheckMousePositionDropDown13(event, renderer);
		CheckMousePositionDropDown14(event, renderer);
		CheckMousePositionSubmitButton(event, renderer, window);
		CheckMousePositionVortex(event, renderer);
		CheckMousePositionMortal(event, renderer);
		CheckMousePositionMedieval(event, renderer);
		CheckMousePositionShogun(event, renderer);
		CheckMousePositionRome(event, renderer);
}

void RenderWarhammer::DrawMedievalButton(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
	SDL_SetRenderDrawColor(renderer, 10, 79, 191, 255);
	SDL_RenderFillRect(renderer, &Medieval);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Medieval);

	TTF_Font* M2font = TTF_OpenFont("Old English Five.ttf", 43);
	if (!M2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* MedievalS = TTF_RenderText_Blended(M2font, "Medieval II", Grey);
	SDL_Texture* MedievalM = SDL_CreateTextureFromSurface(renderer, MedievalS);
	SDL_RenderCopy(renderer, MedievalM, NULL, &MedievalMessage);

	TTF_CloseFont(M2font);
	M2font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(MedievalS);
		SDL_DestroyTexture(MedievalM);
	}
	MedievalS = NULL;
	MedievalM = NULL;

	RenderWarhammer::MedievalIsDefault = true;
	RenderWarhammer::MedievalHovering = false;
}

void RenderWarhammer::DrawMedievalButtonHover(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
	SDL_SetRenderDrawColor(renderer, 10, 79, 222, 255);
	SDL_RenderFillRect(renderer, &Medieval);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Medieval);

	TTF_Font* M2Hfont = TTF_OpenFont("Old English Five.ttf", 43);
	if (!M2Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* MedievalHS = TTF_RenderText_Blended(M2Hfont, "Medieval II", LightGrey);
	SDL_Texture* MedievalHM = SDL_CreateTextureFromSurface(renderer, MedievalHS);
	SDL_RenderCopy(renderer, MedievalHM, NULL, &MedievalMessage);

	TTF_CloseFont(M2Hfont);
	M2Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(MedievalHS);
		SDL_DestroyTexture(MedievalHM);
	}
	MedievalHS = NULL;
	MedievalHM = NULL;

	RenderWarhammer::MedievalIsDefault = false;
	RenderWarhammer::MedievalHovering = true;
}

void RenderWarhammer::CheckMousePositionMedieval(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideMedieval = true;

	//Check if mouse is left of the button
	if (x < MedievalLeftposition.x) insideMedieval = false;
	//Check if mouse is right of the button
	if (x > MedievalRightposition.x) insideMedieval = false;
	//Check if mouse is above the button
	if (y < MedievalTopposition.y) insideMedieval = false;
	//Check if mouse is below the button
	if (y > MedievalBottomposition.y) insideMedieval = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideMedieval == true) {
		if (MedievalHovering == true && RenderingWarhammer == true) {
			SDL_RenderClear(renderer);
			RenderingWarhammer = false;
			MedievalSelected = true;
		}
	};

	if (insideMedieval == true && MedievalHovering == false) DrawMedievalButtonHover(renderer, MedievalButton, MedievalMessage);

	else if (insideMedieval == false && MedievalIsDefault == false) {
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
	};
}

void RenderWarhammer::CheckMousePositionShogun(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideShogun = true;

	//Check if mouse is left of the button
	if (x < ShogunLeftPosition.x) insideShogun = false;
	//Check if mouse is right of the button
	if (x > ShogunRightPosition.x) insideShogun = false;
	//Check if mouse is above the button
	if (y < ShogunTopPosition.y) insideShogun = false;
	//Check if mouse is below the button
	if (y > ShogunBottomPosition.y) insideShogun = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideShogun == true) {
		if (ShogunHovering == true && RenderingWarhammer == true) {
			SDL_RenderClear(renderer);
			RenderingWarhammer = false;
			ShogunSelected = true;
		}
	};

	if (insideShogun == true && ShogunHovering == false) DrawShogunButtonHover(renderer, ShogunButton, ShogunMessage);

	else if (insideShogun == false && ShogunIsDefault == false) {
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
	};
}

void RenderWarhammer::DrawShogunButton(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &ShogunButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &ShogunButton);

	TTF_Font* J2font = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!J2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* ShogunS = TTF_RenderText_Blended(J2font, "Shogun II", Red);
	SDL_Texture* ShogunM = SDL_CreateTextureFromSurface(renderer, ShogunS);
	SDL_RenderCopy(renderer, ShogunM, NULL, &ShogunMessage);

	TTF_CloseFont(J2font);
	J2font = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(ShogunS);
		SDL_DestroyTexture(ShogunM);
	}
	ShogunS = NULL;
	ShogunM = NULL;

	RenderWarhammer::ShogunIsDefault = true;
	RenderWarhammer::ShogunHovering = false;
}

void RenderWarhammer::DrawShogunButtonHover(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage) {
	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &ShogunButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &ShogunButton);

	TTF_Font* J2Hfont = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!J2Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* ShogunHS = TTF_RenderText_Blended(J2Hfont, "Shogun II", DarkRed);
	SDL_Texture* ShogunHM = SDL_CreateTextureFromSurface(renderer, ShogunHS);
	SDL_RenderCopy(renderer, ShogunHM, NULL, &ShogunMessage);

	TTF_CloseFont(J2Hfont);
	J2Hfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(ShogunHS);
		SDL_DestroyTexture(ShogunHM);
	}
	ShogunHS = NULL;
	ShogunHM = NULL;

	RenderWarhammer::ShogunIsDefault = false;
	RenderWarhammer::ShogunHovering = true;
}

void RenderWarhammer::DrawRomeButton(SDL_Renderer* renderer, SDL_Rect Rome, SDL_Rect RomeMessage) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 158, 255);
	SDL_RenderFillRect(renderer, &Rome);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Rome);

	TTF_Font* Romefont = TTF_OpenFont("Praetoria D.otf", 43);
	if (!Romefont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* RomeS = TTF_RenderText_Blended(Romefont, "Rome", Gold);
	SDL_Texture* RomeM = SDL_CreateTextureFromSurface(renderer, RomeS);
	SDL_RenderCopy(renderer, RomeM, NULL, &RomeMessage);

	TTF_CloseFont(Romefont);
	Romefont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(RomeS);
		SDL_DestroyTexture(RomeM);
	}
	RomeS = NULL;
	RomeM = NULL;

	RenderWarhammer::RomeIsDefault = true;
	RenderWarhammer::RomeHovering = false;
}

void RenderWarhammer::DrawRomeButtonHover(SDL_Renderer* renderer, SDL_Rect Rome, SDL_Rect RomeMessage) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 178, 255);
	SDL_RenderFillRect(renderer, &Rome);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Rome);

	TTF_Font* RomeHfont = TTF_OpenFont("Praetoria D.otf", 43);
	if (!RomeHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* RomeHS = TTF_RenderText_Blended(RomeHfont, "Rome", Gold);
	SDL_Texture* RomeHM = SDL_CreateTextureFromSurface(renderer, RomeHS);
	SDL_RenderCopy(renderer, RomeHM, NULL, &RomeMessage);

	TTF_CloseFont(RomeHfont);
	RomeHfont = NULL;
	if (RenderingWarhammer == false) {
		SDL_FreeSurface(RomeHS);
		SDL_DestroyTexture(RomeHM);
	}
	RomeHS = NULL;
	RomeHM = NULL;

	RenderWarhammer::RomeIsDefault = false;
	RenderWarhammer::RomeHovering = true;
}

void RenderWarhammer::CheckMousePositionRome(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideRome = true;

	//Check if mouse is left of the button
	if (x < RomeLeftposition.x) insideRome = false;
	//Check if mouse is right of the button
	if (x > RomeRightposition.x) insideRome = false;
	//Check if mouse is above the button
	if (y < RomeTopposition.y) insideRome = false;
	//Check if mouse is below the button
	if (y > RomeBottomposition.y) insideRome = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideRome == true) {
		if (RomeHovering == true && RenderingWarhammer == true) {
			SDL_RenderClear(renderer);
			RenderingWarhammer = false;
			RomeSelected = true;
		}
	};

	if (insideRome == true && RomeHovering == false) DrawRomeButtonHover(renderer, RomeButton, RomeMessage);

	else if (insideRome == false && RomeIsDefault == false) {
		DrawRomeButton(renderer, RomeButton, RomeMessage);
	};
}