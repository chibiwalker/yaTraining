// underground.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int a, b, n, m,aMin,bMin,aMax,bMax;
    std::cin >> a;
    std::cin >> b;
    std::cin >> n;
    std::cin >> m;
    aMin = a * (n-1) + n;
    bMin = b * (m-1) + m;
    aMax = aMin + 2 * a;
    bMax = bMin + 2 * b;
    if (aMin > bMin + 2 * b || bMin > aMin + 2 * a)
        std::cout << -1;
    else
    {
        std::cout << std::max(aMin, bMin) <<" "<< std::min(aMax, bMax);
    }
}

