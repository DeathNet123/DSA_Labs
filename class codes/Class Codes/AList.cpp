	#include <iostream>

using namespace std;

struct GEdge;//forward declaration

#define VISITED 1
#define NOTVISITED 0

struct GNode
{
	int nodeNo;
	GNode *nextNode;
	GEdge *firstEdge, *lastEdge;
	static int nodeCount;
	GNode (){
		nodeNo = nodeCount++;
		nextNode = NULL; 		
		lastEdge = firstEdge = NULL;
	}
};
int GNode::nodeCount=0;

struct GEdge
{
	GNode *nextNode; // This is data storage....
	GEdge *nextEdge;//This one is for link the linked list at the node 
	GEdge (GNode *n){
		nextNode = n;
		nextEdge = NULL;
	}
};
//Adjacency List has linked implementation of graph
//Useful for sparse graph especially
//Useful to add or remove node at run time
class AList{
	GNode *firstNode, *lastNode;
public:
	AList(){	firstNode = lastNode = NULL;	}
	void addNode(void) 
	{
		if (firstNode == NULL )	firstNode = lastNode = new GNode;
		else					lastNode = lastNode -> nextNode = new GNode;
	}
	void addEdge(int n1, int n2)
	{
		GNode *temp1 = firstNode, *temp2 = firstNode;
		for ( ; temp1 != NULL && temp1->nodeNo != n1 ; temp1 = temp1 -> nextNode);
		for ( ; temp2 != NULL && temp2->nodeNo != n2 ; temp2 = temp2 -> nextNode);
		if (temp1 != NULL && temp2 != NULL)
			if (temp1->firstEdge == NULL)	temp1->firstEdge = temp1->lastEdge = new GEdge(temp2);
			else							temp1->lastEdge = temp1->lastEdge -> nextEdge = new GEdge(temp2);
	}
	void show()
	{
		GNode *tempNode;
		GEdge *tempEdge;
		for ( tempNode = firstNode ; tempNode != NULL ; tempNode = tempNode -> nextNode ){
			cout << tempNode -> nodeNo << ':';
			for ( tempEdge = tempNode -> firstEdge ; tempEdge != NULL ; tempEdge = tempEdge -> nextEdge)
				cout << tempEdge->nextNode->nodeNo << ' ';
			cout << '\n'; 
		}
	}
	//Small dfs
	void dfs(GNode *tempNode, int *visited){
		if (tempNode != NULL && visited[ tempNode -> nodeNo ] != VISITED){
			visited[ tempNode -> nodeNo] = VISITED;
			cout << tempNode -> nodeNo << ' ';
			GEdge *tempEdge = tempNode -> firstEdge;
			//Visit neighboring/ connected nodes with recursive call
			for (int i=0 ; tempEdge != NULL && i < firstNode -> nodeCount ; tempEdge = tempEdge -> nextEdge)
				if ( visited [ tempEdge -> nextNode -> nodeNo] != VISITED )
					dfs( tempEdge -> nextNode, visited );
		}
	}
	//Capital DFS
	void dfs(int nodeNo)
	{
		GNode *tempNode = firstNode;
		int  *visited = new int [ firstNode -> nodeCount ];
		int i;
		for (i = 0 ; i < firstNode -> nodeCount ; i++ )	
				visited [i] = NOTVISITED;
		
		for (  ; tempNode->nodeNo != nodeNo; tempNode = tempNode -> nextNode);
		
		for ( i = 0 ; i < firstNode -> nodeCount  ; i++ )	
		{ 
			if ( tempNode == NULL)	tempNode = firstNode;
			if ( visited [ tempNode -> nodeNo ] == NOTVISITED )
			{
				dfs( tempNode, visited );
				cout << '\n' ;
			}
			if (i == 0 || tempNode != firstNode)	tempNode = tempNode -> nextNode;
		}
		delete []visited;
	}
};

int main(){
	AList list;
	list.addNode();
	list.addNode();
	list.addNode();
	list.addNode();
	list.addNode();
	list.addNode();
	list.addNode();
	list.addEdge(0,2);
	list.addEdge(0,3);
	list.addEdge(0,4);
	list.addEdge(1,0);
	list.addEdge(1,3);
	list.addEdge(2,4);
	list.addEdge(3,0);
	list.addEdge(4,6);
	list.addEdge(4,1);
	list.addEdge(4,2);
	list.addEdge(4,3);
	list.addEdge(6,5);
	//list.show();
	//cout << '\n';
	list.dfs(0);
	cout << '\n';
	list.dfs(2);
	return 0;
}
