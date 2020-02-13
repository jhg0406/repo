//1238 - 파티

#include <iostream>
#include <vector>
using namespace std;

#define INF 101

int N, M, P;
vector<vector<int>> adj;

void init()
{
    cin >> N >> M >> P;
    adj = vector<vector<int>>(N+1, vector<int>(N+1, INF));
    int x, y, r;
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y >> r;
        adj[x][y] = r;
    }
    for(int i = 1; i<=N; ++i)
        adj[i][i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    for(int k = 1; k<=N; ++k)
        for(int i = 1; i<=N; ++i)
            for(int j = 1; j<=N; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    int ans = 0;
    for(int i = 1; i<=N; ++i)
        ans = max(ans, adj[i][P] + adj[P][i]);
    cout << ans << "\n";
}