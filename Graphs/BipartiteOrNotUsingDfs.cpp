//Bipartite or not using DFS
//Code :
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int i,vector<int> adj[],int color[])
{
    if(color[i]==-1)
        color[i]=1;
    for(int j=0;j<adj[i].size();j++)
    {
        if(color[adj[i][j]]==-1)
        {
            color[adj[i][j]]=1-color[i];
            if(!bipartiteDfs(adj[i][j],adj,color))
                return false;
        }
        else if(color[adj[i][j]]==color[i])
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    bool result;
    cin>>n>>m;
    vector<int> adj[n];
    int color[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
    }
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
        
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteDfs(i,adj,color))
            {
                cout<<"Not Bipartite";
                break;
            }
                
            else
                cout<<"Bipartite";
        }
    } 
    
}

