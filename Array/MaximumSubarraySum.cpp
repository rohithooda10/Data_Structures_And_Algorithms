//Maximum subarray sum - Kandane's algorithm
//Code:
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int arr []={2,9,-5,-1,2,8};
    int k=9,n;
    n = sizeof(arr)/sizeof(arr[0]);
    int maxsum=-32767;
    int currsum=0;
    for(int i=1;i<n;i++)
    {
        currsum+=arr[i];
        if(currsum>maxsum)
            maxsum=currsum;
        if(currsum<0)
            currsum=0;
    }
    cout<<"Maximum subarray sum:"<<maxsum;
    
    return 0;
}