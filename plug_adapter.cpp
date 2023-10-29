//
// Created by fredrik on 2023-10-29.
//

#include "plug_adapter.h"

#include <thread>
#include <mutex>
#include <iostream>
/*
 * Unfortunately I don't have a compatible wall plug to finish this project.
 * This file is just a stub that prints the desired state to the terminal. This file
 * will be extended in the future to actually speak with the hardware.
 */

std::mutex mutex;
bool currentState{};



namespace plug_adapter
{
	void delayedTurnoff(std::chrono::seconds seconds)
	{
		//Intentionally lock mutex first so that you can't turn it on again before this thread exits
		std::unique_lock<std::mutex> lock(mutex);
		std::this_thread::sleep_for(seconds);
		currentState = false;
		std::cout << "Current state: " << std::boolalpha << currentState << std::endl;
	}
	
	void setWallPlug(float currentTemp, float goalTemp, int interval)
	{
		bool previousState = currentState;
		float diff = currentTemp - goalTemp;
		if (diff < 0)
		{
			currentState = false;
		}
		else if (diff < 0.4f)
		{
			std::unique_lock<std::mutex> lock(mutex);
			currentState = true;
			// Heuristic for turning on the fridge for a fraction of the ispindel refresh interval
			int seconds = interval * (0.4f / diff);
			std::thread delayThread{plug_adapter::delayedTurnoff, std::chrono::seconds(seconds)};
			delayThread.detach();
		} else
		{
			std::unique_lock<std::mutex> lock{mutex};
			currentState = true;
		}
		//Printout if it changed, while we still have this stub
		if (previousState != currentState)
		{
			std::cout << "Current state: " << std::boolalpha << currentState << std::endl;
		}
	}
}