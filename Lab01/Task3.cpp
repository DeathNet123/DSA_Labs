
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> real_image;

/*int binarySearch(vector<int> array, int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) 
  {
    int mid = low + (high - low) / 2;

    if (image[mid] == array[idx])
      location = mid;

    if (image[mid] < array[idx])
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}*/
int main(void)
{
    vector<int> array;
    vector<int> image;
    int size {0}, temp, low = 0, high, mid = 0, location = -1;
    
    cin>>size;
    for(int idx = 0; idx < size; idx++)
    {
        cin>>temp;
        array.push_back(temp);
        image.push_back(temp);
    }
    sort(image.begin(), image.end());
    high = size;
    
    for(int idx = 0; idx < size; idx++)
    {
      low = 0, mid = 0, high = size;
      while (low <= high) 
    {
      int mid = low + (high - low) / 2;

      if (image[mid] == array[idx])
        location = mid;

      if (image[mid] < array[idx])
        low = mid + 1;

      else
        high = mid - 1;
      }
         if (location != -1) 
         {
            cout << location + 1 << ' ';
        }
    }
    return 0;
}