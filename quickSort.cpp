#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partion(int array[],int b,int e)
{
    int pivot=array[e];
    int partitionIndex=b;
    for(int i=b;i<e;i++)
    {
        if(array[i]<=pivot)
        {
            swap(&array[i],&array[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&array[partitionIndex],&array[e]);
    return partitionIndex;
}
void quickSort(int array[],int b,int e)
{
    if(b>=e)
        return;
    int partitionIndex=partion(array,b,e);
    quickSort(array,b,partitionIndex-1);
    quickSort(array,partitionIndex+1,e);
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
    quickSort(array,1,n);
    printf("\nAfter quick sort the elements of the array are : ");
    for(int i=1;i<=n;i++)
    {
       printf("%d ",array[i]);
    }
}
