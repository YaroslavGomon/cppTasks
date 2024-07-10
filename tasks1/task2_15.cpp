
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 15. ������� ���� ��� ������ ������������ ����� (����, �������, �����������, �������������).
// ��� ������ ������ ������ �������� ���� ������, �����������
// ��� ������ ������� � ���������. ���������� ������� � �������� ��������������� �����.

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

void calcCircleArea() {
    float r, S, P;

    cout << "\n������� ������ �����: ";
    cin >> r;

    if (r <= 0) {
        cout << "������������ ����" << endl;
    } else {
        S = M_PI * r * r;
        P = 2 * M_PI * r;
        cout << "������� ����� S = " << S << endl;
        cout << "�������� ����� P = " << P << endl;
    }
}

void calcSquareArea() {
    float a, S, P;

    cout << "\n������� ����� ������� ��������: ";
    cin >> a;

    if (a <= 0) {
        cout << "������������ ����" << endl;
    } else {
        S = a * a;
        P = 4 * a;
        cout << "������� �������� S = " << S << endl;
        cout << "�������� �������� P = " << P << endl;
    }
}

void calcTriangleArea() {
    float a, b, c, S, P, p2;

    cout << "\n������� ����� ���� ������ ������������. ����� ������� ���������� �������� ������� Enter: \n";
    cin >> a;
    cin >> b;
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "������������ ����" << endl;
    } else if (a + b <= c || a + c <= b || b + c <= a) { // �������� ���������� ������������ � ���������� ������� ������
        cout << "����������� � ������ ������� ������ �� ����������" << endl;
    } else {
        P = a + b + c;
        // ������� ������������ ��������� �� ������� ������
        p2 = P / 2; // ������������
        S = sqrtf(p2 * (p2 - a) * (p2 - b) * (p2 - c));
        cout << "������� ������������ S = " << S << endl;
        cout << "�������� ������������ P = " << P << endl;
    }
}

void calcRectangleArea() {
    float a, b, S, P;

    cout << "\n������� ����� ���� ������ ��������������. ����� ������� ���������� �������� ������� Enter: \n";
    cin >> a;
    cin >> b;

    if (a <= 0 || b <= 0) {
        cout << "������������ ����" << endl;
    } else {
        S = a * b;
        P = 2 * (a + b);
        cout << "������� �������������� S = " << S << endl;
        cout << "�������� �������������� P = " << P << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int selectedValue;

    cout << "\n�������� �������������� ������ �� ������:";
    cout << "\n 1 - ����";
    cout << "\n 2 - �������";
    cout << "\n 3 - �����������";
    cout << "\n 4 - �������������";
    cout << "\n\n������� ����� ��������� ������: ";
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
        cout << "������������ ����" << endl;
        break;
    }

    system("pause");
    return 0;
}
