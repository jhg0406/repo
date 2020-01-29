//algospot - promises

#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

int V, M, N;
int ans;
vector<vector<int>> adj;

void init()
{
    ans = 0;
    cin >> V >> N >> M;
    adj = vector<vector<int>>(V, vector<int>(V, INF));
    for (int i = 0; i < V; ++i)
        adj[i][i] = 0;
    int x, y, r;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y >> r;
        if(adj[x][y] > r)
            adj[x][y] = adj[y][x] = r;
    }

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

void build()
{
    int x, y, r;
    cin >> x >> y >> r;
    if (adj[x][y] <= r)
    {   
        ++ans;
        return;
    }
    for(int i = 0; i<V; ++i)
        for(int j = 0; j<V; ++j)
            adj[i][j] = min(adj[i][j], min(adj[i][x] + r + adj[y][j], adj[i][y] + r + adj[x][j]));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int C;
    cin >> C;
    for (int tn = 0; tn < C; ++tn)
    {
        init();
        for (int i = 0; i < M; ++i)
            build();
        cout << ans << "\n";
    }
}