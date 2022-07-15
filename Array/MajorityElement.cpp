//Majority element
//Approach : Increment count of each element in map and check whether it exceeds n/2
//Code :

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> elements = {3, 3, 4, 2, 4, 4, 2, 4};
    unordered_map<int,int> map;
    int flag = 0;
    for(int i=0;i<elements.size();i++)
    {
        map[elements[i]]=0;
    }
    for(int i=0;i<elements.size();i++)
    {
        map[elements[i]]=map[elements[i]]+1;
        if(map[elements[i]]>(elements.size()/2))
        {
            cout<<"Majority element exists:"<<elements[i];
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"Doesn't exist";
    
    
    
    return 0;
}