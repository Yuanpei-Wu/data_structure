#include <iostream>
#include <vector>
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
			Array InOrderTraversal(){
				
			}
			Array PreOrderTraversal();
			Array PostOrderTraversal();
			/* 
			 *generate bst from inorder array
			 *return root node if success
			 *return NULL if fail
			 */
			Node* GenFromInOrderArray(Array initial ,int step=-1){
				if(GenFromInOrderArray(initial,++step)!=NULL )
					return NULL;
			}
			/*
			 *
			 *
			 */
			Node* GenFromPreOrderArray(Array);
			Node* GenFromPostOrderArray(Array);

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

			bool HasSubTree(Node*);

		
};

