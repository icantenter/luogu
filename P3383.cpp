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
    }
    
    for (int i = 2; i < limit; i++)
    {
        if (all[i])
        {
            prime[counter++] = i;
        }
        for (int j = 0; i * prime[j] < limit; j++)
        {
            all[i * prime[j]] = 0;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return ;
}

int main()
{
    //找出范围最大max以内的素数(质数)
    int prime[1000000];
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
