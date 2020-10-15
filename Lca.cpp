#include<bits/stdc++.h>
using namespace std;
int n, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout,lev;
vector<vector<int>> up;
void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    lev[v]=lev[p]+1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void preprocess(int root) {
    tin.resize(n+10);
    tout.resize(n+10);
    lev.resize(n+10);
    lev[root]=0;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
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
    preprocess(1);
    for(int i=1;i<=q;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}
