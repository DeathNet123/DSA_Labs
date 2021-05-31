/*#include<iostream>
#include<vector>
using namespace std;
#define WAY 1
#define BLOCK 0
vector<pair<int, int>> paths; //stack...

bool check_path(int **maze, int row, int column, int rows, int columns)
{
    bool block = false;
    pair<int, int> test;
    if(maze[row][column] == 2)
        return true;
    
    for(int idx = row; idx <= rows; idx++)
    {
        for(int kdx = column; kdx <= columns; kdx++)
        {
            if(maze[idx][kdx] == BLOCK)
            {
                block = true;
                break;
            }

            if(idx > 0)
            {
                if(maze[idx - 1][kdx] == WAY )
                {
                    paths.push_back(make_pair(idx - 1, kdx));
                }
            }
            if(idx < rows)
            {
                if(maze[idx + 1][kdx] >= WAY )
                {
                    paths.push_back(make_pair(idx + 1, kdx));
                }
            }

            if(kdx > 0)
            {
                if(maze[idx][kdx - 1] == WAY )
                {
                    paths.push_back(make_pair(idx, kdx - 1));
                }
            }
            if(kdx < columns)
            {
                if(maze[idx] [kdx + 1] >= WAY )
                {
                    paths.push_back(make_pair(idx, kdx + 1));
                }
            }
            if(maze[idx][kdx] == 2)
            {
                
                return true;
            }
             
            maze[idx][kdx] = 0;
        }

        if(paths.size() == 0)
            return false;
        if(block)
            break;
    }
    test = paths[paths.size() - 1];
    paths.pop_back();
    return check_path(maze, test.first, test.second, rows, columns);
}

int main(void)
{
    int rows, coloumns;
    int **maze;
    cin>>rows>>coloumns;

    maze = new int*[rows];
    for(int idx = 0; idx < rows; idx++)
        maze[idx] = new int[coloumns];
    
    for(int idx = 0; idx < rows; idx++)
    {
        for(int kdx = 0; kdx < coloumns; kdx++)
        {
            cin>>maze[idx][kdx];
        }
    }

    bool kill;
    kill = check_path(maze, 0, 0, rows - 1, coloumns - 1);
    if(kill)
        cout<<"Path Found"<<endl;
    else
        cout<<"Path Not Found";
    return 0;
}

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define WAY 1
#define BLOCK 0

vector<pair<int, int>> paths; //stack...
bool blocks = false;
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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int rows, coloumns;
    int **maze;
    cin>>rows>>coloumns;

    maze = new int*[rows];
    for(int idx = 0; idx < rows; idx++)
        maze[idx] = new int[coloumns];
    
    for(int idx = 0; idx < rows; idx++)
    {
        for(int kdx = 0; kdx < coloumns; kdx++)
        {
            cin>>maze[idx][kdx];
        }
    }

    bool kill;
    paths.push_back(make_pair(0, 0));
    kill = rat_maze(maze, 0, 0, rows , coloumns);
    if(kill)
        cout<<"Path Found"<<endl;
    else
        cout<<"Path Not Found";
    return 0;

}