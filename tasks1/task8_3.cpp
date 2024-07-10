
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Дан одномерный массив, содержащий целые числа. Использовать дополнительные массивы нельзя.
// Выполнить следующие действия:

// 3. Удалить все четные элементы.

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
            for (int i = count; i < n; i++) {
                a[i] = a[i + 1];
            }
            n--;
        } else {
            count++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
