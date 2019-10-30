#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class ShogunLists {
public:
	std::unordered_map<std::string, std::vector<std::string>> ShogunTotalList = {
			{
			"Vanilla", {
				"Chosokabe",
				"Date",
				"Hattori",
				"Hojo",
				"Ikko Ikki",
				"Mori",
				"Oda",
				"Otomo",
				"Shimazu",
				"Takeda",
				"Tokugawa",
				"Uesugi"
			}
		}, {
			"Rise of the Samurai", {
				"Hiraizumi Fujiwara",
				"Kubota Fujiwara",
				"Kamakura Minamoto",
				"Kiso Minamoto",
				"Fukuhara Taira",
				"Yashima Taira"
			}
		}, {
			"Fall of the Samurai", {
				"Aizu",
				"Choshu",
				"Jozai",
				"Nagaoka",
				"Obama",
				"Saga",
				"Satsuma",
				"Sendai",
				"Tosa",
				"Tsu"
			}
		}
	};

	std::vector<std::string> Campaigns = {
		"Vanilla",
		"Rise of the Samurai",
		"Fall of the Samurai"
	};

	std::vector<std::string> ShogunFilePaths = {
		"Shogun 2 Faction Pictures\\Vanilla\\Chosokabe.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Date.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Hattori.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Hojo.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Ikko Ikki.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Mori.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Oda.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Otomo.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Shimazu.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Takeda.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Tokugawa.png",
		"Shogun 2 Faction Pictures\\Vanilla\\Uesugi.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Fukuhara Taira.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Hiraizumi Fujiwara.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Kamakura Minamoto.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Kiso Minamoto.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Kubota Fujiwara.png",
		"Shogun 2 Faction Pictures\\Rise of the Samurai\\Yashima Taira.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Aizu.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Choshu.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Jozai.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Nagaoka.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Obama.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Saga.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Satsuma.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Sendai.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Tosa.png",
		"Shogun 2 Faction Pictures\\Fall of the Samurai\\Tsu.png"
	};
};