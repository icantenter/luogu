#include <iostream>
#define is_leap_year(year) (year % 400 == 0 || (year % 4 == 0 && year % 100))

int main()
{
    int min, max;
    int counter = 0;
    int leap_years[1500];
    
    std::cin >> min >> max;
    for (int i = min; i <= max; i++)
    {
        if (is_leap_year(i))
        {
            leap_years[counter++] = i;
        }
        
    }

    std::cout << counter << std::endl;
    for (int i = 0; i < counter; i++) 
    {
        std::cout << leap_years[i] << ' ';
    }
    
    return 0;
}

