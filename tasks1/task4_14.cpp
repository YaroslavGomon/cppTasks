
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 14. найти сумму ряда;

#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int n;
    float x;

    cout << "Введите количество членов последовательности" << endl;
    cout << "n = ";
    cin >> n;

    cout << "Введите значение Х" << endl;
    cout << "x = ";
    cin >> x;

    cout << "\n";

    float a = - (x * x * x * x) / 24, S = a;

    cout << "N" << "\t" << "x" << "\t" << "     S" << endl;
    cout << "-------------------------" << endl;
    cout << "1" << "\t" << x << "\t" << S << endl;

    for (int i = 2; i <= n; i++) {
        a *= -x * x / ((2 * i + 2) * (2 * i + 1));
        S += a;
        cout << i << "\t" << x << "\t" << S << endl;
    }

    cout << "\n";

    return 0;
}
