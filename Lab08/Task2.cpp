#include <iostream>
#include <string>
#define SIZE 3

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;
  public:
  string chair = "";

   public:
  Queue() {
    front = -1;
    rear = -1;
  }
  // Check if the queue is full
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  // Adding an element
  void enQueue(int element) {
    if (isFull()) {
      cout << "Customer "<<element <<" Refused\n";
    } else 
    {
        cout << "Customer "<<element <<" Accepted\n";
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
      if(chair == "")
      {
           chair = to_string(element);
          deQueue();
          cout<<"Customer "<<element <<" cutting chair Assigned\n";
      }
    }
  }
  // Removing an element
  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else 
      {
        front = (front + 1) % SIZE;
      }
        if(chair == "")
        {
            cout<<"Customer "<<element<<" cutting chair Assigned\n";
            chair = to_string(element);
        }
      return (element);
    }
  }

  void display() {
    // Function to display status of Circular Queue
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      cout << "Front -> " << front;
      cout << endl
         << "Items -> ";
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i];
      cout << items[i];
      cout << endl
         << "Rear -> " << rear;
    }
  }
};

int main() {
  Queue waiting ;
  int time = - 1, closing = 0;
  for(int idx = 1; idx < 30; idx++)
    {
        if(closing < 4)
        {
            waiting.enQueue(idx);
        }
        time++;
        if(closing == 4)
        {
            cout<<"Shop closed\n";
            closing = 5;
        }
            
        if(time == 3)
        {
            cout <<"Customer "<<waiting.chair<<" Served\n";
            closing++;
            waiting.chair = "";
            if(waiting.isEmpty())
            break;
            waiting.deQueue();
            time = 0;
        }
        

    }
  return 0;
}
