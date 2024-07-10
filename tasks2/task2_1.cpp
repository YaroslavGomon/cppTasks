// 1. Дана последовательность целых чисел. Найти все такие цифры, которые встречаются только в двузначных числах.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

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

    int n;
    cout << "n = ";
    cin >> n;
    vector<int> vec1 = createVector(n, 1);
    printVector(vec1, 1);

    set<int> set1;
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) {
        if (*iter / 100 < 1) {
            set1.insert(*iter % 10);
            set1.insert((*iter - (*iter % 10)) / 10);
        }
    }

    cout << "Найти все такие цифры, которые встречаются только в двузначных числах." << endl;
    cout << "Set: ";
    for (set<int>::iterator it = set1.begin(); it != set1.end(); it++)
        cout << *it << " ";
    cout << endl;

    system("pause");
    return 0;
}
