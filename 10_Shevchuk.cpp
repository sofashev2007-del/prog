#include <iostream>
#include <string>
using namespace std;

// 🔹 КЛАС ВИКОНАВЕЦЬ
class Vykonavets {
public:
    string name;
    string country;
    int year;

    void input() {
        getline(cin, name);
        getline(cin, country);
        cin >> year;
        cin.ignore(1000, '\n');
    }
};

// 🔹 КЛАС ПІСНЯ (містить виконавця)
class Pisnya {
private:
    string title;
    double duration;
    string genre;
    long long views;

public:
    Vykonavets artist; // 🔹 об’єкт класу ВИКОНАВЕЦЬ

    // ввід
    void input() {
        artist.input();

        getline(cin, title);
        cin >> duration;
        cin.ignore(1000, '\n');

        getline(cin, genre);
        cin >> views;
        cin.ignore(1000, '\n');
    }

    // 🔹 зміна жанру
    void changeGenre(string newGenre) {
        genre = newGenre;
    }

    // 🔹 додати прослуховування
    void addViews(long long add) {
        views += add;
    }

    // 🔹 вивід
    void print() {
        cout << "Пісня: " << title << endl;
        cout << "Виконавець: " << artist.name << endl;
        cout << "Країна: " << artist.country << endl;
        cout << "Рік початку кар’єри: " << artist.year << endl;
        cout << "Тривалість: " << duration << endl;
        cout << "Жанр: " << genre << endl;
        cout << "Прослуховування: " << views << endl;
    }
};

int main() {

    Pisnya p;

    // 🔹 ввід основних даних
    p.input();

    string newGenre;
    long long newViews;

    // 🔹 додатковий ввід
    getline(cin, newGenre);
    cin >> newViews;

    // 🔹 зміни
    p.changeGenre(newGenre);
    p.addViews(newViews);

    cout << endl;

    // 🔹 результат
    p.print();

    return 0;
}