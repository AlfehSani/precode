#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const ll mod = 1e9 + 7;

inline int mul(int a, int b) {
  return 1ll * a * b % mod;
}

inline int add(int a, int b) {
  int c = a + b;
  return c >= mod ? c - mod : c;
}

struct matrix{
  int p, q, r, s;
  matrix() {}
  matrix(int p, int q, int r, int s): p(p), q(q), r(r), s(s) {
  }
  matrix operator * (matrix b) {
    return matrix(add(mul(p, b.p), mul(q, b.r)), add(mul(p, b.q), mul(q, b.s)),
        add(mul(r, b.p), mul(s, b.r)), add(mul(r, b.q), mul(s, b.s))
      );
  }
  matrix operator + (matrix b) {
    return matrix(add(p, b.p), add(q, b.q), add(r, b.r), add(s, b.s));
  }
 
};
 matrix pow(matrix a, int b) {
  matrix c(1, 0, 0, 1);
  for(int i = b; i > 0; i >>= 1) {
    if(i & 1) {
      c = (c * a);
    }
    a = a * a;
  }
  return c;
}
int main() {
matrix mtx(0,1,1,1);
int t;
scanf("%d",&t);
while(t--)
{
  int n;
  scanf("%d",&n);
  printf("%d\n",pow(mtx,n).q );
}
}