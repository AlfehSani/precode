#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 400009
#define sz1 109
#define mod 1000000007
//#define mod 998244353
#define pr1 577
#define pr2 593
#define inf 1e18 
#define f first
#define s second
#define pa pair<ll,ll>
#define eps 1e-6
#define eps1 1e-8
#define pi acos(-1.0)
#define matrix vector<vector<ll> > 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll m,n;
matrix mul(matrix a,matrix b)
{
  matrix c(m,vector<ll>(m,0));
  ll a1=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<m;j++)
    {
     for(int k=0;k<m;k++)
     {
      c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
     }
    }
  }
  return c;
}
matrix pow(matrix v,ll val)
{
  if(val==1)
    return v;
  if(val&1)
    return mul(v,pow(v,val-1));
  matrix a=pow(v,val/2);
  return mul(a,a);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("table.in","r",stdin);
  // freopen("output.txt","w",stdout);
  int test_case=1;
 // scanf("%d",&test_case);
  for(int cs=1;cs<=test_case;cs++)
  {
     m=3;
   matrix v(m,vector<ll>(m,0));
   matrix a=pow(v,0);
  }
  return 0;
}
