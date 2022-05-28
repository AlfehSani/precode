#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ios_base::sync_with_stdio(0);cin.tie(0);
  freopen("handle_list.txt","r",stdin);
  freopen("updated_handle_list.txt","w",stdout);
//check if 3 point are in a same line
ll solve(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
  ll a,b,c,d;
  a=-x1+x2;
  b=-y1+y2;
  c=-x1+x3;
  d=-y1+y3;
  if(b==0 && d==0)
    return 1;
  if(b==0 || d==0)
    return 0;
  if(a==0 && c==0)
    return 1;
  if(a==0 || c==0)
    return 0;
  if(a*d==b*c)
    return 1;
    return 0;
}
long long binpow(long long a, long long b) {
    a %= mod;
    if(a==0)
        return 0;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
//find number of co prime with i from 1 to mx
int arr[sz];
void oiler(ll n)
{
    for(int i=2;i<=n;i++)
        arr[i]=i;
    for(int i=2;i<=n;i++){
        if(arr[i]==i){
            for(int j=i;j<=n;j+=i)
                arr[j]-=arr[j]/i;
        }
    }
}
//how to read and write __int128 number
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
//mobius function
void mobius(int N) {
  mob[1] = 1;
  for (int i = 2; i < N; i++){
    mob[i]--;
    for (int j = i + i; j < N; j += i) {
      mob[j] -= mob[i];
    }
  }
}
ll factinv[sz],fact[sz],inv[sz];
ll ncr(ll n,ll r)
{
  if(r>n)
    return 0;
  ll a=(factinv[r]*factinv[n-r])%mod;
  return (a*fact[n])%mod;
}
//find inv and factinv,fact for 1 to n
void calculatefact(int n)
{
  inv[0] = inv[1] = 1;
  factinv[0]=factinv[1]=1;
  fact[0]=fact[1]=1; 
  for(int i = 2; i <= n; i++)
  {  
    inv[i] = inv[mod % i] * (mod - mod / i) %mod;
    factinv[i]=(factinv[i-1]*inv[i])%mod;
    fact[i]=(fact[i-1]*i)%mod;
  }
}
some important formula
for i 0 to a
sum of ncr(n,i)*ncr(m,a-i) = ncr(n+m,a);
for i 0 to n
sum of ncr(n,i)*ncr(m,i) = ncr(n+m,n);
for i 0 to a
sum of ncr(n+i,n) = ncr(n+a+1,n+1);
sum of divisor of n = (((p1^(e1+1))-1)/(p1-1))*pn;
phi(n)=n*((p1-1)/p1)*;
phi(a*b)=phi(a)*phi(b)*d/phi(d);

void find_articulation_bridge(ll node,ll par)
{
dis[node]=low[node]=++tim;
int children=0;
for(int u:v[node])
{
    if(u==par)
        continue;
    if(!dis[u])
    {
        find_articulation_bridge(u,node);
        if(dis[node]<low[u]){
         bridge.push_back({u,node});
        }
        low[node]=min(low[u],low[node]);
        /* articlation point
        if(low[u]>=dis[node] && par!=-1)
        point */
        children++;
    }
    else
        low[node]=min(low[node],dis[u]);
}
 /* articlation point
if(par==-1 && children>1)
point */
}
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
}
ll gcd (ll a, ll b, ll &x , ll &y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  ll x1, y1;
  ll d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
  g = gcd (abs(a), abs(b), x0, y0);
  if (c % g != 0)
    return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0)   x0 *= -1;
  if (b < 0)   y0 *= -1;
  return true;
}
void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {
  x += cnt * b;
  y -= cnt * a;
}

ll find_all_solutions (ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
  ll x, y, g;
  if (! find_any_solution (a, b, c, x, y, g)) return 0;
  a /= g;  b /= g;
  ll sign_a = a > 0 ? +1 : -1;
  ll sign_b = b > 0 ? +1 : -1;
  shift_solution (x, y, a, b, (minx - x) / b);
  if (x < minx)
    shift_solution (x, y, a, b, sign_b);
  if (x > maxx) return 0;
  ll lx1 = x;
  shift_solution (x, y, a, b, (maxx - x) / b);
  if (x > maxx)
    shift_solution (x, y, a, b, -sign_b);
  ll rx1 = x;
  shift_solution (x, y, a, b, - (miny - y) / a);
  if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
  if (y > maxy) return 0;
  ll lx2 = x;
  shift_solution (x, y, a, b, - (maxy - y) / a);
  if (y > maxy)
    shift_solution (x, y, a, b, sign_a);
  ll rx2 = x;
  if (lx2 > rx2) swap (lx2, rx2);
    ll lx = max (lx1, lx2);
  ll rx = min (rx1, rx2);
  return (rx - lx) / abs(b) + 1;
}
#define matrix vector<vector<ll> > 
matrix mul(matrix a,matrix b)
{
  matrix c(m,vector<ll>(m,0));
  ll a1=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<m;j++)
    {
     for(int k=0;k<m;k++)
     {
      c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
     }
    }
  }
  return c;
}
matrix pow(matrix v,ll val)
{
  if(val==1)
    return v;
  if(val&1)
    return mul(v,pow(v,val-1));
  matrix a=pow(v,val/2);
  return mul(a,a);
}
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
namespace mcmf{
    const int MAX = 1000010;
    const long long INF = 1LL << 60;

    long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
    int n, m, s, t, Q[10000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];
    // should call init() at first
    void init(int nodes, int source, int sink){
        m = 0, n = nodes, s = source, t = sink;
        for (int i = 0; i <= n; i++) last[i] = -1;
    }
 
    void addEdge(int u, int v, long long c, long long w){
        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
    }
 
    bool spfa(){
        int i, j, x, f = 0, l = 0;
        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;
 
        dis[s] = 0, Q[l++] = s;
        while (f < l){
            i = Q[f++];
            for (j = last[i]; j != -1; j = link[j]){
                if (flow[j] < cap[j]){
                    x = adj[j];
                    if (dis[x] > dis[i] + cost[j]){
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if (!visited[x]){
                            visited[x] = 1;
                            if (f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t] != INF);
    }
 
    pair <long long, long long> maxFlow(){
        int i, j;
        long long mincost = 0, maxflow = 0;
 
        while (spfa()){
            long long aug = INF;
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                aug = min(aug, cap[j] - flow[j]);
            }
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                flow[j] += aug, flow[j ^ 1] -= aug;
            }
            maxflow += aug, mincost += aug * dis[t];
        }
        return make_pair(maxflow, mincost);
    }
}
using namespace mcmf;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t,int siz) {
    int flow = 0;
    vector<int> parent(siz);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
void add_edge(int u,int v,int cap)
{
  adj[u].push_back(v);
  adj[v].push_back(u);//dont delete this line
  capacity[u][v]=cap;
  //capacity1[u][v]=cap;
  return;
}