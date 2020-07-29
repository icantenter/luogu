#include <iostream>

struct _student
{
    std::string name;
    int age;
    int score;
};

_student train(_student temp)
{
    temp.age += 1;
    temp.score * 1.2 >= 600 ? temp.score = 600 : temp.score *= 1.2;
    return temp;
}

int main()
{
    int num;
    _student temp;
    std::cin >> num;
    for (int i = 0; i < num; i++) 
    {
        std::cin >> temp.name >> temp.age >> temp.score;
        temp = train(temp);
        std::cout << temp.name << ' ' << temp.age << ' ' << temp.score << std::endl;
    }
    return 0;   
}