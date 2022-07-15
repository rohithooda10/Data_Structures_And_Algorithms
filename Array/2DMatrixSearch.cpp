//2D Matrix search
//Approach: Use binary search, middle element is given by matrix[mid/rows][mid%rows]
//Complexity: Time = O(log(m*n))
//Code :

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{8,9,10}};
    int rows = mat.size(),cols=mat[0].size();
    int l=0,h=rows*cols-1;
    int ele = 9,c=0;
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(mat[mid/cols][mid%cols]==ele)
        {
            
            c=1;
            break;
        }
        else if(mat[mid/cols][mid%cols]<ele)
        {
            l=mid+1;
        }
        else
            h=mid-1;
            
            
    }
    if(c==1)
        cout<<"Element found";
    else
        cout<<"Element not found";

    return 0;
}