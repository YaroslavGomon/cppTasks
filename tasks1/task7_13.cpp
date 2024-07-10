
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��� ���������� ������� �11�15 ����������� ��������� ��� ���������� ������������ �������, ��������� ������. 
// ������� �� ����� ����������� �����������
// (������ ���� ����� 10 �����) � ����� �� �������.

// ��������� ����������� �������. ��������� ����������� �������, ��������� 2^k

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;
    cout << "n =";
    cin >> n; // ���-�� ����� ������������
    int **a = new int *[n + 1];

    for (int i = 0; i <= n; i++)
        a[i] = new int[i + 1]; // �������� ������ ��� i-�� ������

    /*********���������� �������************************/
    a[0][0] = 1;
    a[1][0] = a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i][0] = 1;
        for (int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        a[i][i] = 1;
    }

    /*********����� �������****************************/
    for (int i = 0; i <= n; i++, cout << endl)
        for (int j = 0; j <= i; j++)
            cout << a[i][j] << " ";


    cout << "\n";

    int k, res = 0;

    cout << "������� ������� ����� 2: k = ";
    cin >> k;

    for (int i = 0; i <= k; i++) {
        res += a[k][i];
    }

    cout << "2^k = " << res << endl;
    
    return 0;
}
