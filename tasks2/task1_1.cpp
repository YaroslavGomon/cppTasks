// 1. ���� ������������������ ����� �����. ����� ����� ���������, �� ����������
// � �������� �������� [??, ??].

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

    for (int i = 0; i < n; i++) { // �������� �������
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);
    }

    cout << "Vector:";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << " " << *iter;
    cout << endl;

    cout << "������� �������� ��������� [a, b]" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "��������: [" << a << "," << b << "]" << endl;

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        if (*iter > b || *iter < a) {
            sum += *iter;
        }
    }

    cout << "����� = " << sum << endl;

    system("pause");
    return 0;
}
