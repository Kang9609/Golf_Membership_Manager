#include "MemManageService.h"
#include <string.h>

MemManageService::MemManageService()
{
    membersEntity = new MembersEntity();
    membersManagerState = CARD_READER;
}

MemManageService::~MemManageService()
{

}

void MemManageService::updateStateEvent(std::string devName)
{
    switch (membersManagerState)
    {
        case CARD_READER:
            if (devName == "ModeButton")
            {
                membersManagerState = CARD_REGISTER;
                printf("changed to Card_Register_State\n");
                
            }
        break;

        case CARD_REGISTER:
            if (devName == "ModeButton")
            {
                membersManagerState = CARD_READER;
                printf("changed to Card_Reader_State\n");
            }
        break;
    }
}

void MemManageService::checkCard(int *cardNum)
{
    switch (membersManagerState)
    {
        case CARD_READER:
           
           if (membersEntity->findMemberInfo(cardNum))
           {
                printf("Resgistered Member\n");
                membersEntity->printMemberInfo(cardNum);
           }
           else
           {
                printf("Not resgistered Member\n");
           }
        break;

        case CARD_REGISTER:
            MemberInfo tempMember;
            tempMember.id = 10000;
            strcpy(tempMember.name, "JiSungPark");
            strcpy(tempMember.address, "101dong 1003ho");
            strcpy(tempMember.phoneNumber, "010-1234-5678");
            memcpy(tempMember.cardNum, cardNum, sizeof(tempMember.cardNum));

            membersEntity->addMemberInfo(tempMember);
            printf("Member Registered!\n");
        break;
    }
}