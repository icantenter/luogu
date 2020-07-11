#include <iostream>
#include <cstring>
#include <cmath>

bool is_prime(int number);
int main()
{
	int ans[100];
	int number, nums, j = 0;

	std::cin >> nums;
	for (int i = 0; i < nums; i++)
	{
		std::cin >> number;
		if (is_prime(abs(number)))
		{
			ans[j++] = number;
		}
	}
	for (int i = 0; i < j; i++) 
	{
		std::cout << ans[i] << ' ';
	}
	return 0;
}

bool is_prime(int number)
{
	if (number <= 1)
	{
		return false;
	}
	
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}