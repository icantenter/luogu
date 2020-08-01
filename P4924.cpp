#include <iostream>
#include <cmath>
#define size 510

struct BinaryInt
{
    int x, y;
    BinaryInt(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
typedef BinaryInt Point;

struct _M_Rect
{
    int x, y;
    int w, h;
    /*_M_Rect(int _x, int _y, int _w, int _h)
    {
        x = _x;
        y = _y;
        w = _w;
        h = _h;
    }*/
};

void spin(int nums[][size], _M_Rect* rect, bool _clockwise);

int main()
{
    typedef _M_Rect Rect;
    int n, m;
    int nums[size][size];
    int cnt = 1;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            nums[i][j] = cnt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, r, z;

        std::cin >> x >> y >> r >> z;
        if (z)
        {
            _M_Rect temp{x - r, y - r, 2 * r + 1, 2 * r + 1};
            spin(nums, &temp, true);
        }
        else
        {
            _M_Rect temp{x - r, y - r, 2 * r + 1, 2 * r + 1};
            spin(nums, &temp, false);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << nums[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

void spin(int nums[][size], _M_Rect* rect, bool _clockwise = true)
{
    int temp[size][size];
    //temp存放spin前的数组
    for (int j = rect->y; j <= rect->y + rect->h; j++)
    {
        for (int i = rect->x; i <= rect->x + rect->w; i++)
        {
            temp[j][i] = nums[j][i];
        }
    }
    if (_clockwise)
    {
        for (int j = rect->y; j <= rect->y + rect->h; j++)
        {
            for (int i = rect->x; i <= rect->x + rect->w; i++)
            {
                nums[j][i] = temp[rect->y + rect->h - i][rect->x + j];
            }
        }
    }
    else
    {
        for (int j = rect->y; j <= rect->y + rect->h; j++)
        {
            for (int i = rect->x; i <= rect->x + rect->w; i++)
            {
                nums[j][i] = temp[rect->x + j][rect->y + rect->h - i];
            }
        }
    }
}
