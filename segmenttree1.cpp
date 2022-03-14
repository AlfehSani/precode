int arr[sz],t[4*sz];
void build(int node,int l,int r)
{
if(l==r)
{
  t[node]=arr[l];
  return;
}
int mi=(l+r)/2;
build(2*node,l,mi);
build(2*node+1,mi+1,r);
t[node]=min(t[2*node],t[2*node+1]);
return;
}
void update(int node,int l,int r,int id)
{
  if(id<l || id>r)
    return;
  if(l==r)
  {
    t[node]=arr[l];
    return;
  }
  int mi=(l+r)/2;
  update(2*node,l,mi,id);
  update(2*node+1,mi+1,r,id);
  t[node]=min(t[2*node],t[2*node+1]);
  return;
}
int query(int node,int l,int r,int le,int ri)
{
  if(l>r || l>ri || le>r || le>ri)
    return sz;
  if(l>=le && r<=ri)
    return t[node];
  int mi=(l+r)/2;
  int a=query(2*node,l,mi,le,ri);
  int b=query(2*node+1,mi+1,r,le,ri);
  return min(a,b);
}