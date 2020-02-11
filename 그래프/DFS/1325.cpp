//1325 - 효율적인 해킹

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> hacked;

void init()
{
    cin >> N >> M;
    adj = vector<vector<int>>(N+1);
    hacked = vector<int>(N+1);
    int x, y;
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y;
        adj[y].push_back(x);
    }
}

int dfs(int here)
{
    visited[here] = true;
    int ret = 1;
    for(int i = 0; i<adj[here].size(); ++i)
    {
        int there = adj[here][i];
        if(!visited[there])
            ret += dfs(there);
    }
    return ret;
}

void dfsAll()
{
    int big = 0;
    for(int i = 1; i<=N; ++i)
    {
        visited = vector<bool>(N+1, false);
        int t = dfs(i);
        big = max(big, t);
        hacked[i] = t;
    }
    for(int i = 1; i<=N; ++i)
        if(big == hacked[i])
            cout << i << " ";
}

int main()
{
    init();
    dfsAll();
}