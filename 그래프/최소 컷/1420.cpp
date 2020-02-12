//1420 - 학교가지마!

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000

int N, M;
vector<vector<char>> arr;
int source, sink;

int xarr[4] = {1, -1, 0, 0};
int yarr[4] = {0, 0, 1, -1};

struct Edge
{
    int target, capa, flow;
    Edge *oppo;

    int residualCapa()
    {
        if (capa == INF)
            return INF;
        return capa - flow;
    }

    void push(int amt)
    {
        flow += amt;
        oppo->flow -= amt;
    }
};

vector<vector<Edge *>> adj;

void addEdge(int u, int v, int capa)
{
    Edge *uv = new Edge();
    Edge *vu = new Edge();

    uv->target = v;
    uv->capa = capa;
    uv->flow = 0;
    uv->oppo = vu;

    vu->target = u;
    vu->capa = 0;
    vu->flow = 0;
    vu->oppo = uv;

    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

void init()
{
    cin >> N >> M;
    arr = vector<vector<char>>(N, vector<char>(M));
    adj = vector<vector<Edge *>>(2 * N * M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'K')
                source = i * M + j + N * M;
            else if (arr[i][j] == 'H')
                sink = i * M + j;
        }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (arr[i][j] != '#')
            {
                int sidx = i * M + j;
                int eidx = sidx + N * M;
                for (int k = 0; k < 4; ++k)
                    if (i + xarr[k] >= 0 && i + xarr[k] < N && j + yarr[k] >= 0 && j + yarr[k] < M && arr[i + xarr[k]][j + yarr[k]] != '#')
                    {
                        addEdge(eidx, (i + xarr[k]) * M + j + yarr[k], INF);
                        addEdge((i + xarr[k]) * M + j + yarr[k] + N * M, sidx, INF);
                    }
            }

    for (int i = 0; i < N * M; ++i)
        addEdge(i, i + N * M, 1);
}

int networkFlow(int source, int sink)
{
    int totalFlow = 0;
    while (true)
    {
        queue<int> q;
        vector<int> parent(2 * M * N, -1);
        vector<int> pidx(2 * M * N);
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int i = 0; i < adj[here].size(); ++i)
            {
                if (parent[adj[here][i]->target] == -1 && adj[here][i]->residualCapa() > 0)
                {
                    q.push(adj[here][i]->target);
                    parent[adj[here][i]->target] = here;
                    pidx[adj[here][i]->target] = i;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        for (int p = sink; p != source; p = parent[p])
            adj[parent[p]][pidx[p]]->push(1);
        totalFlow += 1;
    }
    return totalFlow;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int t = source - N * M - sink;

    if (t == M || t == -M)
        cout << -1;
    else if (sink / M == (source - N * M) / M)
    {
        if (t == -1 || t == 1)
            cout << -1;
        else
            cout << networkFlow(source, sink);
    }
    else
        cout << networkFlow(source, sink);
}