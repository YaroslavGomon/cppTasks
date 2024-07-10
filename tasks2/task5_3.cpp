// 3. Создать стек, содержащий целые числа. Вставить нулевой элемент после последнего четного элемента. Порядок вывода элементов результирующего стека
// на экран должен совпадать с порядком ввода элементов.
// Например, если введены 1 1 2 3 4 5 1, то результат должен быть 1 1 2 3 4 0 5 1.

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
    stack *r = new stack; // создаем новый элемент
    r->num = x;           // поле inf = x
    r->next = h;          // следующим элементов является h
    h = r;                // теперь r является головой
}

int pop(stack *&h) {
    int i = h->num; // значение первого элемента
    stack *r = h;   // указатель на голову стека
    h = h->next;    // переносим указатель на следующий элемент
    delete r;       // удаляем первый элемент
    return i;       // возвращаем значение
}

void reverse(stack *&h) {    //"обращение"стека
    stack *head1 = NULL;     // инициализация буферного стека
    while (h)                // пока стек не пуст
        push(head1, pop(h)); // переписываем из одного стека в другой
    h = head1;               // переобозначаем указатели
}

stack *result(stack *&h) {
    stack *res = NULL; // инициализация
    bool findLastEven = false;
    while (h) {
        int x = pop(h); // удаляем первый элемент
        if (!findLastEven && x % 2 == 0) {
            push(res, 0);
            push(res, x); // записываем в результат
            findLastEven = true;
        } else {
            push(res, x); // записываем в результат
        }
    }
    return res;
}

int main() {

    setlocale(LC_ALL, "russian");

    int n;
    cout << " n = ";
    cin >> n;
    stack *head = NULL; // инициализация
    int x;
    for (int i = 0; i < n; i++) { // создаем стек
        cin >> x;
        push(head, x);
    }
    stack *res = result(head); // результат
    while (res)
        cout << pop(res) << " "; // выводим на экран

    cout << endl;
    return 0;
}