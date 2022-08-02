//Permutations of an array
//Code:
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> permutations;

void swap(int i,int j,vector<int> &arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void permute(int index,vector<int> arr)
{
    if(index==arr.size())
    {
        if(find(permutations.begin(),permutations.end(),arr)==permutations.end())
            permutations.push_back(arr);
        return;
    }
    else
    {
        for(int i=0;i<arr.size();i++)
        {
            swap(index,i,arr);
            permute(index+1,arr);
            swap(index,i,arr);
        }
    }
}

int main()
{
    vector<int> arr={1,2,3,4};
    permute(0,arr);
    for(int i=0;i<permutations.size();i++)
    {
        for(int j=0;j<permutations[i].size();j++)
        {
            cout<<permutations[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
