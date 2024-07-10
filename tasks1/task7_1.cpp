
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��� ���������� ������� �1�10 ����������� ��������� ��� ������ � ������������. ��������� ����������� ��� ���������� ������ ����������� n + 1, ���
// a[i] � ��� ������������ ���������� ����

// 1. ��� ��������� P(x) ������� n. �������� ��� �����������

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n = ";
    cin >> n;

    int *a = new int[n + 1];

    cout << "������� ����� Enter ������������ ����������: " << endl;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << "\n";

    int *b = new int[n];

    for (int i = 1; i <= n; i++) {
        b[i - 1] = i * a[i];
    }

    for (int i = 0; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n\n";

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    cout << "\n\n";

    return 0;
}
