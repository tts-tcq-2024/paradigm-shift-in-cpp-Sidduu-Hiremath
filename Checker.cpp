#include <assert.h>
#include <iostream>

bool CheckTemperatureIsOk(float temperature){
  if(temperature < 0 || temperature > 45){
    std::cout<< "Temperature is out of range!\n";
    return false;
  }
  return true;
}

bool CheckSocIsOk(float soc){
  if(soc < 20 || soc > 80){
    std::cout<< "State of Charge out of range!\n";
    return false;
  }
  return true;
}

bool CheckChargeRateIsOk(float ChargeRate){
  if(ChargeRate > 0.8){
    std::cout<< "Charge Rate out of range!\n";
    return false;
  }
  return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate){
  return CheckTemperatureIsOk(temperature) && CheckSocIsOk(soc) && CheckChargeRateIsOk(chargeRate);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
