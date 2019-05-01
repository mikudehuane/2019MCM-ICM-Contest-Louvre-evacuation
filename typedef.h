#ifndef TYPEDEF_H_INCLUDED
#define TYPEDEF_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

struct room;
struct pass;

struct pass
{
    static const int O=0, L=1, E=2;
    int next;
    int property;
    friend bool operator==(const pass &l, const pass &r)
    {
        if(l.next==r.next && l.property==r.property) return true;
        else return false;
    }
};

struct room
{
    static const int O=0, T=1, E=2, V=3;    //V表示不存在这个房间
    int code;
    int property;   //O普通房间，T特别火热的房间，E出口外
    int mP;         //最大容量
    int P;          //目前人数
    vector<pass> adjList;   //邻接房间编号
    int exit;       //目标出口，取值1-6
    int direct;     //行动方向, 取值为流向房间的编号,-1表示本来就是出口
    bool border;    //是否为边界节点,取值为true/false
    friend ostream &operator<<(ostream &os, const room &r)
    {
        if(r.property==room::V) return os;

        os<<r.code<<'\t';
        if(r.property==room::O || r.property==room::T)
        {
            os<<((r.property==room::O)?"ordinary":"extra")<<endl;
            os<<"border\t"<<(r.border?"true":"false")<<endl;
            os<<"direct\t"<<r.direct<<endl;
            os<<"exit\t"<<r.exit<<endl;
            os<<"capacity\t"<<r.mP<<endl;
            os<<"current\t"<<r.P<<endl;
            os<<"routes"<<endl;
            for(int k=0; k<int(r.adjList.size()); ++k)
            {
                os<<r.adjList[k].next<<'\t';
                switch(r.adjList[k].property)
                {
                    case pass::E: os<<"exit"<<endl;break;
                    case pass::L: os<<"stairs"<<endl;break;
                    case pass::O: os<<"gate"<<endl;break;
                    default: throw -1;
                }
            }
        }
        else if(r.property==room::V)
            os<<"empty"<<endl;
        else if(r.property==room::E)
        {
            os<<"exit"<<endl;
            os<<"current\t"<<r.P<<endl;
            os<<"route"<<endl;
            for(int k=0; k<int(r.adjList.size()); ++k)
            {
                os<<r.adjList[k].next<<'\t';
                switch(r.adjList[k].property)
                {
                    case pass::E: os<<"exit"<<endl;break;
                    case pass::L: os<<"stairs"<<endl;break;
                    case pass::O: os<<"gate"<<endl;break;
                    default: throw -1;
                }
            }
        }
        os<<endl;
        return os;
    }
    friend bool operator==(const room &l, const room &r)
    {
        //比较出口和方向，连接
        if(l.exit==r.exit&&
           l.direct==r.direct&&
           l.adjList==r.adjList)
           return true;
        else return false;
    }
};

#endif // TYPEDEF_H_INCLUDED
