#include<bits/stdc++.h> //find maximum matching in bipartite graph
using namespace std; //complexity in regular graph V*(sqrt(E))
#define sz1 200009
#define INF 1000000007
int match[sz1],dist[sz1],q[sz1],n,match1[sz1];
vector<int>adj[sz1];
bool bfs()
{
    int f = 0 , b = 0;
    for(int i=1;i<=n;i++)
    {
        if( match1[i] == 0 )
        {
            dist[i] = 0 ;
            q[f++] = i ;
        }
        else dist[i] = INF ;
    }
    dist[0] = INF ;
    while( b < f )
    {
        int x = q[b++] ;
        if( x == 0 ) continue ;
        int sz = adj[x].size();
        for(int i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == INF )
            {
                dist[match[y]] = dist[x] + 1 ;
                q[f++] = match[y];
            }
        }
    }
    return dist[0] != INF ;
}
bool dfs(int x)
{
    if( x )
    {
        int sz = adj[x].size();
        for(int i=0;i<sz;i++)
        {
            int y = adj[x][i];
            if( dist[match[y]] == dist[x] + 1 && dfs(match[y]))
            {
                match1[x] = y ;
                match[y] = x ;
                return 1 ;
            }
        }
        dist[x] = INF ;
        return 0 ;
    }
    return 1 ;
}
int hopcropt()
{
    for(int i=1;i<=n;i++)
        adj[i].clear();
    for(int i=1;i<=n;i++)
        dist[i]=match[i]=q[i]=match1[i]=0;
    int matching = 0 ;
    while( bfs() )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            if( match1[i] == 0 && dfs(i) )
            {
                matching++;
            }
        }
    }
    return  matching ;
}
int main()
{
   hopcropt();
}
