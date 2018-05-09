#include<bits/stdc++.h>
using namespace std;
int n;
int array[10000];
int BinarySearch(int start,int item,int ends)
{
    int lower=start;
    int upper=ends;
    int mid=(int)((lower+upper)/2);
    while(lower<upper && item!=array[mid] )
    {
        if(item>array[mid])
        {
            lower=mid+1;
        }
        else
        {
            upper=mid-1;
        }
        mid=(int)((lower+upper)/2);
    }
    if(array[mid]==item)
        return mid+1;
    return -1;
}
int main()
{
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<endl<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    sort(array,array+n); //if the given array is not sorted then it sort the array but the position of the array will be changed
    cout<<endl<<"Enter the search element : ";
    int item;
    cin>>item;
    int loc=BinarySearch(0,item,n-1);
    if(loc==-1)
        cout<<endl<<"Item does not found in the list"<<endl;
    else
        cout<<endl<<"Item founds in the list at "<<loc<<endl;

}
