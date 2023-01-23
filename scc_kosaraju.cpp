#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, adj_rev,adj_scc;
vector<bool> used;
vector<int> order, component;
vector<int> roots;
vector<int> root_nodes;
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

void init(int n) {
    adj.clear();
    adj_rev.clear();
    adj_scc.clear();
    used.clear();
    component.clear();

    adj.resize(n);
    adj_rev.resize(n);
    adj_scc.resize(n);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("handle_list.txt","r",stdin);
    //freopen("updated_handle_list.txt","w",stdout);
    int test_case=1;
    // scanf("%d",&test_case);
    //printf("%d %d\n",'−','-');
    for(int cs=1;cs<=test_case;cs++) {
        int n,m;
        cin >> n >> m;
        init(n);
        // ... read n ...

        for (int i=0;i<m;i++) {
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
                int root_v = roots[v];
                int root_u = roots[u];

                if (root_u != root_v)
                    adj_scc[root_v].push_back(root_u);
            }
    }
  return 0;
}
