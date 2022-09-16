#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define sz 200005
#define sz1 101
#define vec array<int,3>
#define pa pair<int,int> 
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set t[4*sz];


ll arr[sz];
void build(ll node,ll l,ll r)
{
    if(l==r)
    {
        t[node].insert({arr[l],l});
        return;
    }
    for(ll i=l;i<=r;i++)
        t[node].insert({arr[i],i});
    ll mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
}

ll query(ll node,ll l,ll r,ll le,ll ri,ll v,ll idx)
{
     if(l>r || l>ri || le>r || le>ri)
      return 0;
    if(l>=le && r<=ri)
    {
        ll k=t[node].order_of_key({v,idx});
        return k;
    }
    ll mid=(l+r)/2;
    return query(2*node,l,mid,le,ri,v,idx) + query(2*node+1,mid+1,r,le,ri,v,idx);
}

void update(ll node,ll l,ll r,ll i,ll v,ll nw)
{
    if(i<l or r<i)  return;
    if(l==i and r==i)
    {
        t[node].erase(t[node].find({v,i}));
        t[node].insert({nw,i});
        return;
    }
    ll mid=(l+r)/2;
    update(2*node,l,mid,i,v,nw);
    update(2*node+1,mid+1,r,i,v,nw);
    t[node].erase(t[node].find({v,i}));
    t[node].insert({nw,i});
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
   // cin>>t;
   // prec();
    for(int cs=1;cs<=t;cs++){
     int n;
     cin>>n;
     int nn=200000;
     for(int i=1;i<=n;i++)
      cin>>arr[i];
     build(1,1,nn);
     int q;
     cin>>q;
     while(q--)
     {
      int id;
      cin>>id;
      if(id==1)
      {
        n++;
        int vl;
        cin>>vl;
        update(1,1,nn,n,arr[n],vl);
        arr[n]=vl;
      }
      else if(id==2)
      {
        int vl;
        //cin>>vl;
        update(1,1,nn,n,arr[n],0);
        arr[n]=0;
        n--;
      }
      else
      {
        ll l,r,k;
        cin>>l>>r>>k;
        k=(r-l+1)-k+1;
       // cout<<k<<"\n";
        ll lo=0,hi=1000000001,ans=0;
        while(lo<=hi)
        {
          ll mi=(lo+hi)/2;
          ll a1=query(1,1,nn,l,r,mi,0);
          //cout<<mi<<" "<<a1<<"\n";
          if(a1>=k)
            ans=mi,hi=mi-1;
          else
            lo=mi+1;
        }
        cout<<ans-1<<"\n";
      }
     }
   }
}
