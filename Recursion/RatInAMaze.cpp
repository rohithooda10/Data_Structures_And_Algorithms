//Rat in a maze
//Code
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> allPaths;

void check(int i,int j, vector<vector<int>> &maze,vector<vector<int>> &visited,vector<char> &out)
{
    if(i==maze.size()-1 && j==maze.size()-1)
    {
        allPaths.push_back(out);
        return;
    }
    //down check
    if(i+1<=maze.size()-1 && visited[i+1][j]==0 && maze[i+1][j]==1)
    {
        out.push_back('D');
        visited[i+1][j]=1;
        check(i+1,j,maze,visited,out);
        out.pop_back();
        visited[i+1][j]=0;
    }
    //left check
    if(j-1>=0 && visited[i][j-1]==0 && maze[i][j-1]==1)
    {
        out.push_back('L');
        visited[i][j-1]=1;
        check(i,j-1,maze,visited,out);
        out.pop_back();
        visited[i][j-1]=0;
    }
    //right check
    if(j+1<=maze.size()-1 && visited[i][j+1]==0 && maze[i][j+1]==1)
    {
        out.push_back('R');
        visited[i][j+1]=1;
        check(i,j+1,maze,visited,out);
        out.pop_back();
        visited[i][j+1]=0;
    }
    //up check
    if(i-1>=0 && visited[i-1][j]==0 && maze[i-1][j]==1)
    {
        out.push_back('U');
        visited[i-1][j]=1;
        check(i-1,j,maze,visited,out);
        out.pop_back();
        visited[i-1][j]=0;
    }
    
}

int main()
{
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<vector<int>> visited = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vector<char> out;
    check(0,0,maze,visited,out);
    for(int i=0;i<allPaths.size();i++)
    {
        for(int j=0;j<allPaths[i].size();j++)
        {
            cout<<allPaths[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
