// 2. Создать двусвязный список, содержащий целые числа. После всех максимальных элементов вставить минимальный элемент.
// Например, для списка 5 2 9 1 3 7 9 2 9, результат должен быть 5 2 9 1 1 3 7 9 1 2 9 1.

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

void push(list *&h, list *&t, int x) { // вставка элемента в конец списка
    list *r = new list;                // создаем новый элемент
    r->inf = x;
    r->next = NULL;     // всегда последний
    if (!h && !t) {     // если список пуст
        r->prev = NULL; // первый элемент
        h = r;          // это голова
    } else {
        t->next = r; // r - следующий для хвоста
        r->prev = t; // хвост - предыдущий для r
    }
    t = r; // r теперь хвост
}

void print(list *h, list *t) { // печать элементов списка
    list *p = h;               // укзатель на голову
    while (p) {                // пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; // переход к следующему элементу
    }
}

void insert_after(list *&h, list *&t, list *r, int y) { // вставляем после r
    list *p = new list;                                 // создаем новый элемент
    p->inf = y;
    if (r == t) {       // если вставляем после хвоста
        p->next = NULL; // вставляемый эл-т - последний
        p->prev = r;    // вставляем после r
        r->next = p;
        t = p;             // теперь хвост - p
    } else {               // вставляем в середину списка
        r->next->prev = p; // для следующего за r эл-та предыдущий - p
        p->next = r->next; // следующий за p - следующий за r
        p->prev = r;       // p вставляем после r
        r->next = p;
    }
}

int findMax(list *h, list *t) {
    int max = 0;
    list *p = h; // укзатель на голову
    while (p) {  // пока не дошли до конца списка
        if (p->inf >= max) {
            max = p->inf;
        }
        p = p->next; // переход к следующему элементу
    }
    return max;
}

int findMin(list *h, list *t) {
    int min;
    list *p = h; // укзатель на голову
    while (p) {  // пока не дошли до конца списка
        if (!min) {
            min = p->inf;
        } else if (p->inf <= min) {
            min = p->inf;
        }
        p = p->next; // переход к следующему элементу
    }
    return min;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;

    list *head = NULL; // инициализация
    list *tail = NULL; // инициализация

    int x;
    for (int i = 0; i < n; i++) { // создаем список
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