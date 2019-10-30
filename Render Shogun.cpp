#include "Render Shogun.h"

void RenderShogun::DrawScreen(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 242, 242, 255);
	SDL_Rect RSide{ 1000, 0, 925, 1080 };
	SDL_RenderFillRect(renderer, &RSide);

	SDL_Rect LSide{ 0, 0, 5, 1080 };
	SDL_RenderFillRect(renderer, &LSide);

	SDL_Rect Bottom{ 0, 750, 1000, 480 };
	SDL_RenderFillRect(renderer, &Bottom);

	SDL_SetRenderDrawColor(renderer, 199, 6, 6, 255);
	SDL_Rect WBorder{ 0, 0, 1920, 1080 };
	SDL_RenderDrawRect(renderer, &WBorder);

	SDL_Rect SWBorder{ 5, 0, 995, 750 };
	SDL_RenderDrawRect(renderer, &SWBorder);
}

void RenderShogun::DrawShogun(SDL_Renderer* renderer) {
	DrawScreen(renderer);
	DrawPickAll(renderer, PickAll, PickAllMessage);
	DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
	DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
	DrawRandomByCampaign(renderer, RandomByCampaign, RandomByCampaignMessage);
	DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
	DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
	DrawRomeButton(renderer, RomeButton, RomeMessage);
}

void RenderShogun::ReplaceRightSide(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 242, 242, 255);
	SDL_Rect ReplaceRightSideRect{ 1000,0,920,1080 };
	SDL_RenderFillRect(renderer, &ReplaceRightSideRect);
}

void RenderShogun::DrawPickAll(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllFont = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!PAllFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAll = TTF_RenderText_Blended(PAllFont, "Random All", Red);
	SDL_Texture* PAllM = SDL_CreateTextureFromSurface(renderer, PAll);
	SDL_RenderCopy(renderer, PAllM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllFont);
	PAllFont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(PAll);
		SDL_DestroyTexture(PAllM);
		PAll = NULL;
		PAllM = NULL;
	}

	RenderShogun::PickAllIsDefault = true;
	RenderShogun::PickAllHovering = false;
	RenderShogun::PickAllClicked = false;
}

void RenderShogun::DrawPickAllHover(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllHFont = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!PAllHFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAllH = TTF_RenderText_Blended(PAllHFont, "Random All", DarkRed);
	SDL_Texture* PAllHM = SDL_CreateTextureFromSurface(renderer, PAllH);
	SDL_RenderCopy(renderer, PAllHM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllHFont);
	PAllHFont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(PAllH);
		SDL_DestroyTexture(PAllHM);
		PAllH = NULL;
		PAllHM = NULL;
	}

	RenderShogun::PickAllIsDefault = false;
	RenderShogun::PickAllHovering = true;
	RenderShogun::PickAllClicked = false;
}

void RenderShogun::DrawPickAllClicked(SDL_Renderer* renderer, SDL_Rect PickAll, SDL_Rect PickAllMessage) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderFillRect(renderer, &PickAll);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &PickAll);

	TTF_Font* PAllCFont = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!PAllCFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* PAllC = TTF_RenderText_Blended(PAllCFont, "Random All", SelectRed);
	SDL_Texture* PAllCM = SDL_CreateTextureFromSurface(renderer, PAllC);
	SDL_RenderCopy(renderer, PAllCM, NULL, &PickAllMessage);

	TTF_CloseFont(PAllCFont);
	PAllCFont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(PAllC);
		SDL_DestroyTexture(PAllCM);
		PAllC = NULL;
		PAllCM = NULL;
	}

	RenderShogun::PickAllIsDefault = false;
	RenderShogun::PickAllHovering = false;
	RenderShogun::PickAllClicked = true;
}

