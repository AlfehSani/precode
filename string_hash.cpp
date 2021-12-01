#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 107
#define sz11 5000000
#define mod2 1000000007
#define mod1 998244353
#define pr1 577
#define pr2 593
#define inf 1e18
#define f first
#define s second
#define pa pair<ll,ll>
#define eps 0.0000001
#define eps1 1e-8
#define pi acos(-1.0)
#define vec pair<pa,pa>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,greater<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("handle_list.txt","r",stdin);
  //freopen("updated_handle_list.txt","w",stdout);
  int test_case=1;
  scanf("%d",&test_case);
  for(int cs=1;cs<=test_case;cs++)
  {
 
  }
  return 0;
}