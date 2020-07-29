#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
std::bitset<10000005> all;
typedef int _type;

inline int FindPrime(int limit, int prime[])
{

    int counter = 0;
    //假定都all都初始化为0了
    for (int i = 2; i <= limit; i++)
    {
        if (!all[i]) //in:需要的质数范围，范围之前的质数表
        {           //out:加上了所给范围内质数的质数表
            prime[counter++] = i;
        }
        for (int j = 0; j < counter && i * prime[j] <= limit; j++)
        {
            all[i * prime[j]] = 1;
            if (i % prime[j] == 0) //例如: 315=3×3×5×7; 因为去掉的合数结构是最小质因数 * 最大因数。
            {                      //315应该由3 * (3 * 5 * 7)去掉, 3后面是5,结构不对
                break;
            }
        }
    }
    return counter;
}

inline bool isPalindromicNum(_type num)
{
    int temp = num;
    int reverse = 0;
    while (temp)
    {
        reverse = temp % 10 + reverse * 10;
        temp /= 10;
    }
    if (reverse == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int prime[10000005];
    int a, b;

    std::cin >> a >> b;

    if (b > 10000000)
    {
        b = 10000000;
    }

    FindPrime(b, prime);
    for (int i = a; i <= b; i++)
    {
        if (i > 10000000)
        {
            break;
        }
            
        if (!all[i] && isPalindromicNum(i))
        {
            printf("%d\n", i); 
        }
    }

    return 0;
}