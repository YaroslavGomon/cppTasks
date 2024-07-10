
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ƒан массив, содержащий целые числа, размерностью n x n. »спользовать дополнительные массивы нельз€.
// ¬ыполнить следующие действи€:

// 2. ѕосле строк, содержащих только нечетные элементы, вставить эти строки.

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int **create(int n, int m) {
    int **a = new int *[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == n - 1) {
                a[i][j] = i;
            } else if (i == n - 2) {
                a[i][j] = i + 2;
            } else {
                a[i][j] = i + 1;
            }
        }
    }

    return a;
}

void print(int **a, int n, int m) {
    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n, m;

    cout << "n = ";
    cin >> n;

    m = n;

    int **a = create(n, m);
    print(a, n, m);

    // ƒобавление строки в матрицу********
    int count = 0;

    while (count != n) {
        if (a[count][0] % 2 == 1) {
            n++;
            for (int i = n - 1; i > count; i--) {
                a[i] = a[i - 1];
            }
            a[count + 1] = a[count];
            count++;
        }
        count++;
    }
    // **************
    
    print(a, n, m);

    cout << "\n";

    return 0;
}
