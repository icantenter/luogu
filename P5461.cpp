#include <iostream>
#include <cmath>
#include <cstring>
const int max = 1050;
bool rect[max][max];

void foo(int x, int y, int size);
int main()
{
    int n;

    std::cin >> n;
    n = pow(2, n);
    for (int i = 0; i < n; i++)
    {
        memset(rect + i, true, n * sizeof(bool));
    }

    foo(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rect[i][j])
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
            if (j != n - 1)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

void foo(int x, int y, int size)
{

    for (int i = 0; i < size / 2; i++)
    {
        memset(rect[i + y] + x, false, size / 2 * sizeof(bool));
    }
    if (size == 2)
    {
        return;
    }
    foo(x + size / 2, y, size / 2);
    foo(x, y + size / 2, size / 2);
    foo(x + size / 2, y + size / 2, size / 2);
}