
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Дан одномерный массив, содержащий целые числа. Использовать дополнительные массивы нельзя.
// Выполнить следующие действия:

// 18. После всех четных элементов вставить X

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n, x;

    cout << "n = ";
    cin >> n;

    cout << "x = ";
    cin >> x;

    int *a = new int[n];

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    int count = 0;

    while (count != n) {
        if (a[count] % 2 == 0) {
            n++;
            for (int i = n - 1; i > count; i--) {
                a[i] = a[i - 1];
            }
            a[count + 1] = x;
            count++;
        }
        count++;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
