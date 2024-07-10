
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 12. Дано трехзначное целое число ??. Все цифры должны быть отличны от нуля.
// Вывести новое трехзначное число ??, каждая цифра которого является остатком
// от деления числа 25 на соответствующую цифру числа ??.

#include <cmath>
#include <iostream>

using namespace std;

int calc(int number) {
    return 25 % number;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int x, y;

    cout << "\nВведите целое трехзначное число: ";
    cin >> x;

    int a, b, c;

    c = x % 10;
    b = ((x % 100) - c) / 10;
    a = ((x % 1000) - b - c) / 100;

    if ((x / 1000 >= 1) || (x / 100 < 1)) {
        cout << "\nЧисло должно быть трехзначным!\n";
        main();
    } else if (a == 0 || b == 0 || c == 0) {
        cout << "\nВсе цифры числа должны быть отличны от нуля!\n";
        main();
    } else {
        y = calc(a) * 100 + calc(b) * 10 + calc(c);
        cout << "\nРезультат: " << y << "\n"
             << endl;
        system("pause");
    }

    return 0;
}
