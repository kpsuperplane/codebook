/*
    --- PRIM'S ALGORITHM ---
    Find's the Minimum Spanning Tree
    https://en.wikipedia.org/wiki/Prim%27s_algorithm

*/

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm> /* fill() */
using namespace std;
#define N_MAX 10000 // Max number of nodes
#define pp pair<int, int> //Use pairs to define edge connects [cost, to]

int nodes, edges, parents[N_MAX], costs[N_MAX];

bool visited[N_MAX];

vector<pp> adj[N_MAX];

priority_queue< pp, vector<pp>, greater<pp> > q; //priority queue for optimized performance
//^ Use less<pp> for largest to smallest

void prim(){
    fill_n(costs, nodes, 1<<29); //Fill best cost with huge number
    q.push(make_pair(0, 0)); //start at 0th element
    while(!q.empty()){
        pp cur = q.top(); //get current value
        int idx = cur.second;
        int cost = cur.first;
        q.pop();
        if(visited[idx]) continue; //Skip this one, we've already been here
        visited[idx] = true;
        for(int i = 0; i < adj[idx].size(); i++){
            pp next = adj[idx][i];
            if(next.first < costs[next.second]){
                costs[next.second] = next.first;
                parents[next.second] = idx;
                q.push(adj[idx][i]);
            }
        }
    }
}

int main(){
    //Do whatever you want :P Below is a sample implementation
    scanf("%d%d", &nodes, &edges);
    for(int i = 0; i < edges; i++){
        int a, b, cost;
        scanf("%d%d%d", &a, &b, &cost);
        adj[a].push_back(make_pair(cost, b));
        adj[b].push_back(make_pair(cost, a));
    }
    prim();
    //Gl hf

}
