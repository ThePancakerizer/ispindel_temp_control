//
// Created by Fredrik Ekstedt Karpers on 2023-10-29.
//
#include "config_parser.h"

#include <iostream>
#include <fstream>

namespace settings_parser
{
	std::vector<TempPair> parse(std::ifstream& settings)
	{
		std::vector<TempPair> temps{};
		std::string line;
		while(!settings.eof()) {
			float gravity, temp;
			if (settings >> gravity >> temp) {
				// Data extraction was successful
				temps.emplace_back(gravity, temp);
			} else {
				// Data extraction failed
				std::cerr << "Failed to extract data from the file. Not formatted as float?" << std::endl;
				exit(1);
			}
			
		}
		//Make sure the input is sorted in ascending order.
		if(!std::is_sorted(temps.begin(), temps.end(),std::greater{}))
		{
			throw std::runtime_error("Error, input data is not sorted");
		}
		return temps;
	}
	
	/*
	 * Creates a temp graph that looks kind of like this if there are only 2 inputs
	 * in the "pairs" vector.
	 * _______
	 *        \
	 *         \
	 *          \
	 *           \________
	 *
	 * X-axis is gravity, Y-axis is desired temperature.
	 */
	
	float calculateGoal(float currentGravity, const std::vector<TempPair>& pairs)
	{
		if (pairs.empty())
			return -1;
		if (currentGravity >= pairs[0].gravity)
			return pairs[0].temp;
		for (int i = 0; i < pairs.size() - 1; ++i)
		{
			if (currentGravity <= pairs[i+1].gravity)
				continue;
			// interpolate between the two values
			float diff = pairs[i].gravity - pairs[i+1].gravity;
			float alpha = currentGravity / diff; // value in interval (0,1]
			float tempDiff = pairs[i].temp - pairs[i+1].temp;
			return tempDiff * alpha;
		}
		// The last value if gravity is under it
		return pairs.back().temp;
	}
}