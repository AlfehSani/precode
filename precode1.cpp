#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<pair<int, int>, null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>
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
int arr[7][sz];
char c[sz];
void calculate_string_double_hash_front_back(int n)
{
   ll cur1=pr1,cur2=pr2;
    ll sum1=0,sum2=0;
    arr[5][0]=arr[6][0]=1;
    for(int i=0;i<n;i++)
    {
     ll a1=c[i];
     arr[5][i+1]=cur1;
     arr[6][i+1]=cur2;
     ll val1=(a1*cur1)%mod1;
     ll val2=(a1*cur2)%mod2;
     sum1=(sum1+val1)%mod1;
     sum2=(sum2+val2)%mod2;
     arr[0][i]=sum1;
     arr[1][i]=sum2;
     cur1=(cur1*pr1)%mod1;
     cur2=(cur2*pr2)%mod2;
    }
     cur1=pr1,cur2=pr2;
     sum1=0,sum2=0;
     arr[2][n]=arr[3][n]=0;
    for(int i=n-1;i>=0;i--)
    {
     ll a1=c[i];
     ll val1=(a1*cur1)%mod1;
     ll val2=(a1*cur2)%mod2;
     sum1=(sum1+val1)%mod1;
     sum2=(sum2+val2)%mod2;
     arr[2][i]=sum1;
     arr[3][i]=sum2;
     cur1=(cur1*pr1)%mod1;
     cur2=(cur2*pr2)%mod2;
    }

}
bool is_palindrome(int st,int lst,int n)
{
 ll gap2=max(0ll,(st+1ll)-(n-lst));
 ll gap1=max(0ll,(n-lst)-(st+1ll));
 //if(lst==2)
  //printf("%lld %lld\n",arr[0][lst],gap2);
 ll val0=(((arr[0][lst]-0ll-(st?arr[0][st-1]:0)+mod1)%mod1)*arr[5][gap1])%mod1;
 ll val1=(((arr[1][lst]-0ll-(st?arr[1][st-1]:0)+mod2)%mod2)*arr[6][gap1])%mod2;
 ll val2=(((arr[2][st]-0ll-arr[2][lst+1]+mod1)%mod1)*arr[5][gap2])%mod1;
 ll val3=(((arr[3][st]-0ll-arr[3][lst+1]+mod2)%mod2)*arr[6][gap2])%mod2;
 if(val0==val2 && val1==val3)
  return 1;
return 0;
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