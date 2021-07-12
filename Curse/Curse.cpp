#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iostream>
#define sin -999999999
using namespace std;
#define WAY 1
#define BLOCK 0

vector<pair<int, int>> paths;

bool rat_maze(int **maze, int idx, int kdx, int rows, int columns)
{
    pair<int, int> test;
    
    if(maze[idx][kdx] == 2)
        return true;

    if(paths.size() == 0)
    {
        return false;

    }
                 if(idx > 0)
            {
                if(maze[idx - 1][kdx] >= WAY )
                {
                    paths.push_back(make_pair(idx - 1, kdx));
                }
            }
            if(idx < rows - 1)
            {
                if(maze[idx + 1][kdx] >= WAY )
                {
                    paths.push_back(make_pair(idx + 1, kdx));
                }
            }

            if(kdx > 0)
            {
                if(maze[idx][kdx - 1] >= WAY )
                {
                    paths.push_back(make_pair(idx, kdx - 1));
                }
            }
            if(kdx < columns - 1)
            {
                if(maze[idx] [kdx + 1] >= WAY )
                {
                    paths.push_back(make_pair(idx, kdx + 1));
                }
            }
    maze[idx][kdx] = 0;
    test = paths[paths.size() - 1];
    paths.pop_back();
    return rat_maze(maze, test.first, test.second, rows, columns);
}

int fib(int number)
{
	if(number == 0)
		return 0;
	else if(number == 1 || number == 2)
		return 1;
	else
	{
		return (fib(number - 1) + fib(number - 2));
	}
}

int factorial(int number)
{
	if(number == 1 || number == 0)
		return 1; 
	return factorial(number - 1) * number;
}

int sum_odd_digits(int n)
{
	int cake = 0;
	if(n == 0)
	{
		return 0;
	}
	cake = n % 10;
	n = n / 10;
	
	return ((cake % 2) * cake  + sum_odd_digits(n));
}

bool is_sum(int sum, int *x, int idx, int size)
{
	if(idx == size)
		return false;
	
	if(x[idx] == sum) return true;
	bool result = is_sum(sum, x, idx + 1, size);
	
	if(result == true) return true;
	return is_sum(sum - x[idx], x, idx + 1, size);
}

int sum_digits(int number)
{
	if(number == 0)
		return 0;
	return (number % 10) + sum_digits(number / 10);
}

void reverses(string cake, int size = 0, int idx = 0)
{
	if(idx == size)
	{
		return;
	}	
	reverses(cake, size, idx + 1);
	cout<<cake[idx];
	
}

void nopes(string cake, int size = 0, int idx = 0)
{
	if(idx == size)
	{
		return;
	}
	cout<<cake[idx];
	if(idx + 1 != size)
	cout<<'*';	
	nopes(cake, size, idx + 1);
	
	
}

int occurrences_7(int number)
{
	if(number == 0)
		return 0;
	
	return ((number % 10 == 7) +  occurrences_7(number/10));
	
}

int triangles(int number)
{
	if(number == 0)
		return 0;
	return number + triangles(number - 1);
}

bool array_220(int *array, int n, int size, int idx = 0)
{
	if(idx == size)
		return false;
	if(array[idx] > n)
		return true;
	return array_220(array, n, size, idx + 1);
}

bool check(int sum, int size, int *x)
{
	for(int idx = 0; idx < size; idx++)
		if(x[idx] == sum)
			return true;
	for(int idx = 0; idx < size; idx++);
	return false;
}

bool lucky(int element, int * array, int size, int cake, int kdx = 0)
{
	if(size == kdx)
		return false;
	if(array[kdx] % element == 0 && kdx != cake)
	{
		cout<<array[kdx]<<" and "<<array[cake]<<'\n';
		return true;
	}
		return lucky(element, array, size, cake, kdx + 1);
}

bool lucky(int *x, int size)
{
	for(int idx = 0; idx < size; idx++)
	{
		if(lucky(x[idx], x, size, idx, 0))
			return true;
	}
	return false;
}

int count8(int n, int cake, int count)
{
  if(n == 0)
    return count;
  if(n % 10 == 8)
    count++;
  if(cake == 8 && n % 10 == 8)
    count++;
  return count8(n/10, n % 10, count);
  
}

int count8(int n) 
{
  return count8(n, 0, 0);  
}

std::vector<std::string> towerBuilder(int nFloors)
{
      int size = (nFloors * 2) - 1;
      std::vector<std::string>me_dumb;
      for(int idx = 1; idx <= size; idx = idx + 2)
        {
          int space = size - idx;
          space /= 2;
          me_dumb.push_back(std::string(space, ' ') + std::string(idx, '*') + std::string(space, ' '));
        }
        return me_dumb;
}

bool is_palindrome(string s, int idx, int kdx)
{
	if(idx >= kdx)
		return true;
	if(s[idx] != s[kdx])
		return false;
	return is_palindrome(s, idx + 1, kdx - 1);
	
}

int power(int base, int exponent)
{
	if(exponent == 0)
		return 1;
	else if(exponent == 1)
		return base;
	int result = power(base, exponent/2);
	if(exponent % 2 == 0)
		return result * result;
	else
		return result * result * base;
}
int main(void) 
{
	int cake = power(2, 5);
	cout<<cake;	
    return 0;
}


/*
1-Arrays and Lists
2-2D Arrays
3-Strings
-------------------
	4-Linked List
	5-Stack
	6-Queue
------------------------	
	7-Binary Tree
	8-Binary Search Tree
	9-Trie
	10-Heap
	11-Graphs
	12-Hash Table & Hash Set
		
*/