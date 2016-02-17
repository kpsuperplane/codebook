/*
    --- DISJOINT SETS ---
    Find's the Minimum Spanning Tree
    Each set has a 'representative' node. You can combine sets of things together. Yay?
    https://en.wikipedia.org/wiki/Disjoint_sets

*/

#include <iostream>
#include <stdio.h>
using namespace std;
int p[100001], rnk[100001];
int findSet(int d){
    if(d != p[d]){
        p[d] = findSet(p[d]);
    }
    return p[d];
}
void link(int x, int y){
    if(rnk[x] > rnk[y]){
        p[y] = x;
    }else{
        p[x] = y;
        if(rnk[x] == rnk[y]){
            rnk[y]++;
        }
    }
}
void combine(int x, int y){
    link(findSet(x), findSet(y));
}
int main(){
    //e.g. add  0,1,2,3,4 to the set and combine them
    for(int i = 0; i < 5; i++){
        p[i] = i;
    }
    combine(1, 2);
    combine(0, 1);
    combine(3, 4);
    //findSet(0-2) returns 2, findSet(3-4) returns 4
}
