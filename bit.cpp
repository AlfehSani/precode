#include<bits/stdc++.h>
using namespace std;
#define sz 20009
int bit[sz],n;
//bit is 1 based indexing
void update(int x, int delta)//at x index update delta
{
      for(; x <= n; x += x&-x)
        bit[x] += delta;
}
int query(int x)//query sum from 1 to x index
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += bit[x];
     return sum;
}h
int main()
{
    int q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        update(i,a);
    }
    while(q--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(b)-query(a-1));
    }
}
