// 12. Диагонали, параллельные главной по возрастанию с помощью сортировки чет-нечет.

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

void oddEvenSort(vector<int> &x) {
    int N = x.size();
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j < N; j += 2) {
                if (x[j - 1] > x[j]) {
                    swap(x[j], x[j - 1]);
                }
            }
        } else {
            for (int j = 1; j < N; j += 2) {
                if (x[j - 1] > x[j]) {
                    swap(x[j], x[j - 1]);
                }
            }
        }
    }
}

void matrixSortDiagonal(vector<vector<int>> &x) {
    int N = x.size();
    for (int k = 1; k < N; k++) {
        vector<int> vec1;

        for (int i = 0; i < N; i++) {
            if (k + i < N) {
                vec1.push_back(x[i][k + i]);
            }
        }

        oddEvenSort(vec1);
        int L = 0;

        for (int i = 0; i < N; i++) {
            if (k - i < N) {
                x[i][k + i] = vec1[L];
                L++;
            }
        }

        vec1.clear();

        for (int j = 0; j < N; j++) {
            if (k + j < N) {
                vec1.push_back(x[ k + j][j]);
            }
        }

        oddEvenSort(vec1);
        L = 0;

        for (int j = 0; j < N; j++) {
            if (k + j < N) {
                x[k + j][j] = vec1[L];
                L++;
            }
        }

        vec1.clear();
    }
}

int main() {

    setlocale(LC_ALL, "russian");

    vector<vector<int>> x;
    x = inFile();
    matrixSortDiagonal(x);
    print(x);
}
