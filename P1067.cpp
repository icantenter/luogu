#include <iostream>

int main()
{
    int n, a;
    std::cin >> n;

    for (int i = n; i >= 0; i--)
    {
        std::cin >> a;
        if (a != 0)
        {
            if (i != n && a > 0)
            {
                std::cout << '+';
            }
            if (abs(a) > 1 || i == 0)
            {
                std::cout << a;
            }
            
            if (a == -1 && i)
            {
                std::cout << '-';
            }
            else if (i > 1)
            {
                std::cout << "x^" << i;
            }
            else if (i == 1)
            {
                std::cout << "x";
            }else
            {
                std::cout << 1;
            }
            
            
        }
    }
    return 0;
}