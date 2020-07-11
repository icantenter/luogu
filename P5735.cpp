#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

struct point
{
    double x;
    double y;
};

typedef struct point POINT;

int main()
{
    POINT a, b, c;

    std::cin >> a.x >> a.y >>
        b.x >> b.y >> c.x >> c.y;
    double ans = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)) +
               sqrt(pow((a.x - c.x), 2) + pow((a.y - c.y), 2)) +
               sqrt(pow((c.x - b.x), 2) + pow((c.y - b.y), 2));
    std::cout << std::fixed <<  std::setprecision(2);
    std::cout << ans;
    return 0;
}