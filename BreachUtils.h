#ifndef BREACHUTILS_H
#define BREACHUTILS_H

#include <string>

enum BreachType {
    NORMAL,
    TOO_LOW,
    TOO_HIGH,
    WARNING
};

BreachType checkBatteryParametersAreOk(float value, float minValue, float maxValue, float warningTolerance);
std::string getBreachMessage(const std::string& parameter, BreachType breach);
BreachType checkTooLow(float value, float minValue);
BreachType checkTooHigh(float value, float maxValue);
BreachType checkWarning(float value, float minValue, float maxValue, float warningTolerance);

#endif 
