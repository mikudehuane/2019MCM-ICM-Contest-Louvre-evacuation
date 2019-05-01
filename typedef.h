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
    static const int O=0, T=1, E=2, V=3;    //V��ʾ�������������
    int code;
    int property;   //O��ͨ���䣬T�ر���ȵķ��䣬E������
    int mP;         //�������
    int P;          //Ŀǰ����
    vector<pass> adjList;   //�ڽӷ�����
    int exit;       //Ŀ����ڣ�ȡֵ1-6
    int direct;     //�ж�����, ȡֵΪ���򷿼�ı��,-1��ʾ�������ǳ���
    bool border;    //�Ƿ�Ϊ�߽�ڵ�,ȡֵΪtrue/false
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
        //�Ƚϳ��ںͷ�������
        if(l.exit==r.exit&&
           l.direct==r.direct&&
           l.adjList==r.adjList)
           return true;
        else return false;
    }
};

#endif // TYPEDEF_H_INCLUDED