void RenderShogun::CheckMousePositionPickAll(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
	RenderShogun::RenderingShogun = true;
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
			std::vector<std::string> Result = randomizer.RandomAll(randomizer.ShogunList.ShogunTotalList);
			std::string FilePath = randomizer.GetPictureFilepath(Result[0], Result[1], randomizer.ShogunList.ShogunFilePaths);
			ReplaceInnerWindow(renderer);
			PullImage(renderer, window, FilePath);
			DrawFactionResult(renderer, Result);
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

void RenderShogun::CheckMousePositions(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
	if (RenderingShogun == true) {
		CheckMousePositionPickAll(event, renderer, window);
		CheckMousePositionButton2(event, renderer);
		CheckMousePositionDropDown1(event, renderer);
		CheckMousePositionDropDown2(event, renderer);
		CheckMousePositionSubmitButton(event, renderer, window);
		CheckMousePositionWarhammer(event, renderer);
		CheckMousePositionMedieval(event, renderer);
		CheckMousePositionRome(event, renderer);
	}
}

void RenderShogun::ReplaceInnerWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_Rect ReplaceInnerWindow{ 5,0,995,750 };
	SDL_RenderFillRect(renderer, &ReplaceInnerWindow);
}

void RenderShogun::DrawFactionResult(SDL_Renderer* renderer, std::vector<std::string> FactionResults) {
	TTF_Font* FactionCampaignFont = TTF_OpenFont("Japanese Style.ttf", 41);
	if (!FactionCampaignFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	int w, h;
	if (TTF_SizeText(FactionCampaignFont, FactionResults[0].c_str(), &w, &h)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_Rect FactionCampaignResultRect{ 125,40,w,h };
	SDL_Surface* CampaignR = TTF_RenderText_Blended(FactionCampaignFont, FactionResults[0].c_str(), Red);
	SDL_Texture* CampaignRM = SDL_CreateTextureFromSurface(renderer, CampaignR);
	SDL_RenderCopy(renderer, CampaignRM, NULL, &FactionCampaignResultRect);

	int w2, h2;
	if (TTF_SizeText(FactionCampaignFont, FactionResults[1].c_str(), &w2, &h2)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_Rect FactionResultRect{ 135,80, w2, h2 };
	SDL_Surface* FactionR = TTF_RenderText_Blended(FactionCampaignFont, FactionResults[1].c_str(), Red);
	SDL_Texture* FactionRM = SDL_CreateTextureFromSurface(renderer, FactionR);
	SDL_RenderCopy(renderer, FactionRM, NULL, &FactionResultRect);

	TTF_CloseFont(FactionCampaignFont);
	SDL_FreeSurface(CampaignR);
	SDL_FreeSurface(FactionR);
	SDL_DestroyTexture(CampaignRM);
	SDL_DestroyTexture(FactionRM);
	FactionCampaignFont = NULL;
	CampaignR = NULL;
	FactionR = NULL;
	CampaignRM = NULL;
	FactionRM = NULL;
}

void RenderShogun::DrawFactionResultSingle(SDL_Renderer* renderer, std::string FactionResult) {
	TTF_Font* FactionCampaignFont = TTF_OpenFont("Japanese Style.ttf", 41);
	if (!FactionCampaignFont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	int w, h;
	if (TTF_SizeText(FactionCampaignFont, FactionResult.c_str(), &w, &h)) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}

	SDL_Rect FactionCampaignResultRect{ 125,40,w,h };
	SDL_Surface* CampaignR = TTF_RenderText_Blended(FactionCampaignFont, FactionResult.c_str(), Red);
	SDL_Texture* CampaignRM = SDL_CreateTextureFromSurface(renderer, CampaignR);
	SDL_RenderCopy(renderer, CampaignRM, NULL, &FactionCampaignResultRect);

	TTF_CloseFont(FactionCampaignFont);
	SDL_FreeSurface(CampaignR);
	SDL_DestroyTexture(CampaignRM);
	FactionCampaignFont = NULL;
	CampaignR = NULL;
	CampaignRM = NULL;
}

void RenderShogun::DrawButton2(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2font = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!Button2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2 = TTF_RenderText_Blended(Button2font, randomizer.ShogunList.Campaigns[0].c_str(), Red);
	SDL_Texture* B2M = SDL_CreateTextureFromSurface(renderer, B2);
	SDL_RenderCopy(renderer, B2M, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2font2 = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2font2) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BV = TTF_RenderText_Blended(Button2font2, "V", Red);
	SDL_Texture* BVM = SDL_CreateTextureFromSurface(renderer, BV);
	SDL_RenderCopy(renderer, BVM, NULL, &DropDownV);


	TTF_CloseFont(Button2font);
	TTF_CloseFont(Button2font2);
	Button2font = NULL;
	Button2font2 = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(B2);
		SDL_FreeSurface(BV);
		SDL_DestroyTexture(B2M);
		SDL_DestroyTexture(BVM);
		B2 = NULL;
		BV = NULL;
		B2M = NULL;
		BVM = NULL;
	}

	RenderShogun::Button2IsDefault = true;
	RenderShogun::Button2Hovering = false;
	RenderShogun::Button2Clicked = false;
}

void RenderShogun::DrawButton2Hover(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2fontH = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!Button2fontH) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2H = TTF_RenderText_Blended(Button2fontH, randomizer.ShogunList.Campaigns[0].c_str(), DarkRed);
	SDL_Texture* B2HM = SDL_CreateTextureFromSurface(renderer, B2H);
	SDL_RenderCopy(renderer, B2HM, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2font2H = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2font2H) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BVH = TTF_RenderText_Blended(Button2font2H, "V", DarkRed);
	SDL_Texture* BVHM = SDL_CreateTextureFromSurface(renderer, BVH);
	SDL_RenderCopy(renderer, BVHM, NULL, &DropDownV);


	TTF_CloseFont(Button2fontH);
	TTF_CloseFont(Button2font2H);
	Button2fontH = NULL;
	Button2font2H = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(B2H);
		SDL_FreeSurface(BVH);
		SDL_DestroyTexture(B2HM);
		SDL_DestroyTexture(BVHM);
		B2H = NULL;
		BVH = NULL;
		B2HM = NULL;
		BVHM = NULL;
	}

	RenderShogun::Button2IsDefault = false;
	RenderShogun::Button2Hovering = true;
	RenderShogun::Button2Clicked = false;
}

