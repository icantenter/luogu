#include <iostream>
bool list[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int A[200];
int B[200];
int main()
{
    int N, NA, NB;
    int a_a = 0, a_b = 0;  
    std::cin >> N >> NA >> NB;

    for (int i = 0; i < NA; i++) 
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < NB; i++) 
    {
        std::cin >> B[i];
    }
    for (int i = 0; i < N; i++) 
    {
        a_a += list[A[i % NA]][B[i % NB]];
        a_b += list[B[i % NB]][A[i % NA]];
    }
    std::cout << a_a << ' ' <<a_b << std::endl;
    return 0;
}