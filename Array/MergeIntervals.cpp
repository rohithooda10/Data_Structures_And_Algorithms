//MergeIntervals
//Approach : Sort intervals in ascending order based on their lower limit, this will give
// mergable intervals in contiguous manner, pop last interval from result and compare with
// current and decide whether to merge the intervals or push them separately
//Complexity : Time = O(nlogn), Space = O(n)
//Code :

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a,vector<int> b)
{
    if(a[0]<b[0])
        return true;
    else
        return false;
}

int main() {
    vector<vector<int>> intervals = {{2,4},{1,4}};
    vector<vector<int>> result;
    
    sort(intervals.begin(),intervals.end(),comp);
    
    result.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++)
    {
        vector<int> temp = result[result.size()-1];
        result.pop_back();
        if(intervals[i][0]<=temp[1])
        {
            result.push_back({min(intervals[i][0],temp[0]),max(intervals[i][1],temp[1])});
        }
        else{
            result.push_back(temp);
            result.push_back(intervals[i]);
        }
    }
    
    
    
    for(int i=0;i<result.size();i++)
    {
        cout<<"["<<result[i][0]<<","<<result[i][1]<<"]";
    }
    

    return 0;
}