#ifndef LISTENER_H
#define LISTENER_H

#pragma once

#include "Controller.h"
#include "CardReader.h"
#include "Monitor.h"

class Listener
{
private:
    Controller *controller;
    CardReader *rfid;
    uint8_t rfidData[16];

public:
    Listener();        
    virtual ~Listener();
    void checkEvent();
    bool checkRfid();


};

#endif