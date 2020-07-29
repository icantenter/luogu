#include <iostream>
#include <cstring>
int main()
{
    int n, m;
    int temp;
    int _bucket[1000];
    std::cin >> n >> m;

    memset(_bucket, 0, sizeof(_bucket));
    for (int i = 0; i < m; i++)
    {
        std::cin >> temp;
        _bucket[temp]++;
    }
    for (int i = 1; i < 1000; i++)
    {
        if (_bucket[i])
        {
            for (int j = 0; j < _bucket[i]; j++)
            {
                std::cout << i << ' ';
            }
        }
    }
    return 0;
}