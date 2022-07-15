//Repeated and Missing
//Approach : Create a substitute array and initialise with 0, for each occurance element i //increment in substitute at index i, then traverse substiture array, repeated element will //be index with value 2 and missing will be index with 0 value
//Complexity : Time = O(n), Space = O(n) 
//Code :

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,2,3,5};
    vector<int> temp;
    int repeated,missing;
    for(int i=0;i<nums.size();i++)
    {
        temp.push_back(0);
    }
    for(int i=0;i<nums.size();i++)
    {
        temp[nums[i]]++;
    }
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]==0)
            missing = i;
        else if(temp[i]>1)
            repeated = i;
    }
    cout<<"Repeated:"<<repeated<<endl;
    cout<<"Missing:"<<missing;

    return 0;
}