#include<iostream>
using namespace std;

class D_Node
{
    public:
        D_Node *next;
        D_Node *prev;
        int data;
        D_Node(int data = 0, D_Node *next = NULL, D_Node *prev = NULL)
        {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
};

class DHC_LINKED_LIST
{
    private:
        D_Node *head;
    public:
        DHC_LINKED_LIST(void)
        {
            head = new D_Node(0);
            head->next = head;
            head->prev = head;
        }

        void add_node_start(int data)
        {
            D_Node *new_node = new D_Node(data, head->next, head);
            head->next->prev = new_node;
            head->next = new_node;
        }

        void add_node_end(int data)
        {
            D_Node *idx = new D_Node(data, head, head->prev);
            head->prev->next = idx;
            head->prev = idx;
        }

        void delete_node_start(void)
        {   if(head->next == head)
                return;
            D_Node *temp = head->next;
            temp->next->prev = head;
            head->next = temp->next;
            delete temp;
        }

        void delete_node_end(void)
        {
            if(head->next == head)
                return;                
            D_Node *temp = head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
            delete temp;
        }

        void print(void)
        {
            if(head->next == head)
            {
                cout<<"List is empty..";

            }
            else
                for(D_Node *idx= head->next; idx != head; idx = idx->next)
                {
                    cout<<idx->data<<' ';
                }
            cout<<'\n';
        }
};

int main(void)
{
    DHC_LINKED_LIST list;
    list.print();
    list.add_node_end(2);
    list.add_node_start(1);
    list.add_node_start(0);
  
    list.print();
    return 0;
}