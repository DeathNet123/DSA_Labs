#include <iostream>

using namespace std;

class AVLNode
{
	public:
		int data;
		int height; // this is the extra feature of this AVL NODE it is set in check and balance node ..
		AVLNode *left, *right;
		AVLNode (int d, AVLNode *left=NULL, AVLNode *right=NULL)
		{
			data = d;
			this->left = left;
			this->right = right;
			height = 0;
		}
};
class AVLTree
{	//Linked Implementation
	AVLNode *root;
public:
	AVLTree()
	{	
		root = NULL;
	}
	int findHeight(AVLNode *temp)
	{
		if (temp == NULL)	return -1;
		return temp->height;
	}
	int findHeight() //This function will find height of complete tree...
	{
		if (root == NULL)		return -1;
		int lh = findHeight (root->left);
		int rh = findHeight (root->right);
		if (lh>rh)	return lh+1;
		else		return rh+1;
	}	
	AVLNode* rotateRight(AVLNode *temp)
	{
		AVLNode *tempLeft = temp->left;
		temp->left = tempLeft -> right;
 		tempLeft->right = temp;
 		setHeight(temp); 
		return tempLeft; 
	}	
	AVLNode* rotateLeft(AVLNode *temp)
	{
		AVLNode *tempRight = temp->right;
		temp->right = tempRight -> left;
		tempRight->left = temp;
 		setHeight(temp); 
		return tempRight; 
	}
	void setHeight(AVLNode *temp)
	{
		int lH = findHeight(temp->left);
		int rH = findHeight(temp->right);
		if (lH>rH)	temp->height = lH + 1;
		else 		temp->height =  rH + 1;
	}
	AVLNode* checkAndBalance(AVLNode *temp)
	{
		int lH = findHeight(temp->left);
		int rH = findHeight(temp->right);
		int lH1, rH1;
		if (lH-rH >=2 ) //it means the left height is greater than the right height
		{

			lH1 = findHeight(temp->left->left);
			rH1 = findHeight(temp->left->right);
			if (lH1-rH1 >= 0)
				temp = rotateRight(temp);//Single Rotation
			else

			{
				//Double Rotation
				temp->left = rotateLeft(temp->left);
				temp = rotateRight(temp);
			} 
		}
		else if (rH-lH>=2)
		{
			lH1 = findHeight(temp->right->left);
			rH1 = findHeight(temp->right->right);
			if (rH1-lH1 >= 0)//Sinle Rotation
				temp = rotateLeft(temp);
			else
			{			//Double Rotation

				temp->right = rotateRight(temp->right);
				temp = rotateLeft(temp);
			}
		}
		setHeight(temp);
		return temp;
	}
	AVLNode* insert(int d, AVLNode *temp)
	{
		if (temp==NULL)
		{
			AVLNode *t = new AVLNode(d);
			return t;
		}
		if (temp->data > d)
			temp -> left = insert (d, temp->left);
		else
			temp -> right = insert (d, temp->right);
		return checkAndBalance(temp);
	}
	//Wrapper Function
	void insert(int d)
	{
		root = insert (d, root);
	}
	void preorder(AVLNode *temp)
	{
		if (temp!=NULL)
		{
			cout << temp -> data << ' ';
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	void preorder(void)
	{
		preorder(root);
		cout << '\n';
	}
	void inorder(AVLNode *temp)
	{
		if (temp!=NULL)
		{
			inorder(temp->left);
			cout << temp -> data << ' ';
			inorder(temp->right);
		}
	}
	void inorder()
	{
		inorder(root);
		cout << '\n';
	}
	bool search(int d, AVLNode *temp)
	{
		if (temp==NULL)		return false;
		if (temp->data == d)	return true;
		if (temp->data > d)		return search(d, temp->left);
		return search(d, temp->right);
	}
	bool search(int d)
	{
		return search(d, root);
	}
	//left most node address required
	AVLNode* leftMost(AVLNode *temp)
	{
		if (temp->left==NULL)	return temp;
		return leftMost(temp->left);	
	}
	//Right most node address required
	AVLNode* rightMost(AVLNode *temp)
	{
		if (temp->right==NULL)	return temp;
		return rightMost(temp->right);	
	}
	AVLNode* deleteNode(int d, AVLNode *temp)
	{
		AVLNode *next;
		if 		(temp==NULL)		return NULL;
		else if (temp->data>d)	temp->left = deleteNode(d, temp->left);
		else if (temp->data<d)	temp->right = deleteNode(d, temp->right);
		else
		{//Node found and to be deleted
			if (temp->left == NULL && temp->right == NULL)
			{
				delete temp;
				return NULL;
			} 	
			else if (temp->left == NULL)
			{
				next = temp->right;
				delete temp;
				temp = next;
			} 	
			else if (temp->right == NULL)
			{
				next = temp->left;
				delete temp;
				temp = next;
			}
			else
			{
				next = rightMost (temp->left);
				temp->data = next->data;
				temp->left = deleteNode(next->data, temp->left);
			}			
		}
		return checkAndBalance(temp);
	}
	void cane()
	{
		cout<<root->height;
	}
	void deleteNode(int d)
	{
		root = deleteNode (d, root);
	}
};

int main(void)
{
	AVLTree tree;
	tree.insert(23);

	tree.insert(20);

	tree.insert(25);
	tree.insert(24);
	tree.insert(30);
	tree.insert(26);
	/*tree.insert(15);
	/*tree.insert(35);
	tree.insert(45);
	tree.insert(65);
	tree.inorder(); tree.preorder(); 
	cout << "Height:"	<< tree.findHeight() << '\n';	
	tree.insert(85);
	tree.inorder(); tree.preorder(); 
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.insert(95);
	tree.inorder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.insert(28);
	tree.insert(48);
	tree.insert(68);
	tree.insert(38);
	tree.insert(98);
	//tree.insert(18);
	tree.insert(78);
	tree.inorder(); tree.preorder(); 
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.deleteNode(5); 
	tree.inorder();	 tree.preorder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.deleteNode(78); 
	tree.deleteNode(68); 
	tree.inorder();	 tree.preorder();
	cout << "Height:"	<< tree.findHeight() << '\n';
	tree.deleteNode(85); 
	tree.deleteNode(98); 
	tree.inorder();	 tree.preorder();
	cout << "Height:"	<< tree.findHeight() << '\n';	*/
	return 0;
}
