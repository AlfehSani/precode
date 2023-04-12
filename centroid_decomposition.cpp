#include<bits/stdc++.h>
using namespace std;
#define sz1 200005
vector<int> adj[sz1];
int tot, done[sz1], cenpar[sz1], sz[sz1];
void calc_sz(int u, int p) {
    tot ++;
    sz[u] = 1;
    for (auto v : adj[u]) {
        if(v == p || done[v]) continue;
        calc_sz(v, u);
        sz[u] += sz[v];
    }
}
int find_cen(int u, int p) {
    for (auto v : adj[u]) {
        if(v == p || done[v]) continue;
        else if(sz[v] > tot / 2) return find_cen(v, u);
    }
    return u;
}
void decompose(int u, int pre) {
    tot = 0;
    calc_sz(u, pre);
    int cen = find_cen(u, pre);
    cenpar[cen] = pre;
    done[cen] = 1;
    for(auto v : adj[cen]) {
        if(v == pre || done[v]) continue;
        decompose(v, cen);
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 2; i <= n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        decompose(1, -1);
        for(int i = 1; i <= n; i++) cout << cenpar[i] << " ";
        cout << "\n"; 
    }
} 