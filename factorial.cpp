#include<bits/stdc++.h>
using namespace std;
#define siz 100000
int f[siz];
int fac(int n)
{
    if(n==0 ||n==1)
        return n;
    if(f[n]!=0)
    {
        return f[n];
    }
    return f[n]=n*fac(n-1);
}
int main()
{

  memset(f,0,sizeof f);
  cout<<"Enter a number : ";
  int n;
  cin>>n;
  cout<<endl<<"Factorial of "<<n<<" is "<<fac(n)<<endl;

}
