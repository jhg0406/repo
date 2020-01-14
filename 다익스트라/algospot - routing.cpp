//algospot - routing

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, double>>> adj;
vector<double> c;

void init()
{
    cin >> N >> M;    
    adj = vector<vector<pair<int, double>>>(N);
    c = vector<double>(N, 0);
    int x, y;
    double z;
    for(int i = 0; i<M; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
}

double dijkstra()
{
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(-1, 0));
    int here; double cost;
    int there; double mul;
    while(true)
    {
        here = pq.top().second; cost = pq.top().first;
        if(here == N-1)
            return -cost;
        pq.pop();
        if(!c[here] || cost <= c[here])
        {
            for(int i = 0; i<adj[here].size(); ++i)
            {
                there = adj[here][i].first;
                mul = adj[here][i].second;
                if(!c[there] || cost*mul > c[there])
                {
                    c[there] = cost*mul;
                    pq.push(make_pair(cost*mul, there));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int C; cin >> C;
    for(int t_num = 0; t_num < C; ++t_num)
    {
        init();
        cout.setf(ios::fixed);
        cout.precision(10);
        cout << dijkstra() << "\n";
    }
}