#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define sz 200009
#define vec array<int,4>
int n,cntcnt,arr[sz],ans,cnt1[sz],brr[sz],cnt[sz],l,r; 
map<int,int>cnt2;
const int bloc=2000;
void add(int i)
{
  int num=arr[i];
  cnt1[cnt[num]]--;
  cnt[num]++;
  cnt1[cnt[num]]++;
  if(ans>=cnt[num])
  {
    if(cnt1[cnt[num]-1]==0)
      ans=cnt[num]-1;
    else
      while(cnt1[ans])
        ans++;
  }
}
void remove(int i)
{
  int num=arr[i];
  cnt1[cnt[num]]--;
  cnt[num]--;
  cnt1[cnt[num]]++;
  if(cnt1[cnt[num]+1]==0 && ans>cnt[num])
    ans=cnt[num]+1;
  while(cnt1[ans])
    ans++;
}
void don_time(int a,int val)
{
  if(a>=l && a<=r)
  {
    remove(a);
    arr[a]=val;
    add(a);
  }
  else
    arr[a]=val;
}

int main()
{ 
  ios_base::sync_with_stdio(0);cin.tie(0);
  int test_case=1;
   
   for(int cs=1;cs<=test_case;cs++)
   {
    int n,q;
    cin>>n>>q;
    cnt1[0]=sz;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      
      if(!cnt2[arr[i]])
        cnt2[arr[i]]=++cntcnt;
      
      arr[i]=brr[i]=cnt2[arr[i]];
    }
    
    int timee=0;
    
    std::vector<vec> quer,vupd;
    std::vector<int> querans(q+1);
    
    for(int i=1;i<=q;i++)
    {
     int a,b,c;
     cin>>a>>b>>c; 
     if(a==1)
     {
        quer.push_back({b,c,timee,i});
      }
     else
     {
      if(!cnt2[c])
        cnt2[c]=++cntcnt;
      c=cnt2[c];
      vupd.push_back({b,c,brr[b],0});
      timee++;
      brr[b]=c;
     }
    }
    
    sort(quer.begin(),quer.end(),[&](vec a,vec b){
      int a1=a[0]/bloc;
      int b1=b[0]/bloc;
      if(a1!=b1)
        return a1<b1;
      a1=a[1]/bloc;
      b1=b[1]/bloc;
      if(a1!=b1)
        return a1<b1;
      return a[2]<b[2];
    });
    int curtime=0;
    ans=1;
    l=r=1;
    add(1);
    //for(int u:querlist)
     // cout<<u<<" ";
    for(vec a:quer)
    {
      //cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<"\n";
      while(l>a[0])
        add(--l);
      while(r<a[1])
        add(++r);
     
      while(l<a[0])
        remove(l),l++;
       //cout<<ans<<" ";
      while(r>a[1])
        remove(r),r--;
      while(curtime<a[2])
      {
        don_time(vupd[curtime][0],vupd[curtime][1]);
        curtime++;
      }
      while(curtime>a[2])
      {
        curtime--;
        don_time(vupd[curtime][0],vupd[curtime][2]);
      }
      querans[a[3]]=ans+1;
    }
    for(int i=1;i<=q;i++)
      if(querans[i])
        cout<<querans[i]-1<<"\n";
   }

  return 0;
}