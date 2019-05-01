#include "museum.h"

void museum::print()const
{
    for(int i=0; i<700; ++i)
    {
        cout<<roomList[i];
    }
}

void museum::printPath(int route[7][700], int cost[7][700])const
{
    const int Inf=2147483647;
    int k;
    for(int i=101; i<700; ++i)
    {
        if(roomList[i].property==room::V) continue;
        cout<<roomList[i].code<<endl;
        for(int j=1; j<=6; ++j)
        {
            cout<<cost[j][i]<<'\t';
            if(cost[j][i]==Inf)
            {
                throw -1;
            }
            k = route[j][i];
            cout<<i;
            while(k!=0)
            {
                cout<<" "<<k;
                k = route[j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}


void museum::printBorder()const
{
    for(int i=0; i<700; ++i)
    {
        if(roomList[i].property==room::V) continue;
        if(roomList[i].border == false) continue;
        cout<<roomList[i];
    }
}

void museum::printP()const
{
    for(int i=0; i<700; ++i)
    {
        if(roomList[i].property==room::V) continue;
        else
        {
            if(roomList[i].P)
            {
                cout<<roomList[i].code<<'\t'<<roomList[i].P<<endl;
                cout<<"direct\t"<<roomList[i].direct<<endl;

            }
        }
    }
    cout<<endl;
}
