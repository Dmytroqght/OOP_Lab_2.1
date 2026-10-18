#include "Line.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Структура для демонстрації розміру класу з #pragma pack(1)
#pragma pack(push, 1)
class LinePacked {
    double first;
    double second;
};
#pragma pack(pop)

Line makeLine(double a, double b) {
    Line line;
    if (!line.Init(a, b)) {
        cout << "Error: Invalid arguments for Init! Coefficient A cannot be zero. Exiting..." << endl;
        exit(1);
    }
    return line;
}

int main() {
    cout << "--- Testing Stream Operators and Constructors ---" << endl;
    Line line1;
    cin >> line1;
    cout << line1 << endl;
    cout << "Root: x = " << line1.root() << endl << endl;

    cout << "--- Testing makeLine() and Assignment ---" << endl;
    double a, b;
    cout << "Enter coefficients for a new line:" << endl;
    cout << "A = "; cin >> a;
    cout << "B = "; cin >> b;

    Line line2 = makeLine(a, b);
    Line line3;
    line3 = line2; // Тестування operator=

    cout << "line2: " << line2 << endl;
    cout << "line3 (copied via =): " << line3 << endl;
    cout << "Root: x = " << line2.root() << endl << endl;

    cout << "--- Testing Increment and Decrement ---" << endl;
    cout << "Original line3: " << line3 << endl;

    ++line3;
    cout << "After ++line3 (first changes): " << line3 << endl;

    line3++;
    cout << "After line3++ (second changes): " << line3 << endl;

    cout << "\n--- Demonstrating Class Size ---" << endl;
    cout << "Size of Line class (without pack): " << sizeof(Line) << " bytes" << endl;
    cout << "Size of Line class with #pragma pack(1): " << sizeof(LinePacked) << " bytes" << endl;

    return 0;
}