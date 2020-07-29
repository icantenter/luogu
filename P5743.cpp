#include <iostream>
int peach(int day);

int main()
{
    int day;
    std::cin >> day;
    std::cout << peach(day);
    return 0;
}

int peach(int day)
{
    if (day == 1)
    {
        return 1;
    }
    return (1 + peach(day - 1)) * 2;
}