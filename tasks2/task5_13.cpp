// 13. ������� �������, ���������� ����� �����. ����� ���� �����, ������� ??, �������� ����� �������.
// ��������, ���� ������� 1 1 2 3 2 4 3 5 4 1 � ?? = 2, �� ��������� ������ ����
// 1 1 2 0 3 2 0 4 0 3 5 4 0 1.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

struct queue {
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x) { // ������� �������� � �������
    queue *r = new queue;                // ������� ����� �������
    r->inf = x;
    r->next = NULL; // ������ ���������
    if (!h && !t) { // ���� ������� �����
        h = t = r;  // ��� � ������ � �����
    } else {
        t->next = r; // r - ��������� ��� ������
        t = r;       // ������ r - �����
    }
}

int pop(queue *&h, queue *&t) { // �������� �������� �� �������
    queue *r = h;               // ������� ��������� �� ������
    int i = h->inf;             // ��������� �������� ������
    h = h->next;                // �������� ��������� �� ��������� �������
    if (!h)                     // ���� ������� ��������� ������� �� �������
        t = NULL;
    delete r; // ������� ������ �������
    return i;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;
    
    queue *head = NULL; // �������������
    queue *tail = NULL; // �������������
    queue *resH = NULL; // �������������
    queue *resT = NULL; // �������������

    int x;
    for (int i = 0; i < n; i++) { // ������� �������
        cin >> x;
        push(head, tail, x);
    }

    int X;
    cout << "X = ";
    cin >> X;

    while (head) {
        int elem = pop(head, tail);
        if (elem % X == 0) {
            push(resH, resT, elem);
            push(resH, resT, 0);
        } else {
            push(resH, resT, elem);
        }
    }

    while (resH)
        cout << pop(resH, resT) << " "; // ������� �� �����

    cout << endl;
    return 0;
}