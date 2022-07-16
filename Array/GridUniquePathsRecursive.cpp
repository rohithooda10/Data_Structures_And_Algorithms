//Grid uniquePaths
//Approach - Recursive
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int l,int h,int rows,int cols)
{
    if(l==rows-1 && h==cols-1)    return 1;
    else if(l>=rows || h>=cols)   return 0;
    else
        return uniquePaths(l,h+1,rows,cols) + uniquePaths(l+1,h,rows,cols);
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