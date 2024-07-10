
// kodirovka faila "windows1251", esli ne otobrazhaetsya kirillitsa

// Создать текстовый файл, содержащий строки в стиле C++. В новый файл записать результаты выполнения следующих действий:

// 11. Даны предложения. Вывести все слова предложения в обратном порядке.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    setlocale(LC_ALL, "russian");

    string str, res, word, razdel = " .";
    int prevSpace = 0;

    ifstream in("data12_11.txt");
    while (in.peek() != EOF) {
        getline(in, str);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == razdel[0] || str[i] == razdel[1]) {
                word = str.substr(prevSpace, i - prevSpace) + " ";
                res.insert(0, word);
                prevSpace = i + 1;
            }
        }

        res.replace(res.length() - 1, res.length(), ".");
    }

    ofstream out("result.txt");
    out << res;

    in.close();
    out.close();

    return 0;
}
