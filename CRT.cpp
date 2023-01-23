#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200005
#define f first
#define s second
#define pa pair<ll,ll>
#define mod 1000000007
#define vec array<ll,3>
ll inv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
  
    if (m == 1)
        return 0;
  
    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
  
        t = m;
  
        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;
  
        t = x0;
  
        x0 = x1 - q * x0;
  
        x1 = t;
    }
  
    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
  
    return x1;
}
  
// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
ll findMinX(ll num[], ll rem[], ll k)
{
    // Compute product of all numbers
    ll prod = 1;
    for (ll i = 0; i < k; i++)
        prod *= num[i];
  
    // Initialize result
    ll result = 0;
  
    // Apply above formula
    for (ll i = 0; i < k; i++) {
        ll pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }
  
    return result % prod;
}
ll num[] = {2,3,5,7,11,13,17,19,23};
ll rem[9];
vector<ll> kora (vector<ll>v) {
    ll n = v.size();
    std::vector<ll> v1(n);
    for(ll i=0;i<n;i++)
        v1[i] = v[v[i]-1];
    return v1;
}  
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("handle_list.txt","r",stdin);
    //freopen("updated_handle_list.txt","w",stdout);
    ll test_case=1;
    //cin >> test_case;
    for(ll cs = 1; cs <= test_case ; cs++) {
        ll m = 100;
        std::vector<ll> v(m);
        ll k = sizeof(num) / sizeof(num[0]);
        ll lst = 0;
        ll i = 0;
        while(i < k) {
            for(ll j = 1;j < num[i]; j++)
                v[lst + j - 1] = lst + j + 1;
            
            v[lst + num[i] - 1] = lst + 1;
            
            lst += num[i];
            
            i++;
        }
        
        cout << m << endl;
        
        for(ll i = 0 ; i < m; i++) {
            if(i)
                cout <<" ";
            cout << v[i];
        }
        cout << endl;

        std::vector<ll> v1(m);
        for(ll &u:v1)
            cin >> u;
        // v1 = kora(v);
        // cout <<"\n";
        // for(ll u:v1)
        //     cout << u <<" ";
        // cout <<"\n";
        lst = i = 0;
        while(i < k) {
            for(ll j = 0; j < num[i];j++)
                if(v1[j+lst] == v[lst])
                    rem[i] = (num[i] - j)%num[i];
            //cout << rem[i] <<"\n";
            lst += num[i];
            i++;
        }
        cout <<findMinX(num,rem,k) + 1 << endl; 
         
    }


  return 0;
}