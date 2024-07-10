
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Решить следующие задачи, используя структуры. При решении задач использовать функции.

// 1. Создать структуру Student, содержащую следующие данные: ФИО, год рождения, оценки за сессию. В новый файл вывести студентов, чья средняя оценка
// больше заданного числа.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string birthDate;
    int grade1;
    int grade2;
    int grade3;
    int grade4;
};

Student createStudent(string name, string birthDate, int grade1, int grade2, int grade3, int grade4) {
    Student student = {name, birthDate, grade1, grade2, grade3, grade4};

    return student;
}

double calcAverageGrade(Student student) {
    double averageGrade = (student.grade1 + student.grade2 + student.grade3 + student.grade4) / 4.0;

    return averageGrade;
}

int main() {

    setlocale(LC_ALL, "russian");

    Student studentArr[4];

    studentArr[0] = createStudent("Gomon", "19.07.1987", 4, 5, 5, 4);   // 4.5
    studentArr[1] = createStudent("Ivanov", "19.07.1987", 5, 3, 5, 4);  // 4.25
    studentArr[2] = createStudent("Petrov", "19.07.1987", 5, 3, 3, 3);  // 3.5
    studentArr[3] = createStudent("Smith", "19.07.1987", 5, 5, 5, 5);   // 5.0

    double avgGrade, n;
    cout << "Введите средний балл n = ";
    cin >> n;

    string res;

    for (int i = 0; i < 4; i++) {
        avgGrade = calcAverageGrade(studentArr[i]);

        if (avgGrade >= n) {
            res += studentArr[i].name + ": " + to_string(avgGrade).erase(4) + "\n";
        }
    }

    ofstream out("result.txt");
    out << res;

    out.close();

    return 0;
}
