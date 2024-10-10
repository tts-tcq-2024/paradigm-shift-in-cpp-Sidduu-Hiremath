#include <unordered_set>
#include <cassert>
#include <iostream>
#include "BatteryManagementSystem.h"

void testNormalConditions(const std::unordered_set<std::string>& warningParameters) {
    assert(batteryIsOk(25, 70, 0.7, warningParameters) == true);  // All normal
    assert(batteryIsOk(0, 20, 0.0, warningParameters) == false);   // Low temperature
}

void testTemperatureConditions(const std::unordered_set<std::string>& warningParameters) {
    assert(batteryIsOk(44, 70, 0.7, warningParameters) == false); // Warning for temperature 
    assert(batteryIsOk(45, 70, 0.7, warningParameters) == false); // High temperature breach
    assert(batteryIsOk(-1, 70, 0.7, warningParameters) == false); // Low temperature breach
}

void testSoCConditions(const std::unordered_set<std::string>& warningParameters) {
    assert(batteryIsOk(25, 19, 0.7, warningParameters) == false);  // Low SoC breach
    assert(batteryIsOk(25, 20, 0.7, warningParameters) == false);  // Normal SoC
    assert(batteryIsOk(25, 79, 0.7, warningParameters) == false);  // Warning for SoC
    assert(batteryIsOk(25, 80, 0.7, warningParameters) == false);  // High SoC breach
}

void testChargeRateConditions(const std::unordered_set<std::string>& warningParameters) {
    assert(batteryIsOk(25, 70, 0.79, warningParameters) == false); // Warning for charge rate 
    assert(batteryIsOk(25, 70, 0.8, warningParameters) == false);  // High charge rate breach
    assert(batteryIsOk(25, 70, -0.1, warningParameters) == false); // Low charge rate breach
}

void testEdgeCases(const std::unordered_set<std::string>& warningParameters) {
    assert(batteryIsOk(20, 20, 0.0, warningParameters) == false); // SoC at minimum with no warning
    assert(batteryIsOk(20 + 0.05 * 45, 20, 0.0, warningParameters) == false); // Temperature warning
    assert(batteryIsOk(80 - 0.05 * 80, 20, 0.0, warningParameters) == false); // SoC warning
    assert(batteryIsOk(25, 80 - 0.05 * 0.8, 0.8, warningParameters) == false); // Charge rate warning
}

void runTests() {
    std::unordered_set<std::string> warningParameters = {"temperature", "soc", "chargeRate"};
    
    testNormalConditions(warningParameters);
    testTemperatureConditions(warningParameters);
    testSoCConditions(warningParameters);
    testChargeRateConditions(warningParameters);
    testEdgeCases(warningParameters);
    
    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    runTests(); 
    return 0;
}
