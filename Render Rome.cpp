#include "Render Rome.h"

void RenderRome::DrawScreen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 138, 255);
	SDL_Rect RSide{ 1000,0,925,1080 };
	SDL_RenderFillRect(renderer, &RSide);

	SDL_Rect LSide{ 0,0,5,1080 };
	SDL_RenderFillRect(renderer, &LSide);

	SDL_Rect Bottom{ 0,750,1000,480 };
	SDL_RenderFillRect(renderer, &Bottom);

	SDL_SetRenderDrawColor(renderer, 76,1,108, 255);
	SDL_Rect WBorder{ 0,0,1920,1080 };
	SDL_RenderDrawRect(renderer, &WBorder);

	SDL_Rect SWBorder{ 5,0,995,750 };
	SDL_RenderDrawRect(renderer, &SWBorder);
}

void RenderRome::DrawRome(SDL_Renderer* renderer) {
	DrawScreen(renderer);
	DrawPickAll(renderer, PickAll, PickAllMessage);
	DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
	DrawShogunButton(renderer, ShogunButton, ShogunMessage);
	DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
}

void RenderRome::DrawPickAll(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 158, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllFont = TTF_OpenFont("Praetoria D.otf", 43);
	if (!PAllFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAll = TTF_RenderText_Blended(PAllFont, "Random All", Gold);
	SDL_Texture* PAllM = SDL_CreateTextureFromSurface(renderer, PAll);
	SDL_RenderCopy(renderer, PAllM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllFont);
	PAllFont = NULL;
	if (RenderingRome == false) {
		SDL_FreeSurface(PAll);
		SDL_DestroyTexture(PAllM);
		PAll = NULL;
		PAllM = NULL;
	}

	RenderRome::PickAllIsDefault = true;
	RenderRome::PickAllHovering = false;
	RenderRome::PickAllClicked = false;
}

void RenderRome::DrawPickAllHover(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 178, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllHFont = TTF_OpenFont("Praetoria D.otf", 43);
	if (!PAllHFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAllH = TTF_RenderText_Blended(PAllHFont, "Random All", Gold);
	SDL_Texture* PAllHM = SDL_CreateTextureFromSurface(renderer, PAllH);
	SDL_RenderCopy(renderer, PAllHM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllHFont);
	PAllHFont = NULL;
	if (RenderingRome == false) {
		SDL_FreeSurface(PAllH);
		SDL_DestroyTexture(PAllHM);
		PAllH = NULL;
		PAllHM = NULL;
	}

	RenderRome::PickAllIsDefault = false;
	RenderRome::PickAllHovering = true;
	RenderRome::PickAllClicked = false;
}

void RenderRome::DrawPickAllClicked(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 76, 1, 158, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllCFont = TTF_OpenFont("Praetoria D.otf", 43);
	if (!PAllCFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAllC = TTF_RenderText_Blended(PAllCFont, "Random All", Gold);
	SDL_Texture* PAllCM = SDL_CreateTextureFromSurface(renderer, PAllC);
	SDL_RenderCopy(renderer, PAllCM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllCFont);
	PAllCFont = NULL;
	if (RenderingRome == false) {
		SDL_FreeSurface(PAllC);
		SDL_DestroyTexture(PAllCM);
		PAllC = NULL;
		PAllCM = NULL;
	}

	RenderRome::PickAllIsDefault = false;
	RenderRome::PickAllHovering = false;
	RenderRome::PickAllClicked = true;
}

void RenderRome::ReplaceInnerWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect ReplaceInnerWindow{ 5,0,995,750 };
	SDL_RenderFillRect(renderer, &ReplaceInnerWindow);
}

void RenderRome::DrawFactionResultSingle(SDL_Renderer* renderer, std::string FactionResult) {
	TTF_Font* FactionCampaignFont = TTF_OpenFont("Praetoria D.otf",41);
	if (!FactionCampaignFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	int w, h;
	if (TTF_SizeText(FactionCampaignFont, FactionResult.c_str(), &w, &h)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_Rect FactionResultRect{ 125,40,w,h };
	SDL_Surface* CampaignR = TTF_RenderText_Blended(FactionCampaignFont, FactionResult.c_str(), Gold);
	SDL_Texture* CampaignRM = SDL_CreateTextureFromSurface(renderer, CampaignR);
	SDL_RenderCopy(renderer, CampaignRM, NULL, &FactionResultRect);

	TTF_CloseFont(FactionCampaignFont);
	SDL_FreeSurface(CampaignR);
	SDL_DestroyTexture(CampaignRM);
	FactionCampaignFont = NULL;
	CampaignR = NULL;
	CampaignRM = NULL;
}

void RenderRome::CheckMousePositionPickAll(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
	RenderRome::RenderingRome = true;
	int x, y;
	SDL_GetMouseState(&x, &y);
	insidePickAll = true;

	//Check if mouse is left of the button
	if (x < PickAllLeftPosition.x) insidePickAll = false;
	//Check if mouse is right of the button
	if (x > PickAllRightPosition.x) insidePickAll = false;
	//Check if mouse is above the button
	if (y < PickAllTopPosition.y) insidePickAll = false;
	//Check if mouse is below the button
	if (y > PickAllBottomPosition.y) insidePickAll = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insidePickAll == true) {
		if (PickAllHovering == true) {
			DrawPickAllClicked(renderer, PickAll, PickAllMessage);
			std::vector<std::string> Result = randomizer.RandomAll(randomizer.RomeList.RomeTotalList);
			std::string FilePath = randomizer.GetPictureFilepath(Result[0], Result[1], randomizer.RomeList.RomeFilePaths);
			ReplaceInnerWindow(renderer);
			PullImage(renderer, window, FilePath);
			DrawFactionResultSingle(renderer, Result[1]);
		}
	};

	if (event.type == SDL_MOUSEBUTTONUP && PickAllClicked == true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		PickAllClicked = false;
	}

	if (insidePickAll == true && PickAllHovering == false && PickAllClicked == false) DrawPickAllHover(renderer, PickAll, PickAllMessage);

	else if (insidePickAll == false && PickAllIsDefault == false) {
		DrawPickAll(renderer, PickAll, PickAllMessage);
	};
}

void RenderRome::CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
	CheckMousePositionPickAll(event, renderer, window);
	CheckMousePositionWarhammer(event, renderer);
	CheckMousePositionShogun(event, renderer);
	CheckMousePositionMedieval(event, renderer);
}

void RenderRome::PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester) {
	SDL_Surface* RomeScreen = NULL;
	RomeScreen = SDL_GetWindowSurface(window);
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedImage = IMG_Load(tester.c_str());
	if (loadedImage == NULL) {
		printf("Unable to load image %s! SDL_Image Error: %s \n", tester.c_str(), IMG_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedImage, RomeScreen->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s!\n", tester.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedImage);
	}

	SDL_Rect image{ 6,0,994,749 };
	SDL_Texture* RomeImage = SDL_CreateTextureFromSurface(renderer, optimizedSurface);
	SDL_RenderCopy(renderer, RomeImage, NULL, &image);

	SDL_FreeSurface(RomeScreen);
	SDL_FreeSurface(optimizedSurface);
	SDL_DestroyTexture(RomeImage);
	RomeScreen = NULL;
	optimizedSurface = NULL;
	loadedImage = NULL;
	RomeImage = NULL;
}

void RenderRome::DrawWarhammerButton(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage) {
	SDL_SetRenderDrawColor(renderer, 163, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Warhammer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Warhammer);

	TTF_Font* WHfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!WHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* WarhammerS = TTF_RenderText_Blended(WHfont, "Warhammer II", Grey);
	SDL_Texture* WarhammerM = SDL_CreateTextureFromSurface(renderer, WarhammerS);
	SDL_RenderCopy(renderer, WarhammerM, NULL, &WarhammerMessage);

	TTF_CloseFont(WHfont);
	WHfont = NULL;
	if (RenderingRome == false) {
		SDL_FreeSurface(WarhammerS);
		SDL_DestroyTexture(WarhammerM);
		WarhammerS = NULL;
		WarhammerM = NULL;
	}

	RenderRome::WarhammerIsDefault = true;
	RenderRome::WarhammerHovering = false;
}

void RenderRome::DrawWarhammerButtonHover(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage) {
	SDL_SetRenderDrawColor(renderer, 193, 68, 5, 255);
	SDL_RenderFillRect(renderer, &Warhammer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Warhammer);

	TTF_Font* WHHfont = TTF_OpenFont("darkdominion.ttf", 43);
	if (!WHHfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* WarhammerHS = TTF_RenderText_Blended(WHHfont, "Warhammer II", LightGrey);
	SDL_Texture* WarhammerHM = SDL_CreateTextureFromSurface(renderer, WarhammerHS);
	SDL_RenderCopy(renderer, WarhammerHM, NULL, &WarhammerMessage);

	TTF_CloseFont(WHHfont);
	WHHfont = NULL;
	if (RenderingRome == false) {
		SDL_FreeSurface(WarhammerHS);
		SDL_DestroyTexture(WarhammerHM);
		WarhammerHS = NULL;
		WarhammerHM = NULL;
	}

	RenderRome::WarhammerIsDefault = false;
	RenderRome::WarhammerHovering = true;
}

void RenderRome::CheckMousePositionWarhammer(SDL_Event event, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	insideWarhammer = true;

	//Check if mouse is left of the button
	if (x < WarhammerLeftposition.x) insideWarhammer = false;
	//Check if mouse is right of the button
	if (x > WarhammerRightposition.x) insideWarhammer = false;
	//Check if mouse is above the button
	if (y < WarhammerTopposition.y) insideWarhammer = false;
	//Check if mouse is below the button
	if (y > WarhammerBottomposition.y) insideWarhammer = false;


	if (event.type == SDL_MOUSEBUTTONDOWN && insideWarhammer == true) {
		if (WarhammerHovering == true && RenderingRome == true) {
			SDL_RenderClear(renderer);
			RenderingRome = false;
			WarhammerSelected = true;
		}
	};

	if (insideWarhammer == true && WarhammerHovering == false) DrawWarhammerButtonHover(renderer, WarhammerButton, WarhammerMessage);

	else if (insideWarhammer == false && WarhammerIsDefault == false) {
		DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
	};
}

void RenderRome::CheckMousePositionShogun(SDL_Event event, SDL_Renderer* renderer) {
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
		if (ShogunHovering == true && RenderingRome == true) {
			SDL_RenderClear(renderer);
			RenderingRome = false;
			ShogunSelected = true;
		}
	};

	if (insideShogun == true && ShogunHovering == false) DrawShogunButtonHover(renderer, ShogunButton, ShogunMessage);

	else if (insideShogun == false && ShogunIsDefault == false) {
		DrawShogunButton(renderer, ShogunButton, ShogunMessage);
	};
}

void RenderRome::DrawShogunButton(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage) {
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
	if (RenderingRome == false) {
		SDL_FreeSurface(ShogunS);
		SDL_DestroyTexture(ShogunM);
		ShogunS = NULL;
		ShogunM = NULL;
	}

	RenderRome::ShogunIsDefault = true;
	RenderRome::ShogunHovering = false;
}

void RenderRome::DrawShogunButtonHover(SDL_Renderer* renderer, SDL_Rect ShogunButton, SDL_Rect ShogunMessage) {
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
	if (RenderingRome == false) {
		SDL_FreeSurface(ShogunHS);
		SDL_DestroyTexture(ShogunHM);
		ShogunHS = NULL;
		ShogunHM = NULL;
	}

	RenderRome::ShogunIsDefault = false;
	RenderRome::ShogunHovering = true;
}

void RenderRome::DrawMedievalButton(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
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
	if (RenderingRome == false) {
		SDL_FreeSurface(MedievalS);
		SDL_DestroyTexture(MedievalM);
	}
	MedievalS = NULL;
	MedievalM = NULL;

	RenderRome::MedievalIsDefault = true;
	RenderRome::MedievalHovering = false;
}

void RenderRome::DrawMedievalButtonHover(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
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
	if (RenderingRome == false) {
		SDL_FreeSurface(MedievalHS);
		SDL_DestroyTexture(MedievalHM);
	}
	MedievalHS = NULL;
	MedievalHM = NULL;

	RenderRome::MedievalIsDefault = false;
	RenderRome::MedievalHovering = true;
}

void RenderRome::CheckMousePositionMedieval(SDL_Event event, SDL_Renderer* renderer) {
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
		if (MedievalHovering == true && RenderingRome == true) {
			SDL_RenderClear(renderer);
			RenderingRome = false;
			MedievalSelected = true;
		}
	};

	if (insideMedieval == true && MedievalHovering == false) DrawMedievalButtonHover(renderer, MedievalButton, MedievalMessage);

	else if (insideMedieval == false && MedievalIsDefault == false) {
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
	};
}