#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

struct Student
{
    int number;
    int academic;
    int quality;
    double score;

    bool check_good()
    {
        return (academic + quality) > 140 && score > 80;
    }
};

int main()
{
    int num;

    std::cin >> num;
    Student *students = new Student[num];
    for (int i = 0; i < num; i++)
    {
        std::cin >> students[i].number >> students[i].academic >> students[i].quality;
        students[i].score = students[i].academic * 0.7f + students[i].quality * 0.3f;
        std::cout << ((students[i].check_good()) ? "Excellent" : "Not excellent") << std::endl;
    }
    return 0;
}