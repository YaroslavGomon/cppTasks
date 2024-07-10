// 2. ������� ���������� ������, ���������� ����� �����. ����� ���� ������������ ��������� �������� ����������� �������.
// ��������, ��� ������ 5 2 9 1 3 7 9 2 9, ��������� ������ ���� 5 2 9 1 1 3 7 9 1 2 9 1.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x) { // ������� �������� � ����� ������
    list *r = new list;                // ������� ����� �������
    r->inf = x;
    r->next = NULL;     // ������ ���������
    if (!h && !t) {     // ���� ������ ����
        r->prev = NULL; // ������ �������
        h = r;          // ��� ������
    } else {
        t->next = r; // r - ��������� ��� ������
        r->prev = t; // ����� - ���������� ��� r
    }
    t = r; // r ������ �����
}

void print(list *h, list *t) { // ������ ��������� ������
    list *p = h;               // �������� �� ������
    while (p) {                // ���� �� ����� �� ����� ������
        cout << p->inf << " ";
        p = p->next; // ������� � ���������� ��������
    }
}

void insert_after(list *&h, list *&t, list *r, int y) { // ��������� ����� r
    list *p = new list;                                 // ������� ����� �������
    p->inf = y;
    if (r == t) {       // ���� ��������� ����� ������
        p->next = NULL; // ����������� ��-� - ���������
        p->prev = r;    // ��������� ����� r
        r->next = p;
        t = p;             // ������ ����� - p
    } else {               // ��������� � �������� ������
        r->next->prev = p; // ��� ���������� �� r ��-�� ���������� - p
        p->next = r->next; // ��������� �� p - ��������� �� r
        p->prev = r;       // p ��������� ����� r
        r->next = p;
    }
}

int findMax(list *h, list *t) {
    int max = 0;
    list *p = h; // �������� �� ������
    while (p) {  // ���� �� ����� �� ����� ������
        if (p->inf >= max) {
            max = p->inf;
        }
        p = p->next; // ������� � ���������� ��������
    }
    return max;
}

int findMin(list *h, list *t) {
    int min;
    list *p = h; // �������� �� ������
    while (p) {  // ���� �� ����� �� ����� ������
        if (!min) {
            min = p->inf;
        } else if (p->inf <= min) {
            min = p->inf;
        }
        p = p->next; // ������� � ���������� ��������
    }
    return min;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;

    list *head = NULL; // �������������
    list *tail = NULL; // �������������

    int x;
    for (int i = 0; i < n; i++) { // ������� ������
        cin >> x;
        push(head, tail, x);
    }

    print(head, tail);

    int max = findMax(head, tail);
    int min = findMin(head, tail);
    list *p = head;
    while (p) {
        if (p->inf == max) {
            insert_after(head, tail, p, min);
        }
        p = p->next;
    }

    cout << endl;
    print(head, tail);

    cout << endl;
    return 0;
}