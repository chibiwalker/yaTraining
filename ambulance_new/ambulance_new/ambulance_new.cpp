#include <iostream>
long findLever(long K, long L)//функция нахождения этажа для квартиры К при L этажей на лестничной клетке
{
    if (K % L == 0)
        return (K / L);
    else
        return (K / L) + 1;
}

void inCorrect(long & P,long & N) 
{
    P = -1;
    N = -1;
} // для сообщения о противоречивости о входных данных
void unKnown(long & P, long & N)
{
    P = 0;
    N = 0;
}//невозможно однозначно судить об ответе из текущих входных данных
int main()
{   long K1, M, K2, N2, P2, N1, P1;
    long L, Lmin;
    std::cin>>K1 >> M >> K2 >> P2 >> N2;
    long lAll= M * (P2 - 1) + N2 - 1;
    P1 = -10;
    N1 = -10;
    L = -10;
    Lmin = 1;
    if (lAll == 0) //обработка случаев P2 и N2 ==1
        if (K1 <= K2) //K1 в том же подъезде на том же этаже
        {
            P1 = P2;
            N1 = N2;
        }
        else //определение этажа и подъезда первой квартиры невозможно из-за отсутствия достаточных данных для суждения о кол-ве квартир на клетке
        {
            if (K2 * M >= K1)
            {
                P1 = P2;
                N1 = 0;
            }
            else
            unKnown(P1, N1);
        }
     
    else    //K2 не на первом этаже 1го подъезда
        if (N2 > M) //K2 на этаже больше максимального количества этажей в доме
            inCorrect(P1, N1);
        else
            if (lAll == 1 && K1<K2)
                unKnown(P1, N1);
            else // K2 располагается выше 2го этажа в модели одноподъездного дома
            {
                if (K2 % lAll == 0) //вычисление максимально возможного количества этажей на лестничной клетке для текущих входных данных
                    L = K2 / lAll - 1;
                else
                    L = K2 / lAll;
                if (K2 % (lAll + 1) == 0) //вычисление минимально возможного количества этажей на лестничной клетке для текущих входных данных
                    Lmin = K2 / (lAll + 1);
                else
                    Lmin = K2 / (lAll + 1) + 1;
                if (K2 - lAll * L > L || K2-lAll*L==0) //квартиры до K2 возможно разместить в предшествующих этажах?
                    inCorrect(P1, N1);
                else
                    if (K1 == K2)
                    {
                        P1 = P2;
                        N1 = N2;
                    }
                    else
                    {
                        //if (K2 - (L - 1) * lAll <= L - 1) //существует не единственный вариант квартир на лестничной клетке, удовлетворяющий входным данным 
                        //    unKnown(P1, N1);
                        {
                            if (findLever(K1, L) == findLever(K1, Lmin)) //в случае, если существует однозначное решение
                            {
                                P1 = findLever(K1, L);
                                if (P1 % M == 0)
                                    P1 = P1 / M;
                                else
                                    P1 = P1 / M + 1;
                                N1 = findLever(K1, L) - M * (P1 - 1);

                            }
                            else //проверим возможность однозначного определения подъезда для K1
                                if (findLever(findLever(K1,L),M) == findLever(findLever(K1, Lmin), M))
                                {
                                    P1 = findLever(findLever(K1, L), M);
                                    N1 = 0;
                                }
                                else
                                {
                                    if (findLever(K1, L) - M * (findLever(findLever(K1, L), M) - 1) == findLever(K1, Lmin) - M * (findLever(findLever(K1, Lmin), M) - 1))
                                    {
                                        P1 = 0;
                                        N1 = findLever(K1, L) - M * (findLever(findLever(K1, L), M) - 1);
                                    }
                                    else
                                    unKnown(P1, N1);
                                }
                                    
                        }
                    }
                    
            }
     if (M == 1 && N1!=(-1)) //должно работать и при lAll =0 и при lAll =1 и при невозможности определения точного кол-ва квартир на этаже, но не при N2>M
         N1 = 1;
     std::cout << P1 << " " << N1;
}

