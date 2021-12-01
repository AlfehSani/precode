#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
#define mx 1e18
struct bol{
  ll sum,laz,left,right,left1,right1;
  bool chk;
  bol()
  {
    sum=laz=left=right=right1=left=left1=0;
    chk=false;
  }
}t[4*sz];
bol combine(bol x,bol y)
{
 bol z;
  z.sum=x.sum+y.sum;
   z.left=max(x.left,x.sum+y.left);
   z.right=max(y.right,y.sum+x.right);
   z.left1=min(x.left1,x.sum+y.left1);
   z.right1=min(y.right1,y.sum+x.right1);
   return z;
}
bol single_combine(ll val,ll l,ll r)
{
    bol x;
    x.sum=val*(r-l+1);
    x.laz=val;
    x.chk=true;
    x.left=max(0ll,x.sum);
    x.right=max(0ll,x.sum);
    x.left1=min(0ll,x.sum);
    x.right1=min(0ll,x.sum);
    return x;
}
void kor(ll node,ll l,ll r,ll mid)
{
    t[node].chk=false;
    t[2*node]=single_combine(t[node].laz,l,mid);
    t[2*node+1]=single_combine(t[node].laz,mid+1,r);
    return;    
}
ll arr[sz];
void build(ll node,ll l,ll r)
{
    if(l==r)
    {
     t[node]=single_combine(arr[l],l,r);
     return;
    }
    ll mid=(l+r)/2;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);
    t[node]=combine(t[2*node],t[2*node+1]);
    return;
}
void update(ll node,ll l,ll r,ll le,ll ri,ll val)
{
    if(l>ri || le>r || le>ri)
        return;
    if(l>=le && r<=ri)
    {
        t[node]=single_combine(val,l,r);
        return;
    }
    ll mid=(l+r)/2;
    if(t[node].chk)
    kor(node,l,r,mid);
    update(node*2,l,mid,le,ri,val);
    update(node*2+1,mid+1,r,le,ri,val);
    t[node]=combine(t[2*node],t[2*node+1]);
    return;
}
bol query(ll node,ll l,ll r,ll le,ll ri)
{
    if(l>ri || l>r || le>r || le>ri){
        bol a;
        return a;
    }
    if(l>=le && r<=ri)
       return t[node];
    ll mid=(l+r)/2;
   if(t[node].chk)
        kor(node,l,r,mid);
   bol x,y,z;
   x=query(node*2,l,mid,le,ri);
   y=query(node*2+1,mid+1,r,le,ri);
   return combine(x,y);
}
int main()
{
   //ios_base::sync_with_stdio(0);cin.tie(0);
   //freopen("table.in","r",stdin);
   // freopen("output.txt","w",stdout);
   int test_case=1;
   scanf("%d",&test_case); 
   for(int cs=1;cs<=test_case;cs++)
   {
   
   }
   return 0;
}
