#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;

#define MODMATEXPO mod

#define ll long long
template<typename intex, int N>
struct matrix {
    intex x[N + 1][N + 1];
    
    matrix(intex v = 0) {
        memset(x, 0, sizeof x);
        for (int i = 1; i <= N; i++) {
            x[i][i] = v;
        }
    }

    intex * operator [] (int a) {return x[a];}

    inline matrix operator*(const matrix &r) {
        matrix<intex, N> p(0);
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                if (x[i][k] == 0) continue;
                for (int j = 1; j <= N; ++j) {
                    p.x[i][j] += x[i][k] * r.x[k][j];

#ifdef MODMATEXPO
                    p.x[i][j] %= MODMATEXPO;
#endif
                }
            }
        }
        return p;
    }
    
    inline matrix mul(const matrix &r, const int col) {
        matrix<intex, N> p(0);
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                if (x[i][k] == 0) continue;
                for (int j = 1; j <= col; ++j) {
                    p.x[i][j] += x[i][k] * r.x[k][j];

#ifdef MODMATEXPO
                    p.x[i][j] %= MODMATEXPO;
#endif
                }
            }
        }
        return p;
    }
    inline matrix pow(ll p) {
        matrix r(1), a = *this;
        for (; p > 0 ; p >>= 1) {
            if (p & 1) r = r * a;
            a = a * a;
        }
        return r;
    }
    intex determinant() const {
        intex r = 1, det[N + 1][N + 1];
        for (int i = 1; i <= N; ++i) memcpy(det[i], x[i], sizeof(x[i]));
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                while (det[j][i] != 0) {
                    intex ratio = det[i][i] / det[j][i];
                    for (int k = i; k <= N; ++k) {
                        det[i][k] -= ratio * det[j][k];
                        swap(det[i][k], det[j][k]);
                    }
                    r = -r;
                }
            }
            r = r * det[i][i];
        }
        return r;
    }
    void print() {
        cout << N << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                cout << x[i][j] << " \n"[j == N];
        }
    }
};


int main(int argc, char const *argv[])
{

    int n; cin >> n;
    matrix<int, 3> mat;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
             cin >> mat.x[i][j];
            //cin >> mat[i][j];
        }
    }
    mat.print();
    // int t;
    // scanf("%d",&t);
    // for(int I=1;I<=t;I++)
    // {

    //  printf("Case %d: ",I);
    //  int a,b,c,d,n;
    //  scanf("%d %d %d %d",&n,&a,&b,&c);
    //  matrix<int,4> arr;
    //  matrix<int,4> brr;
    //  int br[]={0,0,0,c};
    //  brr.init(br,4,1);
    //  int ar[]={a,0,b,1,1,0,0,0,0,1,0,0,0,0,0,1};
    //  arr.init(ar,4,4);
    //  arr=arr.pow(n);
    //  arr=arr*brr;
    //  // arr=arr.mul(brr,1);//matrix,col
    //  printf("%d\n", arr.x[3][1]);
    // }
    return 0;
}
