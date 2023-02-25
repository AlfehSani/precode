#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
struct vertex {
 
	int l, r, val;
	vertex() {
		l = r = -1;
		val = 0;
	}
};
vector<vertex> tre;
void get_new(int &x) {
	x = tre.size();
	tre.emplace_back();
}
void combine(int n) {
	if(~tre[n].l) {
		tre[n].val = tre[tre[n].l].val + tre[tre[n].r].val;
	}
}
void init(int n, int l, int r) {
	if(l == r) {
		return;
	}
	int mid = (l + r) / 2;
	get_new(tre[n].l);
	get_new(tre[n].r);
	init(tre[n].l, l, mid);
	init(tre[n].r, mid + 1, r);
}
int update(int n, int l, int r, int i, int val) {
	if(i > r || i < l) {
		return n;
	}
	int cur;
	get_new(cur);
	if(l == r && r == i) {
		tre[cur].val = tre[n].val + val;
		return cur;
	}
	int mid = (l + r) / 2;
	int lf = update(tre[n].l, l, mid, i, val);
	int rg = update(tre[n].r, mid + 1, r, i, val);
	tre[cur].l = lf;
	tre[cur].r = rg;
	combine(cur);
	return  cur;
}
int query(int n, int l, int r, int i, int j) {
	if(i <= l && j >= r) {
		return tre[n].val;
	}
	if(i > r || j < l)
		return 0;
	int mid = (l + r) / 2;
	return query(tre[n].l, l, mid, i, j) + query(tre[n].r, mid + 1, r, i, j);
}
int get(int nr, int nl, int l, int r, int k) {
	if(l == r){
		return l;
	}
	// cout << l << ' ' << r << '\n';
	int mid = (l + r) / 2;
	int l1 = tre[nr].l;
	int l2 = tre[nl].l;
	if((mid - l + 1) - (tre[l1].val - tre[l2].val) < k) return get(tre[nr].r, 
		tre[nl].r, mid + 1, r, k - ((mid - l + 1) - (tre[l1].val - tre[l2].val)));
	else return get(l1, l2, l, mid, k);
}
int root[MAX];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	get_new(root[0]);
	int mx = 1000006;
	init(root[0], 1, mx);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		root[i] = update(root[i - 1], 1, mx, a, 1);
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		if(l > r)
			swap(l, r);
		if(mx - (r - l + 1) < k)
			cout << k + r - l + 1 << "\n";
		else
			cout << get(root[r], root[l - 1],1,mx,k) << "\n";
	}

} 
