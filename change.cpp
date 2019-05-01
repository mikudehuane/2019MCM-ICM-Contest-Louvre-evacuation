#include "museum.h"

bool museum::exist(int r1, int r2)const //判断r1 r2之间有没有通道
{
    if(roomList[r1].property==room::V || roomList[r2].property==room::V) throw -1;
    if(!roomList[r1].border || !roomList[r2].border) throw -1;
    for(int k=0; k<int(roomList[r1].adjList.size()); ++k)
        if(roomList[r1].adjList[k].next == r2) return true;
    return false;
}

void museum::change(int n) //该变room[n]的目标出口
{
    if(!roomList[n].border) throw -1;
    for(int j=0; j<int(roomList[n].adjList.size()); ++j)
    {
//cout<<endl<<roomList[n].adjList[j].next<<endl;
        if(roomList[n].exit != roomList[roomList[n].adjList[j].next].exit)
        {
            roomList[n].exit = roomList[roomList[n].adjList[j].next].exit;
            roomList[n].direct = roomList[n].adjList[j].next;
            return;
        }
    }
    cerr<<endl<<"房间"<<n<<"的所有邻接房间目标出口均与该房间一致"<<endl;
    cerr<<"目标出口:"<<endl;
    cout<<roomList[n];
    for(int j=0; j<int(roomList[n].adjList.size()); ++j)
        cerr<<roomList[n].adjList[j].next<<'\t'<<roomList[roomList[n].adjList[j].next].exit<<endl;
    throw -1;
}
