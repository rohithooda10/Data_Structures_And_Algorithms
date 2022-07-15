//Cycle Detection using BFS
//Code: 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cycleBfs(int i,vector<int> adj[],int visited[])
{
    vector<pair<int,int>> q;
    q.push_back(make_pair(i,-1));
    visited[i]=1;
    while(q.size()>0)
    {
        int t=q.front().first;
        int parent = q.front().second;
        q.erase(q.begin());
        
        for(int j=0;j<adj[t].size();j++)
        {
            
            if(visited[adj[t][j]]==0)
            {
                visited[adj[t][j]]=1;
                q.push_back(make_pair(adj[t][j],t));
            }
            else if(adj[t][j]!=parent)
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
            result = cycleBfs(i,adj,visited);
            if(result==true)
                break;
        }
    }
    if(result==true)
        cout<<"cycle";
    else
        cout<<"No cycle";
    
}

