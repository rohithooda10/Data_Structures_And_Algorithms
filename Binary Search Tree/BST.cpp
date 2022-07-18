//BST - Insert, Deletion, Search, Traversal, Minimum value
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
void inorder(struct Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void preorder(struct Node* root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(struct Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->val<<" ";
}
bool search(struct Node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->val == data)
    {
        return true;
    }
    else if(root->val<data)
    {
        return search(root->right,data);
    }else
    {
        return search(root->left,data);
    }
}

int minValue(struct Node* root)
{
    if(root==NULL)
        return -1;
    else if(root->left !=NULL)
        return minValue(root->left);
    else
        return root->val;
}

int main()
{
    struct Node* root = new Node(2);
    root = insert(root,1);
    root = insert(root,4);
    root = insert(root,7);
    cout<<"Inorder:"<<endl;
    inorder(root);
    cout<<endl<<"Preorder:"<<endl;
    preorder(root);
    cout<<endl<<"Postorder:"<<endl;
    postorder(root);
    bool searchResult = search(root,8);
    if(searchResult==true)
        cout<<endl<<"Element found";
    else
        cout<<endl<<"Element not found";
    cout<<endl<<"Minimum value:"<<minValue(root);
    return 0;
}