#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h> // Необхідно для SetConsoleCP / SetConsoleOutputCP

using namespace std;

// Прототипи звичайних рекурсивних функцій
void Create(int* a, const int size, const int Low, const int High, int i);
void Print(const int* a, const int size, int i);
int Sum(const int* a, const int size, int i);

// Прототипи шаблонних рекурсивних функцій
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i);

template <typename T>
void Print(const T* a, const int size, int i);

template <typename T>
T Sum(const T* a, const int size, int i);

int main()
{
    // Встановлення UTF-8 (65001) для коректного відображення кирилиці в консолі Visual Studio
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned>(time(NULL)));

    const int n = 10;
    int Low = -10;
    int High = 20;

    // 1. Опрацювання масиву a (int)
    int a[n];
    Create(a, n, Low, High, 0);

    cout << "Сформований масив a (int):" << endl;
    Print(a, n, 0);

    cout << "Сума парних елементів [звичайна функція] = " << Sum(a, n, 0) << endl;
    cout << "Сума парних елементів [шаблон <int>]     = " << Sum<int>(a, n, 0) << endl << endl;

    // 2. Опрацювання масиву b (long)
    long b[n];
    Create<long>(b, n, -10, 15, 0);

    cout << "Сформований масив b (long):" << endl;
    Print<long>(b, n, 0);

    cout << "Сума парних елементів [шаблон <long>]    = " << Sum<long>(b, n, 0) << endl;

    return 0;
}

// --- Реалізація звичайних рекурсивних функцій ---

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(const int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int Sum(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 == 0)
            return a[i] + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    return 0;
}

// --- Реалізація шаблонних рекурсивних функцій ---

template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i)
{
    a[i] = static_cast<T>(Low + rand() % static_cast<int>(High - Low + 1));
    if (i < size - 1)
        Create<T>(a, size, Low, High, i + 1);
}

template <typename T>
void Print(const T* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
T Sum(const T* a, const int size, int i)
{
    if (i < size)
    {
        if (static_cast<long long>(a[i]) % 2 == 0)
            return a[i] + Sum<T>(a, size, i + 1);
        else
            return Sum<T>(a, size, i + 1);
    }
    return T();
}