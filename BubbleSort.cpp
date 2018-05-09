#include<bits/stdc++.h>
using namespace std;
int n;
int array[10000];
void sort(void)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    sort();
    printf("\nAfter Bubble sort the elements of the array are : ");
    for(int i=0;i<n;i++)
    {
       printf("%d ",array[i]);
    }
}
