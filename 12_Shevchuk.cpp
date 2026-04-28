#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Chat {
private:
    vector<string> messages;

public:
    // 🔹 оператор << (додати повідомлення)
    Chat& operator << (string msg) {
        messages.push_back(msg);
        return *this;
    }

    // 🔹 оператор >> (взяти і видалити перше)
    Chat& operator >> (string &msg) {
        if (!messages.empty()) {
            msg = messages[0];
            messages.erase(messages.begin());
        }
        return *this;
    }

    // 🔹 оператор ! (перевірка на порожність)
    bool operator ! () {
        return messages.empty();
    }

    // 🔹 вивід
    void print() {
        cout << "Чат: ";
        for (string m : messages)
            cout << m << " ";
        cout << endl;
    }
};

int main() {
    Chat c;

    int n;
    cin >> n;
    cin.ignore();

    string s;

    // ввід
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        c << s;   // 🔹 додавання через <<
    }

    // вивід
    c.print();

    // отримання першого
    string first;
    c >> first;

    cout << "Отримане повідомлення: " << first << endl;

    // перевірка
    if (!c)
        cout << "Чат порожній\n";
    else
        cout << "Чат не порожній\n";

    return 0;
}