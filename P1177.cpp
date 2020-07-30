#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
typedef int Comparable;
Comparable nums[1000001];
void qsort(int low, int high);

template <typename Comparable>
bool is_sorted(Comparable array[], int size);

template <typename Comparable>
void show(Comparable array[], int size);

int N;
int main()
{
    Comparable num;

    std::cin >> num;
    N = num;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", nums + i);
    }
    qsort(0, num - 1);
    for (int i = 0; i < num - 1; i++)
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << nums[num - 1] << std::endl;
    assert(is_sorted(nums, num));
    return 0;
}

void qsort(int low, int high)
{
    if (low >= high)
    {
        return ;
    }
    int i = low, j = high;
    int mid = nums[rand() % (high - low + 1) + low];
    do
    {
        while (nums[j] > mid)
            j--;
        while (nums[i] < mid)
            i++;
        if (i <= j)
        {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    } while (i <= j);
    //快排后数组被划分为三块，且满足low<=j<=i<=high
    qsort(low, j); //在左区间排序
    qsort(i, high); //在右区间排序
}

template <typename Comparable>
void show(Comparable array[], int size)
{

    if (size == 0)
    {
        return;
    }
    system("cls");
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j] >= i)
            {
                std::cout << "■";
            }
            else
            {
                std::cout << "  ";
            }
            if (j == size - 1)
            {
                std::cout << std::endl;
            }
            else
            {
                std::cout << "  ";
            }
        }
    }
    system("pause");
}

template <typename Comparable>
bool is_sorted(Comparable array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}
