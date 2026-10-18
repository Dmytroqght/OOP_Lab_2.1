#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Line
{
private:
    double first;
    double second;

public:
    // Конструктори
    Line();
    Line(double a, double b);
    Line(const Line& other);

    // Методи доступу
    double GetFirst() const { return first; }
    double GetSecond() const { return second; }
    bool SetFirst(double value);
    bool SetSecond(double value);

    // Ініціалізація та обчислення
    bool Init(double a, double b);
    double root() const;
    void Read();
    void Display() const;

    // Перевантаження присвоєння
    Line& operator=(const Line& other);

    // Перевантаження приведення типу
    operator string() const;

    // Перевантаження інкременту та декременту
    Line& operator++();    // Префіксний (змінює first)
    Line& operator--();    // Префіксний (змінює first)
    Line operator++(int);  // Постфіксний (змінює second)
    Line operator--(int);  // Постфіксний (змінює second)

    // Перевантаження введення/виведення
    friend ostream& operator<<(ostream& out, const Line& line) {
        out << string(line);
        return out;
    }

    friend istream& operator>>(istream& in, Line& line) {
        double a, b;
        cout << "Enter coefficient A (first, A cannot be 0) = ";
        in >> a;
        while (!line.SetFirst(a)) {
            cout << "Invalid input. Try again. A = ";
            in >> a;
        }
        cout << "Enter coefficient B (second) = ";
        in >> b;
        line.SetSecond(b);
        return in;
    }
};