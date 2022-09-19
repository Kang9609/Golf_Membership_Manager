#ifndef LISTENER_H
#define LISTENER_H

#pragma once
#include "mfrc522.h"

class Listener
{
private:
    mfrc522 *rfid;
    uint8_t rfidData[16];

public:
    Listener(mfrc522 *rfid);        
    ~Listener();
    void checkEvent();


};

#endif