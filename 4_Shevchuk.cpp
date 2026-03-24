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

int main(){

    int N;
    cout << "Введіть кількість книг: ";
    cin >> N;
    cin.ignore();

    // 🔹1. Масив — це набір об'єктів одного типу
    BOOK SHOP[100];   // одновимірний масив об’єктів

    //  2. Звернення до елемента масиву  SHOP[i]
    for(int i = 0; i < N; i++){
        cout << "\nКнига " << i+1 << endl;

        //  3. Виклик методу елемента масиву
        SHOP[i].input();
    }

    int year;
    cout << "\nВведіть рік: ";
    cin >> year;

    cout << "\nРезультат:\n";

    for(int i = 0; i < N; i++){

        //  4 Звернення до методу через об’єкт
        if(SHOP[i].checkYear(year)){

            // 5 Виклик методу об’єкта масиву
            SHOP[i].print();
        }
    }

    // ===== ДИНАМІЧНИЙ МАСИВ =====

    //  6. Динамічний масив
    BOOK* dyn = new BOOK[N];

    cin.ignore();

    for(int i = 0; i < N; i++){
        dyn[i].input();  // звернення так само
    }

    // 7. Звільнення пам’яті
    delete[] dyn;

    return 0;
}
