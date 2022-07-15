//Topological sort using DFS
//Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

stack<int> st;
bool toposort(int i,vector<int> adj[],int visited[])
{
       
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                toposort(adj[i][j],adj,visited);
            }
        }
         
        st.push(i);
}

int main() {
    int n,m;
    bool result;
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> topoResult;
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
            toposort(i,adj,visited);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        topoResult.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<topoResult.size();i++)
    {
        cout<<topoResult[i]<<" ";
    }
    
}

