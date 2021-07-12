#include <iostream>
#include <queue>
using namespace std;

class BTNode
{
	public:
		int data;
		BTNode *left, *right;
		BTNode (int d = 0, BTNode *left=NULL, BTNode *right=NULL){
			data = d;
			this->left = left;
			this->right = right;
		}
};
class BTree
{	//Linked Implementation
	BTNode *root;
public:
	BTree()
	{	
		root = NULL;
	}
	BTNode* insert(int d, BTNode *temp)
	{
		if (temp==NULL)
		{
			BTNode *t = new BTNode(d);
			return t;
		}
		if (temp->data > d)
			temp -> left = insert (d, temp->left);
		else
			temp -> right = insert (d, temp->right);
		return temp;
	}
	//Wrapper Function
	void insert(int d)
	{
		root = insert (d, root);
	}
	void inorder(BTNode *temp)
	{
		if (temp!=NULL){
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

	void postorder(BTNode *temp)
	{
		if (temp!=NULL)
		{
			cout << temp -> data << ' ';
			postorder(temp->left);
			postorder(temp->right);
		}
	}
	void postorder()
	{
		postorder(root);
		cout<<'\n';
	}
	bool search(int d, BTNode *temp)
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
	BTNode* leftMost(BTNode *temp)
	{
		if (temp->left==NULL)	return temp;
		return leftMost(temp->left);	
	}
	//Right most node address required
	BTNode* rightMost(BTNode *temp)
	{
		if (temp->right==NULL)	return temp;
		return rightMost(temp->right);	
	}
	void rightMost()
	{
		BTNode *temp = rightMost(root);
		cout<<temp->data;
	}
	BTNode* deleteNode(int d, BTNode *temp)
	{
		BTNode *next;
		
		if (temp==NULL)		
			return NULL;
		else if (temp->data > d)	
			temp->left = deleteNode(d, temp->left);
		else if (temp->data < d)	
			temp->right = deleteNode(d, temp->right);
		else
		{//Node found and to be deleted
			if (temp->left == NULL && temp->right == NULL) // it means the node is leaf node
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
			return temp;
		}
		return temp;
	}
	void deleteNode(int d)
	{
		root = deleteNode (d, root);
	}
	int findHeight(BTNode *temp)
	{
		if (temp==NULL)	return -1;
		
		int lh = findHeight(temp->left);
		int rh = findHeight(temp->right);
		
		if (lh>rh)	return lh+1;
		else		return rh+1;
	}
	int findHeight()
	{
		return findHeight(root);
	}
	int depth(BTNode *node)
	{
		int d = 0;
		while(node != NULL)
		{
			node = node->left;
			d++;
		}
		return d;
			
	}
	int depth(void)
	{
		return depth(root);
	}

	bool is_perfect(BTNode *node , int d, int level = 0)
	{
		if(node == NULL)
			return true;
		if(node-> left == NULL && node->right == NULL)
			return (d == level + 1);
		if(node-> right == NULL || node->left == NULL)
			return false;
		return is_perfect(node->left, d, level + 1) && is_perfect(node->right, d, level + 1);
	}
	bool is_perfect()
	{
		int d = depth(root);
		return is_perfect(root, d, 0);
	}

BTNode* searchNode(BTNode *root, char data)
{
    if(root == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
	if(root-> data == data)
		return root;
    queue<BTNode*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode *temp = q.front();
        q.pop();

        if(temp->left != NULL)
		{
			q.push(temp->left);
        if(temp->left->data == data)
			return temp;
		}
        if(temp->right != NULL)
		{
			q.push(temp->right);
			if(temp->right->data == data)
			return temp;
		}
            
    }

    cout << "Node not found\n";
}
};

int main()
{
	BTree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(6);
	tree.insert(2);
	tree.insert(4);
	cout<<tree.findHeight()<<'\n';
	return 0;
}
/*https://www.quora.com/How-can-I-improve-my-programming-skills-18/answers/140798300*/