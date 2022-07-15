//Topological sort using BFS - Kahn's algorithm
//Code: 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
vector<int> toposort(vector<int> adj[],int indgree[])
{
    vector<int> topoResult;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        topoResult.push_back(t);
        for(int j=0;j<adj[t].size();j++)
        {
            indgree[adj[t][j]]--;
            if(indgree[adj[t][j]]==0)
                q.push(adj[t][j]);
            
        }
    }
    return topoResult;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    int indgree[n]={0};
    vector<int> topoResult;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        indgree[v]++;
        adj[u].push_back(v);
    }
    
    for(int i=0;i<n;i++)
    {
        if(!indgree[i])
        {
            q.push(i);
            
        }
    }
    topoResult = toposort(adj,indgree);
    for(int i=0;i<topoResult.size();i++)
    {
        cout<<topoResult[i]<<" ";
    }
    
}

