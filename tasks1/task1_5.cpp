
//kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    float x, y;

    cout << "������� x: ";
    cin >> x;
    cout << "������� y: ";
    cin >> y;

    float res = (0.4 * (pow(M_E, (sqrt(x * y) + sqrt(x + y))) + (sin(y * x)))) / (sqrt(cos(x) * cos(x) + sin(x * x)));

    cout << "���������: " << res << endl;

    system("pause");

    return 0;
}