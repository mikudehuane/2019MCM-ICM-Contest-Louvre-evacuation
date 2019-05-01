#include "museum.h"

bool museum::exist(int r1, int r2)const //�ж�r1 r2֮����û��ͨ��
{
    if(roomList[r1].property==room::V || roomList[r2].property==room::V) throw -1;
    if(!roomList[r1].border || !roomList[r2].border) throw -1;
    for(int k=0; k<int(roomList[r1].adjList.size()); ++k)
        if(roomList[r1].adjList[k].next == r2) return true;
    return false;
}

void museum::change(int n) //�ñ�room[n]��Ŀ�����
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
    cerr<<endl<<"����"<<n<<"�������ڽӷ���Ŀ����ھ���÷���һ��"<<endl;
    cerr<<"Ŀ�����:"<<endl;
    cout<<roomList[n];
    for(int j=0; j<int(roomList[n].adjList.size()); ++j)
        cerr<<roomList[n].adjList[j].next<<'\t'<<roomList[roomList[n].adjList[j].next].exit<<endl;
    throw -1;
}
