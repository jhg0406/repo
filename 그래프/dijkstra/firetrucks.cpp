//algospot - firetrucks
 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
#define INF 2000000000
 
int V, E, N, M;
vector<vector<pair<int, int>>> adj;
vector<int> firePlc;
vector<int> mini;
 
void init()
{
    cin >> V >> E >> N >> M;
    adj = vector<vector<pair<int, int>>>(V + 1);
    firePlc = vector<int>(N);
    mini = vector<int>(V+1, INF);
    int x, y, r;
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y >> r;
        adj[x].push_back(make_pair(y, r));
        adj[y].push_back(make_pair(x, r));
    }
    for (int i = 0; i < N; i++)
        cin >> firePlc[i];
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        adj[0].push_back(make_pair(x, 0));
    }
}
 
void dijkstra()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,0));
    mini[0] = 0;
 
    int here, cost;
    while(!pq.empty())
    {
        here = pq.top().second;
        cost = -pq.top().first;
        pq.pop();
 
        if(mini[here] >= cost)
            for(int i = 0; i<adj[here].size(); ++i)
            {
                int there = adj[here][i].first;
                int c = adj[here][i].second;
                if(c+cost < mini[there])
                {
                    mini[there] = c+cost;
                    pq.push(make_pair(-(c+cost), there));
                }
            }
    }
    int ans = 0;
    for(int i = 0; i<N; i++)
        ans += mini[firePlc[i]];
    cout << ans << "\n";
}
 
int main()
{
    int C;
    cin >> C;
    for (int t_num = 0; t_num < C; ++t_num)
    {
        init();
        dijkstra();
    }
}