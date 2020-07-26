#include <iostream>
#include <cstdio>
#include <cstdlib>
typedef int Comparable;
Comparable nums[1000001];
void q_sort(int low, int high);

int main()
{
    Comparable num;

    std::cin >> num;
    for (int i = 0; i < num; i++) 
    {
        scanf("%d", nums + i);
    }
    q_sort(0, num);
    for (int i = 0; i < num - 1; i++) 
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << nums[num - 1] << std::endl;
    return 0;
}

//high可能取size或size - 1，改动时注意后面递归
void q_sort(int low, int high)
{
    if (high - 1 <= low)
    {
        return ;
    }
    //key选择左边第一个或右边第一个
    //左边的key应与nums[j]交换,反之与nums[i].
    //打乱可以是排序前，但key不能
    int index = rand() % (high - low) + low;
    int i = low;
    int j = high;
    int temp = nums[low];
    nums[low] = nums[index];
    nums[index] = temp;
    int key = nums[low];
    while (true)
    {
        while (key > nums[++i])
        {
            if (i == high)
            {
                break;
            }
            
        }
        while (key < nums[--j])
        {
            if (j == low)
            {
                break;
            }
        }
        if (i >= j)
        {
            break;
        }
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    temp = nums[j];
    nums[j] = nums[low];
    nums[low] = temp;
    q_sort(low, j);
    q_sort(j + 1, high);
    
}