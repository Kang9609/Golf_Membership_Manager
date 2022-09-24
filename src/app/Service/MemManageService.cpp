#include "MemManageService.h"
#include <string.h>
using namespace std;

MemManageService::MemManageService(ComDev *comDev, LCD *lcd)
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
    membersManagerState = CARD_SEARCH;
    this->comDev = comDev;
    this->lcd = lcd;
    count = 10000;
}

MemManageService::~MemManageService()
{

}


void MemManageService::updateStateEvent(std::string devName)
{
    char buff[30];
    switch (membersManagerState)
    {
        case CARD_READER:
            if (devName == "ModeButton")
            {   
                
                membersManagerState = CARD_REGISTER;
                printf("changed to Card_Register_State\n");
                sprintf(buff, "CARD REGISTER     \n");
                lcd->WriteStringXY(0, 0, buff);
                
                
            }
        break;

        case CARD_REGISTER:
            if (devName == "ModeButton")
            {   
                
                membersManagerState = CARD_SEARCH;
                printf("changed to Card_Search_State\n");
                sprintf(buff, "CARD SEARCH     \n");
                lcd->WriteStringXY(0, 0, buff);
            }
        break;

        case CARD_SEARCH:
            if (devName == "ModeButton")
            {   
        
                membersManagerState = CARD_READER;
                printf("changed to Card_Reader_State\n");
                sprintf(buff, "CARD READER     \n");
                lcd->WriteStringXY(0, 0, buff);
            }
        break;
    }
}

void MemManageService::checkCard(int *cardNum)
{
     char buff[30];
    switch (membersManagerState)
    {
        case CARD_READER:
           
           if (membersEntity->findMemberInfo(cardNum))
           {
                printf("Resgistered Member\n");
                membersEntity->printMemberInfo(cardNum);
                comDev->sendData(cardNum);
           }
           else
           {
                printf("Not resgistered Member\n");
           }
        break;

        case CARD_REGISTER:
            MemberInfo tempMember;
            tempMember.id=count;
            printf("이름을 입력하세요:");
            cin.getline(tempMember.name, 20, '\n');
            printf("주소를 입력하세요:");
            cin.getline(tempMember.address, 40, '\n');
            printf("연락처를 입력하세요:");
            cin.getline(tempMember.phoneNumber, 15, '\n');
            // strcpy(tempMember.name, "LEEHYORYN");
            // strcpy(tempMember.address, "101dong 123Ho");
            // strcpy(tempMember.phoneNumber, "010-9876-5432");
            memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));


            membersEntity->addMemberInfo(tempMember);
            printf("Member Registered!\n");

            sprintf(buff, "ID : %02x-%02x-%02x-%02x-%02x", cardNum[0], cardNum[1], cardNum[2], cardNum[3], cardNum[4]);
            lcd->WriteStringXY(1,0,buff);
            count++;
        break;

        case CARD_SEARCH:
        int menu = 0;
        char search[30];

        std::cout << "검색어 입력 : ";
        std::cin >> search;
        
        switch (menu)
        {
            case 1:
                if(membersEntity->findMemberInfo(search)) {
                    printf("Registered Member\n");
                    membersEntity->printMemberInfo(search);
                }else {
                    printf("Not Registered Member\n");
                }
                break;
        }
    }
}