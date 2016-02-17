#include <iostream>
using namespace std;
struct node{
	node* left;
	node* right;
	int val;
	node(int cent){
		val = cent;
	}
	node(){
		left = NULL;
		right = NULL;
		val = -1;
	}
};
void insert(int val, node* cur){
	if(cur->val == -1){
		cur->val = val;
	}else{
		if(val < cur->val){
			if (cur->left == NULL) cur->left = new node();
			insert(val, cur->left);
		}
		else{
			if (cur->right == NULL) cur->right = new node();
			insert(val, cur->right);
		}
	}
}
int main(){
	node tree = node();
	insert(2, &tree);

	insert(5, &tree);
	
	insert(1, &tree);
	
	insert(6, &tree);
	
	insert(8, &tree);
	
	return 0;
}