#include "museum.h"
#include <cmath>

int museum::flow(int s, int e)const //计算从房间s到房间e能
{
    int flow;
    double r = roomList[s].P/double(roomList[s].mP);
    flow = 70*(1.867*pow(r,4)-6.333*pow(r,3)+7.233*pow(r,2)-3.617*r+0.95);
    int flow1, flow2;
    if(roomList[s].P-flow<0 || roomList[e].P+flow>roomList[e].mP)
    {
        flow1 = roomList[s].P;
        flow2 = roomList[e].mP - roomList[e].P;
        flow = flow1<flow2? flow1:flow2;
    }
    return flow;
}
