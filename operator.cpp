#include "museum.h"

museum &museum::operator=(const museum &r)
{
    if(this != &r)
        for(int i=0; i<700; ++i)
            roomList[i] = r.roomList[i];
    return *this;
}

bool operator==(const museum &l, const museum &r)
{
    for(int i=0; i<700; ++i)
    {
        if(!(l.roomList[i]==r.roomList[i]))
            return false;
    }
    return true;
}
