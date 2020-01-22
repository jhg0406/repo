//타임머신 - 11657

#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

int V, E;
vector<vector<pair<int, int>>> adj;

void bellmanFord()
{
    vector<int> bucket(V + 1, INF);
    bucket[1] = 0;

    int update;
    for (int iter = 0; iter < V; ++iter)
    {
        update = false;
        for (int here = 1; here <= V; ++here)
            for (int i = 0; i < adj[here].size(); ++i)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (bucket[here] != INF && bucket[there] > bucket[here] + cost)
                {
                    update = true;
                    bucket[there] = bucket[here] + cost;
                }
            }
        if (!update)
            break;
    }
    if (update)
        cout << -1 << "\n";
    else
        for (int i = 2; i <= V; ++i)
            if (bucket[i] == INF)
                cout << -1 << "\n";
            else
                cout << bucket[i] << "\n";
}

int main()
{
    cin >> V >> E;
    adj = vector<vector<pair<int, int>>>(V + 1);
    int x, y, r;
    for (int i = 0; i < E; ++i)
    {
        cin >> x >> y >> r;
        adj[x].push_back(make_pair(y, r));
    }

    bellmanFord();
}