
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// ��������� �������, �������� ������� ��� �����, ������ �� ����� � ���������� ������� ��� ���������� �������. ������������������ ������ �������� �� �������� ��������, ���������� ����� �����, ������������ ����� �, ���� ��� ��������,
// �������. ��� ��������� ���c�� ����������� n x m. ��������� ��������� ��������:

// 11. ��� ������ ������ �������� ������� X. (��������� ����� ������� ����������
// � ����.)

#include <iostream>

using namespace std;

int **create(int c, int n, int m) { // �������� int
    int **a = new int *[n];         // ��������� ������
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++) // ���� �������
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

void print(int **a, int n, int m) { // ������ int
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}

double **create(double c, int n, int m) { // �������� double
    double **a = new double *[n];         // ��������� ������
    for (int i = 0; i < n; i++)
        a[i] = new double[m];
    for (int i = 0; i < n; i++) // ���� �������
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

void print(double **a, int n, int m) { // ������ double
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}

char **create(char c, int n, int m) { // �������� char
    char **a = new char *[n];         // ��������� ������
    for (int i = 0; i < n; i++)
        a[i] = new char[m];
    for (int i = 0; i < n; i++) // ���� �������
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

void print(char **a, int n, int m) { // ������ char
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
}

void replaceRowWithX(int **a, int n, int m, int x) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j++) {
            a[i][j] = x;
        }
    }
}

void replaceRowWithX(double **a, int n, int m, double x) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j++) {
            a[i][j] = x;
        }
    }
}

void replaceRowWithX(char **a, int n, int m, char x) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j++) {
            a[i][j] = x;
        }
    }
}

int main() {
    int n, m;

    cout << "Input dimension\n";
    cin >> n >> m;

    int c = 1; // ����������� ��� int
    cout << "Input int matrix:\n";

    int **a = create(c, n, m);
    cout << "Print int matrix:\n";
    print(a, n, m);
    cout << "Input replacement int X = ";
    int x;
    cin >> x;
    replaceRowWithX(a, n, m, x);
    cout << "New int matrix:\n";
    print(a, n, m);

    cout << "Input double matrix:\n";
    double d = 1; // ����������� ��� double
    double **a1 = create(d, n, m);
    cout << "Print double matrix:\n";
    print(a1, n, m);
    cout << "Input replacement double X = ";
    double x1;
    cin >> x1;
    replaceRowWithX(a1, n, m, x1);
    cout << "New double matrix:\n";
    print(a1, n, m);

    cout << "Input char matrix:\n";
    char d1 = '1'; // ����������� ��� char
    char **a2 = create(d1, n, m);
    cout << "Print char matrix:\n";
    print(a2, n, m);
    cout << "Input replacement char X = ";
    char x2;
    cin >> x2;
    replaceRowWithX(a2, n, m, x2);
    cout << "New char matrix:\n";
    print(a2, n, m);

    return 0;
}
