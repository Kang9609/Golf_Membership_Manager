#include <iostream>
#include "Golf_Membership_Manager.h"
#include "MembersEntity.h"
#include <string.h>

int main(void)
{
    // mfrc522 rfid(new SPI(10, 3000000));             // (CE0의 wPi 번호, spi 통신 속도 = 3MHz)
    // Listener *listener = new Listener(&rfid);

    Golf_Membership_Manager golf_Membership_Manager;

    golf_Membership_Manager.run();

   

}
/*
    while (1)
    {
        listener->checkEvent();
        delay(1000);
        printf("hihi\n");
    }

*/
