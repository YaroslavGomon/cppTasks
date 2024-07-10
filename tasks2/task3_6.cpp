// 10. —начала по должности, потом по зарплате с помощью гномьей сортировки.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct date { // дата
    int dd, mm, yy;
};

struct people {       // данные о человеке
    string Surname;   // фамили€
    string Position;  // фамили€
    date DateOfBirth; // дата рождени€
    int Experience;
    int Salary;       // зарплата
};

date Str_to_Date(string str) { // из строки в дату
    date x;
    string temp = str.substr(0, 2); // день
    x.dd = atoi(temp.c_str());
    temp = str.substr(3, 2); // мес€ц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4); // год
    x.yy = atoi(temp.c_str());
    return x;
}

vector<people> inFile() { // ввод из файла
    vector<people> x;
    people temp;
    while (in.peek() != EOF) {
        in >> temp.Surname;  // фамили€
        in >> temp.Position; // должность
        string tmp;          // дата рождени€
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience; // опыт
        in >> temp.Salary; // зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x) {                    // вывод в файл
    out << setw(15) << left << x.Surname; // по левому краю, 10 позиций дл€ фамилии
    out << left << setw(15) << x.Position;
    if (x.DateOfBirth.dd < 10)
        out << left << '0' << x.DateOfBirth.dd << '.'; // добавл€ем 0
    else
        out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10)
        out << '0' << x.DateOfBirth.mm << '.';
    else
        out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;  // на год 6 позиций
    out << left << setw(4) << x.Experience;
    out << left << setw(10) << x.Salary << endl; // запрлата
}

bool operator<(people a, people b) { // переопредел€ем оператор < в соотвествии с условием
    if (a.Position < b.Position) return true;
    if (a.Position == b.Position && a.Salary > b.Salary) return true;
    return false;
}

bool operator>(people a, people b) { // переопредел€ем оператор > в соотвествии с условием
    if (a.Position > b.Position) return true;
    if (a.Position == b.Position && a.Salary > b.Salary) return true;
    return false;
}

void gnome(vector<people> &x) {
    int N = x.size();
    int step = N / 2;
    while (step >= 1) {
        for (int i = 0; i < N - step; i++) {
            int j = i;
            while (j >= 0 && x[j] > x[j + step]) {
                swap(x[j], x[j + step]);
                j -= step;
            }
        }
        step /= 2;
    }
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<people> x;
    x = inFile();
    gnome(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}
