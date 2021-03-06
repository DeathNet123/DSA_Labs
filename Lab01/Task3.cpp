
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> real_image;
int binarySearch(vector<int> array, int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}
int main(void)
{
    vector<int> array;
    vector<int> image;
    int size {0}, temp, index;
    cin>>size;
    for(int idx = 0; idx < size; idx++)
    {
        cin>>temp;
        array.push_back(temp);
        image.push_back(temp);
    }
    sort(image.begin(), image.end());
    for(int idx = 0; idx < size; idx++)
    {

       int location = binarySearch(image, , 0, size);
         if (location != -1) 
         {
            cout << location + 1 << ' ';
        }
    }
    return 0;
}