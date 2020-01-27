//히스토그램에서 가장 큰 직사각형 - 6549

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
long long ans;
vector<int> h;
vector<int> Left;
vector<int> Right;

void sweeping()
{
    stack<int> s;
    s.push(0);
    int bidx;
    for (int i = 1; i <= N; ++i)
    {
        while (true)
        {
            bidx = s.top();
            if (h[bidx] < h[i])
            {
                Left[i] = bidx;
                s.push(i);
                break;
            }
            else
            {
                Right[bidx] = i;
                ans = max(ans, ((long long)h[bidx] * (long long)(Right[bidx] - Left[bidx]-1)));
                s.pop();
            }
        }
    }
    while(!s.empty())
    {
        bidx = s.top(); s.pop();
        ans = max(ans, ((long long)h[bidx]*(long long)(N-Left[bidx])));
    }
    cout << ans << "\n";
}

void solve()
{
    Left = Right = h = vector<int>(N + 1);
    Left[0] = h[0] = -1;
    for (int i = 1; i <= N; ++i)
        cin >> h[i];
    sweeping();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (true)
    {
        cin >> N;
        if (!N)
            break;
        ans = 0;
        solve();
    }
}