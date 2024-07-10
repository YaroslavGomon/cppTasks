// 10. —оздать двусв€зный список, содержащий целые числа. ”далить все элементы,
// совпадающие с последним элементом списка.
// Ќапример, дл€ списка 5 2 9 1 3 7 9 2 9, результат должен быть 5 2 1 3 7 2.

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
        t->next = r; // r - следующий дл€ хвоста
        r->prev = t; // хвост - предыдущий дл€ r
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

void insert_after(list *&h, list *&t, list *r, int y) { // вставл€ем после r
    list *p = new list;                                 // создаем новый элемент
    p->inf = y;
    if (r == t) {       // если вставл€ем после хвоста
        p->next = NULL; // вставл€емый эл-т - последний
        p->prev = r;    // вставл€ем после r
        r->next = p;
        t = p;             // теперь хвост - p
    } else {               // вставл€ем в середину списка
        r->next->prev = p; // дл€ следующего за r эл-та предыдущий - p
        p->next = r->next; // следующий за p - следующий за r
        p->prev = r;       // p вставл€ем после r
        r->next = p;
    }
}

void del_node(list *&h, list *&t, list *r) { // удал€ем после r
    if (r == h && r == t)                    // единственный элемент списка
        h = t = NULL;
    else if (r == h) { // удал€ем голову списка
        h = h->next;   // сдвигаем голову
        h->prev = NULL;
    } else if (r == t) { // удал€ем хвост списка
        t = t->prev;     // сдвигаем хвост
        t->next = NULL;
    } else {
        r->next->prev = r->prev; // дл€ следующего от r предыдущим становитс€ r->prev
        r->prev->next = r->next; // дл€ предыдущего от r следующим становитс€ r->next
    }
    delete r; // удал€ем r
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;

    list *head = NULL; // инициализаци€
    list *tail = NULL; // инициализаци€

    int x;
    for (int i = 0; i < n; i++) { // создаем список
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