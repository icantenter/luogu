#include <iostream>
#include <cmath>
#include <string>
struct Student
{
    std::string name;
    int Chinese;
    int math;
    int English;
};


int main()
{

    int num;
    std::cin >> num;
    auto students = new Student[num];

    std::cin >> students[0].name >> 
            students[0].Chinese >> students[0].math 
            >> students[0].English;
    int max = students[0].math + students[0].Chinese + students[0].English;
    int ans = 0;
    for (int i = 1; i < num; i++) 
    {
        std::cin >> students[i].name >> 
            students[i].Chinese >> students[i].math 
            >> students[i].English;
        int temp = students[i].math + students[i].Chinese + students[i].English;
        if (temp > max)
        {
            ans = i;
            max = temp;
        }
        
    }
    std::cout << students[ans].name << ' ' << students[ans].Chinese << ' ' << students[ans].math << ' ' << students[ans].English;
    return 0;
}