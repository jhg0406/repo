//algospot - lan

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x;
vector<int> y;
vector<pair<double, pair<int, int>>> edges;

struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 1)
    {
        for(int i = 0; i<n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
};


double distance(double x1, double x2, double y1, double y2)
{
    double ret = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    return ret;
}

void init(DisjointSet& sets)
{
    edges.clear();
    x = y = vector<int>(N);
    for(int i = 0; i<N; ++i)
        cin >> x[i];
    for(int i = 0; i<N; ++i)
        cin >> y[i];
    double r;
    for(int i = 0; i<N; ++i)
        for(int j = i+1; j<N; ++j)
        {
            r = distance(x[i], x[j], y[i], y[j]);
            edges.push_back(make_pair(r, make_pair(i, j)));
        }
    sort(edges.begin(), edges.end());
    int a, b;
    for(int i = 0; i<M; ++i)
    {
        cin >> a >> b;
        sets.merge(a, b);
    }
}

double kruskal(DisjointSet& sets)
{
    int u, v;
    double ret = 0;
    double cost;
    for(int i = 0; i<edges.size(); ++i)
    {
        cost = edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;

        sets.merge(u, v);
        ret += cost;
    }
    return ret;
}

int main()
{
    int C; cin >> C;
    cout << fixed;
    cout.precision(8);  
    for(int tn = 0; tn < C; ++tn)
    {
        cin >> N >> M;
        DisjointSet sets(N);
        init(sets);
        cout << kruskal(sets) << "\n";
    }
}