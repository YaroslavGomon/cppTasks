
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 5. ���� ����� ����� N. ��������� N!!. (N!! � ������������ ����� ��� �� ��������, ��� � N.
// ��������, 5!! = 1 x 3 x 5, 4!! = 2 x 4.)

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "������� ����� ����� N ������ ����: ";
    cin >> n;

    if (n <= 0) {
        cout << "������������ ����" << endl;
    } else {
        int i, res = 1;
        i = (n % 2 == 0) ? 2 : 1;
        for (i; i <= n; i += 2) {
            res = i * res;
        }

        cout << "���������: N!! = " << res << endl;
    }

    system("pause");
    return 0;
}
