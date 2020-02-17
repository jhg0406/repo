//algospot - matchfix

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int N, M;
vector<int> base;
vector<vector<int>> capa, flow;
int bot;

void init()
{
    cin >> N >> M;
    base = vector<int>(N);
    capa = flow = vector<vector<int>>(N+M+2, vector<int>(N+M+2, 0));
    cin >> base[0];
    bot = base[0];
    for(int i = 1; i<N; ++i)
    {
        cin >> base[i];
        if(bot <= base[i])
            bot = base[i]+1;
    }
    capa[M+1][M+N+1] = bot - base[0];
    for(int i = M+2; i<=M+N; ++i)
        capa[i][N+M+1] = bot - base[i - M - 1] -1;
    int x, y;
    for(int i = 1; i<=M; ++i)
    {
        cin >> x >> y;
        capa[0][i] = capa[i][M+x+1] = capa[i][M+y+1] = 1;
    }
}

void adjust()
{
    for(int i = M+1; i<=M+N; ++i)
        ++capa[i][M+N+1]; 
    ++bot;
}

bool networkFlow(int source, int sink)
{
    int count = 0;
    while(true)
    {
        vector<int> parent(N+M+2, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;
        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there<=N+M+1; ++there)
                if(capa[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
        }

        if(parent[sink] == -1)
            if(count < M)
            {
                adjust();
                continue;
            }
            else
                break;
        int amt = INF;
        for(int p = sink; p != source; p = parent[p])
            amt = min(amt, capa[parent[p]][p] - flow[parent[p]][p]);
        for(int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amt;
            flow[p][parent[p]] -= amt;
        }
        ++count;
    }
    if(capa[M+1][M+N+1] - flow[M+1][M+N+1] > 0)
        return false;
    return true;
}

int main()
{
    int C; cin >> C;
    for(int tn = 0; tn< C; ++tn)
    {
        init();
        if(networkFlow(0, N+M+1))
            cout << bot << "\n";
        else
            cout << -1 << "\n";
    }
}