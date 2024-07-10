
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// 6. необходимо вывести n первых членов соответствующей последовательности;

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    float y1 = 2, y2 = 1, y;
    int n;

    cout << "¬ведите количество членов последовательности" << endl;
    cout << "n = ";
    cin >> n;

    cout << "\n";

    if (n == 1) {
        cout << "1:\t" << y1 << endl;
    } else {
        cout << "1:\t" << y1 << endl;
        cout << "2:\t" << y2 << endl;
        for (int i = 3; i <= n; i++) {
            y = ((y2 / 2) + (y1 / 3)) / 3;
            y1 = y2;
            y2 = y;
            cout << i << ":\t" << y << endl;
        }
    }

    return 0;
}
