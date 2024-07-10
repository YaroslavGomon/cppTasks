// 6. ƒан текст, состо€щий из предложений, разделенных знаками препинани€ из
// набора Ђ.?!ї. ѕредложени€ в свою очередь состо€т из слов, отделенных друг от
// друга пробелами. Ќайти слова (без учета регистра) и их количество, которые
// встречаютс€ только в повествовательных предложени€х.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

std::string str{"One two three.Four five six?Seven eight nine!Ten eleven."};

int main() {
    setlocale(LC_ALL, "russian");

    cout << "\n" << str << "\n" << endl;

    set<string> pov;
    std::string razd = ".?!";

    int pos = 0;
    int k = str.find_first_of(razd, pos);

    while (k < str.length()) {

        char tmp = str[k];

        std::string temp = str.substr(pos, k - pos);
        temp += " ";

        int pos1 = 0;
        int k1 = temp.find_first_of(" ", pos1);

        while (k1 < temp.length()) {
            std::string word = temp.substr(pos1, k1 - pos1);
            for (int i = 0; i < word.length(); i++) {
                word[i] = (isupper(word[i])) ? tolower(word[i]) : word[i];
            }

            switch (tmp) {
            case '.':
                pov.insert(word);
                break;
            }

            pos1 = k1 + 1;
            k1 = temp.find_first_of(" ", pos1);
        }

        // cout << temp << endl;

        pos = k + 1;
        k = str.find_first_of(razd, pos);
    }

    for (set<string>::iterator it = pov.begin(); it != pov.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
    cout << " оличество слов: " << pov.size() << endl;

    system("pause");
    return 0;
}
