
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 5. Дано целое число N. Вычислить N!!. (N!! — перемножение чисел той же четности, что и N.
// Например, 5!! = 1 x 3 x 5, 4!! = 2 x 4.)

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;

    cout << "Введите целое число N больше нуля: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректный ввод" << endl;
    } else {
        int i, res = 1;
        i = (n % 2 == 0) ? 2 : 1;
        for (i; i <= n; i += 2) {
            res = i * res;
        }

        cout << "Результат: N!! = " << res << endl;
    }

    system("pause");
    return 0;
}
