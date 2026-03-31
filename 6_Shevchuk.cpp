#include <iostream>
using namespace std;

// 1. Створюємо базовий клас Прямокутник
class Pryamokutnyk {
protected:
    double length; // довжина
    double width;  // ширина

public:
    // 2. Конструктор (задаємо значення)
    Pryamokutnyk(double l, double w) {
        length = l;
        width = w;
    }

    // 3. Метод для обчислення площі
    double area() {
        return length * width; // формула площі
    }

    // 4. Вивід даних
    void show() {
        cout << "Прямокутник:\n";
        cout << "Довжина: " << length << endl;
        cout << "Ширина: " << width << endl;
        cout << "Площа: " << area() << endl;
    }
};

// 5. Створюємо похідний клас Коробка
class Korobka : public Pryamokutnyk {
private:
    double height; // висота

public:
    // 6. Конструктор коробки (викликає конструктор базового класу)
    Korobka(double l, double w, double h)
        : Pryamokutnyk(l, w) {
        height = h;
    }

    // 7. Метод для обчислення об’єму
    double volume() {
        return length * width * height; // формула об’єму
    }

    // 8. Вивід даних
    void show() {
        cout << "\nКоробка:\n";
        cout << "Довжина: " << length << endl;
        cout << "Ширина: " << width << endl;
        cout << "Висота: " << height << endl;
        cout << "Площа: " << area() << endl;   // беремо з базового класу
        cout << "Об'єм: " << volume() << endl;
    }
};

int main() {
    // 9. Створюємо об'єкт прямокутника
    Pryamokutnyk rect(5, 3);

    // 10. Створюємо об'єкт коробки
    Korobka box(5, 3, 4);

    // 11. Виводимо дані
    rect.show();
    box.show();

    return 0;
}