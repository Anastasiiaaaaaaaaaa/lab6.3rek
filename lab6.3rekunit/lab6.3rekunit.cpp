#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// --- Реалізація функцій для тестування ---

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

// --- Клас Unit-тесту ---

namespace UnitTestLab63
{
    TEST_CLASS(UnitTestLab63)
    {
    public:

        // 1. Тест звичайної рекурсивної функції (масив int)
        TEST_METHOD(Test_Sum_Ordinary_Recursive)
        {
            const int size = 6;
            int a[size] = { 10, 11, -10, 0, 5, 8 };
            // Парні елементи: 10, -10, 0, 8
            // Очікувана сума: 10 + (-10) + 0 + 8 = 8

            int expected = 8;
            int actual = Sum(a, size, 0);

            Assert::AreEqual(expected, actual);
        }

        // 2. Тест шаблонної рекурсивної функції (тип long)
        TEST_METHOD(Test_Sum_Template_Long)
        {
            const int size = 5;
            long b[size] = { 8, 6, 13, -4, -5 };
            // Парні елементи: 8, 6, -4
            // Очікувана сума: 8 + 6 + (-4) = 10

            long expected = 10;
            long actual = Sum<long>(b, size, 0);

            Assert::AreEqual(expected, actual);
        }

        // 3. Тест випадку, коли в масиві немає парних елементів
        TEST_METHOD(Test_Sum_No_Even_Elements)
        {
            const int size = 4;
            int a[size] = { 1, 3, 5, 7 };

            int expected = 0;
            int actual = Sum<int>(a, size, 0);

            Assert::AreEqual(expected, actual);
        }
    };
}