#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    ll n = a.size();
    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
int main()
{
    string c,d;
    ll t;
    cin >> t;
    while(t--)
    {
        cin >> c >> d;
        ll n=c.size();
        ll m=d.size();
        vector<ll>v,v1;
        for(ll i=n-1;i>=0;i--)
        {
            ll l=c[i]-'0';
            v.push_back(l);
        }
        for(ll i=m-1;i>=0;i--)
        {
            ll l=d[i]-'0';
            v1.push_back(l);
        }
        vector<ll>result;
        result=multiply(v,v1);
     // for multiply long number process those line,unless skip
     ll carry = 0;
      n=result.size();
    for (ll i = 0; i < n; i++){
        result[i] += carry;
        carry = result[i] / 10;
        result[i] %= 10;
    }
    ll k=0;
    for(ll i=n-1;i>=0;i--){
        if(result[i]>0 || k==1 || i==0)
        cout << result[i],k=1;
    }
    printf("\n");
    }
}

