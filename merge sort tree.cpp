#include<bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set t[4*sz];


int arr[sz];
void buildd(int node,int l,int r) {
	if(l == r) {
		t[node].insert({arr[l], l});
		return;
	}
	for(int i = l; i <= r; i++)
		t[node].insert({arr[i],i});
	int mid = (l + r) / 2;
	buildd(2 * node, l, mid);
	buildd(2 * node + 1, mid + 1, r);
}

int query(int node,int l,int r,int le,int ri,int v) {
	 if(l > r || l > ri || le > r || le > ri)
	  return 0;
	if(l >= le && r <= ri)
	{
		int k = t[node].order_of_key({v + 1, - 1});
		return k;
	}
	int mid = (l + r) / 2;
	return query(2 * node, l, mid, le, ri, v) + 
	query(2 * node + 1, mid + 1, r, le, ri, v);
}

void update(int node,int l,int r,int i,int v,int nw) {
	if(i < l or r < i)  return;
	t[node].erase(t[node].find({v, i}));
    t[node].insert({nw, i});
	if(l == i and r == i) return; 
	int mid=(l+r)/2;
	update(2 * node, l, mid, i, v, nw);
	update(2 * node + 1,mid + 1, r, i, v, nw);
   	return;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	buildd(1, 1, n);
	while(q--) {
		char c; cin >> c;
		if(c == 'M') {
			int i, X; cin >> i >> X;
			int v = arr[i];
			update(1, 1, n, i, v, X);
			arr[i] = X;
		} else {
			int P, Q, X; cin >> P >> Q >> X;
			cout << query(1, 1, n, P, Q, X) << "\n";
		}
	}
	return 0; 
}
