//Bipartite or not using BFS
//Code :                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int i,vector<int> adj[],int color[])
{
    vector<int> q;
    color[i]=1;
    q.push_back(i);
    
    while(q.size()>0)
    {
        int t = q.front();
        q.erase(q.begin());
        
        for(int j=0;j<adj[t].size();j++)
        {
            if(color[adj[t][j]]==-1)
            {
                color[adj[t][j]]=1-color[t];
                q.push_back(adj[t][j]);
            }
            else if(color[adj[t][j]]==color[t])
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
            if(!bipartiteBfs(i,adj,color))
            {
                cout<<"Not Bipartite";
                break;
            }
                
            else
                cout<<"Bipartite";
        }
    } 
    
}

