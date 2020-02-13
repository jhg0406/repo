//2463 - 비용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000000

int N, M;
vector<pair<int, pair<int, int>>> edge;
vector<int> msize;

struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n+1), rank(n+1, 1)
    {
        for(int i = 1; i<=n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {  
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v)
    {
        u = find(u); v = find(v);
        if(u == v) return false;
        if(rank[u] > rank[v]) swap(u, v);
        msize[v] += msize[u];
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
        return true;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    msize = vector<int>(N+1, 1);
    int x, y, r;
    long long ans = 0;
    long long allSum = 0;
    DisjointSet sets(N);
    edge = vector<pair<int, pair<int, int>>>(M);
    for(int i = 0; i<M; ++i)
    {
        cin >> x >> y >> r;
        allSum += r;
        edge[i].first = -r;
        edge[i].second.first = x;
        edge[i].second.second = y;
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i<M; ++i)
    {
        long long u = msize[sets.find(edge[i].second.first)];
        long long v = msize[sets.find(edge[i].second.second)];
        if(sets.merge(edge[i].second.first, edge[i].second.second))
        {
            ans += (u*v%MOD)*allSum%MOD;
            ans %= MOD;
        }
        allSum += edge[i].first;
    }
    cout << ans;
}