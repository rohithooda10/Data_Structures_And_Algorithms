//Grid uniquePaths
//Approach - Dynamic programming/ Tabulation
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfPaths(int m,int n,vector<vector<int>> &dp)
{
        
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1;
            else{
                if(i>0)
                {
                     dp[i][j]+= dp[i-1][j];
                    
                }if(j>0)
                {
                     dp[i][j]+= dp[i][j-1];
                }
            }
        }
    }
    
    return dp[m-1][n-1];
        
}


int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> dp(m,vector<int>(n,0));
    int result = numberOfPaths(m,n,dp);
    cout<<"Number of unique paths:"<<result;
    return 0;
}