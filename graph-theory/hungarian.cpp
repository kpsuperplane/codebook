/*
    --- HUNGARIAN ALGORITHM ---
    Finds the best match while optimization for lowest cost.
    https://en.wikipedia.org/wiki/Hungarian_algorithm

*/

#include <iostream>
#define MAX 1000
using namespace std;
bool vis[MAX]; //visited
int pre[MAX]; //previously visited nodes
int n; //number of total verticies
int adj[MAX][MAX]; //adjacency matrix
bool hungary(int x){
	for(int i = 0; i < n; i++){
		if(adj[x][i] && !vis[i]){
			vis[i] = true;
			if(!pre[i] || hungary(pre[i])){
				pre[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main(){
    int cnt = 0; //answer [How many can be matched?]
	for(int i = 0; i < n;i ++){
		cnt += hungary(i);
	}
	return 0;
}
