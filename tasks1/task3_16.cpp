
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Вывести на экран следующую таблицу:
// 1
// 2
// 2 2
// 4 4
// 3 3 3
// 6 6 6
// 4 4 4 4
// 8 8 8 8

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int i, j;

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= i; j++) {
            cout << i << "  ";
        }
        cout << "\n";
        for (j = 1; j <= i; j++) {
            cout << i * 2 << "  ";
        }
        cout << "\n";
    }

    return 0;
}
