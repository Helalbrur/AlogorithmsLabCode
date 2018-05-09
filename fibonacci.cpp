#include<bits/stdc++.h>
using namespace std;
#define siz 100000
int f[siz];
int fib(int n)
{
    if(n==0 ||n==1)
        return n;
    if(f[n]!=-1)
    {
        return f[n];
    }
    return f[n]=fib(n-1)+fib(n-2);
}
int main()
{

  for(int i=0;i<siz;i++)
  {
      f[i]=-1;
  }
  cout<<"Enter a number : ";
  int n;
  cin>>n;
  cout<<endl<<"The "<<n<<"th Fibonacci number is "<< fib(n)<<endl;

}
