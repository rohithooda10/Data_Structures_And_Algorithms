//Two BST comparison 
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

bool compare(struct Node* root,struct Node* root2)
{
    if(root==NULL && root2==NULL)
        return true;
    else if(root==NULL && root2!=NULL)
        return false;
    else if(root2==NULL && root!=NULL)
        return false;    
    else if(root->val!=root2->val)
        return false;
    bool left = compare(root->left,root2->left);
    bool right = compare(root->right,root2->right);
    
    return (left&&right);
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
    
    struct Node* root2 = new Node(8);
    root2 = insert(root2,6);
    root2 = insert(root2,10);
    root2 = insert(root2,3);
    root2 = insert(root2,11);
    root2 = insert(root2,8);
    root2 = insert(root2,2);
    root2 = insert(root2,1);
    
    bool comparisonResult = compare(root,root2);
    if(comparisonResult==false)
        cout<<"Two BSTs are different";
    else
        cout<<"Both BSTs are same";
    
    
    return 0;
}