#include <iostream>
#include <string>
#include <cstring>
void to_Int(int a, int num[]);
inline void mul(int product[], int number);
int main()
{
    int product[5000];
    size_t size = sizeof(product);
    int t, n, a;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int counter = 0;
        std::cin >> n >> a;
        memset(product, 0, size);
        to_Int(1, product);
        for (int j = 2; j <= n; j++)
        {
            mul(product, j);
        }
        for (int j = 1; j <= product[0]; j++)
        {
            if (product[j] == a)
            {
                counter++;
            }
        }
        std::cout << counter << std::endl;
    }

    return 0;
}

inline void mul(int product[], int number)
{
    int i;
    int offset = 0;
    for (i = 1; i <= product[0]; i++)
    {
        product[i] = product[i] * number + offset;
        offset = product[i] / 10;
        product[i] %= 10;
    }
    //加上最后的offset
    while (offset)
    {
        product[i++] = offset % 10;
        offset /= 10;
    }
    //trim
    int temp_index = i;
    while (product[temp_index] == 0 && temp_index > 1)
    {
        temp_index--;
    }
    product[0] = temp_index;
}

void to_Int(int a, int num[])
{
    int counter = 0;
    while (a)
    {
        num[counter + 1] = a % 10;
        a /= 10;
        counter++;  
    }
    num[0] = counter;
}
