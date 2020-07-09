#include <iostream>
#include <algorithm>
#include <string>


int main()
{
    std::string star, queue;
    int star_sum = 1, queue_sum = 1;

    std::cin >> star >> queue;

    for (std::string::iterator i = star.begin(); i < star.end(); i++)
    {
        star_sum *= (*i - 'A' + 1);
    }
    for (std::string::iterator i = queue.begin(); i < queue.end(); i++)
    {
        queue_sum *= (*i - 'A' + 1);
    }
    if (star_sum % 47 == queue_sum % 47)
    {
        std::cout << "GO";
    }
    else
    {
        std::cout << "STAY";
    }
    
    return 0;
}