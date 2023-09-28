// notebooks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
int table(int a, int b, int c, int d)
{
    return std::max(a, b) * (c + d);
}
void printRes(int a, int b, int c, int d)
{
    std::cout << std::max(a, b) << " " << c + d;
}

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (table(a, c, b, d) <= table(a, d, b, c))
        if (table(a, c, b, d) <= table(b, c, a, d))
            if (table(a, c, b, d) <= table(b, d, a, c))
                printRes(a, c, b, d);
            else
                printRes(b, d, a, c);
        else
            if (table(b, c, a, d) <= table(b, d, a, c))
                printRes(b, c, a, d);
            else
                printRes(b, d, a, c);
    else
        if (table(a, d, b, c) <= table(b, c, a, d))
            if (table(a, d, b, c) <= table(b, d, a, c))
                printRes(a, d, b, c);
            else
                printRes(b, d, a, c);
        else
            if (table(b, c, a, d) <= table(b, d, a, c))
                printRes(b,c, a, d);
            else
                printRes(b, d, a, c);
}