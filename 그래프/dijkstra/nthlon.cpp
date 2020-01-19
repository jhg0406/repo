//algospot - nthlon

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000

int M;
vector<vector<pair<int, int>>> adj;

void init()
{
    cin >> M;
    adj = vector<vector<pair<int, int>>>(400);
    int x, y, gap;
    for(int i = 0; i<M; i++)
    {
        cin >> x >> y;
        gap = x-y;
        for(int j = 1; j<400; ++j)
        {
            if(j+gap < 1 || j+gap >= 400) continue;

            adj[j].push_back(make_pair(j+gap, x));
        }
        adj[0].push_back(make_pair(200+gap, x));
    }
}

void dijkstra()
{
    vector<int> bucket(400, INF);
    priority_queue<pair<int, int>> pq;
    bucket[0] = 0;
    pq.push(make_pair(0, 0));

    int here, cost;
    while(!pq.empty())
    {
        here = pq.top().second;
        cost = -pq.top().first;
        pq.pop();

        if(cost > bucket[here]) continue;

        for(int i = 0; i<adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int c = adj[here][i].second;
            if(c+cost < bucket[there])
            {
                bucket[there] = c+cost;
                pq.push(make_pair(-(c+cost), there));
            }
        }
    }
    if(bucket[200] == INF)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << bucket[200] << "\n";
}

int main()
{
    int C; cin >> C;
    for(int t_num = 0; t_num < C; ++t_num)
    {
        init();
        dijkstra();
    }
}