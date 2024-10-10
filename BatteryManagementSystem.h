#ifndef BATTERYMANAGEMENTSYSTEM_H
#define BATTERYMANAGEMENTSYSTEM_H

#include <unordered_set>
#include "BreachUtils.h"

BreachType isBatteryTemperatureOk(float temperature);
BreachType isBatterySocOk(float soc);
BreachType isBatteryChargeRateOk(float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate, const std::unordered_set<std::string>& warningParameters);

#endif 
