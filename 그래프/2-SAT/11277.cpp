//백준 2-SAT-1 11277

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> sccId;
stack<int> st;
int counter = 0, sccCounter = 0;
bool a_flag;

int scc(int here)
{
    int ret = discovered[here] = counter++;
    int there;
    st.push(here);
    for(int i = 0; i<adj[here].size(); i++)
    {
        there = adj[here][i];
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        else if(sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }

    if(ret == discovered[here])
    {
        int t, ori;
        while(true)
        {
            ori = st.top(); st.pop();
            t = ori%N;
            
            if(sccId[t] == -1)
                sccId[t] = sccCounter;
            else if(sccId[t] == sccCounter)
                a_flag = false;

            if(ori == here)
                break;
        }
        ++sccCounter;
    }
    return ret;
}

void tarjanScc()
{
    for(int i = 0; i<2*N; i++)
        if(discovered[i] == -1)
            scc(i);
}

int main()
{
    cin >> N >> M;
    a_flag = true;
    adj = vector<vector<int>>(2*N);
    discovered = vector<int>(2*N, -1);
    sccId = vector<int>(N, -1);
    st = stack<int>();
    int x, y;
    for(int i = 0; i<M; i++)
    {
        cin >> x >> y;
        if(x < 0) x *= -1;
        else x += N;
        if(y < 0) y *= -1;
        else y += N;
        --x; --y;

        adj[(x+N)%(2*N)].push_back(y);
        adj[(y+N)%(2*N)].push_back(x);
    }
    tarjanScc();

    if(a_flag)
        cout << "1" << endl;
    else
        cout << "0" << endl;
    
}