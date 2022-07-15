//Cycle detection using DFS
//Code: 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cycleDfs(int i,vector<int> adj[],int visited[],int parent)
{
    
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                visited[adj[i][j]]=1;
                if(cycleDfs(adj[i][j],adj,visited,i)) return true;
            }
            else if(parent!=adj[i][j])
            {
                return true;
            }
        }
        return false;
}

int main() {
    int n,m;
    bool result;
    cin>>n>>m;
    vector<int> adj[n];
    int visited[n]={0};
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            result = cycleDfs(i,adj,visited,-1);
            if(result==true)
                break;
        }
    }
    if(result==true)
        cout<<"cycle";
    else
        cout<<"No cycle";
    
}

