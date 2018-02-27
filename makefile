kmp:kmp.cpp
	g++ -std=c++11 -g -o ds_kmp kmp.cpp
btree:binary_tree_test.cpp binary_tree.h
	g++ -std=c++11 -g -o ds_btree binary_tree_test.cpp
sort:sort_test.cpp sort.h
	g++ -std=c++11 -g -o ds_sort sort_test.cpp
clean:
	rm ds* 
clear:
	rm *~
