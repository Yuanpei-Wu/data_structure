#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <iterator>
#include "sort.h"
using namespace std;

int main(){
	vector<int> to_be_sorted;
	srand((unsigned)time(NULL));
	for(int i=0;i<10;++i){
		to_be_sorted.push_back(rand()%10);
	}

	cout<<"origin array:";
	copy(to_be_sorted.begin(),to_be_sorted.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	vector<int> test={4,3,2,1,0};
	clock_t begin=clock();
//	QuickSort(test.begin(),test.end());	
	QuickSort(to_be_sorted.begin(),to_be_sorted.end());
	clock_t end=clock();
	
	//cout<<"use time: "<<1000*((double)begin-end)/CLOCKS_PER_SEC<<" ms"<<endl;
	cout<<"sorted array:";
	copy(to_be_sorted.begin(),to_be_sorted.end(),ostream_iterator<int>(cout," "));
//	copy(test.begin(),test.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
}
