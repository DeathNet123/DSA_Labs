#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class BST
{
	struct BTNode
	{
		int data;
		BTNode *left, *right;
		BTNode(int data, BTNode *left=NULL, BTNode *right=NULL){
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BST()
	{	
		root = NULL;	
	}
	BTNode* add(int d, BTNode *t)
	{	
		if (t==NULL)	return new BTNode(d);
		if (t->data>d) 		t->left = add(d, t->left);
		else if (t->data<d) t->right = add(d, t->right);
		return t;	
	}
	void add(int d)
	{	
		root = add(d, root);
	}
	void inorder(BTNode* t)
	{
		if (t!=NULL)
		{
			inorder(t->left);
			cout << t->data << ' ';
			inorder(t->right);
		}
	}
	void inorder()
	{
		inorder(root);
		cout << '\n';
	}
	void preorder(BTNode* t)
	{
		if (t!=NULL){
			cout << t->data << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder()
	{
		preorder(root);
		cout << '\n';
	}
	int countNodes(BTNode *t)
	{
		//Count nodes as we calculate height, instead of finding max, add left and right
		if(t == NULL)
			return -1;
		int lh = countNodes(t->left);
		int rh = countNodes(t->right);

		return lh + rh + 2;
	}

	int countNodes_rapper(BTNode *t)
	{
		return countNodes(t) + 1;
	}
	int inOrderArray(BTNode *t, int *array, int index)
	{
		if (t!=NULL)
		{
			//call function for left of tree and get index
			index = inOrderArray(t->left, array, index);
			array[index] = t->data;
			index = inOrderArray(t->right, array, index + 1);
			//store value of current node in array according to index
			//call function for right of tree with index+1 and get index
			return index;
		}
		return index;
	}
	void addBinarySearch(int *array, int start, int end, int total)
	{
		if (start<=end)
		{
			//calculate middle index
			int middle = (start + end) / 2;
			if(middle < total)
			add(array[middle]);
			//call same function for left sub-array
			addBinarySearch(array, start, middle - 1, total);
			//call same function for right sub-array
			addBinarySearch(array, middle + 1, end, total);
		}		
	}
	void checkAndBalanceTree(int countNodes)
	{
		//declare arrya of approriate size .......... idk what arrya is that is why i am taking array...
		int *array = new int[countNodes + 1];
		//call inorderArray with appropriate arguments
		int index = inOrderArray(root, array, 1);
		//remove BST
		removeNodes(root);
		root = NULL;
		//call addBinarySearch with appropriate arguments..
		addBinarySearch(array, 1, countNodes + 1, countNodes + 1);
	}
	void checkAndBalance()
	{
		//get left count at root
		int left_count = countNodes_rapper(root->left);
		//get right count at root
		int right_count = countNodes_rapper(root->right);
		//get difference
		int difference = left_count - right_count;
		//if difference is more then one......
		if(difference <= -2 || difference >= 2)
		{
			//call checkAndBalanceTree with appropriate arguments;
			checkAndBalanceTree(left_count + right_count + 1);
		}
			
	}
	void removeNodes(BTNode* t)
	{
		if(t == NULL)
			return;
		removeNodes(t->left);
		BTNode *temp = t->right;
		delete t;
		removeNodes(temp);
	}
	~BST()
	{
		removeNodes(root);
	}
};

int main(){
	/*srand(time(0));
	BST tree;
	for (int i=0;i<20;i++)
		tree.add(rand()%900+100);
	tree.preorder();
	tree.inorder();
	tree.checkAndBalance();
	tree.preorder();
	tree.inorder();*/
	BST tree;
	tree.add(5);
	tree.add(4);
	tree.add(10);
	tree.preorder();
	tree.inorder();
	tree.checkAndBalance();
	tree.preorder();
	tree.inorder();
	
	return 0;
}
