#include<bits/stdc++.h>
#define ll long long int
#define sz 200009
#define mod 1000000007
using namespace std;

ll factinv[sz],fact[sz],inv[sz];
ll ncr(ll n,ll r)
{
  if(r>n)
    return 0;
  ll a=(factinv[r]*factinv[n-r])%mod;
  return (a*fact[n])%mod;
}
//find inv and factinv,fact for 1 to n
void calculatefact(int n)
{
  inv[0] = inv[1] = 1;
  factinv[0]=factinv[1]=1;
  fact[0]=fact[1]=1; 
  for(int i = 2; i <= n; i++)
  {  
    inv[i] = inv[mod % i] * (mod - mod / i) %mod;
    factinv[i]=(factinv[i-1]*inv[i])%mod;
    fact[i]=(fact[i-1]*i)%mod;
  }
}
int main()
{

}
/*
some important formula
for i 0 to a
sum of ncr(n,i)*ncr(m,a-i) = ncr(n+m,a);
for i 0 to n
sum of ncr(n,i)*ncr(m,i) = ncr(n+m,n);
for i 0 to a
sum of ncr(n+i,n) = ncr(n+a+1,n+1); 
catalan triangle C(n, k) = (n - k + 1) / (n + 1) * ncr(n + k, k)
*/
