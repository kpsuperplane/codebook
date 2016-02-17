/*
    --- SEGMENTED TREE WITH LAZY PROPAGATION ---
    A segmented tree with lazy propagation
    This was the solution to `Good Debugging`
    https://en.wikipedia.org/wiki/Segment_tree

*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;
int mid(node in){
	return floor(((double)in.left + (double)in.right)/2);
}
int lines, attempts, maxbugs;
struct node{
    int correct, wrong, left, right;
    bool lazy;
};
node tree[3000001];
void buildTree(int pos, int left, int right){
    tree[pos].left = left;
    tree[pos].correct = 0;
    tree[pos].lazy = false;
    tree[pos].wrong = right-left+1;
    tree[pos].right = right;
	int middle = mid(tree[pos]);
    if(left == right){
        return;
    }
    buildTree(pos*2, left, middle);
    buildTree(pos*2+1, middle+1, right);
}
void pushdown(int pos){
    int temp;
    if(tree[pos].lazy){
        tree[pos].lazy ^= 1;
        tree[pos*2+1].lazy ^= 1;
        temp = tree[pos*2+1].correct;
        tree[pos*2+1].correct = tree[pos*2+1].wrong;
        tree[pos*2+1].wrong = temp;
        tree[pos*2].lazy ^= 1;
        temp = tree[pos*2].correct;
        tree[pos*2].correct = tree[pos*2].wrong;
        tree[pos*2].wrong = temp;
    }
}
int query(int pos, int wrong){
    if(tree[pos].left == tree[pos].right){
        return tree[pos].left;
    }else{
        pushdown(pos);
        if(tree[pos*2].wrong + wrong < maxbugs){
            return query(pos*2+1, tree[pos*2].wrong + wrong);
        }else{
            return query(pos*2, wrong);
        }
    }
}
void change(int pos, int left, int right){
    if(tree[pos].left == tree[pos].right){
        tree[pos].correct = !tree[pos].correct;
        tree[pos].wrong = !tree[pos].wrong;
    }else{
        if(tree[pos].left == left && tree[pos].right == right){
            tree[pos].lazy ^= 1;
            int temp = tree[pos].correct;
            tree[pos].correct = tree[pos].wrong;
            tree[pos].wrong = temp;
            return;
        }
        pushdown(pos);
        if(right <= mid(tree[pos])){
            change(pos*2, left, right);
        }else if(left >= mid(tree[pos])+1){
            change(pos*2+1, left, right);
        }else{
            change(pos*2, left, mid(tree[pos]));
            change(pos*2+1, mid(tree[pos])+1, right);
        }
        tree[pos].correct = tree[pos*2].correct + tree[pos*2+1].correct;
        tree[pos].wrong = tree[pos*2].wrong + tree[pos*2+1].wrong;
    }
}
int main(){
    scanf("%d%d%d", &lines, &attempts, &maxbugs);
    buildTree(1, 1, lines);
    while(attempts--){
        int left, right;
        scanf("%d%d", &left, &right);
        change(1, left, right);
        if(tree[1].wrong < maxbugs){
            printf("AC?\n");
        }else{
            printf("%d\n", query(1, 0));
        }
    }
    return 0;
}

