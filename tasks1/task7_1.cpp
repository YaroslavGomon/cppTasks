
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Для выполнения заданий №1—10 разработать программу для работы с многочленами. Многочлен представлен как одномерный массив размерности n + 1, где
// a[i] — это коэффициенты многочлена вида

// 1. Дан многочлен P(x) степени n. Получить его производную

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

    cout << "Введите через Enter коэффициенты многочлена: " << endl;
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
