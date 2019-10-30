#include "Randomizer.h"

std::string Randomizer::RandomBySelectedCampaign(std::unordered_map<std::string, std::vector<std::string>> List, std::string Campaign) {
	bool ResultTwice = false;
	std::string DuplicateResult = "";
	int CampaignResult = List.at(Campaign).size();
	int IPOS = rand() % CampaignResult;
	std::string result = List.at(Campaign)[IPOS];

	for (int i = 0; i < PriorTwoResults.size(); i++) {
		if (result == PriorTwoResults.at(i)) {
			DuplicateResult = result;
			ResultTwice = true;
			IPOS = rand() % CampaignResult;
			result = List.at(Campaign)[IPOS];
			if (DuplicateResult == result) {
				IPOS = rand() % CampaignResult;
				result = List.at(Campaign)[IPOS];
				PriorTwoResults.push_back(result);
				return result;
			}
			PriorTwoResults.push_back(result);
			return result;
		}
	}

	if (ResultTwice == false) {
		PriorTwoResults.push_back(result);
		if (PriorTwoResults.size() >= 2) {
			PriorTwoResults.erase(PriorTwoResults.begin());
		}

		return result;
	}
};

std::vector<std::string> Randomizer::Reinclude(std::vector<std::string>& source, std::vector<std::string>& DestV) {
	for (int i = 0; i < source.size(); i++) {
		DestV.push_back(source.at(i));
		source.erase(source.begin() + i);
		i -= 1;
	}
	
	return source;
}

std::string Randomizer::GetPictureFilepath(std::string CamporRace, std::string Faction, std::vector<std::string> FilePaths) {
	std::string PictureFilepath = "";
	for (int i = 0; i < FilePaths.size(); i++) {
		if (FilePaths.at(i).find(CamporRace) != std::string::npos && FilePaths.at(i).find(Faction) != std::string::npos) PictureFilepath = FilePaths.at(i);
	}

	return PictureFilepath;
}

std::string Randomizer::GetPictureFilepath(std::string Faction, std::vector<std::string> FilePaths) {
	std::string FilePath = "";
	for (int i = 0; i < FilePaths.size(); i++) {
		if (FilePaths.at(i).find(Faction) != std::string::npos) FilePath = FilePaths.at(i);
	}

	return FilePath;
}

bool Randomizer::VortexorMortal(std::string tester) {
	bool inBoth = false;
	for (auto& i : Warhammerlist.LordList) {
		if (i.find(tester) != std::string::npos) {
			for (auto& t : Warhammerlist.Vortex) {
				if (t.find(tester) != std::string::npos) inBoth = true;
			}
		}
	}

	return inBoth;
}

bool Randomizer::VortexorMortalRaces(std::string tester) {
	bool inBoth = false;
	for (auto& i : Warhammerlist.Races) {
		if (i.find(tester) != std::string::npos) {
			for (auto& t : Warhammerlist.VortexRaces) {
				if (t.find(tester) != std::string::npos) inBoth = true;
			}
		}
	}

	return inBoth;
}

std::vector<std::string>  Randomizer::ExcludeRandAll(std::vector<std::string> &source, std::vector<std::string> &DestV) {
	for (int i = 0; i < source.size(); i++) {
		bool VM = VortexorMortal(source.at(i));
		if (VM == false) {
			DestV.push_back(source.at(i));
			source.erase(source.begin() + i);
			i -= 1;
		}
	}

	return source;
}

std::vector<std::string> Randomizer::ExcludeRandByRace(std::vector<std::string>& source, std::vector<std::string>& DestV) {
	for (int i = 0; i < source.size(); i++) {
		bool VMR = VortexorMortalRaces(source.at(i));
		if (VMR == false) {
			DestV.push_back(source.at(i));
			source.erase(source.begin() + i);
			i -= 1;
		}
	}

	return source;
}

std::vector<std::string> Randomizer::RandomAll(std::unordered_map<std::string, std::vector<std::string>> List) {
	bool ResultTwice = false;
	std::vector<std::string> FinalVector = {};
	std::vector<std::string> TransferVector = {};
	std::string DuplicateResult = "";
	for (auto& i : List) {
		TransferVector.push_back(i.first);
	}
	int Key = rand() % List.size();
	std::string TransferKey = TransferVector.at(Key);
	FinalVector.push_back(TransferKey);
	int value = rand() % List.at(TransferKey).size();
	std::string TransferValue = List.at(TransferKey).at(value);
	FinalVector.push_back(TransferValue);

	for (int i = 0; i < PriorTwoResults.size(); i++) {
		if (FinalVector[1] == PriorTwoResults.at(i)) {
			DuplicateResult = FinalVector[1];
			ResultTwice = true;
			FinalVector.clear();
			Key = rand() % List.size();
			TransferKey = TransferVector.at(Key);
			FinalVector.push_back(TransferKey);
			value = rand() % List.size();
			TransferValue = List.at(TransferKey).at(value);
			FinalVector.push_back(TransferValue);
			if (FinalVector[1] == DuplicateResult) {
				FinalVector.clear();
				Key = rand() % List.size();
				TransferKey = TransferVector.at(Key);
				FinalVector.push_back(TransferKey);
				value = rand() % List.size();
				TransferValue = List.at(TransferKey).at(value);
				FinalVector.push_back(TransferValue);

				return FinalVector;
			}
			PriorTwoResults.push_back(FinalVector[1]);
			return FinalVector;
		}
		else if (PriorTwoResults.size() >= 2) {
			PriorTwoResults.erase(PriorTwoResults.begin());
		}
	}

	if (ResultTwice == false) {
		PriorTwoResults.push_back(FinalVector[1]);
		if (PriorTwoResults.size() >= 2) {
			PriorTwoResults.erase(PriorTwoResults.begin());
		}

		return FinalVector;
	}
}