// 11. Во входном файле задан набор слов и целых чисел, разделенных пробелами.
// Найти все слова, встречающиеся столько же раз, сколько первое число.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "russian");

    string number = "0123456789";

    string word, firstNum = "";
    map<string, int> let, num;

    ifstream in;
    in.open("data2_11.txt"); // two 33 1 5 one one two 7 33 33 five one 99

    while (in >> word) {
        if (word.find_first_not_of(number) && firstNum == "") {
            firstNum = word;
            num[word]++;
        } else if (word.find_first_not_of(number)) {
            num[word]++;
        } else {
            let[word]++;
        }
    }

    int p = num[firstNum];

    for (map<string, int>::iterator iter = let.begin(); iter != let.end(); iter++) {
        if (iter->second == p) {
            cout << iter->first << " ";
        }
    }
    cout << endl;

    in.close();

    system("pause");
    return 0;
}
