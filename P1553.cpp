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
    if (src == "0")
    {
        return;
    }
    for (std::string::iterator i = src.begin(); i < src.end(); i++)
    {
        if (*i != '0')
        {
            src = std::string(i, src.end());
            break;
        }
    }
}

void trim_behind(std::string &src)
{
    if (src == "0")
    {
        return;
    }
    for (std::string::iterator i = src.end() - 1; i >= src.begin(); i--)
    {
        if (*i != '0')
        {
            src = std::string(src.begin(), i + 1);
            break;
        }
    }
}