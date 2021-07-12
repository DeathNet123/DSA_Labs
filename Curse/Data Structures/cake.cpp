#include <iostream>
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
    public:
        LinkedList()
        {
            first = new Node(0);
            last = NULL;
        }
        Node * add_k_node(Node *node, int data)
        {
            if(node == NULL)
            {
                last = new Node(data);
                return last;
            }
            if(node->data > data)
            {
                Node *new_node = new Node(data, node);
                return new_node;
            }
            node ->next = add_k_node(node->next, data);
            return node;
        }

        void add_k_node(int data)
        {
            first->next = add_k_node(first->next, data);
        }
        
        Node* delete_end(Node *node)
        {
            if(node == NULL)
                return node;
            if(node == last)
            {
                delete last;
                return NULL;
            }

            node->next = delete_end(node->next);
                if(node->next == NULL)
                    last = node;
            return node;

        }
        void delete_end(void)
        {
            first->next = delete_end(first->next);
        }
        Node* delete_k(Node *node, int data)
        {
            if(node == NULL)
                return NULL;
            if(node->data == data)
            {
                Node *new_node = node->next;
                delete node;
                return new_node;
            }

            node->next = delete_k(node->next, data);
                if(node->next == NULL)
                    last = node;
            return node;
        }
        void delete_k(int data)
        {
            first->next = delete_k(first->next);
            
        }
        void print(Node *node)
        {
            if(node == NULL)
                return;
            cout<<node->data<<' ';
            print(node->next);
        }
        void print(void)
        {
            print(first->next);
            cout<<'\n';
        }
};

int main(void)
{
    LinkedList list;
    list.add_k_node(0);
    list.add_k_node(-1);
    list.add_k_node(1);
    list.add_k_node(2);
    list.print();
    list.delete_end();
    list.print();
    list.add_k_node(2);
    list.print();
    return 0;
}