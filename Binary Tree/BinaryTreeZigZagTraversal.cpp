//Binary Tree zigzag traversal 
//Code:

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

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

void zigzag(struct Node* root)
{
    bool flag = true;
    vector<vector<struct Node*>> q;
    q.push_back({root});
    result.push_back({{root->val}});
    while(q.size()>0)
    {
        vector<int> currentLevel;
        flag = !flag;
        vector<struct Node*> temp = q.front();
        q.erase(q.begin());
        vector<struct Node*> children;
        for(int i=0;i<temp.size();i++)
        {
            struct Node* child = temp[i];
            if(child->left!=NULL)
                children.push_back(child->left);
            if(child->right!=NULL)
                children.push_back(child->right);
              
        }
        if(children.size()>0)
            q.push_back(children);
        for(int i=0;i<children.size();i++)
        {
            if(flag==true)
                currentLevel.push_back(children[i]->val);
            else
                currentLevel.insert(currentLevel.begin(),children[i]->val);
        }
        result.push_back(currentLevel);
    }

}

int main()
{
    struct Node* root = new Node(8);
    root = insert(root,6);
    root = insert(root,10);
    root = insert(root,9);
    root = insert(root,3);
    root = insert(root,11);
    root = insert(root,7);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,1);
    
    zigzag(root);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}