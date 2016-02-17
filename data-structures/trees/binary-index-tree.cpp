/*----- BINARY INDEX TREE ---------
A.K.A FENWICK TREE
ESSENTIALLY SEGMENTED TREE CUT IN HALF

MUCH SIMPLER THAN SEGMENTED TREE CODE WISE

PERFORMANCE: O(log N)

1 Dimensional Array 

Each element in the array stores cumulative frequency of consecutive list of boxes

Range of boxes is related to the binary value of the index

Sum format based on index (hyphen means sum of)

16: 1-16 (10000)
15: 15 (1111)
14: 13-14 (1110)
13: 13 (1101)
12: 9-12 (1100)
11: 11 (1011)
10: 9-10 (1010)
9: 9 (1001)
8: 1-8 (1000)
7: 7 (111)
6: 5-6 (110)
5: 4 (101)
4: 1-4 (100)
3: 3 (11)
2: 1-2 (10)
1: 1 (01)

E.g. 11
11 = 1011
   = 1000 + 1010 + 1011
   = 8 + 10 + 11

--How to find which ones to add?--

A node at index X will store sum in the range (X - (2^r) + 1) to X where r is the position of the last digit of 1

--How to know which indices to update when changing value?--

Add the decimal value of the last digit 1 

E.g. update index 5 (in tree from 1 to 16):

5 = 00101 (add 1)
6 = 00110 (add 2)
8 = 01000 (add 8)
16 = 10000 (done)

Use 2's compliment to find last 1 (complement is to switch 0 to 1 and 1 to 0 and add 1)

e.g.

1100's compliment = 0011 + 1 = 0100

x = a1b where a is from 0 to the last 1 and b is from the last 1 to the end
e.g.
x = 12 = 1 1 00
         a 1 b

!!! "&" means binary addition

*/
#include <isotream>
#include <stdio.h>
int n; //number of keys

void update(int idx, int val){ //O(log N)
	while(idx <= n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int freqTo(int idx){ //O(log N) SUM FROM 1 TO IDX
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
int freqAt(int idx){ //O(log N) # AT IDX
	return freqTo(idx) - freqTo(idx-1);
}
int main(){
	
}