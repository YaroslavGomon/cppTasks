// 1. �� �������� � ������� ������� ����������.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date { // ����
    int dd, mm, yy;
};

struct people {       // ������ � ��������
    string Surname;   // �������
    string Position;  // �������
    date DateOfBirth; // ���� ��������
    int Experience;
    int Salary;       // ��������
};

date Str_to_Date(string str) { // �� ������ � ����
    date x;
    string temp = str.substr(0, 2); // ����
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // �����
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // ���
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile() { // ���� �� �����
    vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname;  // �������
        in >> temp.Position; // ���������
        string tmp;          // ���� ��������
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience; // ����
        in >> temp.Salary; // ��������
        x.push_back(temp);
    }
    return x;
}

void print(people x) {                    // ����� � ����
    out << setw(15) << left << x.Surname; // �� ������ ����, 10 ������� ��� �������
    out << left << setw(15) << x.Position;
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.'; // ��������� 0
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;  // �� ��� 6 �������
    out << left << setw(4) << x.Experience;
    out << left << setw(10) << x.Salary << endl; // ��������
}

bool operator<(people a, people b) { // �������������� �������� < � ����������� � ��������
    if (a.Salary < b.Salary)
        return true;
    return false;
}

bool operator>(people a, people b) { // �������������� �������� > � ����������� � ��������
    if (a.Salary > b.Salary)
        return true;
    return false;
}

void quick(vector<people> &x, int l, int r) {
    int i = l, j = r;
    people m = x[(l + r) / 2];
    while (i <= j) {
        while (x[i] < m) i++;
        while (x[j] > m) j--;
        if (i <= j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (j > l) quick(x, l, j);
    if (i < r) quick(x, i, r);
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<people> x;
    x = inFile();
    quick(x, 0, x.size() - 1);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
