// 1. Дана последовательность целых чисел. Найти сумму элементов, не попадающих
// в заданный интервал [??, ??].

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");

    int n, x, a, b, sum = 0;
    cout << "n = ";
    cin >> n;
    vector<int> vec;

    for (int i = 0; i < n; i++) { // создание вектора
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    cout << "Vector:";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << " " << *iter;
    cout << endl;

    cout << "Введите значения интервала [a, b]" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Интервал: [" << a << "," << b << "]" << endl;

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        if (*iter > b || *iter < a) {
            sum += *iter;
        }
    }

    cout << "Сумма = " << sum << endl;

    system("pause");
    return 0;
}
