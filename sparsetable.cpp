#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 500006
#define sz1 1001
#define mod 1000000007
#define mod1 998244353
#define pr1 67
#define pr2 61
#define f first
#define s second
#define pa pair<int,int>
#define vec array<ll,4>
const ll mx = 10000000000000000ll;
int arr[sz],t[21][sz],brr[sz];
void build(int n)
{
    for(int i = 1;i <= n; i++)
    {
      t[0][i] = arr[i];
    }
    for(int i = 1;i <= 20; i++)
    {
      for(int j = 1;j <= n; j++)
      {
        int r1 = min(n,j + (1 << (i - 1)));
        t[i][j] = max(t[i - 1][j],t[i - 1][r1]);
      }
    }
    for(int i = 2;i <= n; i++)
      brr[i] = brr[i / 2] + 1;
}
int query(int l,int r)
{
    if(l > r)
        return 0;
  int a1 = brr[r - l + 1];
  int a2 = t[a1][l];
  int b1 = r - (1 << a1) + 1;
  int b2 = t[a1][b1];
  return max(a2,b2);
}
int main()
{ 
  ios_base::sync_with_stdio(0);cin.tie(0);
  int test_case = 1;
   cin >> test_case;
   for(int cs = 1;cs <= test_case; cs++)
   { 
    
   }
  return 0;
}
