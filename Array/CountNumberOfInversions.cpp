//Count number of inversions in an array using merge sort
//Complexity : Time = O(nlogn), Space = O(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int c=0; //to store number of inversions
void merge(int arr[],int l,int mid,int h)
{
    int n=l,m=mid+1,k=0;
    int temp[h-l+1];
    
    while(n<=(mid) && m<=h)
    {
        if(arr[n]<arr[m])
        {
            temp[k++] = arr[n++];
            
        }else{
            temp[k++] = arr[m++];
            c=c+(mid-n+1); 
        }
        
    }
    
    while(n<=mid)
    {
        temp[k++]= arr[n++];
    }
    while(m<=h)
    {
        temp[k++] = arr[m++];
    }
    k=0;
    for(int i=l;i<=h;i++)
    {
        arr[i]=temp[k++];
    }
    
}

void mergesort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
    else
        return;
    
}

int main() {
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    cout<<"Number of inversions: "<<c;
    
}

