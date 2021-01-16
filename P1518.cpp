#include <iostream>
#include <string>

struct move
{
    int x, y, r;
    move(int x, int y, int r) : x(x), y(y), r(r){};
    void turn()
    {
        r = (r + 1) % 4;
    }
    bool operator==(const struct move tmp)
    {
        return x == tmp.x && y == tmp.y;
    }
};
typedef struct move move;

void _move(move *tmp);
int main()
{
    char map[12][12];
    bool vis[200000];
    move *c, *f;
    int m = 0;
    for (int i = 0; i < 12; i++)
    {
        map[i][0] = '*';
        map[i][11] = '*';
    }
    for (int i = 1; i < 12; i++)
    {
        map[0][i] = '*';
        map[11][i] = '*';
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 'F')
                f = new move(i, j, 0);
            else if (map[i][j] == 'C')
                c = new move(i, j, 0);
        }
    }
    while (true)
    {
        move tmp(0, 0, 0);

        tmp = *c;
        _move(&tmp);
        if (map[tmp.x][tmp.y] == '*')
            c->turn();
        else
        {
            _move(c);
        }
        
        tmp = *f;
        _move(&tmp);
        if (map[tmp.x][tmp.y] == '*')
            f->turn();
        else
        {
            _move(f);
        }
        m++;
        if (*c == *f)
        {
            std::cout << m;
            return 0;
        }
        int temp = c->x + c->y * 11 + f->x * 121 + f->y * 1111 + f->r * 11111 + c->r * 33334;
        if (vis[temp])
        {
            std::cout << 0 << std::endl;
            return 0; 
        }
        vis[temp] = true;
    }
}



void _move(move *tmp)
{
    switch (tmp->r)
    {
    case 0:
        tmp->x--;
        break;
    case 1:
        tmp->y++;
        break;
    case 2:
        tmp->x++;
        break;
    case 3:
        tmp->y--;
    }
}