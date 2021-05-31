#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(vector<int> &hT, int i)
{
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}
void insert(vector<int> &hT, int newNum)
{
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int idx = size / 2 - 1; idx >= 0; idx--)
    {
      heapify(hT, idx);
    }
  }
}
void deleteNode(vector<int> &hT, int num)
{
  int size = hT.size();
  int idx;
  for (idx = 0; idx < size; idx++)
  {
    if (num == hT[idx])
      break;
  }
  swap(&hT[idx], &hT[size - 1]);

  hT.pop_back();
  for (int idx = size / 2 - 1; idx >= 0; idx--)
  {
    heapify(hT, idx);
  }
}
void printArray(vector<int> &hT)
{
    if(hT.size() == 0)
    {
        cout<<"Sorry My Friend everyone is dead no one is here to kill....\nbetter add more numbers in HEAP... fun....\n";
    }
  for (int idx = 0; idx < hT.size(); ++idx)
    cout << hT[idx] << " ";
  cout << "\n";
}

int main()
{
  vector<int> heapTree;
  for(int idx = 19; idx <= 100; idx = idx + 7)
    {
    cout<<"Task with Priority "<<idx<<" added "<<'\n';
    insert(heapTree, idx);
    }
    printArray(heapTree);
    cout<<"\nDeletion Time.........\n";
    for(int idx = 19; idx <= 100; idx = idx + 7)
    {
        cout<<"Task with Priority "<<idx<<" deleted "<<'\n';
        deleteNode(heapTree, idx);
        printArray(heapTree);
    }

}