void RenderShogun::DrawButton2Clicked(SDL_Renderer* renderer, SDL_Rect Button2, SDL_Rect Button2MessageRect, SDL_Rect Button2DropDown, SDL_Rect DropDownV) {
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderFillRect(renderer, &Button2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2);

	TTF_Font* Button2fontC = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!Button2fontC) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* B2C = TTF_RenderText_Blended(Button2fontC, randomizer.ShogunList.Campaigns[0].c_str(), SelectRed);
	SDL_Texture* B2CM = SDL_CreateTextureFromSurface(renderer, B2C);
	SDL_RenderCopy(renderer, B2CM, NULL, &Button2MessageRect);

	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderFillRect(renderer, &Button2DropDown);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &Button2DropDown);

	TTF_Font* Button2font2C = TTF_OpenFont("Caviar Dreams Bold.ttf", 25);
	if (!Button2font2C) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* BVC = TTF_RenderText_Blended(Button2font2C, "V", SelectRed);
	SDL_Texture* BVCM = SDL_CreateTextureFromSurface(renderer, BVC);
	SDL_RenderCopy(renderer, BVCM, NULL, &DropDownV);


	TTF_CloseFont(Button2fontC);
	TTF_CloseFont(Button2font2C);
	Button2fontC = NULL;
	Button2font2C = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(B2C);
		SDL_FreeSurface(BVC);
		SDL_DestroyTexture(B2CM);
		SDL_DestroyTexture(BVCM);
		B2C = NULL;
		BVC = NULL;
		B2CM = NULL;
		BVCM = NULL;
	}

	RenderShogun::Button2IsDefault = false;
	RenderShogun::Button2Hovering = false;
	RenderShogun::Button2Clicked = true;
}

void RenderShogun::CheckMousePositionButton2(SDL_Event event, SDL_Renderer* renderer) {
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
		if (Button2Hovering == true) DrawButton2Clicked(renderer, Button2, Button2MessageRect, Button2DropDown,  DropDownV);
		DrawDropDownBox1(renderer, DropDownBox1);
		DrawDropDownBox2(renderer, DropDownBox2);
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

void RenderShogun::DrawDropDownBox1(SDL_Renderer* renderer, SDL_Rect DropDownBox1) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1);

	TTF_Font* D1font = TTF_OpenFont("Japanese Style.ttf", 35);
	if (!D1font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1 = TTF_RenderText_Blended(D1font, randomizer.ShogunList.Campaigns[1].c_str(), Red);
	SDL_Texture* Drop1M = SDL_CreateTextureFromSurface(renderer, Drop1);
	SDL_RenderCopy(renderer, Drop1M, NULL, &DropDownBox1);

	TTF_CloseFont(D1font);
	D1font = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(Drop1);
		SDL_DestroyTexture(Drop1M);
		Drop1 = NULL;
		Drop1M = NULL;
	}

	RenderShogun::DropDown1IsDefault = true;
	RenderShogun::DropDown1Hovering = false;
}

