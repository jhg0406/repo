//algospot

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<double>> cache;

void init()
{
    cout << fixed;
    cout.precision(8);
    cin >> N >> M;
    cache = vector<vector<double>>(M, vector<double>(N, -1.0));
}

double dp(int day, int met)
{
    if(day == M)
        if(met >= N)
            return 1.0;
        else
            return 0.0;

    if(met >= N)
        return 1.0;     

    double& ret = cache[day][met];
    if(ret != -1.0)
        return ret;
    
    return ret = dp(day+1, met+1)*0.25 + dp(day+1, met+2)*0.75;
}

int main()
{
    int C; cin >> C;
    for(int tn = 0; tn<C; ++tn)
    {
        init();
        cout << dp(0, 0) << "\n";
    }
}