#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mx 200009
ll treesum[3*mx],arr[mx],treemin[3*mx];
void buildsum(ll node,ll l,ll r)
{
    if(l==r)
    {
        treesum[node]=arr[l];
        return;
    }
    ll mid=(l+r)/2;
    buildsum(node*2,l,mid);
    buildsum(node*2+1,mid+1,r);
    treesum[node]=treesum[2*node]+treesum[2*node+1];
    return;
}
void updatesum(ll node,ll l,ll r,ll val,ll ind)
{
    if(l==r)
    {
        treesum[node]=val;
        return;
    }
    ll mid=(l+r)/2;
    if(ind<=mid)
        updatesum(node*2,l,mid,val,ind);
    else
        updatesum(node*2+1,mid+1,r,val,ind);
    treesum[node]=treesum[2*node]+treesum[2*node+1];
    return;
}
ll querysum(ll node,ll l,ll r,ll le,ll ri)
{
    if(l>ri || l>r || r<le)
        return 0;
    if(l>=le && r<=ri)
    {
       return treesum[node];
    }
    ll mid=(l+r)/2;
    ll x,y;
   x=querysum(node*2,l,mid,le,ri);
   y=querysum(node*2+1,mid+1,r,le,ri);
    return x+y;
}
int main()
{
    buildsum(1,1,n);
    updatesum(1,1,n,i);
    querysum(1,1,n,l,r);

}
