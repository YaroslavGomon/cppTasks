// 1. Дан неориентированный граф. Вывести количество вершин, смежных с данной.

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

ifstream in("gr.txt");

vector<vector<int>> Gr;

bool orient = false;

void quick(vector<int> &x, int l, int r) {
    int i = l, j = r;
    int m = (l + r) / 2;
    while (i <= j) {
        while (x[i] < x[m])
            i++;
        while (x[j] > x[m])
            j--;
        if (i <= j) {
            swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (j > l)
        quick(x, l, j);
    if (i < r)
        quick(x, i, r);
}

void createGraph(int N, int M) {
    Gr.resize(N);
    int x, y;

    while (in.peek() != EOF) {
        in >> x;
        in >> y;
        // cout << x << " " << y << endl;
        if (orient == true) {
            if (x > N || y > N) {
                continue;
            } else {
                Gr[x].push_back(y);
            }
        } else {
            if (x > N || y > N) {
                continue;
            } else {
                Gr[x].push_back(y);
                Gr[y].push_back(x);
            }
        }
    }

    for (vector<vector<int>>::iterator iter = Gr.begin(); iter != Gr.end(); iter++) {
        quick((*iter), 0, (*iter).size() - 1);
        (*iter).erase(unique((*iter).begin(), (*iter).end()), (*iter).end());
    }
}

void countLinksOnPoint(vector<vector<int>> Gr) {
    for (vector<vector<int>>::iterator iter = Gr.begin(); iter != Gr.end(); iter++) {
        cout << iter - Gr.begin() << ": ";
        int count = 0;
        for (vector<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); iter1++) {
            count += 1;
        }
        cout << count << endl;
    }
}

void printAdjacencyList(vector<vector<int>> Gr) {
    for (vector<vector<int>>::iterator iter = Gr.begin(); iter != Gr.end(); iter++) {
        cout << iter - Gr.begin() << ": ";
        for (vector<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); iter1++) {
            cout << *iter1 << " ";
        }
        cout << endl;
    }
}

int main() {

    createGraph(7, 8);

    printAdjacencyList(Gr);
    cout << endl;

    countLinksOnPoint(Gr);

    return 0;
}