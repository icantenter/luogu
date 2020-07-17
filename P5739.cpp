#include <iostream>
int fac(int n);
int main()
{
    int num;

    std::cin >> num;
    std::cout << fac(num);
    return 0;
}

int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fac(n - 1);
    }
    
}