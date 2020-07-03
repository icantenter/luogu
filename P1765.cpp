#include <iostream>
#include <string>
#include <map>
int main()
{
    std::string msg;
    int counter = 0;
    int temp;
    const std::string keyboard[12] = {
        "",     "abc",  "def", 
        "ghi",  "jkl",  "mno", 
        "pqrs", "tuv",  "wxyz", 
        "*",    " ",    "#"};
    getline(std::cin , msg);
    //std::map<int, std::string> ke; 
    for (std::string::iterator i = msg.begin(); i < msg.end(); i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if ((temp = keyboard[j].find(*i)) != std::string::npos)
            {
                counter += temp + 1;
            }
        }
    }
    std::cout << counter;

    system("pause");
    return 0;
}