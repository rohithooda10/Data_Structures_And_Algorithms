//Merge two sorted arrays
//Approach : Compare elements of both arrays and insert the smaller in the resultant array
//Code :

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> firstArray= {1,4,5};
    vector<int> secondArray= {3,6,8};
    vector<int> mergedArray={};
    int m=0,n=0;
    while(m<firstArray.size() && n<secondArray.size())
    {
        if(firstArray[m]<secondArray[n])
        {
            mergedArray.push_back(firstArray[m++]);
        }
        else
        {
            mergedArray.push_back(secondArray[n++]);
        }
    }
    while(m<firstArray.size())
    {
        mergedArray.push_back(firstArray[m++]);
    }
    while(n<secondArray.size())
    {
        mergedArray.push_back(secondArray[n++]);
    }
    for(int i=0;i<mergedArray.size();i++)
    {
        cout<<mergedArray[i];
    }

    return 0;
}