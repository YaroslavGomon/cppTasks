// 3. ������� ����, ���������� ����� �����. �������� ������� ������� ����� ���������� ������� ��������. ������� ������ ��������� ��������������� �����
// �� ����� ������ ��������� � �������� ����� ���������.
// ��������, ���� ������� 1 1 2 3 4 5 1, �� ��������� ������ ���� 1 1 2 3 4 0 5 1.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

struct stack {
    int num;
    stack *next;
};

void push(stack *&h, int x) {
    stack *r = new stack; // ������� ����� �������
    r->num = x;           // ���� inf = x
    r->next = h;          // ��������� ��������� �������� h
    h = r;                // ������ r �������� �������
}

int pop(stack *&h) {
    int i = h->num; // �������� ������� ��������
    stack *r = h;   // ��������� �� ������ �����
    h = h->next;    // ��������� ��������� �� ��������� �������
    delete r;       // ������� ������ �������
    return i;       // ���������� ��������
}

void reverse(stack *&h) {    //"���������"�����
    stack *head1 = NULL;     // ������������� ��������� �����
    while (h)                // ���� ���� �� ����
        push(head1, pop(h)); // ������������ �� ������ ����� � ������
    h = head1;               // �������������� ���������
}

stack *result(stack *&h) {
    stack *res = NULL; // �������������
    bool findLastEven = false;
    while (h) {
        int x = pop(h); // ������� ������ �������
        if (!findLastEven && x % 2 == 0) {
            push(res, 0);
            push(res, x); // ���������� � ���������
            findLastEven = true;
        } else {
            push(res, x); // ���������� � ���������
        }
    }
    return res;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;
    stack *head = NULL; // �������������
    int x;
    for (int i = 0; i < n; i++) { // ������� ����
        cin >> x;
        push(head, x);
    }
    stack *res = result(head); // ���������
    while (res)
        cout << pop(res) << " "; // ������� �� �����

    cout << endl;
    return 0;
}