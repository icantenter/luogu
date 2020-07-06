#include <iostream>
#include <algorithm>
#include <map>
#include <string>


int main()
{
    std::map<std::string, int> dic;
    std::string msg;
    int ans[6], counter = 0;
    dic["one"] = 1;
    dic["two"] = 2;
    dic["three"] = 3;
    dic["four"] = 4;
    dic["five"] = 5;
    dic["six"] = 6;
    dic["seven"] = 7;
    dic["eight"] = 8;
    dic["nine"] = 9;
    dic["ten"] = 10;
    dic["eleven"] = 11;
    dic["twelve"] = 12;
    dic["thirteen"] = 13;
    dic["fourteen"] = 14;
    dic["fifteen"] = 15;
    dic["sixteen"] = 16;
    dic["seventeen"] = 17;
    dic["eighteen"] = 18;
    dic["nineteen"] = 19;
    dic["twenty"] = 20;
    dic["a"] = 1;
    dic["both"] = 2;
    dic["another"] = 1;
    dic["first"] = 1;
    dic["second"] = 2;
    dic["third"] = 3;

    for (int i = 0; i < 6; i++)
    {
        std::cin >> msg;
        
        auto temp = dic.find(msg);
        if (temp != dic.end() && temp->second != 0) 
        {
            ans[counter] = (temp->second * temp->second) % 100;
            counter++;
        }
    }
    std::sort(ans, ans + counter);
    if (counter)
    {
        std::cout << ans[0];
    }
    else
    {
        std::cout << 0;
    }

    for (int i = 1; i < counter; i++)
    {
        if (ans[i] < 10)
        {
            std::cout << 0;
        }
        
        std::cout << ans[i];
    }
    return 0;
}