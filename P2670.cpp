#include <iostream>
#include <cstring>
bool _map[102][102];
int main()
{
    int n, m;
    char temp;

    memset(_map, false, sizeof(_map));
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> temp;
            if (temp == '*')
            {
                _map[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (_map[i][j])
            {
                std::cout << '*';
            }
            else
            {
                std::cout << _map[i + 1][j + 1] 
                + _map[i + 1][j - 1] + _map[i + 1][j] 
                + _map[i][j + 1] + _map[i][j - 1] 
                + _map[i - 1][j + 1] + _map[i - 1][j] 
                + _map[i - 1][j - 1];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}