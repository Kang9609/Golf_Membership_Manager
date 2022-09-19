#include <iostream>
#include "mfrc522.h"

int main(void)
{
    mfrc522 rfid(new SPI(10, 3000000));             // (CE0의 wPi 번호, spi 통신 속도 = 3MHz)
    uint8_t byte;
    uint8_t str[MAX_LEN];                            
    byte = 0x55; // just to check that byte is getting loaded and printed
    delay(1500);

    // check version of the reader
    byte = rfid.mfrc522_read(VersionReg);           // Version 정보를 읽고 Version에 따른 printf 출력

    printf("ver --> %0x\n", byte);
    if (byte == 0x92)
    {
        printf("MIFARE RC522v2\r\n");
        printf("Detected\r\n");
    }
    else if (byte == 0x91 || byte == 0x90)
    {
        printf("MIFARE RC522v1\r\n");
        printf("Detected\r\n");
    }
    else
    {
        printf("No reader found\r\n");
    }

    while (1)
    {
        byte = rfid.mfrc522_request(PICC_REQALL, str);      // Card Detect 1초 간격으로 확인
        printf("byte-->%d ", byte);
        if (byte == CARD_FOUND)                             // Card found = 3
        {
            for (int i = 0; i < MAX_LEN; i++)
                str[i] = ' ';
            byte = rfid.mfrc522_get_card_serial(str);

            for (int i = 0; i < 5; i++)
                printf("%02x ", str[i]);
            printf("\n");
        }
        delay(1000);
        printf("hihi\n");
    }
}
