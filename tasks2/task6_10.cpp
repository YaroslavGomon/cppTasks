// 10. ������� ���������� ������, ���������� ����� �����. ������� ��� ��������,
// ����������� � ��������� ��������� ������.
// ��������, ��� ������ 5 2 9 1 3 7 9 2 9, ��������� ������ ���� 5 2 1 3 7 2.

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

void del_node(list *&h, list *&t, list *r) { // ������� ����� r
    if (r == h && r == t)                    // ������������ ������� ������
        h = t = NULL;
    else if (r == h) { // ������� ������ ������
        h = h->next;   // �������� ������
        h->prev = NULL;
    } else if (r == t) { // ������� ����� ������
        t = t->prev;     // �������� �����
        t->next = NULL;
    } else {
        r->next->prev = r->prev; // ��� ���������� �� r ���������� ���������� r->prev
        r->prev->next = r->next; // ��� ����������� �� r ��������� ���������� r->next
    }
    delete r; // ������� r
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

    list *p = head;
    while (p) {
        if (p->inf == tail->inf) {
            del_node(head, tail, p);
        }
        p = p->next;
    }

    cout << endl;
    print(head, tail);

    return 0;
}