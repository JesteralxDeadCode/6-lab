#include <iostream>
using namespace std;

void zad1()
{

    const double mass1[3][3] = {
        {1.1, 2.2 ,3.3},
        {2.2, 4.4, 6.6},
        {3.3, 6.6 ,9.9}
    };

    double a = 1.1, b = 2.2, c = 3.3;

    double* aU = &a;
    double* bU = &b;
    double* cU = &c;

    double* mass2[] = {aU, bU, cU};

    for (int f = 0; f < 3; f++)
    {
        double low;
        int x = 0;
        low = mass1[f][0];

        for (int i = 0; i < 3; i++)
        {
            if (mass1[f][i] < low)
            {
                low = mass1[f][i];
                x = i;
            }
        }
        if (f == 0)
        {
            a = (double)mass1[f][x];
        }
        else if (f ==1)
        {
            b = (double)mass1[f][x];
        }
        else
        {
            c = (double)mass1[f][x];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            cout << "Значение элемента массива #" << f+1 << " в строке #" << i+1 << " Равно :" << mass1[i][f]<<endl;
        }
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    { 
        cout << "минимальный элемент строчки #"<< i+1 << " в массиве равен :"<< *mass2[i] << endl;
    
    }
}
void zad2()
{
    int max = 0, summa = 0, a, b;

    int mass[3][3];

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            cout<< "Введите значение эелемента массива #" << y + 1 << " для столбца #" << x + 1 << " :";
            cin >> mass[x][y];
        }
    }


    for (int x = 0; x < 3; x++)
    {
        int sum = 0;

        for (int y = 0; y < 3; y++)
        {
            sum += mass[x][y];
        }

        if (x == 0)
        {
            max = sum;
        }

        if (sum > max)
        {
            max = sum;
        }
    }
    cout<< endl << "Наибольшая сумма в одной строчке ровна :" << max;

    for (int x = 0; x < 3; x++)
    {
        int sum = 1;

        for (int y = 0; y < 3; y++)
        {
            sum *= mass[x][y];
        }   

        if (x == 0)
        {
            max = sum;
        }

        if (sum < max)
        {
            max = sum;
        }
    }
    cout<< endl << "Наименьшое произведение в одной строчке ровна :" << max;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            summa += mass[x][y];
        }
    }
    cout << endl << "Cумма элементов массива ровна :" << summa;

    for (int x = 0; x < 3; x++)
    {
        if (x == 0)
        {
            a = 0; b = 0;
        }
        for (int y = 0; y < 3; y++)
        {
            if (mass[a][b] > mass[x][y])
            {
                a = x; b = y;
            }
        }
    }
    cout << endl << "Индексы x и y для наименьнешего значения двухмерного массива соответственно равны :" << a << " и "<< b<<" (Счет индекса идет от 0)"<<endl;

}
void zad3()
{
    int a = 1; int* aU = &a; int** aUU = &aU; // указатьель на указатель на целое 

    int mass[5];// последовательность целых чиссел

    for (int x = 0; x < 5; x++)
    {
        cout << "Введите значение эелемента массива #" << x + 1 << " :";
        cin >> mass[x];
    }

    int* massU[5]; // = {&mass[1],&mass[2],&mass[3],&mass[4],&mass[5]};//последовательность указателей на последовательность целочислкенных
    aUU = massU; //пренастроил указатель на указатель с указателя на последовательность указателей

    for (int i = 0; i < 5; i++)
    {
        massU[i] = &mass[i];
    }

    int min; int max;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            max = *aUU[i];
            min = *aUU[i];
        }
        if (max < *aUU[i])
        {
            max = *aUU[i];
        }
        if (min > *aUU[i])
        {
            min = *aUU[i];
        }
    }
    cout <<"Квадрат разности минимального и максимального значения равен :" << pow((max - min), 2);
}

int main()
{
    setlocale(LC_ALL, "ru");
    zad3();
}

