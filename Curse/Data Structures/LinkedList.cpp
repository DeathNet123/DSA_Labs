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

        void delinked(Node *idx) //helping function for destructer  o(n)
        {
            if(idx != NULL)
            delinked(idx->next);
                delete idx;
        }
    public:
        LinkedList(void)
        {
            first = new Node(0);
            last = NULL;
        }
        
        void add_node_start(int data) // add node at start.. o(1)
        {
            Node *new_node = new Node(data, first->next);
            first-> next = new_node;
            if(last == NULL)
                last = new_node;
        }

        void add_node_end(int data) // add node at the end of list.. 0(1)
        {
            if(last == NULL)
                add_node_start(data);
            else
            {
                Node *new_node = new Node(data);
                last->next = new_node;
                last = new_node;
            }
        }

        void add_node_after_k(int data) //this is for the sorted list only will add node at suitable location .. time complexity o(n)
        {
            if(last == NULL)
            {
                add_node_start(data);
                return;
            }
            Node *idx = first;
            for(; idx != NULL; idx = idx -> next)
            {
                if(idx != last)
                {
                    if(idx -> next -> data >= data)
                    {
                        Node *new_node = new Node(data, idx -> next);
                        idx -> next = new_node;
                        return;
                        
                    }
                }
                else
                {
                    add_node_end(data);
                    return;
                } 
            }
        }

        void delete_node_start(void) //delete node from the start o(1)
        {
            if(last != NULL)
            {
                Node *temp = first -> next;
                first -> next = temp -> next;
                if(temp == last)
                    last = NULL;
                delete temp;
            }
        }

        void delete_node_end(void) // delete node from the end o(n)
        {
            if(first-> next == last)
                delete_node_start();
            if(last != NULL)
            {
                Node *idx = first->next;
                for(; idx->next != last; idx = idx->next);
                    delete last;
                    last = idx;
                    last->next = NULL;
            }
                
        }

        void delete_node_k(int key) // delete the matching based on data... o(n)
        {
            if(first->next->data == key)
            {
                delete_node_start();
                return;
            }
            if(last != NULL)
            {
                
                Node *idx = first -> next;
                for(; idx != NULL; idx = idx -> next)
                {
                    if(idx != last)
                    {
                        if(idx -> next -> data == key)
                        {
                            Node *temp = idx -> next;
                            idx -> next = temp-> next;
                            if(temp == last)
                                last = idx;
                            delete temp;
                            last->next = NULL;
                        }
                    }
                }
            }
        }

        void delete_negative(int coin = 0) // delete the negative node from the list o(n)
        {
            if(coin == 2)
                return;
            if(first ->next == last && last ->data < 0)
            {
                delete_node_start();
                return;
            }
            for(Node *idx = first; idx != NULL; idx = idx->next)
            {
                if(idx != last)
                {
                    if(idx -> next -> data < 0)
                    {
                        Node *temp = idx -> next;
                        idx-> next = temp -> next;
                        if(temp == last)
                            last = idx;
                        delete temp;
                        last->next = NULL;    
                    }
        
                }                
            }
            delete_negative(coin + 1);
           
        }

        void print_list(void)
        {

            if(last == NULL)
                cout<<"List is empty";
            else
            {
                Node *idx = first ->next;
                
                for(; idx != NULL; idx = idx->next)
                {
                    cout<<idx->data<<' ';
                }
            }
            cout<<'\n';
        }

        Node* get_node(int kdx) //return node at certain index.. o(n)
        {

            Node *buffer = NULL;
            if(last != NULL)
            {
                Node *idx = first->next;
                for(; idx != NULL && kdx > 0; idx = idx->next, kdx--)
                {
                    cout<<idx->data<<' ';
                }
                    buffer = idx;
                    return buffer;
            }
        }


        ~LinkedList()
        {
            delinked(first);
            last = NULL;
        }

};

int main(void)
{
    LinkedList list;
    list.add_node_start(1);
    list.add_node_end(2);
    list.add_node_end(3);
    list.add_node_end(5);
    list.add_node_end(6);
    list.add_node_end(7);
    list.add_node_start(0);
    list.add_node_after_k(8);
    list.add_node_after_k(4);
    list.add_node_end(10);
    list.delete_node_start();
    list.delete_node_end();
    list.add_node_after_k(9);
    list.add_node_after_k(-1);
    list.add_node_after_k(-2);
    list.add_node_after_k(-3);
    list.delete_negative();   
    list.print_list();
    return 0;
}