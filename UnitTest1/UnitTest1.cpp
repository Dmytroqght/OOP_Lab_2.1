#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.1/Line.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LineTests
{
    TEST_CLASS(LineTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            Line line;
            Assert::AreEqual(1.0, line.GetFirst());
            Assert::AreEqual(0.0, line.GetSecond());
        }

        TEST_METHOD(TestParameterizedConstructor)
        {
            Line line(2.5, -5.0);
            Assert::AreEqual(2.5, line.GetFirst());
            Assert::AreEqual(-5.0, line.GetSecond());
        }

        TEST_METHOD(TestZeroCoefficientA)
        {
            // Перевірка ініціалізації нулем
            Line line(0.0, 5.0);
            Assert::AreEqual(1.0, line.GetFirst()); // Має встановитись 1.0 за замовчуванням

            // Перевірка сеттера
            bool result = line.SetFirst(0.0);
            Assert::IsFalse(result); // Метод має повернути false
            Assert::AreEqual(1.0, line.GetFirst()); // Значення не повинно змінитись
        }

        TEST_METHOD(TestRootCalculation)
        {
            Line line(2.0, -10.0); // 2x - 10 = 0  =>  x = 5
            Assert::AreEqual(5.0, line.root());
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            Line line(2.0, 3.0);
            ++line; // Префіксний інкремент змінює поле first
            Assert::AreEqual(3.0, line.GetFirst());
            Assert::AreEqual(3.0, line.GetSecond());
        }

        TEST_METHOD(TestPostfixIncrement)
        {
            Line line(2.0, 3.0);
            line++; // Постфіксний інкремент змінює поле second
            Assert::AreEqual(2.0, line.GetFirst());
            Assert::AreEqual(4.0, line.GetSecond());
        }

        TEST_METHOD(TestCopyConstructorAndAssignment)
        {
            Line line1(4.0, 8.0);
            Line line2 = line1; // Копіювання

            Assert::AreEqual(4.0, line2.GetFirst());
            Assert::AreEqual(8.0, line2.GetSecond());

            Line line3;
            line3 = line1; // Присвоєння

            Assert::AreEqual(4.0, line3.GetFirst());
            Assert::AreEqual(8.0, line3.GetSecond());
        }
    };
}