#include <iostream>
#include <string>
#include <cmath>
void print(int system, std::string &_infor);

int main()
{
    std::string _infor;
    char temp;
    while (true)
    {
        std::cin >> temp;
        if (temp == 'E')
        {
            break;
        }
        _infor += temp;
    }
    print(11, _infor);
    std::cout << std::endl
              << std::endl;
    print(21, _infor);

    return 0;
}

void print(int system, std::string &_infor)
{
    int win = 0, lose = 0;
    for (int i = 0; i < _infor.length(); i++)
    {
        _infor[i] == 'W' ? win++ : lose++;
        if ((win >= system || lose >= system) && abs(win - lose) >= 2)
        {
            std::cout << win << ':' << lose << std::endl;
            win = 0;
            lose = 0;
        }
    }
    std::cout << win << ':' << lose;
}
