#include "Listener.h"

Listener::Listener(mfrc522 *rfid)
: rfid(rfid)                // 변수 초기화 방법 중 1 | == mfrc522 *rfid = rfid;
{
    //this->rfid = rfid;
}

Listener::~Listener()
{

}

void Listener::checkEvent()
{
    uint8_t byte;
    if ((byte = rfid->mfrc522_request(PICC_REQALL, rfidData)) == CARD_FOUND)
    {
        rfid->mfrc522_get_card_serial(rfidData);
        for (int i=0; i<5; i++)
            printf("002x", rfidData[i]);
    }
}