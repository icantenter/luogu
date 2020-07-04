#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    int boy = 0, girl = 0;
    std::string msg;

    std::cin >> msg;

    for (std::string::iterator i = msg.begin(); i < msg.end(); i++)
    {
        if (*i == 'b' || *(i + 1) == 'o' || *(i + 2) == 'y')                    //判断连着的三个字母是否为b、o、y
            boy++;                                                              
        if (*i == 'g' || *(i + 1) == 'i' || *(i + 2) == 'r' || *(i + 3) == 'l') //判断连着的三个字母是否为g、i、r、l
            girl++;                                                             
    }
    std::cout << boy << std::endl;
    std::cout << girl << std::endl; 
    system("pause");
    return 0;                  
}