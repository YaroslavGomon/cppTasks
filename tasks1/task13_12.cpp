
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ������ ��������� ������, ��������� ���������. ��� ������� ����� ������������ �������.

// 12. ���� ������, ���������� ���� � ���� �dd.mm.yyyy�. ���������� ����� ����
// ������ ������������� ���� ����.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

date STR_date(string str) { // ������� �� ������ � ����
    date data;
    // ��day�������-
    string str1 = str.substr(0, 2);
    const char *sd = str1.c_str();
    int dd = atoi(sd);
    data.day = dd;
    // ���month�����-
    str1 = str.substr(3, 2);
    sd = str1.c_str();
    dd = atoi(sd);
    data.month = dd;
    // ���year������
    str1 = str.substr(6, 4);
    sd = str1.c_str();
    dd = atoi(sd);
    data.year = dd;
    return data;
}

bool vis(int y) { // ���������� ���
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int EndOfMonth(int m, int y){//����� ������
    switch (m) {
        case 1: case 3: case 5:
        case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: if(vis(y)) return 29;
            else return 28;
    }
}


int correct(string str) { // �������� ������������ ������
    if (str.length() != 10)
        return -1;
    for (string::size_type i = 0; i < str.length(); i++)
        if (i != 2 && i != 5) {
            if (!isdigit(str[i]))
                return -1;
        }
    date data = STR_date(str);
    if (data.day <= 0 || data.day > EndOfMonth(data.month, data.year))
        return -2;
    if (data.month <= 0 || data.month > 12)
        return -3;
    if (data.year == 0)
        return -4;
    return 1;
}

// �������� ������� ��������� ���������� ���� ������ ��� ����� ���� � ���������� � 1 ������ 1583 ���� �� 31 ������� 9999 ����. � ������ ��������� ������� ����� �������:

// ���� ����� �� ����� 1 ��� 2:
// (��� = ��� - 1) � (����� = ����� + 10)
// �����:
// ����� = ����� ? 2

// A = (����� + ((31 * �����) / 12) + ��� + (��� / 4) ? (��� / 100) + (��� / 400))

// ���� ������ = ������� ������� �� (A / 7).

// ���������� ��������� �������� ������� ��� ������, ��� 0 - �����������, 1 - �����������, ..., 6 - �������.

int calcWeekDay(date data) {
    int d, m, y, A;

    d = data.day;

    if (data.month == 1 || data.month == 2) {
        m = data.month + 10;
        y = data.year - 1;
    } else {
        m = data.month - 2;
        y = data.year;
    }

    A = d + (31 * m) / 12 + y + y / 4 - y / 100 + y / 400;
    
    return A % 7;
}

int main() {

    setlocale(LC_ALL, "russian");

    date data;

    string str;
    cout << "Input date as dd.mm.yyyy\n";
    getline(cin, str);

    int fl = correct(str);

    if (fl == -1)
        cout << "Error input\n";
    else if (fl == -2)
        cout << "Error day\n";
    else if (fl == -3)
        cout << "Error month\n";
    else if (fl == -4)
        cout << "Error year\n";
    else
        data = STR_date(str);

    string dayNames[] = {"�����������", "�����������", "�������", "�����", "�������", "�������", "�������"};

    cout << dayNames[calcWeekDay(data)] << endl;

    return 0;
}
