#include<iostream>
#include<vector>
using namespace std;
#define GOAL 2
#define WAY 1
#define BLOCK 0
vector<pair<int, int>> paths;
bool check_path(int **maze, int row , int coloumn, int rows, int coloumns)
{
    bool block = false;
    pair<int, int> test;
    if(rows  == row || coloumns == coloumn)
        return false;
    cout<<row<<" "<<coloumn<<'\n';
    for(int idx = row; idx < rows; idx++)
    {
        for(int kdx = coloumn; kdx < coloumns; kdx++)
        {   
            cout<<maze[idx][kdx];
            if(maze[idx][kdx] == BLOCK || kdx == coloumns)
            {
                cout<<" BLocked";
                block = true;
                break;
            }
            if(row != rows - 1)
           if(maze[idx + 1][kdx] == WAY)
            {
                cout<<" one path added ";
                paths.push_back(make_pair(idx+1, kdx));

            }
            /*
            if(row != 0)
                if(maze[idx - 1][kdx] == WAY)
                    paths.push_back(make_pair(idx - 1, kdx));

            if(coloumn != 0)
                if(maze[idx][kdx - 1] == WAY)
                    paths.push_back(make_pair(idx, kdx - 1));

            if(kdx != coloumns - 1)
                if(maze[idx][kdx + 1] == WAY)
                    paths.push_back(make_pair(idx, kdx + 1));
*/
            if (maze[idx][kdx] == 2)
                return true;
            
        }
        cout<<'\n';
        if(block)
            break;
    }
    if(paths.size() == 0)
        return 0;
    if(paths.size() >= 1)
    {
        test = paths[paths.size() - 1];
        paths.pop_back();
    }
    return check_path(maze, test.first, test.second, rows, coloumns);
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
    kill = check_path(maze, 0, 0, rows, coloumns);
    if(kill)
        cout<<"Yes"<<endl;
    else
        cout<<"No";
    return 0;
}