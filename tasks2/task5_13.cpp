// 13. —оздать очередь, содержащую целые числа. ѕосле всех чисел, кратных ??, вставить новый элемент.
// Ќапример, если введены 1 1 2 3 2 4 3 5 4 1 и ?? = 2, то результат должен быть
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

void push(queue *&h, queue *&t, int x) { // вставка элемента в очередь
    queue *r = new queue;                // создаем новый элемент
    r->inf = x;
    r->next = NULL; // всегда последний
    if (!h && !t) { // если очередь пуста
        h = t = r;  // это и голова и хвост
    } else {
        t->next = r; // r - следующий дл€ хвоста
        t = r;       // теперь r - хвост
    }
}

int pop(queue *&h, queue *&t) { // удаление элемента из очереди
    queue *r = h;               // создаем указатель на голову
    int i = h->inf;             // сохран€ем значение головы
    h = h->next;                // сдвигаем указатель на следующий элемент
    if (!h)                     // если удал€ем последний элемент из очереди
        t = NULL;
    delete r; // удал€ем первый элемент
    return i;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;
    
    queue *head = NULL; // инициализаци€
    queue *tail = NULL; // инициализаци€
    queue *resH = NULL; // инициализаци€
    queue *resT = NULL; // инициализаци€

    int x;
    for (int i = 0; i < n; i++) { // создаем очередь
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
        cout << pop(resH, resT) << " "; // выводим на экран

    cout << endl;
    return 0;
}