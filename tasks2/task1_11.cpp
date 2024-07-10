// 6. Дана последовательность целых чисел. Найти сумму элементов, кратных ??. Вывести минимальный элемент. Все четные элементы заменить на максимальный.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool even(int x) { // четные
    return x % 2 == 0;
}

bool odd(int x) {
    return x % 2 != 0;
}

int X;              // предикат может содержать только один параметр
bool kratn(int x) { // не кратный X
    return x % X != 0;
}

vector<int> createVector(int n, int index) {
    int x;
    vector<int> vec;

    for (int i = 0; i < n; i++) { // создание вектора
        cout << (index == 1 ? "a" : "b") << "[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    return vec;
}

void printVector(vector<int> vec, int index) {
    cout << "Vector" << index << ":";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << " " << *iter;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "russian");

    int n, m, sum = 0;
    cout << "n = ";
    cin >> n;
    vector<int> vec1 = createVector(n, 1);
    printVector(vec1, 1);

    cout << "m = ";
    cin >> m;
    vector<int> vec2 = createVector(m, 2);
    printVector(vec2, 2);

    cout << "В первой последовательности удалить все четные элементы" << endl;
    vector<int>::iterator it = remove_if(vec1.begin(), vec1.end(), even);
    vec1.erase(it, vec1.end());
    printVector(vec1, 1);

    cout << "во второй — все нечетные" << endl;
    vector<int>::iterator ite = remove_if(vec2.begin(), vec2.end(), odd);
    vec2.erase(ite, vec2.end());
    printVector(vec2, 2);

    cout << "Отсортировать данные последовательности" << endl;
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    printVector(vec1, 1);
    printVector(vec2, 2);

    cout << "Объединить их в одну отсортированную последовательность" << endl;
    vector<int> vec3;
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) {
        vec3.push_back(*iter);
    }
    for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) {
        vec3.push_back(*iter);
    }
    sort(vec3.begin(), vec3.end());

    printVector(vec3, 3);

    system("pause");
    return 0;
}
