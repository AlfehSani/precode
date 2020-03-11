#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mx 35
ll L[mx][mx];
set<string> findLCS(string X, string Y, int m, int n)
{
    set<string> s;
    if (m == 0 || n == 0)
    {
        s.insert("");
        return s;
    }
    // If the last characters of X and Y are same
    if (X[m - 1] == Y[n - 1])
    {
        // recurse for X[0..m-2] and Y[0..n-2] in
        // the matrix
        set<string> tmp = findLCS(X, Y, m - 1, n - 1);

        // append current character to all possible LCS
        // of substring X[0..m-2] and Y[0..n-2].
        for (string str : tmp)
            s.insert(str + X[m - 1]);
    }

    // If the last characters of X and Y are not same
    else
    {
        // If LCS can be constructed from top side of
        // the matrix, recurse for X[0..m-2] and Y[0..n-1]
        if (L[m - 1][n] >= L[m][n - 1])
            s = findLCS(X, Y, m - 1, n);

        // If LCS can be constructed from left side of
        // the matrix, recurse for X[0..m-1] and Y[0..n-2]
        if (L[m][n - 1] >= L[m - 1][n])
        {
            set<string> tmp = findLCS(X, Y, m, n - 1);

            // merge two sets if L[m-1][n] == L[m][n-1]
            // Note s will be empty if L[m-1][n] != L[m][n-1]
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}
int LCS(string X, string Y, int m, int n)
{
    // Build L[m+1][n+1] in bottom up fashion
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}
int main()
{
    ll t,n,m,i,j,k,l;
    scanf("%lld",&t);
    for(int cs=1;cs<=t;cs++)
    {
        string c,d;
        cin >> c >> d;
        n=c.size();
        m=d.size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                L[i][j]=0;
        }
        LCS(c,d,n,m);
        printf("%lld\n",L[n][m]);
        set<string> s = findLCS(c, d,n,m);
        for(string str: s)
        {
            cout << str << endl;
        }
    }
}

