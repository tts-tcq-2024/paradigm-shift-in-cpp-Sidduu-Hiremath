#include <unordered_set>
#include <cassert>
#include <iostream>
#include "BatteryManagementSystem.h"

int main() {
    std::unordered_set<std::string> warningParameters = {"temperature", "soc", "chargeRate"};

    assert(batteryIsOk(25, 70, 0.7, warningParameters) == true);  // All normal
    assert(batteryIsOk(0, 20, 0.0, warningParameters) == false);   // Low temperature
    
    // Test cases for temperature
    assert(batteryIsOk(44, 70, 0.7, warningParameters) == false); // Warning for temperature 
    assert(batteryIsOk(45, 70, 0.7, warningParameters) == false); // High temperature breach
    assert(batteryIsOk(-1, 70, 0.7, warningParameters) == false); // Low temperature breach

    // Test cases for State of Charge (SoC)
    assert(batteryIsOk(25, 19, 0.7, warningParameters) == false);  // Low SoC breach
    assert(batteryIsOk(25, 20, 0.7, warningParameters) == false);  // Normal SoC
    assert(batteryIsOk(25, 79, 0.7, warningParameters) == false);  // Warning for SoC
    assert(batteryIsOk(25, 80, 0.7, warningParameters) == false);  // High SoC breach

    // Test cases for charge rate
    assert(batteryIsOk(25, 70, 0.79, warningParameters) == false); // Warning for charge rate 
    assert(batteryIsOk(25, 70, 0.8, warningParameters) == false);  // High charge rate breach
    assert(batteryIsOk(25, 70, -0.1, warningParameters) == false); // Low charge rate breach

    // Edge cases around warning thresholds
    assert(batteryIsOk(20, 20, 0.0, warningParameters) == false); // SoC at minimum with no warning
    assert(batteryIsOk(20 + 0.05 * 45, 20, 0.0, warningParameters) == false); // Temperature warning
    assert(batteryIsOk(80 - 0.05 * 80, 20, 0.0, warningParameters) == false); // SoC warning
    assert(batteryIsOk(25, 80 - 0.05 * 0.8, 0.8, warningParameters) == false); // Charge rate warning

    return 0;
}
