#ifndef MEMMANAGESERVICE_H
#define MEMMANAGESERVICE_H

#pragma once
#include <string>
#include "MembersEntity.h"
#include "Memberinfo.h"

enum {CARD_READER, CARD_REGISTER};

class MemManageService
{
private:
    int membersManagerState;        // State 값이 중요 => 카드 확인 및 등록을 위해
    MembersEntity *membersEntity;

public:
    MemManageService();
    virtual ~MemManageService();
    void updateStateEvent(std::string devName);    // devName : device Name -> button
    void checkCard(int *cardNum);

};

#endif