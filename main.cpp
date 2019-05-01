#include <iostream>
#include "museum.h"
#include <vector>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

int main()
{
    double rate;
    cout<<"Please enter congestion level(rate)(0-1)"<<endl;
    cin>>rate;
    museum louvre(rate);
    louvre.dataInput();
    //bfs
    vector<int> border;             //Store boundary node number
    int route[7][700];
    //route[i][j] represents the next node under the shortest path from node j to exit i
    int cost[7][700];
    //cost[i][j] Represents the number of rooms traversed by the shortest path from room j to exit j
    for(int i=0; i<7; ++i)  //initializing
        for(int j=0; j<700; ++j)
        {
            route[i][j]=0; cost[i][j]=0;
        }
    louvre.unweightedShortDistance(route, cost);    //bfs
    //Build the initial evacuation plan
    louvre.judgeDirection(route, cost);
    louvre.judgeBorder(border);
    louvre.judgeP(rate);
    int tp = louvre.calculateTime(), t;
    const double rt = 0.99, Te = 5;
    double T = 500;
    //Simulated Annealing
    cout<<"In the calculation process, the time required for the evacuation of the intermediate scheme"<<endl;
    int e1, e2, d1, d2, r1, r2;
    srand(time(NULL));
    double possi;   //probability
    const int Inf=2147483647;
    while(T>Te)
    {
        //Calculate the new evacuation plan
        do
        {
            r1 = rand()%border.size();
            r2 = rand()%border.size();
        }while(r1==r2 || louvre.exist(border[r1], border[r2]));
        e1 = louvre.exit(border[r1]);
        e2 = louvre.exit(border[r2]);
        d1 = louvre.dire(border[r1]);
        d2 = louvre.dire(border[r2]);
        louvre.change(border[r1]);
        louvre.change(border[r2]);
        t = louvre.calculateTime();
        if(t<tp)                                        //accept
        {
            louvre.judgeBorder(border);
            tp = t;
        }
        else
        {
            possi = exp((tp-t)/double(T));
            if(t==Inf || rand()/double(RAND_MAX)>possi) //reject
            {
                louvre.change(border[r1], e1, d1);
                louvre.change(border[r2], e2, d2);
            }
            else                                        //accept
            {
                louvre.judgeBorder(border);
                tp = t;
            }
        }
        T = T*rt;
        cout<<tp<<endl;
    }
    return 0;
}
