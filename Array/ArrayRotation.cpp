//Array rotation
/* Approach : Divide the array into sets(=gcd(n,k)) and do the swapping of array[i] with array[i+k] */
//Complexity: Time = O(n), Space = O(1)
//Code :

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//Function to find out gcd of two numbers
int gcd(int a,int b)
{
    if(a==b)
        return a;
    else if(a>b)
        gcd(a-b,b);
    else
        gcd(a,b-a);
}


int main() {
    vector<int> array= {1,2,3,4,5,6,7,8,9}; //Given array
    int k=4; //Number of rotation
    int n = array.size(); //Number of elements in array
    int j,d;
    for(int i=0;i<gcd(n,k);i++)
    {
        j=i;
        d=(j+k)%n;
        int temp = array[i];
        while(d!=i)
        {
            array[j]=array[d];
            j=d;
            d=(j+k)%n;
            
        }
        array[j]=temp;
    }
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i];
    }

    return 0;
}