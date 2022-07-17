//Grid Unique Paths
//Approach - Dynamic programming/ Memoization
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfPaths(int i,int j,int rows,int cols,vector<vector<int>> &dp)
{
    if(i==rows-1 && j==cols-1)    return 1;
    else if(i>=rows || j>=cols)   return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        dp[i][j] = numberOfPaths(i,j+1,rows,cols,dp) + numberOfPaths(i+1,j,rows,cols,dp);
        return dp[i][j];
    }
}


int main()
{
    int rows,cols;
    cout<<"Enter number of rows and columns:";
    cin>>rows;
    cin>>cols;
    vector<vector<int>> dp(rows,vector<int>(cols,-1));
    cout<<"Total number of paths possible:"<<numberOfPaths(0,0,rows,cols,dp);
    
    return 0;
}