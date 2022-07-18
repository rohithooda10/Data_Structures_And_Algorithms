//BST maximum path sum
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxi=0;

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

int maxPathSum(struct Node* root)
{
    if(root==NULL)
        return 0;
    int left = max(0,maxPathSum(root->left));
    int right = max(0,maxPathSum(root->right));
    maxi = max(maxi,root->val+ left + right);
    return root->val + max(left,right);
}

int main()
{
    struct Node* root = new Node(8);
    root = insert(root,6);
    root = insert(root,-10);
    root = insert(root,3);
    root = insert(root,11);
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,1);
    maxPathSum(root);
    cout<<"Maximum path sum of the BST:"<<maxi;
    
    return 0;
}