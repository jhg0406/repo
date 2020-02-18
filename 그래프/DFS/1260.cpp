//1260 - DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, S;
vector<vector<int>> adj;
vector<bool> visit;

void init()
{
    cin >> N >> M >> S;
    adj = vector<vector<int>>(N+1);
    visit = vector<bool>(N+1, false);
    int x, y;
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i<=N; ++i)
        sort(adj[i].begin(), adj[i].end());
}

void dfs(int here)
{
    cout << here << " ";
    visit[here] = true;
    for(int i = 0; i<adj[here].size(); ++i)
    {
        int there = adj[here][i];
        if(!visit[there])
            dfs(there);
    }
}

void bfs()
{
    visit = vector<bool>(N+1, false);
    queue<int> q;
    q.push(S);
    visit[S] = true;

    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        cout << here << " ";
        for(int i = 0; i<adj[here].size(); ++i)
        {
            int there = adj[here][i];
            if(!visit[there])
            {
                visit[there] = true;
                q.push(there);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    dfs(S);
    cout << "\n";
    bfs();
}