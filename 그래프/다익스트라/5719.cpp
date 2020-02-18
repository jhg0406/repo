//5719 - 거의 최단 경로

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 200000000

int N, M, S, D;
vector<vector<int>> adj;

void init()
{
    cin >> S >> D;
    adj = vector<vector<int>>(N, vector<int>(N, INF));
    int x, y, r;
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y >> r;
        adj[x][y] = r;
    }
}

int dijkstra()
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N, INF);
    vector<vector<int>> parent(N);
    pq.push(make_pair(0, S));
    dist[S] = 0;

    while(!pq.empty())
    {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int there = 0; there<N; ++there)
            if(cost + adj[here][there] < dist[there])
            {
                dist[there] = cost + adj[here][there];
                pq.push(make_pair(-dist[there], there));
                parent[there].clear();
                parent[there].push_back(here);
            }
            else if(cost + adj[here][there] == dist[there])
                parent[there].push_back(here);
    }

    if(dist[D] != INF)
    {
        int del = D;
        queue<int> q;
        q.push(D);
        while(!q.empty())
        {
            int from = q.front(); q.pop();
            for(int i = 0; i<parent[from].size(); ++i)
            {
                int to = parent[from][i];
                adj[to][from] = INF;
                q.push(to);
            }
        }
    }
    return dist[D];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(true)
    {
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;
        init();
        dijkstra();
        int ans = dijkstra();
        if(ans == INF)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
}