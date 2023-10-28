#include<bits/stdc++.h>
using namespace std;
#define sz 20009
struct BIT{
    int n;
    std::vector<ll> bt;
    BIT() {}
    BIT(int _n) {
        n = _n;
        bt.resize(n + 1);
    }
    void update(int i, ll val) {
        if(i <= 0) return;
        while(i <= n) {
            bt[i] += val;
            i += i&(-i);
        }
    }
    void update(int i, int j, ll val) {
        if(i > j) return;
        update(i, val);
        update(j + 1, -val);
    }
    ll query(int l) {
        ll ans = 0;
        while(l > 0) {
            ans += bt[l];
            l -= l&-l;
        }
        return ans;
    }
    ll query(int l, int r) {
        if(l > r || l == 0) return 0LL;
        return query(r) - query(l - 1);
    }
};
int main() {
    int n; cin >> n;
    BIT bit(n);
}
