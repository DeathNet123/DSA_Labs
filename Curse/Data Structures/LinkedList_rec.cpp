#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(int data = 0, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
};

class LinkedList
{
    private:
        Node *first, *last;

        void delinked(Node *node)
        {
            if(node == NULL)
                return;
            delinked(node->next);
                delete node;
        }
    public:
        LinkedList(void)
        {
            first = new Node(0);
            last = NULL;
        }

        void add_node_start(int data)
        {
            Node *node = new Node(data, first -> next);
            first -> next = node;
            if(last == NULL)
                last = node;
        }

        void add_node_end(int data)
        {
            if(last == NULL)
            {
                add_node_start(data);
            }
            else
            {
                Node *node = new Node(data);
                last->next = node;
                last = node;
            }
        }

        Node* add_node_k(Node *node, int data)
        {
            if(node == NULL)
            {
                last = new Node(data); // basically we created new last and then throw it back even if there is no element in array it will work..
                return last;
            }
            if(node->data > data)
            {
                Node *new_node = new Node(data, node->next);
                return new_node;
            }
            node->next = add_node_k(node->next, data);
            return node;
        }

        void add_node_k(int data)
        {
            first->next = add_node_k(first->next, data);
        }
        void delete_node_start(void)
        {
            if(last != NULL)
            {
                Node * temp = first->next;
                first->next = temp -> next;
                if(temp == last)
                {
                    last = NULL;
                }
                delete temp;
            }

        }
        
        Node* delete_node_end(Node *node)
        {
            if(node == NULL)
                return NULL;
            if(node == last )
            {
                delete last;
                return NULL;
            }
            else
            {
                node->next = delete_node_end(node->next);
                if(node->next == NULL)
                    last = node;
            }
            return node;
        }
        void delete_node_end(void)
        {
                first->next = delete_node_end(first->next);
                if(first->next == NULL)
                {
                    last = NULL;
                }
                    
        }

        Node* delete_node_k(Node *node, int key)
        {
            if(node == NULL)
                return NULL;
            if(node->data == key)
            {
                Node *temp = node -> next;
                delete node;
                return temp;
            }
            else
            {
                node->next = delete_node_k(node->next, key);
                if(node->next == NULL) last = node;
            }
            return node;
        }

        void delete_node_k(int key)
        {
            first->next = delete_node_k(first->next, key);
            if(first->next == NULL)
                last = NULL;
        }

        void print(Node *node)
        {
            if(node == NULL)
                return;
            else
                cout<<node->data<<' ';
                print(node->next);
        }
        void print()
        {
            
            if(last == NULL)
                cout<<"List is empty..";
            else if(last != NULL)
                print(first->next);
            cout<<'\n';
        }
        
        ~LinkedList()
        {
            delinked(first->next);
            last = NULL;
        }
};

int main(void)
{
    LinkedList list;
    list.print();
    list.add_node_k(0);
    list.add_node_k(1);
    list.add_node_start(-1);
    list.add_node_end(2);
    list.add_node_end(3);
    list.add_node_end(4);
    list.print();
    list.delete_node_k(4);
    list.print();
    list.add_node_end(4);
    list.print(); 
    
   
    return 0;
}