#include <iostream>

int sum1(int x);
int sum2(int x);
int main()
{
    int a, n, m, x;

    std::cin >> a >> n >> m >> x;
    
    int b = (m - a * sum1(n - 1)) / sum2(n - 1);
    std::cout << a *  sum1(x) + b * sum2(x);
    system("pause");
    return 0;
    
}

int sum1(int x)
{
    if (x == 1)
        return 0;
    if (x == 2) return 1;
    if (x == 3)
        return 2;
    return sum1(x - 1) + sum1(x - 2) - 1;
}

int sum2(int x)
{
    if (x == 1 || x== 2 || x== 3)
        return 0;
    return sum2(x - 1) + sum2(x - 2) + 1;
}