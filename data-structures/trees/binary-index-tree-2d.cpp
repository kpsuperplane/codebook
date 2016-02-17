#include <isotream>
#include <stdio.h>
int xn, yn; //number of keys
int tree[10000][10000];
void update(int x, int y, int val){
	while(y <= yn){
		tree[x][y] += val;
		y += (y & -y);
	}
}
int freqTo(int x, int y){ 
	int sum = 0;
	while(x > 0){
		int theY = y;
		sum += tree[x];
		x -= (x & -x);
		while(theY > 0){
			sum += tree[theY];
			theY -= (theY & -theY);
		}
	}
	return sum;
}
int freqTo2D(int x1, int x2, int y1, int y2){
	return freqTo(x2, y2) - (freqTo(x1, y2)+freqTo(y1, x2)-freqTo(x1, y1));
}
int main(){
	
}