void RenderShogun::DrawDropDownBox2(SDL_Renderer* renderer, SDL_Rect DropDownBox2) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2);

	TTF_Font* D2font = TTF_OpenFont("Japanese Style.ttf", 35);
	if (!D2font) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2 = TTF_RenderText_Blended(D2font, randomizer.ShogunList.Campaigns[2].c_str(), Red);
	SDL_Texture* Drop2M = SDL_CreateTextureFromSurface(renderer, Drop2);
	SDL_RenderCopy(renderer, Drop2M, NULL, &DropDownBox2);

	TTF_CloseFont(D2font);
	D2font = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(Drop2);
		SDL_DestroyTexture(Drop2M);
		Drop2 = NULL;
		Drop2M = NULL;
	}

	RenderShogun::DropDown2IsDefault = true;
	RenderShogun::DropDown2Hovering = false;
}

void RenderShogun::DrawDropDownBox1Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox1) {
	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &DropDownBox1);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox1);

	TTF_Font* D1Hfont = TTF_OpenFont("Japanese Style.ttf", 35);
	if (!D1Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop1H = TTF_RenderText_Blended(D1Hfont, randomizer.ShogunList.Campaigns[1].c_str(), Red);
	SDL_Texture* Drop1HM = SDL_CreateTextureFromSurface(renderer, Drop1H);
	SDL_RenderCopy(renderer, Drop1HM, NULL, &DropDownBox1);

	TTF_CloseFont(D1Hfont);
	D1Hfont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(Drop1H);
		SDL_DestroyTexture(Drop1HM);
		Drop1H = NULL;
		Drop1HM = NULL;
	}

	RenderShogun::DropDown1IsDefault = false;
	RenderShogun::DropDown1Hovering = true;
}

void RenderShogun::DrawDropDownBox2Hover(SDL_Renderer* renderer, SDL_Rect DropDownBox2) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &DropDownBox2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &DropDownBox2);

	TTF_Font* D2Hfont = TTF_OpenFont("Japanese Style.ttf", 35);
	if (!D2Hfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Drop2H = TTF_RenderText_Blended(D2Hfont, randomizer.ShogunList.Campaigns[2].c_str(), Red);
	SDL_Texture* Drop2HM = SDL_CreateTextureFromSurface(renderer, Drop2H);
	SDL_RenderCopy(renderer, Drop2HM, NULL, &DropDownBox2);

	TTF_CloseFont(D2Hfont);
	D2Hfont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(Drop2H);
		SDL_DestroyTexture(Drop2HM);
		Drop2H = NULL;
		Drop2HM = NULL;
	}

	RenderShogun::DropDown2IsDefault = false;
	RenderShogun::DropDown2Hovering = true;
}

