#include <iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int data;
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
        LinkedList()
        {
            first = new Node(0);
            last = NULL;
        }

        void delete_end()
        {
            first->next = delete_end(first->next);
        }

        Node * delete_end(Node *node)
        {
            if(node == NULL)
            {
                return NULL;
            }
            if(node == last)
            {
                delete node;
                return NULL;
            }

            node->next = delete_end(node->next);
            if(node->next == NULL)
                last = node;
            return node;
        }

        Node* add_k_node(Node *node, int data)
        {
            if(node == NULL)
            {
                Node *new_node = new Node(data);
                last = new_node;
                return last;
            }

            if(node->data > data)
            {
                Node *new_node = new Node(data, node);
                return new_node;
            }
            node->next = add_k_node(node->next, data);
            return node;
        }

        void add_k_node(int data)
        {
            first->next = add_k_node(first->next, data);
        }

        void print(Node *node)
        {
            if(node == NULL)
                return;
            cout<<node->data<<' ';
                print(node->next);
        }
        void print()
        {
            if(last == NULL || first->next == NULL)
                cout<<"List is empty";
            else
                print(first->next);
                cout<<"\n";
        }

        Node* delete_k(Node *node, int data)
        {
            if(node == NULL)
            {
                return NULL;
            }
            if(node->data == data)
            {
                Node *temp = node->next;
                delete node;
                return temp;
            }
            node->next = delete_k(node->next, data);
            if(node->next == NULL)
                last = node;
            return node;
        }

        void delete_k(int data)
        {
            first->next = delete_k(first->next, data);
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
    list.add_k_node(0);
    list.add_k_node(-1);
    list.add_k_node(2);
    list.print();
    list.delete_end();
    list.delete_end();
    list.delete_end();
    list.add_k_node(13);
    list.add_k_node(15);
    list.add_k_node(12);
    list.delete_k(15);
    list.print();

    return 0;
}