
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ������� ��������� ����, ���������� ������ � ����� C++. � ����� ���� �������� ���������� ���������� ��������� ��������:

// 1. ���� ������, ���������� ��������� ����� � �����. ����� ������ �������
// ������ �������� ��������������� ����.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string addSymbol(string str) {
    string res, vowels = "aeiouyAEIOUY";

    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < vowels.length(); j++) {
            if (str[i] == vowels[j]) {
                res += "!";
            }
        }
        res += str[i];
    }

    return res;
}

int main() {

    setlocale(LC_ALL, "russian");

    string str, res;

    ifstream in("data.txt");
    while (in.peek() != EOF) {
        getline(in, str);

        res += addSymbol(str) + "\n";
    }

    ofstream out("result.txt");
    out << res.erase(res.length() - 1);

    in.close();
    out.close();

    // cout << "NEW STRING: \n" << res << endl;

    return 0;
}
