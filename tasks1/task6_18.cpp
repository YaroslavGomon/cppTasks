
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��� ������ � ���������� ��������� ������������ ������������ ������ �
// ��������� ������� � ���� ������ �������: �����, ������ � ���������� �������.
// �� ����� ������ ���� ������� ��������� ������ � ��������� ����������
// �������.

// 19) ��������� ������ n x n ������� �� 0 �� n*n - 1 � ��������� �������:
// �������������� ������ ������ - ������

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int **create(int n) {
    int **a = new int *[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 != 0) {
                a[i][n - 1 - j] = k;
            } else {
                a[i][j] = k;
            }
            k++;
        }
    }

    return a;
}

void print(int **a, int n) {
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (a[i][j] / 10 >= 1) {
                cout << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n = ";
    cin >> n;

    int **a = create(n);
    print(a, n);

    cout << "\n";

    return 0;
}
