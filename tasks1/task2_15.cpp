
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 15. Создать меню для выбора определенных фигур (круг, квадрат, треугольник, прямоугольник).
// Для каждой фигуры должны вводится свои данные, необходимые
// для поиска площади и периметра. Определить площадь и периметр соответствующих фигур.

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

void calcCircleArea() {
    float r, S, P;

    cout << "\nВведите радиус круга: ";
    cin >> r;

    if (r <= 0) {
        cout << "Некорректный ввод" << endl;
    } else {
        S = M_PI * r * r;
        P = 2 * M_PI * r;
        cout << "Площадь круга S = " << S << endl;
        cout << "Периметр круга P = " << P << endl;
    }
}

void calcSquareArea() {
    float a, S, P;

    cout << "\nВведите длину стороны квадрата: ";
    cin >> a;

    if (a <= 0) {
        cout << "Некорректный ввод" << endl;
    } else {
        S = a * a;
        P = 4 * a;
        cout << "Площадь квадрата S = " << S << endl;
        cout << "Периметр квадрата P = " << P << endl;
    }
}

void calcTriangleArea() {
    float a, b, c, S, P, p2;

    cout << "\nВведите длины трех сторон треугольника. После каждого введенного значения нажмите Enter: \n";
    cin >> a;
    cin >> b;
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Некорректный ввод" << endl;
    } else if (a + b <= c || a + c <= b || b + c <= a) { // Проверка валидности треугольника с введенными длинами сторон
        cout << "Треугольник с такими длинами сторон не существует" << endl;
    } else {
        P = a + b + c;
        // Площадь треугольника находится по формуле Герона
        p2 = P / 2; // полупериметр
        S = sqrtf(p2 * (p2 - a) * (p2 - b) * (p2 - c));
        cout << "Площадь треугольника S = " << S << endl;
        cout << "Периметр треугольника P = " << P << endl;
    }
}

void calcRectangleArea() {
    float a, b, S, P;

    cout << "\nВведите длины двух сторон прямоугольника. После каждого введенного значения нажмите Enter: \n";
    cin >> a;
    cin >> b;

    if (a <= 0 || b <= 0) {
        cout << "Некорректный ввод" << endl;
    } else {
        S = a * b;
        P = 2 * (a + b);
        cout << "Площадь прямоугольника S = " << S << endl;
        cout << "Периметр прямоугольника P = " << P << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int selectedValue;

    cout << "\nВыберите геометрическую фигуру из списка:";
    cout << "\n 1 - круг";
    cout << "\n 2 - квадрат";
    cout << "\n 3 - треугольник";
    cout << "\n 4 - прямоугольник";
    cout << "\n\nВведите номер выбранной фигуры: ";
    cin >> selectedValue;

    switch (selectedValue) {
    case 1:
        calcCircleArea();
        break;
    case 2:
        calcSquareArea();
        break;
    case 3:
        calcTriangleArea();
        break;
    case 4:
        calcRectangleArea();
        break;
    default:
        cout << "Некорректный ввод" << endl;
        break;
    }

    system("pause");
    return 0;
}
