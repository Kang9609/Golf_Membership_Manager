#include "Controller.h"
#include <iostream>

Controller::Controller()
{
    monitor = new Monitor();
}

Controller::~Controller()
{

}

void Controller::updateEvent(DeviceData data)      // Card ID를 넘겨줘야한다
{
    std::cout << data.devName << " : ";
    for(const auto &data : data.devData)
    {
        std::cout << data << " ";
    }
    std::cout << std::endl;
}