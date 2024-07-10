
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 13. —оздайте рекурсивную функцию дл€ перевода числа из дес€тичной системы
// счислени€ в двоичную.

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// массив нужен чтобы записать двоичное представление числа в обратном пор€дке
int *arr = new int[20];
int count = 0;

int calc(int n) {               // ћетод √орнера
    if (n == 1) {
        arr[count] = 1;
        count++;
        return 1;
    } else {
        arr[count] = n % 2;
        count++;
        return calc(n / 2);
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n = ";
    cin >> n;

    calc(n);

    for (int i = count - 1; i >= 0; i--) {
        cout << arr[i];
    }

    cout << "\n";

    return 0;
}
