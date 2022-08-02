//Subsquences of an array
//Code:
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> subseqs;

void getSubSeq(int index,vector<int> arr,vector<int> &sub)
{
    if(index == arr.size())
    {
        subseqs.push_back(sub);
        return;
    }
    else
    {
        sub.push_back(arr[index]);     //Add an element in subsequence
        getSubSeq(index+1,arr,sub);    //Call with that element considered
        sub.pop_back();                //Remove the element
        getSubSeq(index+1,arr,sub);    //Call without that element considered
        
    }
}

int main()
{
    vector<int> arr={1,2,3};
    vector<int> sub;
    getSubSeq(0,arr,sub);
    for(int i=0;i<subseqs.size();i++)
    {
        for(int j=0;j<subseqs[i].size();j++)
        {
            cout<<subseqs[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
 