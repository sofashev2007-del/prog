#include <iostream>
#include <string>
using namespace std;

// 🔹 8. АНОНС КЛАСУ (попереднє оголошення)
class Song;

// 🔹 4. ПРОТОТИП ФУНКЦІЇ (оголошення без коду)
void updateSong(Song &s, int addViews, int addLikes);

// 🔹 КЛАС
class Song {
private:  
    // 🔹 1. private — доступ тільки всередині класу
    string name;
    int views;
    int likes;

public:
    // 🔹 КОНСТРУКТОР
    Song(string n, int v, int l) {
        name = n;
        views = v;
        likes = l;
    }

    // 🔹 МЕТОД ВИВЕДЕННЯ
    void print() {
        cout << "Пісня: " << name << endl;
        cout << "Прослуховування: " << views << endl;
        cout << "Лайки: " << likes << endl;
    }

    // 🔹 3. ОГОЛОШЕННЯ ДРУЖНЬОЇ ФУНКЦІЇ
    // 🔹 5. дає доступ до private полів
    friend void updateSong(Song &s, int addViews, int addLikes);

    // 🔹 11. ПРИКЛАД FRIEND CLASS (всі методи мають доступ)
    friend class Admin;
};

// 🔹 2. ДРУЖНЯ ФУНКЦІЯ (має доступ до private)
void updateSong(Song &s, int addViews, int addLikes) {
    s.views += addViews;
    s.likes += addLikes;

    cout << "\nПісля змін:\n";
    s.print();

    // 🔹 рейтинг
    if (s.views > 1000000)
        cout << "Рейтинг: популярна\n";
    else
        cout << "Рейтинг: не популярна\n";
}

// 🔹 11. ДРУЖНІЙ КЛАС
class Admin {
public:
    void show(Song &s) {
        cout << "\n[Admin доступ до private]\n";
        cout << "Лайки: " << s.likes << endl;
    }
};

// 🔹 12. ДРУЖНІЙ МЕТОД (приклад)
class B;

class A {
private:
    int x = 10;

public:
    // 🔹 12. дружній метод іншого класу
    friend void B_show(A obj);
};

class B {
public:
    void show(A obj) {
        cout << "\nB бачить private A: " << obj.x << endl;
    }
};

// 🔹 реалізація дружнього методу
void B_show(A obj) {
    cout << "\nFriend method: " << obj.x << endl;
}

int main() {

    // 🔹 створення об’єкта
    Song s("Hello", 1200000, 500000);

    // 🔹 17. виклик friend функції (НЕ через об’єкт)
    updateSong(s, 50000, 10000);

    cout << "\nМетод:\n";
    s.print();

    // 🔹 19. виклик методів дружнього класу
    Admin a;
    a.show(s);

    // 🔹 приклад friend method
    A objA;
    B objB;
    objB.show(objA);
    B_show(objA);

    return 0;
}