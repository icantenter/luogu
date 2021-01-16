#include <iostream>
#include <vector>
int sq[505][505], tmp[505][505];
void r_spin(int x, int y,int r);
void l_spin(int x, int y,int r);
int main()
{
    int m, n, t = 0;
    int x, y, r, z;

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sq[i][j] = ++t;
        }
    }
    
    for (int i = 0; i < m; i++) 
    {
        std::cin >> x >> y >> r >> z;
        if (z)
            l_spin(x, y, r);
        else
        {
            r_spin(x, y, r);
        }
    }
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ",sq[i][j]);
        }
        putchar('\n');
    }
    return 0;
}


void r_spin(int x, int y,int r)
{

    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r ; j++)
        {
            tmp[j - y + x][-1 * (i - x) + y] = sq[i][j];
        }
    }
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r ; j++)
        {
            sq[i][j] = tmp[i][j];
        }
    }
    
}

void l_spin(int x, int y,int r)
{

    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r ; j++)
        {
            tmp[i][j] = sq[j - y + x][-1 * (i - x) + y];
        }
    }
    for (int i = x - r; i <= x + r; i++)
    {
        for (int j = y - r; j <= y + r ; j++)
        {
            sq[i][j] = tmp[i][j];
        }
    }
    
}