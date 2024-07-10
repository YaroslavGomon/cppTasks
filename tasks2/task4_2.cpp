// 2. Строки по возрастанию с помощью сортировки подсчетом.

#include <fstream>
#include <iomanip>
#include <iostream>
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

void countingSort(vector<int> &row, int N) {
    int k = 10;
    vector<int> arr(k);
    fill(arr.begin(), arr.end(), 0);
    for (int i = 0; i < N; i++) {
        arr[row[i]]++;
    }
    row.clear();
    for (int i = 0; i < k; i++) {
        if (arr[i] != 0) {
            for (int j = 1; j <= arr[i]; j++) {
                row.push_back(i);
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<vector<int>> x;
    x = inFile();
    for (vector<vector<int>>::iterator iter = x.begin(); iter != x.end(); iter++) {
        countingSort(*iter, N);
    }
    print(x);
}