void RenderShogun::CheckMousePositionDropDown1(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.ShogunList.Campaigns[1], randomizer.ShogunList.Campaigns[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawPickAll(renderer, PickAll, PickAllMessage);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByCampaign(renderer, RandomByCampaign, RandomByCampaignMessage);
		DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
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

void RenderShogun::CheckMousePositionDropDown2(SDL_Event event, SDL_Renderer* renderer) {
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
		std::swap(randomizer.ShogunList.Campaigns[2], randomizer.ShogunList.Campaigns[0]);
		ReplaceRightSide(renderer);
		ReplaceInnerWindow(renderer);
		DrawPickAll(renderer, PickAll, PickAllMessage);
		DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
		DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
		DrawRandomByCampaign(renderer, RandomByCampaign, RandomByCampaignMessage);
		DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
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

void RenderShogun::DrawSubmitButton(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButton);

	TTF_Font* Submitfont = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!Submitfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* Submit = TTF_RenderText_Blended(Submitfont, "Submit", Red);
	SDL_Texture* SubmitM = SDL_CreateTextureFromSurface(renderer, Submit);
	SDL_RenderCopy(renderer, SubmitM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(Submitfont);
	Submitfont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(Submit);
		SDL_DestroyTexture(SubmitM);
		Submit = NULL;
		SubmitM = NULL;
	}

	RenderShogun::SubmitIsDefault = true;
	RenderShogun::SubmitHovering = false;
	RenderShogun::SubmitClicked = false;
}

void RenderShogun::DrawSubmitButtonHover(SDL_Renderer* renderer, SDL_Rect SubmitButton, SDL_Rect SubmitButtonMessage) {
	SDL_SetRenderDrawColor(renderer, 201, 201, 201, 255);
	SDL_RenderFillRect(renderer, &SubmitButton);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &SubmitButton);

	TTF_Font* SubmitfontH = TTF_OpenFont("Japanese Style.ttf", 43);
	if (!SubmitfontH) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		TTF_Quit();
	}
	SDL_Surface* SubmitH = TTF_RenderText_Blended(SubmitfontH, "Submit", DarkRed);
	SDL_Texture* SubmitHM = SDL_CreateTextureFromSurface(renderer, SubmitH);
	SDL_RenderCopy(renderer, SubmitHM, NULL, &SubmitButtonMessage);

	TTF_CloseFont(SubmitfontH);
	SubmitfontH = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(SubmitH);
		SDL_DestroyTexture(SubmitHM);
		SubmitH = NULL;
		SubmitHM = NULL;
	}

	RenderShogun::SubmitIsDefault = false;
	RenderShogun::SubmitHovering = true;
	RenderShogun::SubmitClicked = false;
}

void RenderShogun::CheckMousePositionSubmitButton(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window) {
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
			std::string result = randomizer.RandomBySelectedCampaign(randomizer.ShogunList.ShogunTotalList, randomizer.ShogunList.Campaigns[0]);
			std::string FilePath = randomizer.GetPictureFilepath(randomizer.ShogunList.Campaigns[0], result, randomizer.ShogunList.ShogunFilePaths);
			ReplaceInnerWindow(renderer);
			ReplaceRightSide(renderer);
			DrawPickAll(renderer, PickAll, PickAllMessage);
			DrawButton2(renderer, Button2, Button2MessageRect, Button2DropDown, DropDownV);
			DrawRandomByCampaign(renderer, RandomByCampaign, RandomByCampaignMessage);
			DrawSubmitButton(renderer, SubmitButton, SubmitButtonMessage);
			DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
			DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
			DrawRomeButton(renderer, RomeButton, RomeMessage);
			PullImage(renderer, window, FilePath);
			DrawFactionResultSingle(renderer, result);
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

void RenderShogun::PullImage(SDL_Renderer* renderer, SDL_Window* window, std::string tester) {
	SDL_Surface* ShogunScreen = NULL;
	ShogunScreen = SDL_GetWindowSurface(window);
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedImage = IMG_Load(tester.c_str());
	if (loadedImage == NULL) {
		printf("Unable to load image %s! SDL_Image Error: %s \n", tester.c_str(), IMG_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedImage, ShogunScreen->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s!\n", tester.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedImage);
	}

	SDL_Rect image{ 6,0,994,749 };
	SDL_Texture* ShogunImage = SDL_CreateTextureFromSurface(renderer, optimizedSurface);
	SDL_RenderCopy(renderer, ShogunImage, NULL, &image);

	SDL_FreeSurface(ShogunScreen);
	SDL_FreeSurface(optimizedSurface);
	SDL_DestroyTexture(ShogunImage);
	ShogunScreen = NULL;
	optimizedSurface = NULL;
	loadedImage = NULL;
	ShogunImage = NULL;
}

void RenderShogun::DrawRandomByCampaign(SDL_Renderer* renderer, SDL_Rect RandomByCampaign, SDL_Rect RandomByCampaignMessage) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &RandomByCampaign);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &RandomByCampaign);

	TTF_Font* RBCfont = TTF_OpenFont("Japanese Style.ttf", 25);
	if (!RBCfont) {
		std::cout << "Error: " << TTF_GetError() << std::endl;
	}
	SDL_Surface* RandByCampaign = TTF_RenderText_Blended(RBCfont, "Random By Campaign", Red);
	SDL_Texture* RandByCampaignM = SDL_CreateTextureFromSurface(renderer, RandByCampaign);
	SDL_RenderCopy(renderer, RandByCampaignM, NULL, &RandomByCampaignMessage);

	TTF_CloseFont(RBCfont);
	RBCfont = NULL;
	if (RenderingShogun == false) {
		SDL_FreeSurface(RandByCampaign);
		SDL_DestroyTexture(RandByCampaignM);
		RandByCampaign = NULL;
		RandByCampaignM = NULL;
	}
}

