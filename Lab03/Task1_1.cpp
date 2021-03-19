#include<iostream>
#include<vector>
using namespace std;
#define WAY 1
#define BLOCK 0
vector<pair<int, int>> paths;
bool check_path(int **maze, int row, int column, int rows, int columns)
{
    bool block = false;
    pair<int, int> test;
    cout<<row<<' '<<column<<'\n';
    if(row == 0 && column == 0)
        return true;
    for(int idx = row; idx >= 0; idx--)
    {
        for(int kdx = column; kdx >= 0; kdx--)
        {
            if(maze[idx][kdx] == 2)
                return true;
            if(maze[idx][kdx] == BLOCK || kdx == 0)
            {
                cout<<" BLOCK ";
                block = true;
                break;
            }
            maze[row][column] = 0;
            cout<<row<<' '<<column;
            if(idx != 0) // checking the upper rows for path..
            {
                if(maze[idx - 1][kdx] == WAY)
                {
                    cout<<" One Path added ";
                    paths.push_back(make_pair(idx - 1, kdx));
                }
            }
            if(idx != rows) //Checking path on lower row..
            {
                if(maze[idx +1][kdx] == WAY)
                {
                    cout<<" One Path added ";
                    paths.push_back(make_pair(idx + 1, kdx));
                }
            }

            if(kdx != columns) //Checking path on righ side..
            {
                if(maze[idx][kdx + 1] == WAY)
                {
                    cout<<" One Path added ";
                    paths.push_back(make_pair(idx , kdx + 1));
                }
            }

            if(kdx != 0)
            {
                if(maze[idx][kdx + 1] == WAY)
                {
                    cout<<" One Path added ";
                    paths.push_back(make_pair(idx , kdx - 1));
                }
            }
        }
        cout<<'\n';
        if(paths.size() == 0)
            return false;
        if(block)
            break;   
    }
    if(paths.size() != 0)
    {    
        test = paths[paths.size() - 1];
        paths.pop_back();
    }
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
    maze[0][0] = 2;
    maze[rows - 1][coloumns - 1] = 1
    bool kill;
    kill = check_path(maze, rows - 1, coloumns - 1, rows - 1, coloumns - 1);
    if(kill)
        cout<<"Path Found"<<endl;
    else
        cout<<"Path Not Found";
    return 0;
}