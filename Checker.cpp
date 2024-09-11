#include <assert.h>
#include <iostream>
#include <string>

enum BreachType {
    NORMAL,
    TOO_LOW,
    TOO_HIGH
};

BreachType checkBatteryParametersAreOk(float value, float minValue, float maxValue) {
    if (value < minValue) {
        return TOO_LOW;
    }
    if (value > maxValue) {
        return TOO_HIGH;
    }
    return NORMAL;
}

std::string getBreachMessage(const std::string& parameter, BreachType breach) {
    switch (breach) {
        case TOO_LOW:
            return parameter + " is too low!\n";
        case TOO_HIGH:
            return parameter + " is too high!\n";
        default:
            return parameter + " is normal.\n";
    }
}

BreachType IsBatteryTemperatureOk(float temperature) {
    return checkBatteryParametersAreOk(temperature, 0, 45);
}

BreachType IsBatterySocOk(float soc) {
    return checkBatteryParametersAreOk(soc, 20, 80);
}

BreachType IsBatteryChargeRateOk(float chargeRate) {
    return checkBatteryParametersAreOk(chargeRate, 0, 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    BreachType temperatureStatus = IsBatteryTemperatureOk(temperature);
    BreachType socStatus = IsBatterySocOk(soc);
    BreachType chargeRateStatus = IsBatteryChargeRateOk(chargeRate);

    std::cout << getBreachMessage("Temperature", temperatureStatus);
    std::cout << getBreachMessage("State of Charge", socStatus);
    std::cout << getBreachMessage("Charge Rate", chargeRateStatus);

    return (temperatureStatus == NORMAL && socStatus == NORMAL && chargeRateStatus == NORMAL);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
    return 0;
}