void RenderShogun::DrawMedievalButton(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(MedievalS);
		SDL_DestroyTexture(MedievalM);
		MedievalS = NULL;
		MedievalM = NULL;
	}

	RenderShogun::MedievalIsDefault = true;
	RenderShogun::MedievalHovering = false;
}

void RenderShogun::DrawMedievalButtonHover(SDL_Renderer* renderer, SDL_Rect Medieval, SDL_Rect MedievalMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(MedievalHS);
		SDL_DestroyTexture(MedievalHM);
		MedievalHS = NULL;
		MedievalHM = NULL;
	}

	RenderShogun::MedievalIsDefault = false;
	RenderShogun::MedievalHovering = true;
}

void RenderShogun::CheckMousePositionMedieval(SDL_Event event, SDL_Renderer* renderer) {
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
		if (MedievalHovering == true && RenderingShogun == true) {
			SDL_RenderClear(renderer);
			RenderingShogun = false;
			MedievalSelected = true;
		}
	};

	if (insideMedieval == true && MedievalHovering == false) DrawMedievalButtonHover(renderer, MedievalButton, MedievalMessage);

	else if (insideMedieval == false && MedievalIsDefault == false) {
		DrawMedievalButton(renderer, MedievalButton, MedievalMessage);
	};
}

void RenderShogun::DrawWarhammerButton(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(WarhammerS);
		SDL_DestroyTexture(WarhammerM);
		WarhammerS = NULL;
		WarhammerM = NULL;
	}

	RenderShogun::WarhammerIsDefault = true;
	RenderShogun::WarhammerHovering = false;
}

void RenderShogun::DrawWarhammerButtonHover(SDL_Renderer* renderer, SDL_Rect Warhammer, SDL_Rect WarhammerMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(WarhammerHS);
		SDL_DestroyTexture(WarhammerHM);
		WarhammerHS = NULL;
		WarhammerHM = NULL;
	}

	RenderShogun::WarhammerIsDefault = false;
	RenderShogun::WarhammerHovering = true;
}

void RenderShogun::CheckMousePositionWarhammer(SDL_Event event, SDL_Renderer* renderer) {
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
		if (WarhammerHovering == true && RenderingShogun == true) {
			SDL_RenderClear(renderer);
			RenderingShogun = false;
			WarhammerSelected = true;
		}
	};

	if (insideWarhammer == true && WarhammerHovering == false) DrawWarhammerButtonHover(renderer, WarhammerButton, WarhammerMessage);

	else if (insideWarhammer == false && WarhammerIsDefault == false) {
		DrawWarhammerButton(renderer, WarhammerButton, WarhammerMessage);
	};
}

void RenderShogun::DrawRomeButton(SDL_Renderer* renderer, SDL_Rect Rome, SDL_Rect RomeMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(RomeS);
		SDL_DestroyTexture(RomeM);
	}
	RomeS = NULL;
	RomeM = NULL;

	RenderShogun::RomeIsDefault = true;
	RenderShogun::RomeHovering = false;
}

void RenderShogun::DrawRomeButtonHover(SDL_Renderer* renderer, SDL_Rect Rome, SDL_Rect RomeMessage) {
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
	if (RenderingShogun == false) {
		SDL_FreeSurface(RomeHS);
		SDL_DestroyTexture(RomeHM);
	}
	RomeHS = NULL;
	RomeHM = NULL;

	RenderShogun::RomeIsDefault = false;
	RenderShogun::RomeHovering = true;
}

void RenderShogun::CheckMousePositionRome(SDL_Event event, SDL_Renderer* renderer) {
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
		if (RomeHovering == true && RenderingShogun == true) {
			SDL_RenderClear(renderer);
			RenderingShogun = false;
			RomeSelected = true;
		}
	};

	if (insideRome == true && RomeHovering == false) DrawRomeButtonHover(renderer, RomeButton, RomeMessage);

	else if (insideRome == false && RomeIsDefault == false) {
		DrawRomeButton(renderer, RomeButton, RomeMessage);
	};
}