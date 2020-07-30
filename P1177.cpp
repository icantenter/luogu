#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
typedef int value_type;
template <typename Comparable>
void qsort(Comparable nums[], int low, int high);

template <typename Comparable>
bool is_sorted(Comparable array[], int size);

template <typename Comparable>
void show(Comparable array[], int size);

int N;
int main()
{
    value_type num;
    value_type nums[100000];

    std::cin >> num;
    N = num;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", nums + i);
    }
    qsort(nums, 0, num - 1);
    for (int i = 0; i < num - 1; i++)
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << nums[num - 1] << std::endl;
    assert(is_sorted(nums, num));
    return 0;
}

template <typename Comparable>
void qsort(Comparable nums[], int low, int high)
{
    if (low >= high)
    {
        return ;
    }
    int i = low, j = high;
    Comparable mid = nums[rand() % (high - low + 1) + low];
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
    qsort(nums, low, j); //在左区间排序
    qsort(nums, i, high); //在右区间排序
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
