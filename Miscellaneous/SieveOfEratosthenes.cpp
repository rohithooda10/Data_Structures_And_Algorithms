//Sieve Of Eratosthenes - Find prime numbers in 1 and n
//Complexity - Time = O(n(log(log(n))))
//Code:

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> listOfPrime;

void sieve(int n)
{
    int arr[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i]=-1;
    }
    
    for(int i=2;i<n+1;i++)
    {
        for(int j=i*i;j<n+1;j=i+j)
        {
            if(arr[j]==-1)
                arr[j]=0;
        }
    }
    for(int i=2;i<n+1;i++)
    {
        if(arr[i]==-1)
            listOfPrime.push_back(i);
    }
    for(int i=0;i<listOfPrime.size();i++)
    {
        cout<<listOfPrime[i]<<" ";
    }
}

int main()
{
    int n=12;
    sieve(24);

    return 0;
}
