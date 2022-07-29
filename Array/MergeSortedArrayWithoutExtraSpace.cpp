//Merge two sorted arrays without extra space
//Approach - Take pointer to last element of first array and last element of second array, check which is greater and put that at the end of first array
//Code:

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
        
        
    }

int main()
{
    vector<int> nums1={6,7,8,12,0,0,0};
    vector<int> nums2={4,5,10};
    merge(nums1,nums1.size()-nums2.size(),nums2,nums2.size());
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }

    return 0;
}
