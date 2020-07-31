#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

void trim_front(std::string &src);
void trim_behind(std::string &src);
int main()
{
    std::string number;
    std::string front, behind;
    char ch;
    std::cin >> number;

    for (std::string::iterator i = number.begin(); i < number.end(); i++)
    {
        if (*i < '0' || *i > '9')
        {
            front = std::string(number.begin(), i);
            behind = std::string(i + 1, number.end());
            ch = *i;
        }
    }
    reverse(front.begin(), front.end());
    trim_front(front);
    switch (ch)
    {
    case '%':
        number = front + ch;
        break;
    case '.':
    case '/':
        reverse(behind.begin(), behind.end());
        trim_behind(behind);
        trim_front(behind);
        number = front + ch + behind;
        break;
    default:
        reverse(number.begin(), number.end());
        trim_front(number);
    }
    std::cout << number;
    system("pause");
}

void trim_front(std::string &src)
{
    for (int i = 0; ; i++) 
    {
        if (src[i] != '0' || i == src.length() - 1)
        {
            src = src.substr(i);
            return ;
        }
    }
}

void trim_behind(std::string &src)
{
    for (int i = src.length() - 1; ; i--) 
    {
        if (src[i] != '0' || i == 0)
        {
            src = src.substr(i);
            return ;
        }
    }
}