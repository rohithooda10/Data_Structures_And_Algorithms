//Binary Tree Root To Node Path
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> path;

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

bool rootToNode(struct Node* root, int ele)
{
    
    if(root==NULL)
        return false;
    path.push_back(root->val);
    if(root->val==ele)
    {
        return true;
    }
    if(rootToNode(root->left,ele)==false && rootToNode(root->right,ele)==false)
    {
        
        path.pop_back();
        return false;
    }
    return true;
    
}

int main()
{
    
    struct Node* root = new Node(25);
    root = insert(root,22);
    root = insert(root,29);
    root = insert(root,20);
    root = insert(root,24);
    root = insert(root,27);
    root = insert(root,32);
    int ele=2; //element to be searched
    bool result = rootToNode(root,ele);
    if(result)
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
    else
        cout<<"Element not present";
    
    return 0;
}