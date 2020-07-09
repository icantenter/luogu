#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>
#include <string>

int main()
{
    std::string letters;
    int counter[26], max;

    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < 4; i++)
    {
        getline(std::cin ,letters);

        for (std::string::iterator i = letters.begin(); i < letters.end(); i++)
        {
            if (isalpha(*i))
            {
                counter[*i - 'A']++;
            }
        }
    }
    max = counter[0];
    for (auto &&i : counter)
    {
        max = std::max(i, max);
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (counter[j] >= i)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
            if (j != 25)
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 26; i++)
    {
        std::cout << char(i + 'A');
        if (i != 25)
        {
            std::cout << ' ';
        }
    }
    return 0;
}