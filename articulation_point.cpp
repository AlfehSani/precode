#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 300009
#define sz1 2000
//#define mod 1000000007
#define mod 998244353
#define pr1 577
#define pr2 593
#define inf 1e18
#define f first
#define s second
#define pa pair<ll,ll>
#define eps 1e-6
#define eps1 1e-8
#define pi acos(-1.0)
#define vec pair<pa,pa>
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
std::vector<ll> v[sz];
ll tim=0;
ll dis[sz],low[sz];
std::vector<pa>bridge;
void find_articulation_bridge(ll node,ll par)
{
dis[node]=low[node]=++tim;
int children=0;
for(int u:v[node])
{
    if(u==par)
        continue;
    if(!dis[u])
    {
        find_articulation_bridge(u,node);
        if(dis[node]<low[u]){
         bridge.push_back({u,node});
        }
        low[node]=min(low[u],low[node]);
        /* articlation point
        if(low[u]>=dis[node] && par!=-1)
        point */
        children++;
    }
    else
        low[node]=min(low[node],dis[u]);
}
 /* articlation point
if(par==-1 && children>1)
point */
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
 // freopen("chainblock_validation_input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int test_case=1;
  //scanf("%d",&test_case);
  for(int cs=1;cs<=test_case;cs++)
  {
   ll n,m;
   scanf("%lld %lld",&n,&m);
   for(int i=1;i<=m;i++)
   {
    ll a,b;
    scanf("%lld %lld",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
   }
   find_articulation_bridge(1,-1);
  }
  return 0;
}
