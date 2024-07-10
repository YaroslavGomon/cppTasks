
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 2. Дано трехзначное число A. Если все его цифры больше X, уменьшить число A
// на 100; если его первая и вторая цифры больше X, увеличить число A на 100;
// если все его цифры меньше X, уменьшить число A на 50; если вторая и третья
// цифры меньше X, увеличить число A на 50; в остальных случаях — увеличить
// число A на 10.

#include <cmath>
#include <iostream>

using namespace std;

void calc(int a, int x) {
    int a1, a2, a3, result;

    a3 = a % 10;
    a2 = ((a % 100) - a3) / 10;
    a1 = ((a % 1000) - a2 - a3) / 100;

    if (a1 > x && a2 > x && a3 > x) {
        result = a - 100;
    } else if (a1 > x && a2 > x) {
        result = a + 100;
    } else if (a1 < x && a2 < x && a3 < x) {
        result = a - 50;
    } else if (a2 < x && a3 < x) {
        result = a + 50;
    } else {
        result = a + 10;
    }

    cout << "\nРезультат: " << result << endl;
    cout << "\n";
    system("pause");
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int a, x;

    cout << "\nВведите целое трехзначное число A: ";
    cin >> a;
    cout << "\nВведите целое число X от 1 до 9: ";
    cin >> x;

    if (a >= 1000 || a < 100 || x >= 10 || x <= 0) {
        cout << "\nНекорректный ввод";
        cout << "\n";
        system("pause");
    } else {
        calc(a, x);
    }

    return 0;
}
