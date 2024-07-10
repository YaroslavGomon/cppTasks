
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 2. ���� ����������� ����� A. ���� ��� ��� ����� ������ X, ��������� ����� A
// �� 100; ���� ��� ������ � ������ ����� ������ X, ��������� ����� A �� 100;
// ���� ��� ��� ����� ������ X, ��������� ����� A �� 50; ���� ������ � ������
// ����� ������ X, ��������� ����� A �� 50; � ��������� ������� � ���������
// ����� A �� 10.

#include <cmath>
#include <iostream>

using namespace std;

void calc(int a, int x) {
    int a1, a2, a3, result;

    a3 = a % 10;
    a2 = ((a % 100) - a3) / 10;
    a1 = ((a % 1000) - a2 - a3) / 100;

    if (a1 > x && a2 > x && a3 > x) {
        result = a - 100;
    } else if (a1 > x && a2 > x) {
        result = a + 100;
    } else if (a1 < x && a2 < x && a3 < x) {
        result = a - 50;
    } else if (a2 < x && a3 < x) {
        result = a + 50;
    } else {
        result = a + 10;
    }

    cout << "\n���������: " << result << endl;
    cout << "\n";
    system("pause");
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int a, x;

    cout << "\n������� ����� ����������� ����� A: ";
    cin >> a;
    cout << "\n������� ����� ����� X �� 1 �� 9: ";
    cin >> x;

    if (a >= 1000 || a < 100 || x >= 10 || x <= 0) {
        cout << "\n������������ ����";
        cout << "\n";
        system("pause");
    } else {
        calc(a, x);
    }

    return 0;
}
