#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#define MAXN 110
bool path[MAXN][MAXN];
long long map[MAXN][MAXN];
int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    int bx, by;
    int hx, hy;

    std::cin >> bx >> by >> hx >> hy;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < sizeof(x) / sizeof(int); i++) 
    {
        if (hx + x[i] <= bx && hx + x[i] >= 0
            && hy + y[i] <= by && hy + y[i] >= 0)
        map[hx + x[i]][hy + y[i]] = 1;
    }
    for (int i = 0; i <= bx; i++) 
    {
        if (!map[0][i])
        {
            path[0][i] = 1;
        }
        
    }
    for (int j = 0; j <= by; j++) 
    {
        if (!map[j][0])
        {
            path[j][0] = 1;
        }
    }
    for (int i = 0; i <= bx; i++) 
    {
        for (int j = 0; j <= by; j++)
        {
            if (map[j][i])
            {
                path[j][i] = 0;
            }
            else
            {
                path[j][i] = path[j - 1][i] + path[j][i - 1];
            }
            
        }
    }
    std::cout << path[by][bx];
    return 0;
    
    
}