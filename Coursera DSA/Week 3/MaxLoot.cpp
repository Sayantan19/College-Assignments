#include<bits/stdc++.h>
using namespace std;

int MaxLoot(int capacity,int  * values,int * weights, int items)
{
    double fract[items];
    for(int i=0;i<items;i++)
    {
        fract[i] = (double)values[i]/weights[i];
    }
    
}