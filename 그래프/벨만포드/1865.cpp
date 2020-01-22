//웜홀 - 1865

#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

int V, E, T;
vector<vector<pair<int, int>>> adj;

void init()
{
    cin >> V >> E >> T;
    adj = vector<vector<pair<int, int>>>(V+1);
    int x, y, r;
    for(int i = 0; i<E; ++i)
    {
        cin >> x >> y >> r;
        adj[x].push_back(make_pair(y, r));
        adj[y].push_back(make_pair(x, r));
    }
    for(int i = 0; i<T; ++i)
    {
        cin >> x >> y >> r;
        adj[x].push_back(make_pair(y, -r));
    }
}

void bellmanFord()
{
    vector<int> bucket(V+1, INF);
    bucket[1] = 0;

    bool update;
    for(int iter = 0; iter < V; ++iter)
    {   
        update = false;
        for(int here = 1; here <= V; ++here)
            for(int i = 0; i<adj[here].size(); ++i)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(bucket[there] > bucket[here]+cost)
                {
                    bucket[there] = bucket[here]+cost;
                    update = true;
                }
            }
    }
    if(update)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main()
{
    int C; cin>> C;
    for(int tn = 0; tn < C; ++tn)
    {
        init();
        bellmanFord();
    }
}