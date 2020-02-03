//algospot - quantize

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 200000000

int N, S;
vector<int> v;
vector<int> subv;
vector<int> subv2;
vector<vector<int>> cache;

void init()
{
    cin >> N >> S;
    subv2 = subv = v = vector<int>(N);
    cache = vector<vector<int>>(N, vector<int>(S+1, -1));
    for(int i = 0; i<N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    subv[0] = v[0];
    for(int i = 1; i<N; ++i)
        subv[i] = subv[i-1] + v[i];

    subv2[0] = v[0]*v[0];
    for(int i = 1; i<N; ++i)
        subv2[i] = subv2[i-1] + v[i]*v[i];
}

int getMid(int start, int end)
{
    double u = subv[end] - subv[start] + v[start];
    u /= (end-start+1);
    int v = u;
    if(u - (double)v > 0.5)
        return v + 1;
    else
        return v;
}


int mini(int start, int end)
{
    int a = getMid(start, end);
    int n = end-start + 1;
    int part = subv2[end] - subv2[start] + v[start]*v[start];
    int part2 = 2*a*(subv[end]-subv[start]+v[start]);
    int part3 = n*a*a;
    return part-part2+part3;
}

int dive(int from, int part)
{
    if(from == N)
        return 0;
    if(!part)
        return INF;
    int& ret = cache[from][part];
    if(ret != -1)
        return ret;
    ret = INF;
    for(int size = 0; size < N-from; ++size)
        ret = min(ret, mini(from, from+size) + dive(from+size+1, part-1));
    return ret;
}

int main()
{
    int C; cin >> C;
    for(int tn = 0; tn<C; ++tn)
    {
        init();
        cout << dive(0, S) << "\n";
    }
}