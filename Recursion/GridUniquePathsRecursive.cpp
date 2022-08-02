//Grid uniquePaths
//Approach - Recursive
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int i,int j,int rows,int cols)
{
    if(i==rows-1 && j==cols-1)    return 1;
    else if(i>=rows || j>=cols)   return 0;
    else
        return uniquePaths(i,j+1,rows,cols) + uniquePaths(i+1,j,rows,cols);
}

int main()
{
    int rows,cols;
    cout<<"Enter number of rows and columns:";
    cin>>rows;
    cin>>cols;
    cout<<"Total number of paths possible:"<<uniquePaths(0,0,rows,cols);
    
    return 0;
}