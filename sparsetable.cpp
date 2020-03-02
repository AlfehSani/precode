#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 200009
#define K 25
// range sum queries
ll st[MAXN][K];
ll arr[MAXN];
void sum(ll N)
{
for (ll i = 0; i < N; i++)
    st[i][0] = arr[i];

for (ll j = 1; j <= K; j++){
    for (ll i = 0; i + (1 << j) <= N; i++){
        st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
    }
}
return;
}
ll querysum(ll L,ll R)
{
    ll sum = 0;
for (ll j = K; j >= 0; j--) {
    if ((1 << j) <= R - L + 1) {
        sum += st[L][j];
        L += 1 << j;
    }
}
return sum;
}
//range minimum/maximum query
ll logg[MAXN];
ll stm[MAXN][K];
void mum(ll N)
{
   logg[1] = 0;
for (ll i = 2; i <= MAXN; i++)
    logg[i] = logg[i/2] + 1;
for (ll i = 0; i < N; i++)
    stm[i][0] = arr[i];
for (ll j = 1; j <= K; j++)
    for (ll i = 0; i + (1 << j) <= N; i++)
        stm[i][j] = min(stm[i][j-1], stm[i + (1 << (j - 1))][j - 1]);//max in maximum
return;
}
ll querymum(ll L,ll R)
{
 int j = logg[R - L + 1];
int minimum = min(stm[L][j], stm[R - (1 << j) + 1][j]);//max in maximum
return minimum;
}
int main()
{
    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sum(n);
    mum(n);
    return 0;
}


