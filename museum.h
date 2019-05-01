#ifndef MUSEUM_H_INCLUDED
#define MUSEUM_H_INCLUDED

#include "typedef.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <assert.h>
using namespace std;

class museum
{
private:
    room roomList[700];
    void Insert(int x, int y, char type);
    int flow(int start, int End)const;
    double rate;
public:
    int totalP;         //headcount
    museum(double rate);
    void dataInput();
    void unweightedShortDistance(int route[6][700], int cost[6][700])const;
    void judgeDirection(int route[7][700], int cost[7][700]);
    //Assign values to direct and border
    void judgeP(double rate);   //The P member is determined by the rate
    void judgeBorder(vector<int> &border);
    int calculateTime();        //Calculate the evacuation time under the current plan in seconds
    bool exist(int r1, int r2)const; //judge if there's a channel between r1 and r2
    void change(int n); //Change the target exit of room n
    int exit(int r)const{return roomList[r].exit;}
    int dire(int r)const{return roomList[r].direct;}
    void change(int n, int exit, int dire){roomList[n].exit = exit; roomList[n].direct = dire;}
};

#endif // MUSEUM_H_INCLUDED
