#include "museum.h"

void museum::Insert(int x, int y, char type)
{
    if(roomList[x].property==room::V || roomList[y].property==room::V)
    {
        cout<<x<<'\t'<<y<<endl;
        throw -1;
    }
    pass tmp1, tmp2;
    tmp1.next = y;
    tmp2.next = x;
    switch(type)
    {
        case 'O': tmp1.property=tmp2.property=pass::O; break;
        case 'L': tmp1.property=tmp2.property=pass::L; break;
        case 'E': tmp1.property=tmp2.property=pass::E; break;
        default: throw -1;
    }
    roomList[x].adjList.push_back(tmp1);
    roomList[y].adjList.push_back(tmp2);
}

museum::museum(double r)
{
    for(int i=0; i<700; ++i)
    {
        roomList[i].border = false;
        roomList[i].code = i;
        roomList[i].property = room::V;
    }
    for(int i=1; i<=6; ++i)
    {
        roomList[i].exit = i;
        roomList[i].direct = -1;//表示是出口,没有下一个
        roomList[i].mP = 2147483647;
        roomList[i].property=room::E;
    }
    totalP = 0;
    rate = r;
}

void museum::dataInput()
{
    ifstream fin("room.txt");
    assert(fin);
    int code;
    char type;
    int maxP;
    while(fin>>code)
    {
        fin>>type;
        fin>>maxP;
        if(type=='O')
            roomList[code].property=room::O;
        else if(type=='T')
            roomList[code].property=room::T;
        else throw -1;
        roomList[code].mP = maxP;
    }
    fin.close();

    fin.open("route.txt");
    assert(fin);
    int room1, room2;
    while(fin>>room1)
    {
        fin>>room2;
        fin>>type;
        Insert(room1, room2, type); //函数中自动在两边添加
    }
    fin.close();
}

