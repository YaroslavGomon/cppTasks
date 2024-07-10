
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// —оздайте рекурсивную функцию, определ€ющую n!! (n!! перемножает числа,
// имеющую ту же четность, что и n, например, 4!! = 2 * 4, 5!! = 1 * 3 * 5)

#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int calc(int n) {

    if (n <= 0) {
        return 1;
    } else {
        return n * calc(n - 2);
    }
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "n = ";
    cin >> n;

    cout << calc(n) << endl;

    cout << "\n";

    return 0;
}
