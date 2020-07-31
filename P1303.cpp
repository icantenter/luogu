#include <iostream>
#include <string>

void FillVacancy(std::string &temp, int length);
std::string mul(std::string a, std::string b);
std::string add(std::string a, std::string b);

int main()
{
    std::string a, b;
    //getline有时候会有点问题
    std::cin >> a >> b;
    std::cout << mul(a, b);
    return 0;
}

std::string mul(std::string a, std::string b)
{
    std::string ans;
    int offset;
    int _temp;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        offset = 0;
        //初始当前乘数的位数
        std::string temp(a.length() - i - 1, '0');

        for (int j = b.length() - 1; j >= 0; j--)
        {       //这里加法类似
            _temp = (a[i] - '0') * (b[j] - '0') + offset;
            offset = _temp / 10;
            _temp %= 10;
            temp = char('0' + _temp) + temp;
        }
        //最后的offset要加上
        if (offset)
        {
            temp = char(offset + '0') + temp;
        }
        ans = add(ans, temp);
    }
    //trim无意义的0
    for (int i = 0; ; i++) 
    {
        if (ans[i] != '0' || i == ans.length() - 1)
        {
            ans = ans.substr(i);
            break;
        }
    }
    
    return ans;
}


//首要的是可读性，其次是运行
std::string add(std::string a, std::string b)
{
    int offset = 0;

    a.length() > b.length()? FillVacancy(b, a.length()):FillVacancy(a, b.length());
    for (int i = a.length() - 1; i >= 0 ; i--)
    {
        int temp;

        temp = a[i] - '0' + b[i] - '0' + offset;
        offset = temp / 10;
        temp %= 10;
        a[i] = char('0' + temp);
    }
    if (offset)
    {
        a = char(offset + '0') + a;
    }
    
    return a;
}
//补位使两个数能对齐，循环处理更方便
void FillVacancy(std::string& temp, int length)
{
    while (temp.length() < length)
    {
        temp = '0' + temp;
    }
}