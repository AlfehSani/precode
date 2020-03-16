//Copied from tahseen bhai
// Complexity O(n+m)
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 10009
vector<int>adj[sz];
vector<pair<int,int> > ans;
int n,t,i;
vector<bool> visited(sz);
vector<int> tin(sz),low(sz);
int timer;
void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                if(v<to)
                ans.push_back({v,to});
               else
               ans.push_back({to,v});
            }
        }
    }
}
void find_bridges() {
    timer = 0;
    for (int ii = 0; ii < n; ++ii) {
        if (!visited[ii])
            dfs(ii,-1);
    }
}
int main()
{
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         int a,b;
         scanf("%d %d",&a,&b);
         adj[a].push_back(b);
         adj[b].push_back(a);
     }
     find_bridges();
}

