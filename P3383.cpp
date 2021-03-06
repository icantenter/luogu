#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
std::bitset<100000002> all;

inline void FindPrime(int limit, int prime[])
{
    
    int counter = 0;
    for (int i = 0; i < limit; i++)
    {
        all[i] = 1;
    }//不初始化效率更高，但可能不安全
    
    for (int i = 2; i < limit; i++)
    {
        if (all[i])//in:需要的质数范围，范围之前的质数表
        {           //out:加上了所给范围内质数的质数表
            prime[counter++] = i;
        }
        for (int j = 0; j < counter && i * prime[j] < limit; j++)
        {
            all[i * prime[j]] = 0;
            if (i % prime[j] == 0) //例如: 315=3×3×5×7; 因为去掉的合数结构是最小质因数 * 最大因数。
            {                       //315应该由3 * (3 * 5 * 7)去掉, 3后面是5,结构不对
                break;
            }
        }
    }
    return ;
}

int main()
{
    //找出范围最大max以内的素数(质数)
    int prime[6000010];
    int limit, q;
    int *ans;

    scanf("%d%d", &limit, &q);
    ans = (int *)malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++)
        scanf("%d", ans + i);
    FindPrime(limit, prime);
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", prime[ans[i] - 1]);
    }
    return 0;
}
