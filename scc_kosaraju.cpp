#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 400007
#define sz11 5000000
#define mod1 1000000007
#define mod11 998244353
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
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;
vector<int> roots(n, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(n);
void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("handle_list.txt","r",stdin);
  //freopen("updated_handle_list.txt","w",stdout);
  int test_case=1;
 // scanf("%d",&test_case);
  //printf("%d %d\n",'−','-');
  for(int cs=1;cs<=test_case;cs++)
  {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
    if (!used[v]) {
        dfs2(v);

        int root = component.front();
        for (auto u : component) roots[u] = root;
        root_nodes.push_back(root);

        component.clear();
    }


for (int v = 0; v < n; v++)
    for (auto u : adj[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v)
            adj_scc[root_v].push_back(root_u);
    }
  }
  return 0;
}