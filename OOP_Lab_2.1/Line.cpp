#include "Line.h"
#include <iostream>

using namespace std;

// Конструктори
Line::Line() {
    SetFirst(1.0);
    SetSecond(0.0);
}

Line::Line(double a, double b) {
    if (!Init(a, b)) {
        SetFirst(1.0);
        SetSecond(0.0);
    }
}

Line::Line(const Line& other) {
    first = other.first;
    second = other.second;
}

// Методи доступу та ініціалізації
bool Line::SetFirst(double value) {
    if (value != 0) {
        first = value;
        return true;
    }
    return false;
}

bool Line::SetSecond(double value) {
    second = value;
    return true;
}

bool Line::Init(double a, double b) {
    return SetFirst(a) && SetSecond(b);
}

// Старі методи вводу/виводу
void Line::Read() {
    cin >> *this; // Використовуємо перевантажений оператор
}

void Line::Display() const {
    cout << *this << endl; // Використовуємо перевантажений оператор
}

double Line::root() const {
    return -second / first;
}

// Перевантаження операції присвоєння
Line& Line::operator=(const Line& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

// Перевантаження приведення типу
Line::operator string() const {
    stringstream ss;
    ss << "Equation: y = " << first << "x + " << second;
    return ss.str();
}

// Перевантаження унарних операторів
Line& Line::operator++() {
    first++;
    if (first == 0) first++; // Запобігаємо рівності нулю
    return *this;
}

Line& Line::operator--() {
    first--;
    if (first == 0) first--; // Запобігаємо рівності нулю
    return *this;
}

Line Line::operator++(int) {
    Line temp(*this);
    second++;
    return temp;
}

Line Line::operator--(int) {
    Line temp(*this);
    second--;
    return temp;
}