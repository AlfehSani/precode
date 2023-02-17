#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct bol {
    ll sum,lz;
    bol() {
        sum = lz = 0;
    }
};
struct segment_tree{
    std::vector<bol> t;
    int n;
    segment_tree(int _n) {
        t.resize(4 * _n + 1);
        n = _n;
    }
    bol merge(bol a,bol b) {
        bol c;
        c.sum = a.sum + b.sum;
        return c;
    }
    int chk(int a,int b,int c,int d) {
        if(a > b || a > d || c > d || c > b)
            return 1;
        return 0;
    }
    bol query(int node, int l, int r, int le, int ri) {
        bol c;
        if(chk(l, r, le, ri))
            return c;
        if(l >= le && r <= ri)
            return t[node];
        int mi = (l + r) / 2;
        bol a = query(2 * node, l, mi, le, ri);
        bol b = query(2 * node + 1, mi + 1, r, le, ri);
        return merge(a, b);
    }
    bol query(int l, int r) {
        return query(1, 1, n, l, r);
    }
    void update(int node, int l, int r, int le, int ri, int vala) {
        if(chk(l, r, le, ri))
            return;
        if(l >= le && r <= ri) {
            t[node].lz += vala;
            t[node].sum += 1LL*(r - l + 1) * vala;
            return;
        }
        int mi = (l + r) / 2;
        update(2 * node, l, mi, le, ri, vala);
        update(2 * node + 1, mi + 1, r, le, ri, vala);
        t[node] = merge(t[2 * node], t[2 * node + 1]);
        return;
    }
    void update(int le, int ri, int vala) {
        update(1, 1, n, le, ri, vala);
    }
};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test_case=1;
    cin >> test_case;
    for(int cs = 1; cs <= test_case; cs++) {
   
    }
    return 0;
}
