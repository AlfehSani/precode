#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
map<ll,ll>phi;
ll MOD(ll x,ll p){
	return x>p?x%p+p:x;
}
ll poww(ll a,ll b,ll m){
	ll res=1;
	while(b){
		if(b&1)res*=a,res=MOD(res,m);
		a*=a,a=MOD(a,m);
		b>>=1;
	}
	return res%m;
}
ll getphi(ll m){
	if(phi[m]!=0)return phi[m];
	ll res=m;
	for(ll i=2;i<=m/i;i++){
		if(m%i==0){
			res=res/i*(i-1);
			while(m%i==0){
				m=m/i;
			}
		}
	}
	if(m>1)res=res/m*(m-1);
	return phi[m]=res;
}
ll solve(ll L,ll R,ll m){
	if(m==1)return 1;
	if(L==R)return MOD(a[R],m);
	return poww(a[L],solve(L+1,R,getphi(m)),m);

}
int main(){
	ll n;ll m;ll q;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	//find solution for a^b^c^d^d......mod m;
	while(q--){
		ll L;ll R;
		cin>>L>>R;
		cout<<solve(L,R,m)%m<<"\n";
	}
	return 0;
}
