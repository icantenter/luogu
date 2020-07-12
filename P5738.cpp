#include <iostream>
#include <algorithm>
#include <iomanip>
int main()
{
    int x, y;
    int sum = 0;
    float ans = -1;

    std::cin >> y >> x;
    int *numbers = (int *)malloc(sizeof(int) * x);

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            std::cin >> numbers[j];
        }
        std::sort(numbers, numbers + x);
        for (int j = 1; j < x - 1; j++)
        {
            sum += numbers[j];
        }
        if (ans == -1)
        {
            ans = sum;
        }
        else if (ans < sum)
        {
            ans = sum;
        }

        sum = 0;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << ans / (x - 2);
    return 0;
}