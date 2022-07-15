//Leaders in an array
//Approach : Scan from right and keep track of max
//Complexity : Time = O(n), Space = O(1)
//Code :

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> array = {16, 17, 4, 3, 5, 2};
    vector<int> answer={array[array.size()-1]};
    int max=array[array.size()-1];
    
    for(int i=array.size()-2;i>=0;i--)
    {   
        if(max<array[i])
        {
            answer.push_back(array[i]);
            max=array[i];
        }
    }
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }

    return 0;
}