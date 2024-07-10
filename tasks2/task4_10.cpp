// 10. Нечетные строки по убыванию, четные по возрастанию помощью гномьей сортировки.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

ifstream in("input_matrix.txt");
ofstream out("output.txt");

int N;

vector<vector<int>> inFile() { // ввод из файла
    vector<int> row;
    vector<vector<int>> M;
    in >> N;
    while (in.peek() != EOF) {
        int num;
        for (int i = N; i >= 1; i--) {
            in >> num;
            row.push_back(num);
        }
        M.push_back(row);
        row.clear();
    }
    return M;
}

void print(vector<vector<int>> M) { // вывод в файл
    out << N << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out << M[i][j] << " ";
        }
        out << "\n";
    }
}

void gnomeSort(vector<int> &x, bool direction) {
    int N = x.size();
    int i = 1;
    while (i < N) {
        if (i == 0)
            i++;
        if (direction ? x[i - 1] <= x[i] : x[i - 1] >= x[i]) {
            i++;
        } else {
            swap(x[i], x[i - 1]);
            i--;
        }
    }
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<vector<int>> x;
    x = inFile();
    int count = 0;
    for (vector<vector<int>>::iterator iter = x.begin(); iter != x.end(); iter++) {
        if (count % 2 == 0) {
            gnomeSort(*iter, true);
        } else {
            gnomeSort(*iter, false);
        }
        count++;
    }
    print(x);
}
