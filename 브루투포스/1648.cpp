//https://codeup.kr/problem.php?id=4458

#include <iostream>
using namespace std;

int arr[201][201];

void init()
{
    int y, x;
    cin >> y >> x;
    arr[2*x][2*y] = 3;
    int n; cin >> n;
    char c;
    int r;
    for(int i = 0; i<n; ++i)
    {
        cin >> c >> r;
        if(c == 'R')
        {
            for(int j = 2*y+1; j <= 2*(y+r); ++j)
                if(arr[2*x][j] == 0)
                    arr[2*x][j] = 1;
                else if(arr[2*x][j] == 2)
                    arr[2*x][j] = 3;
            y += r;
        }
        else if(c == 'L')
        {
            for(int j = 2*y-1; j>=2*(y-r); --j)
                if(arr[x*2][j] == 0)
                    arr[x*2][j] = 1;
                else if(arr[x*2][j] == 2)
                    arr[x*2][j] = 3;
            y -= r;
        }
        else if(c == 'U')
        {
            for(int j = 2*x+1; j <= 2*(x+r); ++j)
                if(arr[j][y*2] == 0)
                    arr[j][y*2] = 2;
                else if(arr[j][y*2] == 1)
                    arr[j][y*2] = 3;
            x += r;
        }
        else
        {
            for(int j = 2*x-1; j>= 2*(x-r); --j)
                if(arr[j][y*2] == 0)
                    arr[j][y*2] = 2;
                else if(arr[j][y*2] == 1)
                    arr[j][y*2] = 3;
            x -= r;
        }
        arr[x*2][y*2] = 3;
    }
}

int main()
{
    init();
    int ans = 10001;
    int y1, x1, y2, x2;
    for(int i = 0; i<101; ++i)
        for(int j = 0; j<101; ++j)
            if(arr[i*2][j*2] == 3)
            {
                int xp = -1, yp = -1;

                if(arr[i*2][j*2+1] == 1)
                    for(int k = 2*j+1; k<201; ++k)
                        if(arr[2*i][k] == 3)
                        {
                            yp = k/2-j;
                            break;
                        }
                if(arr[2*i+1][2*j] == 2)       
                    for(int k = 2*i+1; k < 201; ++k)
                        if(arr[k][2*j] == 3)
                        {
                            xp = k/2 - i;
                            break;
                        }
                if(xp == -1 || yp == -1)
                    continue;
                bool flag = true;
                for(int k = 2*j; k<=2*(j+yp); ++k)
                    if(arr[2*(i+xp)][k] == 0 || arr[2*(i+xp)][k] == 2)
                    {
                        flag = false;
                        break;
                    }
                for(int k = 2*i; k<=2*(i+xp); ++k)
                    if(arr[k][2*(j+yp)] == 0 || arr[k][2*(j+yp)] == 1)
                    {
                        flag = false;
                        break;
                    }
                if(!flag) continue;
                if(arr[2*(i+xp)][2*(j+yp)] == 3)
                    if(ans > xp*yp)
                    {
                        ans = xp*yp;
                        y1 = j;
                        x1 = i;
                        y2 = j+yp;
                        x2 = i+xp;
                    }
            }
    if(ans != 10001)
        cout << y1 << " " << x1 << "\n" << y2 << " " << x2;
    else
        cout << 0;
}