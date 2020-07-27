#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
typedef struct
{
    std::string name;
    int Chinese;
    int Math;
    int English;
    int sum;
} STUDENT;

int main(void)
{
    int num, ans = 0;

    std::cin >> num;
    STUDENT *student = new STUDENT[num];
    for (size_t i = 0; i < num; i++)
    {
        std::cin >> student[i].name >> student[i].Chinese >> student[i].Math >> student[i].English;
        student[i].sum = student[i].Chinese + student[i].Math + student[i].English;
    }
    for (size_t i = 0; i < num; i++)
    {
        for (size_t j = i + 1; j < num; j++)
        {
            if (abs(student[i].Chinese - student[j].Chinese) <= 5 &&
                abs(student[i].Math - student[j].Math) <= 5 &&
                abs(student[i].English - student[j].English) <= 5 &&
                abs(student[i].sum - student[j].sum) <= 10)
            {
                if (student[i].name < student[j].name)
                {
                    std::cout << student[i].name << ' ' << student[j].name;
                }
                else
                {
                    std::cout << student[j].name << ' ' << student[i].name;
                }
                std::cout << std::endl;

            }
        }
    }
    system("pause");
    return 0;
}