
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 12. ���� ����������� ����� ����� ??. ��� ����� ������ ���� ������� �� ����.
// ������� ����� ����������� ����� ??, ������ ����� �������� �������� ��������
// �� ������� ����� 25 �� ��������������� ����� ����� ??.

#include <cmath>
#include <iostream>

using namespace std;

int calc(int number) {
    return 25 % number;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int x, y;

    cout << "\n������� ����� ����������� �����: ";
    cin >> x;

    int a, b, c;

    c = x % 10;
    b = ((x % 100) - c) / 10;
    a = ((x % 1000) - b - c) / 100;

    if ((x / 1000 >= 1) || (x / 100 < 1)) {
        cout << "\n����� ������ ���� �����������!\n";
        main();
    } else if (a == 0 || b == 0 || c == 0) {
        cout << "\n��� ����� ����� ������ ���� ������� �� ����!\n";
        main();
    } else {
        y = calc(a) * 100 + calc(b) * 10 + calc(c);
        cout << "\n���������: " << y << "\n"
             << endl;
        system("pause");
    }

    return 0;
}
