#include <iostream>
#include <cstdio>
#include <cstdlib>

struct _toy
{
    int direction;
    char name[11];
};


int main()
{
    int n, m;
    int ans = 0;
    scanf("%d%d", &n, &m);
    _toy *toys = new _toy[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d%s", &toys[i].direction, &toys[i].name);
    }
    for (int i = 0; i < m; i++) 
    {
        int _direction, number;
        scanf("%d%d", &_direction, &number);
        if (_direction ^ toys[ans].direction)
            ans = (ans + number) % n;
        else
            ans - number < 0 ? ans += n - number : ans -= number;
        
    }
    printf("%s", toys[ans].name);
    return 0;
    
}