#include<bits/stdc++.h>
using namespace std;
void insertionSort(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        int x=array[i];
        int j=i-1;
        while(j>=0 && array[j]>x)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=x;
    }
    return;
}
int main()
{
    int array[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    insertionSort(array,n);
    printf("\nAfter Insertion sort the elements of the array are : ");
    for(int i=0;i<n;i++)
    {
       printf("%d ",array[i]);
    }

}
