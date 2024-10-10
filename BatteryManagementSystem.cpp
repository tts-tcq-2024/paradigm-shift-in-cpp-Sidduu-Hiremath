#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include "BatteryManagementSystem.h"

BreachType isBatteryTemperatureOk(float temperature) {
    float warningTolerance = 0.05f * 45; 
    return checkBatteryParametersAreOk(temperature, 0, 45, warningTolerance);
}

BreachType isBatterySocOk(float soc) {
    float warningTolerance = 0.05f * 80; 
    return checkBatteryParametersAreOk(soc, 20, 80, warningTolerance);
}

BreachType isBatteryChargeRateOk(float chargeRate) {
    float warningTolerance = 0.05f * 0.8; 
    return checkBatteryParametersAreOk(chargeRate, 0, 0.8, warningTolerance);
}

bool batteryIsOk(float temperature, float soc, float chargeRate, const std::unordered_set<std::string>& warningParameters) {
    BreachType temperatureStatus = isBatteryTemperatureOk(temperature);
    BreachType socStatus = isBatterySocOk(soc);
    BreachType chargeRateStatus = isBatteryChargeRateOk(chargeRate);

    std::cout << getBreachMessage("Temperature", temperatureStatus);
    std::cout << getBreachMessage("State of Charge", socStatus);
    std::cout << getBreachMessage("Charge Rate", chargeRateStatus);

    return (temperatureStatus == NORMAL && socStatus == NORMAL && chargeRateStatus == NORMAL);
}
