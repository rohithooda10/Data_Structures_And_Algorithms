//Binary Tree symmetrical or not
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> result;

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

bool checkSymmetry(struct Node* left,struct Node* right)
{
    if(left==NULL || right==NULL)
        return left==right;
    if(left->val!=right->val)
        return false;
    return (checkSymmetry(left->left,right->right) && checkSymmetry(left->right,right->left));
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
    
    bool result;
    result = checkSymmetry(root->left,root->right);
    if(result==true)
        cout<<"Symmetric";
    else
        cout<<"Not Symmetric";
    
    
    return 0;
}