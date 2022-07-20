//Binary Tree right view 
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> result;

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

void rightView(struct Node* root,int level)
{
    if(root!=NULL)
    {
        if(level==result.size())
        {
            result.push_back(root->val);
        }
        rightView(root->right,level+1);
        rightView(root->left,level+1);
    }
}

int main()
{
    int level=0;
    struct Node* root = new Node(25);
    root = insert(root,22);
    root = insert(root,29);
    root = insert(root,20);
    root = insert(root,24);
    root = insert(root,27);
    root = insert(root,32);
    
    rightView(root,0);
    
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}