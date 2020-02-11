//2188 - 축사 배정

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int N, M;
vector<vector<int>> capa, flow;

void init()
{
    cin >> N >> M;
    capa = flow = vector<vector<int>>(N+M+2, vector<int>(N+M+2, 0));
    int n, y;
    for(int i = 1; i<=N; ++i)
        capa[0][i] = 1;
    for(int i = 1; i<=M; ++i)
        capa[i+N][N+M+1] = 1;
    for(int i = 1; i<=N; ++i)
    {
        cin >> n;
        for(int j = 0; j<n; ++j)
        {
            cin >> y;
            y += N;
            capa[i][y] = 1;
        }
    }
}

int networkFlow(int source, int sink)
{
    int totalFlow = 0;
    while(true)
    {
        vector<int> parent(N+M+2, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there <= N+M+1; ++there)
                if(capa[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
        }
        if(parent[sink] == -1)
            break;
        
        int amount = INF;
        for(int p = sink; p != source; p = parent[p])
            amount = min(amount, capa[parent[p]][p] - flow[parent[p]][p]);

        for(int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    cout << networkFlow(0, M+N+1);
}