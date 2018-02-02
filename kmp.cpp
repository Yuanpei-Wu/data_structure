#include <string>
#include <iostream>
#include <vector>
#include <iterator> 
using namespace std;
typedef vector<int> IntArray;
IntArray get_partial_match(string t){
	int len=t.length();


	IntArray result(len);
	int k=-1,j=0;
	result[0]=-1;
	while(j<len-1){		//注意是len-1，否则跳不出循环。因为要计算的是每个节点之前的最长前缀后缀长度，最后一个节点的最长前缀后缀和最后一个节点的值没有关系
		if(k==-1||t[k]==t[j]){
			++k;
			++j;
			result[j]=k;
		}
		else
			k=result[k];
//		cout<<"j:"j<<" k:"<<k<<endl;
	}
	//copy(result.begin(),result.end(),ostream_iterator<int>(cout," "));
	//cout<<endl;
	return result;
}
int KMP(string s, string t ){
	int i=0,j=0;
	IntArray next=get_partial_match(t);
	int s_len=s.length(),t_len=t.length();	
	while(i<s_len&&j<t_len){	//这里如果像下一行那样写会在 i=5 j=-1 时跳出循环，因为小于0的int值不能和size_t比较
//	while(i<s.length() && j<t.length() ){
		if((j<0)||t[j]==s[i]){	//next[0]=-1
			++j;
			++i;
		}else{
			j=next[j];	//j退回某个位置继续匹配
		}
		cout<<"i:"<<i<<" j:"<<j<<endl;
	}
	//若完全匹配，则最后跳出while循环是j=t.length()
	if(j==t.length())
		return i-t.length();
	else
		return -1;

}

int main(){
	string t="abcabx";
	string s="abcabefgabcabx";
	int i=KMP(s,t);
	cout<<"result:"<<i<<endl;
}
