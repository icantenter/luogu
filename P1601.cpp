#include <iostream>
#include <string>
void FillVacancy(std::string& temp, int length);
std::string add(std::string a, std::string b);

int main()
{
    std::string a, b;
    //getline有时候会有点问题
    std::cin >> a >> b;
    std::cout << add(a, b);
    return 0;
}

std::string add(std::string a, std::string b)
{
    int offset = 0;
    a.length() > b.length()? FillVacancy(b, a.length()):FillVacancy(a, b.length());
    for (int i = a.length() - 1; i >= 0; i--)
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