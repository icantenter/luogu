#include <iostream>
#include <cmath>
typedef long long int _type;

int main()
{
    _type num, sum = 0;
    _type counter = 0;

    while (std::cin >> num)
    {
        sum += num;
        counter++;
    }
    sum *= pow(2, counter - 1);
    std::cout << sum;
    return 0;
}