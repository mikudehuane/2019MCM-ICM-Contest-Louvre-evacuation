#include "museum.h"
#include <cmath>

int museum::calculateTime()
{
    const int Inf = 2147483647;
    int t=0, flowP, errorC=0;
    int exitP = 0;  //Already alienated
    int texitP = 0; //Number of people evacuated at the last moment
    while(exitP<totalP)
    {
        for(int i=100; i<700; ++i)
        {
            if(roomList[i].property == room::V) continue;
            flowP = flow(i, roomList[i].direct);
            roomList[i].P -= flowP;
            roomList[roomList[i].direct].P += flowP;
        }
        texitP = exitP;
        exitP=0;
        for(int i=1; i<=6; ++i)
            exitP+=roomList[i].P;

        if(texitP==exitP) ++errorC;
        if(errorC >= 1000)  //The scheme is stuck in an endless loop
        {
            t = Inf;
            break;
        }
        ++t;
    }
    judgeP(rate);
    return t;
}
