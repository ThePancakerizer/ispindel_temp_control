//
// Created by Fredrik Ekstedt Karpers on 2023-10-29.
//

#ifndef GESALLPROV_CONFIG_PARSER_H
#define GESALLPROV_CONFIG_PARSER_H

#include <vector>
#include <fstream>

namespace settings_parser
{
	struct TempPair {
		float gravity;
		float temp;
		
		auto operator<=>(const TempPair&) const = default;
	};
	
	std::vector<TempPair> parse(std::ifstream& settings);
	
	float calculateGoal(float currentGravity, const std::vector<settings_parser::TempPair>& pairs);
}

#endif //GESALLPROV_CONFIG_PARSER_H
