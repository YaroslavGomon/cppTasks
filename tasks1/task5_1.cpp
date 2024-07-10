
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Дан одномерный массив, содержащий целые числа. Выполнить следующие
// действия:

// 1. Найти сумму четных элементов, попадающих в заданный интервал,
// включая границы интервала. Ноль не учитывать. Если четных элементов
// нет, вывести сообщение об этом.

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

    int b, c;

    cout << "b=";
    cin >> b;
    cout << "c=";
    cin >> c;

    int sum = 0;

    for (int i = b; i <= c; i++) {
        if (a[i] != 0 && a[i] % 2 == 0) {
            sum += a[i];
        }
    }

    if (sum == 0) {
        cout << "В интервале [" << b << ", " << c << "] четных элементов нет" << endl;
    } else {
        cout << "Сумма четных элементов массива в границах [" << b << ", " << c << "] равна: " << sum << endl;
    }

    cout << "\n";

    return 0;
}
