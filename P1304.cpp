#include <iostream>
#include <cmath>
typedef int _type;
bool isprime(_type number);

int main()
{
    int N;

    std::cin >> N;

    for (int i = 4; i <= N; i += 2) 
    {
        if (isprime(i - 2)) 
        {
            std::cout << i << '=' << 2 << '+' << i - 2 << std::endl;
            continue;
        }  
        for (int j = 3; ; j += 2) 
        {
            if (isprime(j) && isprime(i - j))
            {
                std::cout << i << '=' << j << '+' << i - j << std::endl;
                break;
            }    
        }
        
    }
    return 0;
}

bool isprime(_type number)
{
    for (int i = 2; i <= sqrt(number); i++) 
    {
        if (number % i == 0)
        {
            return false;
        }
        
    }
    return true;
}