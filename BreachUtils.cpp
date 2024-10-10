#include "BreachUtils.h"

BreachType checkTooLow(float value, float minValue) {
    return (value < minValue) ? TOO_LOW : NORMAL;
}

BreachType checkTooHigh(float value, float maxValue) {
    return (value > maxValue) ? TOO_HIGH : NORMAL;
}

BreachType checkWarning(float value, float minValue, float maxValue, float warningTolerance) {
    if (value >= maxValue - warningTolerance) {
        return WARNING; 
    }
    if (value <= minValue + warningTolerance) {
        return WARNING;
    }
    return NORMAL;
}

BreachType checkBatteryParametersAreOk(float value, float minValue, float maxValue, float warningTolerance) {
    BreachType breach = checkTooLow(value, minValue);
    if (breach != NORMAL) return breach;  

    breach = checkTooHigh(value, maxValue);
    if (breach != NORMAL) return breach; 

    return checkWarning(value, minValue, maxValue, warningTolerance);
}

#include <unordered_map>

std::string getBreachMessage(const std::string& parameter, BreachType breach) {
    static const std::unordered_map<BreachType, std::string> messages = {
        {TOO_LOW, parameter + " is too low!\n"},
        {TOO_HIGH, parameter + " is too high!\n"},
        {WARNING, parameter + " warning: approaching limit!\n"},
        {NORMAL, parameter + " is normal.\n"}
    };

    return messages.at(breach);
}


