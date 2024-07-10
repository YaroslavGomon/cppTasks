
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��� ������ � ���������� ��������� ������������ ������������ ������ �
// ��������� ������� � ���� ������ �������: �����, ������ � ���������� �������.
// �� ����� ������ ���� ������� ��������� ������ � ��������� ����������
// �������.

// 1. ��� ��������� ������, ���������� ����� �����, ������������ n x n.
// ��������� ��������� ��������:

// 1) �������� ������� ������ �� ���������� �������: ������ � ���������,
// ������ � ������������� � �. �.

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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i + 1;
        }
    }

    return a;
}

void print(int **a, int n) {
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

void swapRows(int **a, int n) {
    for (int i = 0; i < n/2; i++) {
        swap(a[i], a[(n - 1) - i]);
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n = ";
    cin >> n;

    int **a = create(n);
    print(a, n);
    swapRows(a, n);
    print(a, n);

    cout << "\n";

    return 0;
}
