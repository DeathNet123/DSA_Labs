#include<iostream>
using namespace std;

class Node
{
    public:
        Node *next;
        int data;
        Node(const int data = 0, class Node *next = NULL)
        {
            this->next = next;
            this->data = data;
        }
};

class LinkedList
{
    private:
        Node *first, *last;
    public:
        LinkedList() // Constructor..
        {
            first = new Node();
            last = NULL;
        }
        
        void new_node_start(const int data = 0)
        {
            Node *new_node = new Node(data);
            new_node -> next = first -> next;
            first -> next = new_node;
            if(last == NULL)
                last = new_node;
        } 
        
        void new_node_end(const int data = 0)
        {
            if(last == NULL)
                new_node_start(data);
            else
            {
                Node *new_node = new Node(data);
                new_node -> next = NULL;
                last-> next = new_node;
                last = new_node;
            }
            
        }
        
        void print(void)
        {
            if(last == NULL)
                cout<<"Empty String";
            else
                for(Node *idx = first -> next; idx != NULL; idx = idx -> next)
                {
                    cout<<idx -> data<<' ';
                }
            cout<<'\n';
        }

        void delete_node_start(void)
        {
            if(last != NULL)
            {
                Node *new_node = first -> next;
                first -> next = new_node-> next;
                delete new_node;

                if(first -> next == NULL)
                {
                    last = NULL;
                } 
                    
            }
        }

        void delete_node_end(void)
        {
            if(last != NULL)
            {
                if(first -> next == last)
                    delete_node_start();
                else
                {
                    Node *idx;
                    for(idx = first -> next; idx -> next != last; idx = idx -> next);
                    delete idx-> next;
                    idx -> next = NULL;
                    last = idx;
                }
            }
        }

        void add_node_k(const int key, const int value)
        {
            for(Node *idx = first -> next; idx != NULL; idx = idx -> next)
            {
                if(idx -> data == key)
                {
                    Node *new_node = new Node(value, idx -> next);
                    idx -> next = new_node;
                    if(idx == last) last = new_node;
                    break;
                }
            }
        }

        void delete_node(const int k)
        {
            Node *idx;
            for(idx = first; idx != NULL; idx = idx ->next)
            {
                if(idx != last)
                if(idx->next->data == k)
                {
                   Node * buff = idx->next;
                    idx->next = buff->next;
                    if(buff == last)
                        last = idx;
                    delete buff;
                    break;
                }
            }
        }
};

int main(void)
{
    Node *node = new Node;
    cout<<n->data
    LinkedList list;
    list.new_node_start(13);
    list.new_node_end(65);
    list.new_node_end(89);
    list.new_node_end(55);
    list.new_node_end(80);
    list.new_node_end(95);
    list.print();
   list.add_node_k(95, 99);
    list.print();
    list.delete_node_end();
    list.print();
    return 0;
}