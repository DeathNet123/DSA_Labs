#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ISFULL 1
#define ISEMPTY 0
class CMaxHeap
{
	int *x, currentSize, size;
public:
	CMaxHeap(int size = 20)
	{	
		currentSize = 1; //Again index 0 is left blank purposely
		this->size = size + 1;
		x = new int[size];
	}
	void swap(int &a, int &b)
	{
		int temp = a;
		a  = b;
		b = temp;
	}
	void insert(int d) 
	{
		if (currentSize >= size)	throw(ISFULL);
		x[currentSize] = d;
		int i = currentSize;
		while (i>1)
		{
			if (x[i/2] < x[i])
			{
				swap(x[i/2], x[i]);
				i = i / 2 ;
			}
			else break;
		}	
		currentSize++;
	}
	int remove(void) 
	{
		if (currentSize<=1)		
			throw (ISEMPTY);
		int temp = x[1];
		currentSize --;
		x[1] = x[currentSize];
		int i = 1, largerChild;
		while (i*2 < currentSize)
		{
			largerChild = i*2+1;
			if (i * 2 + 1 >= currentSize || x[i * 2] > x[i * 2 + 1])  
				largerChild = i * 2;
			if (x[i]>=x[largerChild])	
				break;
			swap(x[i], x[largerChild]);
			i = largerChild;
		}
		return temp;
	}
	bool isEmpty(void) const
	{
		return currentSize == 1;
	}
	~CMaxHeap(){
		delete []x;
	}
};

int main()
{
	srand(time(0));
	int val;
	CMaxHeap heap(20);
	for (int i=1; i<=15; i++)
	{
		
		heap.insert(i);
	}
	while (!heap.isEmpty())
	{
		cout << setw(2) << heap.remove() << " is removed\n";
	}
	return 0;
}
