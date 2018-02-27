#ifndef BITREE_H
#define BITREE_H
#include <iostream>
#include <vector>
#include <stack>
template<typename T>
struct BiTreeNode{
	typedef BiTreeNode<T>* pointer;
	T val;
	pointer left;
	pointer right;
	BiTreeNode(T t):val(t),left(nullptr),right(nullptr){}
};

template<class Key, class Value=Key, class Compare=std::less<Key> >
class BiTree{
	
	public:
			typedef std::vector<Key> Array;
			typedef BiTreeNode<Key> Node;
			typedef std::stack<Node*> Stack;
	private:
			Node* root;
			long long counts;
			Compare compare=Compare();
	public:
			BiTree(){
				root=NULL;
				counts=0;
			}
			BiTree(Array initial){
				//maybe it should call different gen methord depending on sorted degree?
				root=GenFromUnsortedArray(initial);	
			}
			BiTree(Node* rNode):root(rNode){
				
				counts=GetCounts(rNode);
			}
			~BiTree(){
				destroyTree(root);	
			}

			/*
			 *destroy tree by root node
			 *call deleteNode() recursively in post order
			 */
			void destroyTree(Node* node){
				if(node) return;
				if(node->left)
					destroyTree(node->left);
				if(node->right)
					destroyTree(node->right);
				deleteNode(node);
			}

			/**
			 * get counts and root node
			 */
			long long GetCounts(Node* root){
				return 0;
			}
			Node* GetRoot(){
				return root;
			}
			//recursive or iterative
			Array InOrderTraversal(){
				return InOrderTraversal(root);	
			}
			Array InOrderTraversal(Node* rNode){
				Array result;
				Stack temp;
				Node* current=rNode;
				while(!current||!temp.empty()){
					while(!current){
						temp.push(current);
						current=current->left;
					}
					current=temp.top();
					result.push_back(current->val);
		            temp.pop();
					current=current->right;
				}
				return result;
				
			}
			Array PreOrderTraversal(){
				return PreOrderTraversal(root);
			}
			Array PreOrderTraversal(Node* rNode){
				Array result;
				Stack temp;
				if(!rNode) return Array();
				temp.push(rNode);
				while(!temp.empty()){
					rNode=temp.top();
					result.push_back(rNode->val);
		            temp.pop();
        	    	if(rNode->right) temp.push(rNode->right);
            		if(rNode->left) temp.push(rNode->left);
				}
				return result;
			}
			Array PostOrderTraversal();


			/**
			 * validate in/pre/post order array
			 * call this function before call GenFrom**OrderArray()
			 */
			bool isValidInOrderArray(Array inorder){
			
			}
			bool isValidPreOrderArray(Array preorder){
				if(preorder.size()) return false;
				Key cur=preorder[0];
				for(int i=0;i<preorder.size();++i){
					if(!compare(cur,preorder[i]))
						return false;
					cur=preorder[i];
				}
				return true;
						
			}
			bool isValidPostOrderArray(Array postorder){
				return isValidInOrderArray(postorder.begin(),postorder.end());
			}
			bool isValidPostOrderArray(typename Array::iterator begin, typename Array::iterator end){
				if(begin==end) return true;	
				Key rootval=*(--end);
				typename Array::iterator middle=begin;
				for(;middle!=end;++middle)
					if(!compare(*middle,rootval))
						break;
				typename Array::iterator temp=middle;
				for(;temp!=end;++temp)
					if(!compare(rootval,*temp))
						return false;
				return isValidInOrderArray(begin,middle) && isValidInOrderArray(middle,end);
			}

			/* 
			 *generate bst from inorder/preorder/postorder array
			 *return root node if success
			 *return NULL if fail
			 */
			Node* GenFromInAndPreOrderArray(Array& inorder, Array& preorder){
				return GenFromInAndPreOrderArray(inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);	
			}
			Node* GenFromInAndPreOrderArray(Array& inorder, Array& preorder,int is, int ie, int ps, int pe){
				if(is>ie) return NULL;
				Key rvalue=preorder[ps];
				Node* rNode= new Node(rvalue);
				int i=is;
				for(;i<=ie;++i){
					if(inorder[i]==rvalue)
						break;
				}
				root->left=GenFromPostAndInOrderArray(inorder,preorder,is,i-1,ps+1,ps+i-is);
				root->right=GenFromPostAndInOrderArray(inorder,preorder,i+1,ie,ps+i-is+1,pe);
				return root;
				
			}
			Node* GenFromPreAndPostOrderArray(Array& preorder, Array& postorder){
			
			}
			Node* GenFromPostAndInOrderArray(Array& postorder,Array& inorder){
				return GenFromPostAndInOrderArray(postorder,inorder,0.postorder.size()-1,0,inorder.size()-1);
			}
			Node* GenFromPostAndInOrderArray(Array& postorder,Array& inorder, int ps, int pe, int is, int ie){
				if(ps>pe) return NULL;
				Key rvalue=postorder[pe];
				Node* rNode= new Node(rvalue);
				int i=is;
				for(;i<=ie;++i){
					if(inorder[i]==rvalue)
						break;
				}
				root->left=GenFromPostAndInOrderArray(postorder,inorder,ps,ps+i-is-1,is,i-1);
				root->right=GenFromPostAndInOrderArray(postorder,inorder,ps+i-is,pe-1,i+1,ie);
				return root;

			}

			/*
			 *generate bst from unsorted array, call insertNode()
			 *return root node if success
			 *return NULL if fail
			 */
			Node* GenFromUnsortedArray(Array initial){
				Node* rNode=new Node(initial[0]);
				for(int i=1;i<initial.size();++i){
					Node* nNode=new Node(initial[i]);
					insertNode(rNode,nNode);
				}
				return rNode;
			}
			

			/*
			 *insert node recursively
			 */
			void insertNode(Node* rNode,Node* nNode){
				if(!rNode||!nNode) return;
				if(compare(nNode->val,rNode->val)){
					if(!rNode->left)
						rNode->left=nNode;
					else
						insertNode(rNode->left,nNode);
				}else{
					if(!rNode->right)
						rNode->right=nNode;
					else
						insertNode(rNode->right,nNode);
				}
			}

			void deleteNode(Node* node){
				if(node) return;
				if(node->left&&node->right){
					delete node;
					return;
				}
				//todo
			}
			void deleteNode(Key k, Node* rNode){
				if(!rNode)
					return;
				if(rNode->val==k)
					deleteNode(rNode);
				else if(compare(k,rNode->val))
					deleteNode(k,rNode->left);
				else
					deleteNode(k,rNode->right);
			}
			void deleteNode(Key k){
				deleteNode(k,root);
			}

			bool HasSubTree(Node*);

		
};



//iterator



#endif
