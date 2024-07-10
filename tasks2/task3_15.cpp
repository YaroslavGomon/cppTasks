// 15. ������� �� �������, ����� �� ����� ������, ����� �� ���� �������� � ������� ���������� ���������.

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
    if (a.Surname < b.Surname) return true;
    if (a.Surname == b.Surname && a.Experience < b.Experience) return true;
    if (a.Surname == b.Surname && a.Experience == b.Experience && a.DateOfBirth.yy < b.DateOfBirth.yy) return true;
    return false;
}

bool operator>(people a, people b) { // �������������� �������� > � ����������� � ��������
    if (a.Surname > b.Surname) return true;
    if (a.Surname == b.Surname && a.Experience > b.Experience) return true;
    if (a.Surname == b.Surname && a.Experience == b.Experience && a.DateOfBirth.yy > b.DateOfBirth.yy) return true;
    return false;
}

void insertion(vector<people> &x) {
    for (int i = 1; i < x.size(); i++) {
        int j = i;
        while (j > 0 && x[j] < x[j-1]) {
            swap(x[j], x[j-1]);
            j--;
        }
    }
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<people> x;
    x = inFile();
    insertion(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
