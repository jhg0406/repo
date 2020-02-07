//poly

#include <iostream>
#include <vector>
using namespace std;

#define MOD 10000000

int N;
vector<vector<int>> cache;

void init()
{
    cin >> N;
    cache = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
}

int dp(int n, int first)
{
    if (n == first)
        return 1;

    int &ret = cache[n][first];
    if (ret != -1)
        return ret;
    ret = 0;

    for (int i = 1; i <= n - first; ++i)
    {
        ret += (first + i - 1) * dp(n - first, i);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    int C;
    cin >> C;
    for (int tn = 0; tn < C; ++tn)
    {
        init();
        int ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            ans += dp(N, i);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}