#include<bits/stdc++.h>
#define f first
#define s second
#define sz 200009
#define l 25
using namespace std;
int n,lev[sz],up[sz+10][l+10],tin[sz+10],tout[sz+10],tim; 
vector<int>adj[sz+10];
void dfs(int v, int p)
{
    up[v][0] = p;
    lev[v]=lev[p]+1;
    tin[v]=++tim;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v]=++tim;
    return;
}
bool is_ancestor(int u,int v)//check if u is an ancestor of v
{
    return (tin[u]<=tin[v] && tout[u]>=tout[v]);
}
int lca(int u, int v)
{
    if(is_ancestor(u,v))
    return u;
    if(is_ancestor(v,u))
    return v;
     if(lev[u]<lev[v])
    swap(u,v);//I supossed level of u is higher than v
     for(int i=l;i>=0;i--)//Equalize both level
   {
    if(lev[up[u][i]]>=lev[v])
    {
        u=up[u][i];
    }
   }
    for(int i=l;i>=0;i--)
   {
    if(up[u][i]!=up[v][i])
    {
       u=up[u][i];
       v=up[v][i];
    }
   }
    if(u!=v)
   {
    u=up[u][0];
    v=up[v][0];
   }
   return u;
}
int main()
{
    int q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=q;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}
