
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Дан массив, содержащий целые числа, размерностью n x n. Использовать дополнительные массивы нельзя.
// Выполнить следующие действия:

// 13. Удалить все строки, содержащие хотя бы один элемент X.

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int **create(int n, int m) {
    int **a = new int *[n];
    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 9 + 1;
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

    int n, m, x;

    cout << "n = ";
    cin >> n;
    cout << "x = ";
    cin >> x;

    m = n;

    int **a = create(n, m);
    print(a, n, m);

    // Проверка и удаление строки********
    int count = 0;

    while (count != n) {
        for (int j = 0; j < m; j++) {
            if (a[count][j] == x) {
                for (int i = count; i < n - 1; i++) {
                    a[i] = a[i + 1];
                }
                n--;
                break;
            } else if (j == m - 1) {
                count++;
            }
        }
    }
    // **************

    print(a, n, m);

    if (n == 0 ) {
        cout << "Число Х присутствовало во всех строках, все строки удалены." << endl;
    }

    cout << "\n";

    return 0;
}
