//Binary Tree lowest common ancestor
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

struct Node* lca(struct Node* root,int a,int b)
{
    if(root==NULL)
        return NULL;
        
    if(root->val==a || root->val==b)
        return root;
        
    struct Node* left = lca(root->left,a,b);
    struct Node* right = lca(root->right,a,b);
    
    if(left==NULL && right==NULL) return NULL;
    if(left!=NULL && right==NULL) return left;
    if(right!=NULL && left==NULL) return right;
    
    if((left->val==a || left->val==b) && (right->val==a || right->val==b))
    {
        return root;
    }
    return root;
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
    root = insert(root,18);
    int ele1=24,ele2=18; 
    struct Node* result = lca(root,ele1,ele2);
    if(result!=NULL)
    {
        cout<<"Lowest common ancestor:"<<result->val;
    }
    else
        cout<<"Not found";
    
    return 0;
}