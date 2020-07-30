#include <iostream>
int k;
typedef int Comparable;
//high可能取size或size - 1，改动时注意后面递归
void q_sort(Comparable nums[], int low, int high)
{
    if (high - 1 <= low)
    {
        if (high - 1 == k)
        {
            std::cout << nums[high - 1];
        }
        
        return;
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
    if (k < j)
    {
        q_sort(nums, low, j);
    }
    else if (k > j)
    {
        q_sort(nums, j + 1, high);
    }
    else
    {
        std::cout << nums[j];
    }
    
}

int main()
{
    int n;
    int nums[5000];
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    q_sort(nums, 0, n);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int x[5000005],k;
void qsort(int l,int r)
{
	int i=l,j=r,mid=x[(l+r)/2];
	do
	{
		while(x[j]>mid)
			j--;
		while(x[i]<mid)
			i++;
		if(i<=j)
		{
			swap(x[i],x[j]);
			i++;
			j--;
		}
	}
	while(i<=j);
	//快排后数组被划分为三块： l<=j<=i<=r
	if(k<=j) qsort(l,j);//在左区间只需要搜左区间
	else if(i<=k) qsort(i,r);//在右区间只需要搜右区间
	else //如果在中间区间直接输出
	{
		printf("%d",x[j+1]);
		exit(0);
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	qsort(0,n-1);
}*/