// 6. ���� ������������������ ����� �����. ����� ����� ���������, ������� ??. ������� ����������� �������. ��� ������ �������� �������� �� ������������.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool odd(int x) { // ������
    return x % 2 == 0;
}

int X;              // �������� ����� ��������� ������ ���� ��������
bool kratn(int x) { // �� ������� X
    return x % X != 0;
}

int main() {
    setlocale(LC_ALL, "russian");

    int n, x, sum = 0;
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

    cout << "������� �������� ����� X" << endl;
    cout << "X = ";
    cin >> X;

    vector<int> temp(vec); // ����� �������
    replace_if(temp.begin(), temp.end(), kratn, 0);

    sum = accumulate(temp.begin(), temp.end(), 0);

    cout << "����� ���������, ������� X: " << sum << endl;

    cout << "minElement = " << *min_element(vec.begin(), vec.end()) << endl;

    int max = *max_element(vec.begin(), vec.end());

    replace_if(vec.begin(), vec.end(), odd, max);
    cout << "��� ������ �������� �������� �� ������������" << endl;
    cout << "newVector:";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
        cout << " " << *iter;
    cout << endl;

    system("pause");
    return 0;
}
