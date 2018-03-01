#ifndef SORT_H
#define SORT_H
#include <iterator>
#include <iostream>
#include <algorithm> //for make_heap
template<class RandomIter>
RandomIter QSortPartition(RandomIter low,RandomIter high);
template<class T>
const T& __median(const T& a,const T& b,const T& c);
template<class RandomIter>
void QuickSort(RandomIter first,RandomIter last);

template<class RandomIter>
void HeapSort(RandomIter, RandomIter);
template<class RandomIter,class Diff>
void HeapAdjust(RandomIter,Diff,Diff);

/**
 *QuickSort
 */
template<class RandomIter>
void QuickSort(RandomIter first, RandomIter last){
	//如何判断first在last左边？
	if(first<last){
		RandomIter middle=QSortPartition(first,last);
		/**
		std::cout<<"before"<<std::endl;
		std::copy(first,last,std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
		**/
		QuickSort(first,middle);
		QuickSort(middle+1,last);//+1?
		/**
		std::cout<<"after"<<std::endl;
		std::copy(first,last,std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
		**/
	}
}
template<class RandomIter>
RandomIter QSortPartition(RandomIter low,RandomIter high){
	typedef typename std::iterator_traits<RandomIter>::value_type Type;
	Type pivotkey=__median(*low,*(high-1),*(low+(high-1-low)/2) )	;	
	high--;
	while(low<high){
		while(low<high){
			if(*high>*low)
				high--;
			else{
				std::swap(*low,*high);//swap or iter_swap?
				low++;
				break;
			}	
		}
		while(low<high){
			if( *low<*high)
				low++;
			else{
				std::swap(*low,*high);
				high--;
				break;
			}
		}
	}
	return low;
}
template<class T>
const T& __median(const T& a,const T& b,const T& c){	//why return const T&?
		if (a < b)
            if (b < c)        // a < b < c
                return b;
            else if (a < c)    // a < b, b >= c, a < c  -->     a < b <= c
                return c;
            else            // a < b, b >= c, a >= c    -->     c <= a < b
                return a;
        else if (a < c)        // c > a >= b
            return a;
        else if (b < c)        // a >= b, a >= c, b < c    -->   b < c <= a
            return c;
        else                // a >= b, a >= c, b >= c    -->      c<= b <= a
            return b;	
}

/**
 *HeapSort
 */
template<class RandomIter>
void HeapSort(RandomIter begin,RandomIter end){
	typedef typename std::iterator_traits<RandomIter>::value_type Value;
	typedef typename std::iterator_traits<RandomIter>::difference_type Diff;
	Diff len=end-begin;		// for other iter, use distance()
	if(len<2) return;  //can diff < int ? or if(end-begin<2)
	for(Diff i=(len-2)/2;i>=0;i--)
		HeapAdjust(begin,i,len);
	for(Diff i=len-1;i>=0;i--){
		std::swap(*begin,*(--end));
		HeapAdjust(begin,(Diff)0,i);
	}
	
	//or use make_heap instead
	/**64 ms for 1000 number,why so slow?
	for(int i=0;i<len;i++){
		std::make_heap(begin,end);
		std::swap(*begin,*(--end));
	}
	**/

}
template<class RandomIter, class Diff>
void HeapAdjust(RandomIter begin, Diff index, Diff len){	//使用 RandomIter end 有可能逾越？
	Diff next=2*index+1;
	if(next>=len)
		return;	
	RandomIter self=begin+index;
	RandomIter child=begin+next;
	if(next+1<len && *child<*(child+1)){
			child++;
			next++;
	}
	if(*self<*child){
		std::swap(*self,*child);
		HeapAdjust(begin,next,len);
	}

}



/**
 *MergeSort
 */


#endif
