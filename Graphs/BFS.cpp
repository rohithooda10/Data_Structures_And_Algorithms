//BFS
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    
void bfs(int i,vector<int> list[],int visited[])
{
    vector<int> q;
    visited[i]=1;
    q.push_back(i);
    
    while(q.size()>0)
    {
        int t = q.front();
        q.erase(q.begin());
        cout<<t<<"-";
        for(int j=0;j<list[t].size();j++)
        {
            if(visited[list[t][j]]==0)
            {
                q.push_back(list[t][j]);
                visited[list[t][j]]=1;
            }
                
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
            bfs(i,list,visited);
        }
    }
    
}
