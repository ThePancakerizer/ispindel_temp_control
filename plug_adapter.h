//
// Created by fredrik on 2023-10-29.
//

#ifndef GESALLPROV_PLUG_ADAPTER_H
#define GESALLPROV_PLUG_ADAPTER_H

#include <chrono>

namespace plug_adapter{
	void delayedTurnoff(std::chrono::seconds seconds);
	
	void setWallPlug(float currentTemp, float goalTemp, int interval);
}

#endif //GESALLPROV_PLUG_ADAPTER_H
