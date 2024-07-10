// 2. Дано дерево. Удалить элементы, кратные X.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

struct tree {
    int inf;
    tree *left;
    tree *right;
    tree *parent;
};

tree *node(int x) { // начальный узел
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x) { // вставка
    tree *n = node(x);
    if (!tr)
        tr = n; // если дерево пустое - корень
    else {
        tree *y = tr;
        while (y) {              // ищем куда вставлять
            if (n->inf > y->inf) // правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; // узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; // узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

void inorder(tree *tr) { // симметричный обход
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

tree *find(tree *tr, int x) { // поиск
    if (!tr || x == tr->inf)  // нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); // ищем по левой ветке
    else
        return find(tr->right, x); // ищем по правой ветке
}

tree *Min(tree *tr) { // поиск min
    if (!tr->left)
        return tr; // нет левого ребенка
    else
        return Min(tr->left); // идем по левой ветке до конца
}

tree *Max(tree *tr) { // поиск max
    if (!tr->right)
        return tr; // нет правого ребенка
    else
        return Max(tr->right); // идем по правой ветке до конца
}

tree *Next(tree *tr, int x) { // поиск следующего
    tree *n = find(tr, x);
    if (n->right)                // если есть правый ребенок
        return Min(n->right);    // min по правой ветке
    tree *y = n->parent;         // родитель
    while (y && n == y->right) { // пока не дошли до корня или узел - правый ребенок
        n = y;                   // идем вверх по дереву
        y = y->parent;
    }
    return y; // возвращаем родителя
}

tree *Prev(tree *tr, int x) { // поиск предыдущего
    tree *n = find(tr, x);
    if (n->left)                // если есть левый ребенок
        return Max(n->left);    // max по левой ветке
    tree *y = n->parent;        // родитель
    while (y && n == y->left) { // пока не дошли до корня или узел - левый ребенок
        n = y;                  // идем вверх по дереву
        y = y->parent;
    }
    return y; // возвращаем родителя
}

void erase(tree *&tr, tree *v) {
    tree *p = v->parent;
    if (!p && !v->left && !v->right) {
        tr = nullptr;
        delete v;
    } else if (!v->left && !v->right) { // leaf
        if (p->left == v)
            p->left = nullptr;
        else
            p->right = nullptr;
        delete v;
    } else if (!v->left || !v->right) { // 1 child
        if (!p) {
            if (!v->left) {
                tr = v->right;
                v->parent = nullptr;
            } else {
                tr = v->left;
                v->parent = nullptr;
            }
        } else {
            if (!v->left) {
                if (p->left == v) {
                    p->left = v->right;
                } else {
                    p->right = v->right;
                }
                v->right->parent = p;
            } else {
                if (p->left == v) {
                    p->left = v->left;
                } else {
                    p->right = v->left;
                }
                v->left->parent = p;
            }
        }
        delete v;
    } else { // 2 child
        tree *succ = Next(tr, v->inf);
        v->inf = succ->inf;
        if (succ->parent->left == succ) {
            succ->parent->left = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        } else {
            succ->parent->right = succ->right;
            if (succ->right)
                succ->right->parent = succ->parent;
        }
        delete succ;
    }
}

void deleteKratX(tree *tr, int x) {
    if (tr) {
        int num = tr->inf;
        if (num % x == 0) {
            erase(tr, find(tr, num));
        }
        deleteKratX(tr->left, x);
        deleteKratX(tr->right, x);
    }
}

int main() {

    int n, x;
    cout << "n=";
    cin >> n;

    tree *tr = NULL;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        cin >> x;
        insert(tr, x);
    }

    inorder(tr);
    cout << endl;
    cout << "min = " << Min(tr)->inf << endl;
    cout << "max = " << Max(tr)->inf << endl;
    cout << "x = ";
    cin >> x;

    // if (find(tr, x)) {
    //     // cout << "next = " << Next(tr, x)->inf << endl;
    //     // cout << "prev = " << Prev(tr, x)->inf << endl;
    //     erase(tr, find(tr, x));
    //     inorder(tr);
    //     cout << endl;
    // } else {
    //     cout << "Such node not exist in this tree\n";
    // }

    deleteKratX(tr, x);

    inorder(tr);

    return 0;
}