// details.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int N, K, M, res, Z,det,ostZ,oldN;
    std::cin >> N >> K >> M; 
    oldN = N;
    det = K / M;
    ostZ = K % M;
    res = 0;
    if (M > K)
        std::cout << 0;
    else
    {
        while (N / K > 0)
        {
            Z = N / K;
            res += Z * det;
            N = N % K + Z * ostZ;
        }
        std::cout << res;
    }
}
