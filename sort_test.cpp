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
	vector<int> back2=to_be_sorted;
	vector<int> back3=to_be_sorted;
	vector<int> back4=to_be_sorted;
	clock_t quick_sort_begin=clock();
//	QuickSort(test.begin(),test.end());	
	QuickSort(back1.begin(),back1.end());
	clock_t quick_sort_end=clock();
	cout<<"quick sort use time: "<<1000*((double)quick_sort_end-quick_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;

	clock_t heap_sort_begin=clock();
	HeapSort(back2.begin(),back2.end());
	clock_t heap_sort_end=clock();
	cout<<"heap sort use time: "<<1000*((double)heap_sort_end-heap_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;

	clock_t stl_sort_begin=clock();
	sort(back3.begin(),back3.end());
	clock_t stl_sort_end=clock();
	cout<<"stl sort use time: "<<1000*((double)stl_sort_end-stl_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;
	
	clock_t merge_sort_begin=clock();
	MergeSort(back4.begin(),back4.end());
	clock_t merge_sort_end=clock();
	cout<<"merge sort use time: "<<1000*((double)merge_sort_end-merge_sort_begin)/CLOCKS_PER_SEC<<" ms"<<endl;
	

	
	//for duplicate elements
	vector<int> to_be_sorted2;
	for(int i=0;i<10000;++i){
		to_be_sorted.push_back(rand()%100);
	}
	

				
//	cout<<"sorted array:";
//	copy(to_be_sorted.begin(),to_be_sorted.end(),ostream_iterator<int>(cout," "));
//	MergeSort(test.begin(),test.end());
//	copy(test.begin(),test.end(),ostream_iterator<int>(cout," "));
//	cout<<endl;
}
