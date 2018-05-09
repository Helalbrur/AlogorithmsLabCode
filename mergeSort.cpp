#include<bits/stdc++.h>
using namespace std;
void merge(int array[],int low,int mid,int high)
{
    int temp[100];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(array[i]<=array[j])
            temp[k++]=array[i++];
        else
            temp[k++]=array[j++];
    }
    while(i<=mid)
    {
        temp[k++]=array[i++];
    }
    while(j<=high)
    {
        temp[k++]=array[j++];
    }
    for(int i=low;i<=high;i++)
    {
        array[i]=temp[i];
    }
}
void mergeSort(int array[],int low,int high)
{
    if(low==high)
        return;
    int mid=(low+high)/2;
    mergeSort(array,low,mid);
    mergeSort(array,mid+1,high);
    merge(array,low,mid,high);
}
int main()
{
    int array[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }
    mergeSort(array,1,n);
    printf("\nAfter merge sort the elements of the array are : ");
    for(int i=1;i<=n;i++)
    {
       printf("%d ",array[i]);
    }
}


