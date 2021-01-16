#include <iostream>
#include <string>
int p1, p2, p3;
int main()
{
    std::string tmp;

    std::cin >> p1 >> p2 >> p3;
    std::cin >> tmp;
   
    for (size_t i = 0; i < tmp.size(); ++i)
    {
        if (tmp[i] == '-')
        {
            if ((isdigit(tmp[i - 1]) && isdigit(tmp[i + 1]))
            || (isalpha(tmp[i - 1]) && isalpha(tmp[i + 1])))
            {
                foo(tmp[i - 1], tmp[i + 1]);
            }
            
        }
        else
        {
            /* code */
        }
        
    }

}

void foo(int a, int b)
{

}