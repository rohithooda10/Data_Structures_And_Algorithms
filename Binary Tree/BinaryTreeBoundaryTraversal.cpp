//Binary Tree boundary traversal 
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

void addLeftBoundary(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    while(root->left!=NULL || root->right!=NULL)
    {
        if(root->left!=NULL)
        {
            result.push_back(root->val);
            root=root->left;
        } else if(root->right!=NULL)
        {
            result.push_back(root->val);
            root=root->right;
        }
    }
    
}

void addRightBoundary(struct Node* root)
{
    vector<int> rightBorder;
    if(root==NULL)
    {
        return;
    }
    while(root->left!=NULL || root->right!=NULL)
    {
        if(root->right!=NULL)
        {
            rightBorder.insert(rightBorder.begin(),root->val);
            root=root->right;
        } else if(root->left!=NULL)
        {
            rightBorder.insert(rightBorder.begin(),root->val);
            root=root->left;
        }
    }
    int t = rightBorder.size();
    for(int i=0;i<t-1;i++)
    {
        result.push_back(rightBorder[i]);
    }
    
}

void addLeaves(struct Node* root)
{
    if(root!=NULL)
    {
        addLeaves(root->left);
        if(root->left==NULL && root->right==NULL)
        {
            result.push_back(root->val);
        }
        addLeaves(root->right);
    }
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
    
    
    addLeftBoundary(root);
    addLeaves(root);
    addRightBoundary(root);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
        
    }
    
    return 0;
}