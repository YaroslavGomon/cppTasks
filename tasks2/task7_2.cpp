// 2. ���� ������. ������� ��������, ������� X.

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

tree *node(int x) { // ��������� ����
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree *&tr, int x) { // �������
    tree *n = node(x);
    if (!tr)
        tr = n; // ���� ������ ������ - ������
    else {
        tree *y = tr;
        while (y) {              // ���� ���� ���������
            if (n->inf > y->inf) // ������ �����
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; // ���� ���������� ������ ��������
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf) // ����� �����
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y; // ���� ���������� ����� ��������
                    y->left = n;
                    break;
                }
        }
    }
}

void inorder(tree *tr) { // ������������ �����
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

tree *find(tree *tr, int x) { // �����
    if (!tr || x == tr->inf)  // ����� ��� ����� �� ����� �����
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); // ���� �� ����� �����
    else
        return find(tr->right, x); // ���� �� ������ �����
}

tree *Min(tree *tr) { // ����� min
    if (!tr->left)
        return tr; // ��� ������ �������
    else
        return Min(tr->left); // ���� �� ����� ����� �� �����
}

tree *Max(tree *tr) { // ����� max
    if (!tr->right)
        return tr; // ��� ������� �������
    else
        return Max(tr->right); // ���� �� ������ ����� �� �����
}

tree *Next(tree *tr, int x) { // ����� ����������
    tree *n = find(tr, x);
    if (n->right)                // ���� ���� ������ �������
        return Min(n->right);    // min �� ������ �����
    tree *y = n->parent;         // ��������
    while (y && n == y->right) { // ���� �� ����� �� ����� ��� ���� - ������ �������
        n = y;                   // ���� ����� �� ������
        y = y->parent;
    }
    return y; // ���������� ��������
}

tree *Prev(tree *tr, int x) { // ����� �����������
    tree *n = find(tr, x);
    if (n->left)                // ���� ���� ����� �������
        return Max(n->left);    // max �� ����� �����
    tree *y = n->parent;        // ��������
    while (y && n == y->left) { // ���� �� ����� �� ����� ��� ���� - ����� �������
        n = y;                  // ���� ����� �� ������
        y = y->parent;
    }
    return y; // ���������� ��������
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