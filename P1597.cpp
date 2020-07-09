#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <string>

int main()
{
    std::map<char, int> var;
    std::string statement;

    var['a'] = 0;
    var['b'] = 0;
    var['c'] = 0;

    std::cin >> statement; //数字和字符混合， 做字符处理方便
    for (std::string::iterator i = statement.begin(); i < statement.end(); i += 5)
    {
        if (isdigit(*(i + 3)))
        {
            var[*i] = *(i + 3) - '0';
        }
        else
        {
            var[*i] = var[*(i + 3)];
        }
    }
    std::cout << var['a'] << ' ' << var['b'] << ' ' << var['c'];
    return 0;
}