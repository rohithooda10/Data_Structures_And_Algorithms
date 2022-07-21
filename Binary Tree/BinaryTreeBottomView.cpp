//Binary Tree bottom view 
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

void bottomView(struct Node* root,int horizontal)
{
    vector<pair<struct Node*,int>> q;
    q.push_back(make_pair(root,horizontal));
    result.insert({horizontal,root->val});
    while(q.size()>0)
    {
        struct Node* temp = q.front().first;
        int temp_horizontal = q.front().second;
        q.erase(q.begin());
        
        if(temp->left!=NULL)
        {
            q.push_back(make_pair(temp->left,temp_horizontal-1));
            if(result.find(temp_horizontal-1)==result.end())
            {
                result.insert({temp_horizontal-1,temp->left->val});
            
            }else{
                result[temp_horizontal-1]=temp->left->val;
            }
        }
        if(temp->right!=NULL)
        {
            q.push_back(make_pair(temp->right,temp_horizontal+1));
            if(result.find(temp_horizontal+1)==result.end())
            {
                result.insert({temp_horizontal+1,temp->right->val});
            }else
            {
                result[temp_horizontal+1]=temp->right->val;
            }
        }
        
        
    }
    
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
    
    bottomView(root,0);
    vector<int> keyList;
    for(auto i:result)
    {
        keyList.push_back(i.first);
        //cout<<i.first<<" "<<i.second<<endl;
    }
    sort(keyList.begin(),keyList.end());
    
    for(int i=0;i<keyList.size();i++)
    {
        cout<<result[keyList[i]]<<" ";
    }
    
    
    
    return 0;
}