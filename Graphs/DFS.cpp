//DFS
//Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> list[],int visited[])
{
    visited[i]=1;
    cout<<i<<"-";
    
    for(int j=0;j<list[i].size();j++)
    {
        if(visited[list[i][j]]==0)
        {
            
            dfs(list[i][j],list,visited);
        }
    }
}

int main() {
    int n,m;
    cin>>n;
    cin>>m;
    vector<int> list[n];
    int visited[n]={0};
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u;
        cin>>v;
        list[u].push_back(v);
    }

    for(int i=0;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,list,visited);
        }
    }
    
}

