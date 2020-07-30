#include <iostream>
#include <cstdlib>
#include <cstdio>
int k;
typedef int value_type;

template <typename Comparable>
void qsort(Comparable nums[], int low, int high);

int main()
{
    int n;
    value_type nums[5000];
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", nums + i);
    }
    qsort(nums, 0, n - 1);
    return 0;
}

template <typename Comparable>
void qsort(Comparable nums[], int low, int high)
{
    //caution:查找和排序不同
    if (low == high)
    {
        printf("%d", nums[low]);
        return ;
    }
    int i = low, j = high;
    Comparable pivot = nums[rand() % (high - low + 1) + low];
    do
    {
        while (nums[j] > pivot)
            j--;
        while (nums[i] < pivot)
            i++;
        if (i <= j)
        {
            std::swap(nums[i], nums[j]);
            i++;
            j--;
        }
    } while (i <= j);
    //快排后数组被划分为三块，且满足low<=j<=i<=high
    if (k <= j)
        qsort(nums, low, j); //在左区间只需要搜左区间
    else if (i <= k)
        qsort(nums, i, high); //在右区间只需要搜右区间
    else
    {
        printf("%d", nums[j + 1]);
    }
}

