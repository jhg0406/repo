//1504 - 특정한 최단 경로

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 200000000

int N, M, U, V;
vector<vector<pair<int, int>>> adj;

void init()
{
    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N+1);
    int x, y, r;
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y >> r;
        adj[x].push_back(make_pair(y, r));
        adj[y].push_back(make_pair(x, r));
    }
    cin >> U >> V;
}

int dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> pq;
    vector<int> cost(N+1, INF);
    pq.push(make_pair(0, start));
    cost[start] = 0;

    while(!pq.empty())
    {
        int here = pq.top().second;
        int base = -pq.top().first;
        pq.pop();

        if(cost[here] == base)
            for(int i = 0; i<adj[here].size(); ++i)
            {
                int there = adj[here][i].first;
                int Cost = adj[here][i].second + base;
                if(Cost < cost[there])
                {
                    cost[there] = Cost;
                    pq.push(make_pair(-Cost, there));
                }
            }
    }
    return cost[end];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t = min(dijkstra(1, U) + dijkstra(V, N), dijkstra(1, V) + dijkstra(U, N)) + dijkstra(U, V);
    cout << (t >= INF ? -1 : t);    
}