//
// Created by Fredrik Ekstedt Karpers on 2023-10-29.
//

#ifndef GESALLPROV_PARSER_H
#define GESALLPROV_PARSER_H

#include <vector>
#include <fstream>

namespace settings_parser
{
	struct TempPair {
		float gravity;
		float temp;
		
		auto operator<=>(const TempPair&) const = default;
	};
	
	std::vector<TempPair> parse(const std::ifstream& settings);
}

#endif //GESALLPROV_PARSER_H
