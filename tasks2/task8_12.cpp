// 12. Дан неориентированный граф. Вставить в граф ребро, соединяющее вершины a и b.

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
vector<int> used(8, 0);
vector<int> path;

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

void printAdjacencyList(vector<vector<int>> Gr) {
    for (vector<vector<int>>::iterator iter = Gr.begin(); iter != Gr.end(); iter++) {
        cout << iter - Gr.begin() << ": ";
        for (vector<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); iter1++) {
            cout << *iter1 << " ";
        }
        cout << endl;
    }
}

void inDepth(int x) {
    used[x] = 1;
    path.push_back(x);
    cout << x << " ";
    for (int i = 0; i < Gr[x].size(); i++) {
        bool was = false;
        for (int k = 0; k < path.size(); k++) {
            if (path[k] == Gr[x][i]) {
                was = true;
            }
        }
        if (!was) {
            inDepth(Gr[x][i]);
        }
    }
}

void printPath() {
    for (vector<int>::iterator iter = path.begin(); iter != path.end(); iter++) {
        cout << *iter << " ";
    }
}

void insertLink(int a, int b) {
    Gr[a].push_back(b);
    quick(Gr[a], 0, Gr[a].size() - 1);
    Gr[b].push_back(a);
    quick(Gr[b], 0, Gr[b].size() - 1);
}

int main() {

    createGraph(7, 8);

    printAdjacencyList(Gr);
    cout << endl;

    insertLink(0, 6);
    printAdjacencyList(Gr);

    // cout << endl;
    // inDepth(0);
    // printPath();

    return 0;
}