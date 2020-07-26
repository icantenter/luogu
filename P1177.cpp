#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
typedef int Comparable;
Comparable nums[1000001];
void q_sort(int low, int high);

template<typename Comparable>
bool is_sorted(Comparable array[], int size);


template<typename Comparable>
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
    q_sort(0, num);
    for (int i = 0; i < num - 1; i++) 
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << nums[num - 1] << std::endl;
    assert(is_sorted(nums, num));
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
        show(nums, N);
    }
    temp = nums[j];
    nums[j] = nums[low];
    nums[low] = temp;
    show(nums, N);
    q_sort(low, j);
    q_sort(j + 1, high);
    
}


template<typename Comparable>
void show(Comparable array[], int size)
{
    
    if (size == 0)
    {
        return ;
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

template<typename Comparable>
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