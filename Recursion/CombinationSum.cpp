//Combination sum
//Code:
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> allCombo;

void getCombo(int index,vector<int> &arr,int k,vector<int> &combo)
{
    if(index>=arr.size())
    {
       if(k==0)
       {
           allCombo.push_back(combo);
       }
    }
    else
    {
        if(arr[index]<=k)
        {
            combo.push_back(arr[index]);
            k=k-arr[index];
            getCombo(index,arr,k,combo);
            combo.pop_back();
            k+=arr[index];
            getCombo(index+1,arr,k,combo);
        }
        else
        {
            getCombo(index+1,arr,k,combo);
        }
    }
}

int main()
{
    vector<int> arr = {2,3,6,7},combo;
    int k=7;
    getCombo(0,arr,k,combo);
    for(int i=0;i<allCombo.size();i++)
    {
        for(int j=0;j<allCombo[i].size();j++)
        {
            cout<<allCombo[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
