//  __builtin_popcount 
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200002
#define sz1 102
#define mod 1000000007
#define mod 998244353
#define pr1 577
#define pr2 593
#define inf 1e18
#define f first
#define endl "\n"
#define s second
#define pa pair<ll,ll>
#define eps 0.0000001
#define eps1 1e-8
#define pi acos(-1.0)
#define vec array<ll,3>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, nuint_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

//ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("handle_list.txt","r",stdin);
  //freopen("updated_handle_list.txt","w",stdout);

//check if 3 point are in a same line
ll solve(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
  ll a,b,c,d;
  a=x1-x2;
  b=y1-y2;
  c=x1-x3;
  d=y1-y3;
  if(b==0 && d==0)
    return 1;
  if(b==0 || d==0)
    return 0;
  if(a==0 && c==0)
    return 1;
  if(a==0 || c==0)
    return 0;
  if(a*d==b*c)
    return 1;
    return 0;
}
//find a^b%mod,mod not nesseceryliy prime
//also find a^-1%mod,for which call binpow(a,mod-2) mod should be prime
int mod=1000000007;
long long binpow(long long a, long long b) {
    a %= mod;
    if(a==0)
        return 0;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void build_sieve() {
    vector<int> pr;
    mind[0] = mind[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (mind[i] == 0) {
            pr.push_back(i);
            mind[i] = i;
        }
        for (int j = 0; j < int(pr.size()) && pr[j] <= mind[i] && i * pr[j] < N; ++j) {
            mind[i * pr[j]] = pr[j];
        }
    }
}

//find number of co prime with i from 1 to mx
void oiler(ll n)
{
    for(int i=2;i<=n;i++)
        arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==i){
            for(int j=i;j<=n;j+=i)
                arr[j]-=arr[j]/i;
        }
    }
}
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
//how to read and write __int128 number
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
//mobius function
void mobius(int N) {
  mob[1] = 1;
  for (int i = 2; i < N; i++){
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}
#define pair<int,int> pii
 priority_queue<pii, vector<pii>, greater<pii> >pq;
struct pl
{
    int w[51],p;
};
bool comp2(const pl &r1,const pl &r2)
{
   if(r1.p!=r2.p)
    return r1.p>r2.p;
   for(i=1;i<=50;i++){
    if(r1.w[i]!=r2.w[i])
        return r1.w[i]>r2.w[i];
   }
   return false;
}
bool comp1(const pl &r1,const pl &r2)
{
   if(r1.w[1]!=r2.w[1])
    return r1.w[1]>r2.w[1];
   return comp2(r1,r2);
}
cout.precision(23);
cout << x + y << endl;
#include <iostream>
#include <vector>
#include <queue>
#define pb push_back
using namespace std;
vector<int>adj[sz],cost[sz],v[sz],v1[sz];
priority_queue<pair< int, pair<int,int> >,
        vector< pair< int, pair<int,int> > >,
        greater< pair< int, pair<int,int> > > > pq;
int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
