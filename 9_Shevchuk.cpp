#include "BOOK.h"

int main() {

    int N;
    cout << "Введіть кількість книг: ";
    cin >> N;
    cin.ignore(1000, '\n');

    BOOK SHOP[100];

    // Ввід
    for (int i = 0; i < N; i++) {
        cout << "\n--- Книга " << i + 1 << " ---\n";
        SHOP[i].input();
    }

    int year;
    cout << "\nВведіть рік: ";
    cin >> year;

    cout << "\n=== Результат ===\n";

    for (int i = 0; i < N; i++) {
        if (SHOP[i].checkYear(year)) {
            SHOP[i].print();
        }
    }

    return 0;
}