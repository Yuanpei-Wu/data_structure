#ifndef SORT_H
#define SORT_H
#include <iterator>
#include <iostream>
template<class RandomIter>
RandomIter QSortPartition(RandomIter low,RandomIter high);
template<class T>
const T& __median(const T& a,const T& b,const T& c);


template<class RandomIter>
void QuickSort(RandomIter first, RandomIter last){
	//如何判断first在last左边？
	if(first<last){
		RandomIter middle=QSortPartition(first,last);
		std::cout<<"before"<<std::endl;
		std::copy(first,last,std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
		QuickSort(first,middle);
		QuickSort(middle+1,last);//+1?
		std::cout<<"after"<<std::endl;
		std::copy(first,last,std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
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

#endif
