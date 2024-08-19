#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int sz = 5e5 + 5, mod = 1e9 + 7;
struct node {
	string ans;
	int len;
	std::vector<int> next;
	node() {
		ans = "";
		len = -1;
		next.resize(26, 0);
	}
}arr[sz * 10];
int tim;

void insert(string s, int cnt) {
	int cur = 0;
	for(auto &u:s) {
		int a = u - 'a';
		if(!arr[cur].next[a]) 
			arr[cur].next[a] = ++tim;
		cur = arr[cur].next[a];
		if(arr[cur].len < cnt || 
			(arr[cur].ans > s && arr[cur].len == cnt)) {
			arr[cur].len = cnt;
			arr[cur].ans = s;
		}
	}
}

pair<string, int> query(string &s) {
	int cur = 0;
	string ans = "";
	int len = -1;
	// cout << s << "\n";
	for(auto &u:s) {
		int a = u - 'a';
		if(!arr[cur].next[a]) 
			return {ans, len};
		cur = arr[cur].next[a];
		// cout << cur << "\n";
	}
	return {arr[cur].ans, arr[cur].len};
}
int32_t main() {
	ios_base::sync_with_stdio(0);
  	cin.tie(0);
	int t = 1; //cin >> t;
	while(t--) {
		map<string, int>mp;
		int n; cin >> n;
		for(int i = 0; i < n; i++) {
			string a; cin >> a;
			mp[a]++;
		}
		for(auto &[s, cnt]:mp)
			insert(s, cnt);
		int q; cin >> q;
		while(q--) {
			string s; cin >> s;
			auto [ans, cnt] = query(s);
			if(cnt == -1) cout << "-1\n";
			else cout << ans << " " << cnt << "\n";
		}

	}
	return 0;
}
