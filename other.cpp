#include "museum.h"

void museum::unweightedShortDistance(int route[7][700], int cost[7][700])const
{
    for(int start=1; start<=6; ++start)
    {
        const int Inf=2147483647;
        priority_queue<int> q;

        int u;

        for(int i=0; i<700; ++i) cost[start][i] = Inf;

        //寻找最短路径
        cost[start][start] = 0;
        route[start][start] = 0;    //表示出口
        q.push(start);

        while(!q.empty())
        {
            u = q.top();
            q.pop();
            for(int k=0; k<int(roomList[u].adjList.size()); ++k)
            {
                if(cost[start][roomList[u].adjList[k].next] == Inf)
                {
                    cost [start] [roomList[u].adjList[k].next] = cost[start][u]+1;
                    route[start][roomList[u].adjList[k].next] = u;
                    q.push(roomList[u].adjList[k].next);
                }
            }
        }
    }
}

void museum::judgeDirection(int route[7][700], int cost[7][700])   //给direct赋值
{
    const int Inf=2147483647;
    int mExit, mCost;
    for(int i=100; i<700;++i)
    {
        if(roomList[i].property == room::V) continue;
        mExit = 0;
        mCost = Inf;
        for(int k=1; k<=6; ++k)
            if(cost[k][i]<mCost) {mCost = cost[k][i]; mExit=k;}
        roomList[i].exit = mExit;
        roomList[i].direct = route[mExit][i];
    }

}

void museum::judgeBorder(vector<int> &border)
{
    border.clear();
    for(int i=100; i<700;++i)
    {
        if(roomList[i].property == room::V) continue;
        roomList[i].border = false;
        for(int j=0; j<int(roomList[i].adjList.size()); ++j)
        {
            if(roomList[i].exit != roomList[roomList[i].adjList[j].next].exit)
            {
                roomList[i].border = true;
                border.push_back(i);
                break;
            }
        }

    }
}

void museum::judgeP(double rate)
{
    totalP = 0;
    for(int i=1; i<=6; ++i)
        roomList[i].P = 0;
    for(int i=100; i<700;++i)
    {
        if(roomList[i].property == room::V) continue;
        if(roomList[i].property == room::T)
        {
            if(10*rate>1) roomList[i].P = roomList[i].mP;
            else roomList[i].P = roomList[i].mP*(10*rate);
        }
        else if(roomList[i].property == room::O)
            roomList[i].P = roomList[i].mP*rate;
        else throw -1;
        totalP+=roomList[i].P;
    }
}
