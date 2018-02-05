#include "binary_tree.h"
#include <iostream>

using namespace std;

int main(){
	vector<int> initArray={2,10,5};
	BiTree<int> testTree(initArray); 
	cout<<testTree.GetRoot()->val<<endl;
	if(testTree.GetRoot()->right)
			cout<<"right"<<endl;
	if(testTree.GetRoot()->left)
			cout<<"left"<<endl;
}
