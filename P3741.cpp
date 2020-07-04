#include <iostream>
#include <string>
#include <cstdlib>
int main()
{
    int num, pos = 0;
    int ans = 0;
    
    std::string src;
    std::cin >> num >> src;

    while ((pos = src.find("VK", pos)) != std::string::npos)
    {
        ans++;
        src.replace(pos, 2, "F"); //如果去掉“VK",字符串结构改变了
    }
    if (src.find("VV") != std::string::npos ||
        src.find("KK") != std::string::npos)
    {
        ans++;
    }
    std::cout << ans;
    system("pause");
    return 0;
}