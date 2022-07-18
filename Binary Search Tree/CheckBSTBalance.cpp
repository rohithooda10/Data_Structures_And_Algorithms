//Check BST balance
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

int checkBalance(struct Node* root)
{
    if(root==NULL)
        return 0;
    int left = checkBalance(root->left);
    int right = checkBalance(root->right);
    if(left==-1 || right==-1)
    {
        return -1;
    }
    if(abs(left-right)>1)
        return -1;
    
    return (1 + max(left,right));
}

int main()
{
    struct Node* root = new Node(8);
    root = insert(root,6);
    root = insert(root,10);
    root = insert(root,3);
    root = insert(root,11);
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,1);
    
    int balance = checkBalance(root);
    if(balance==-1)
        cout<<endl<<"Unbalanced";
    else
        cout<<endl<<"Balanced";
    
    return 0;
}