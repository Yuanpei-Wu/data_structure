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
	for(int i=0;i<10000;++i){
		to_be_sorted.push_back(rand()%10000);
	}

	/**
	cout<<"origin array:";
	copy(to_be_sorted.begin(),to_be_sorted.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	**/

	vector<int> test={4,3,2,1,0};
	
	vector<int> back1=to_be_sorted;
	clock_t quick_sort_begin=clock();
//	QuickSort(test.begin(),test.end());	
	QuickSort(back1.begin(),back1.end());
	clock_t quick_sort_end=clock();
	cout<<"quick sort use time: "<<1000*((double)quick_sort_end-quick_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;

	clock_t heap_sort_begin=clock();
	HeapSort(to_be_sorted.begin(),to_be_sorted.end());
	clock_t heap_sort_end=clock();
	
	cout<<"heap sort use time: "<<1000*((double)heap_sort_end-heap_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;
	cout<<"sorted array:";
//	copy(to_be_sorted.begin(),to_be_sorted.end(),ostream_iterator<int>(cout," "));
//	copy(test.begin(),test.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
}
