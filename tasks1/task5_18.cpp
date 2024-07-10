
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��� ���������� ������, ���������� ����� �����. ��������� ���������
// ��������:

// 18. �������� ������� ������ ����������� � ��������� ������������
// �������� �������.

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n=";
    cin >> n;

    int *a = new int[n];
    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }

    cout << endl;

    int min, max, iMin, iMax;
    min = max = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] >= max) {                  // iMax ��������� ��������� ������������, �� <=
            max = a[i];
            iMax = i;
        } else if (a[i] < min) {            // iMin ��������� ������ �����������, �� <
            min = a[i];
            iMin = i;
        }
    }

    cout << "firstMin: a[" << iMin << "] = " << min << endl;
    cout << "lastMax : a[" << iMax << "] = " << max << endl;

    a[iMin] = max;
    a[iMax] = min;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";

    return 0;
}
