#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 400009
#define sz1 109
#define mod 1000000007
//#define mod 998244353
#define pr1 577
#define pr2 593
#define inf 1e18 
#define f first
#define s second
#define pa pair<ll,ll>
#define eps 1e-6
#define eps1 1e-8
#define pi acos(-1.0)
#define matrix vector<vector<ll> > 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll m;
void mul(matrix &mat1, matrix &mat2)
{
  int a=mat1.size();
  int b=mat1[0].size();
  int c=mat2[0].size();
  int d=mat2.size();
  //assert(b==d);
  matrix ret(a,vector<int>(c));
  for(int i=0;i<a;i++)
    for(int k=0;k<b;k++)
      for(int j=0;j<c;j++){
        ret[i][j]+=(1ll*mat1[i][k]*mat2[k][j])%mod;
        if(ret[i][j] >= mod)
        ret[i][j]-=mod;
      }
     mat1 = ret;
  //return ret;
}
 
matrix pow(matrix v,ll val)
{
  if(val==1)
    return v;
	matrix ans(2,vector<int>(2,1));
	int ektao = 0;
	while(val) {
		if(val&1){
			if(ektao)
				mul(ans,v);
			else
				ans = v;
			ektao++;
		}
		mul(v,v);
		val /= 2;
	}
  return ans;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("table.in","r",stdin);
  // freopen("output.txt","w",stdout);
  int test_case=1;
 // scanf("%d",&test_case);
  for(int cs=1;cs<=test_case;cs++)
  {
     m=3;
   matrix v(m,vector<ll>(m,0));
   matrix a=pow(v,0);
  }
  return 0;
}
