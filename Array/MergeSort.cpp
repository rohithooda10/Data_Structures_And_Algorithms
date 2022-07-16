//MergeSort
//Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=0,temp[ub-lb+1];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=ub)
    {
        temp[k++]=arr[j++];
    }
    k=0;
    for(int t=lb;t<=ub;t++)
    {
        arr[t] = temp[k++];
    }
    
}

void mergesort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int main()
{
    int arr[]={2,6,3,4,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);
    cout<<endl<<"After:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}