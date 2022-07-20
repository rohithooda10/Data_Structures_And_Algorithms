//Binary Tree vertical traversal 
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<struct Node*,pair<int,int>>> result;

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

struct Node* insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        
    }
    else if(root->val>data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;
}

void verticalOrder(struct Node* root,int level,int horizontal)
{
    vector<pair<struct Node*,pair<int,int>>> q;
    
    q.push_back(make_pair(root,make_pair(level,horizontal)));
    result.push_back(make_pair(root,make_pair(level,horizontal)));
    
    while(q.size()>0)
    {
        struct Node* temp = q.front().first;
        int temp_level = q.front().second.first;
        int temp_horizontal = q.front().second.second;
        q.erase(q.begin());
        
        if(temp->left!=NULL)
        {
            q.push_back(make_pair(temp->left,make_pair(temp_level-1,temp_horizontal-1)));
            result.push_back(make_pair(temp->left,make_pair(temp_level-1,temp_horizontal-1)));
        }
        if(temp->right!=NULL)
        {
            q.push_back(make_pair(temp->right,make_pair(temp_level-1,temp_horizontal+1)));
            result.push_back(make_pair(temp->right,make_pair(temp_level-1,temp_horizontal+1)));
        }
    }
}

bool sortbysec(pair<struct Node*,pair<int,int>> a,pair<struct Node*,pair<int,int>> b)
{
    return (a.second.second<b.second.second);
}

int main()
{
    struct Node* root = new Node(11);
    root = insert(root,12);
    root = insert(root,13);
    root = insert(root,16);
    root = insert(root,14);
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,8);
    root = insert(root,9);
    
    verticalOrder(root,0,0);
    sort(result.begin(),result.end(),sortbysec);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first->val<<" "<<result[i].second.first<<","<<result[i].second.second<<endl;
        
    }
    
    return 0;
}