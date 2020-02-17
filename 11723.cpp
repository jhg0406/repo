//11723 - 집합

#include <iostream>
#include <string>
using namespace std;

int N;

void add(int u)
{
    N |= (1 << u);
}

void remove(int u)
{
    N &= ~(1 << u);
}

void check(int u)
{
    if(N & (1 << u))
        cout << 1 << "\n";
    else
        cout << 0 << "\n";    
}

void toggle(int u)
{
    N ^= (1 << u);
}

void all()
{
    N = (1 << 21) - 1;
}

void empty()
{
    N = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s, s2;
    for(int i = 0; i<n; ++i)
    {
        cin >> s;
        if(s == "all")
        {
            all();
            continue;
        }
        else if(s == "empty")
        {
            empty();
            continue;
        }
        cin >> s2;
        int idx = stoi(s2);
        if(s == "add")
            add(idx);
        else if(s == "remove")
            remove(idx);
        else if(s == "check")
            check(idx);
        else if(s == "toggle")
            toggle(idx);
        else if(s == "all")
            all();
        else if(s == "empty")
            empty();     
    }
}