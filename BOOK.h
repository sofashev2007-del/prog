#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

// КЛАС (що таке клас)
class BOOK {
private:
    string name;   // поле (назва)
    string author; // поле (автор)
    int year;      // поле (рік)
    double cost;   // поле (ціна)

public:
    // Конструктор
    BOOK(){
        name = "";
        author = "";
        year = 0;
        cost = 0;
    }

    // Ввід даних
    void input(){
        cout << "Назва: ";
        getline(cin, name);

        cout << "Автор: ";
        getline(cin, author);

        cout << "Рік: ";
        cin >> year;

        cout << "Ціна: ";
        cin >> cost;

        cin.ignore(); // щоб працював getline
    }

    // Вивід даних
    void print(){
        cout << "Назва: " << name << endl;
        cout << "Автор: " << author << endl;
        cout << "Рік: " << year << endl;
        cout << "Ціна: " << cost << " грн" << endl;
        cout << "------------------" << endl;
    }

    // Метод перевірки
    bool checkYear(int y){
        return year == y;
    }
};

#endif