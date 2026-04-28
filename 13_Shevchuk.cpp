#include <iostream>
#include <vector>
using namespace std;

// 🔹 БАЗОВИЙ КЛАС
class Workstation {
public:
    // 🔹 віртуальний метод
    virtual bool process(string material) {
        return true;
    }

    // 🔹 віртуальний деструктор
    virtual ~Workstation() {}
};

// 🔹 ПІЧКА
class Pichka : public Workstation {
public:
    bool process(string material) override {
        cout << material << " -> переплавка\n";
        return true;
    }
};

// 🔹 КОВАДЛО
class Kovadlo : public Workstation {
public:
    bool process(string material) override {
        cout << material << " -> кування\n";
        return true;
    }
};

// 🔹 АЛХІМІЧНА СТІЙКА
class Alchemy : public Workstation {
public:
    bool process(string material) override {
        if (material == "вугілля") {
            cout << material << " -> не підходить для зілля\n";
            return false;
        }
        cout << material << " -> вариво зілля\n";
        return true;
    }

    void explode() {
        cout << "Алхімічна стійка вибухнула!\n";
    }
};

int main() {

    // 🔹 список станцій
    vector<Workstation*> stations;

    stations.push_back(new Pichka());
    stations.push_back(new Kovadlo());
    stations.push_back(new Alchemy());

    string materials[2] = {"золото", "вугілля"};

    // 🔹 обробка матеріалів
    for (string mat : materials) {
        cout << "\nМатеріал: " << mat << endl;

        for (Workstation* s : stations) {
            bool result = s->process(mat);

            // 🔹 якщо це алхімія і неуспішно → вибух
            if (!result) {
                Alchemy* a = dynamic_cast<Alchemy*>(s);
                if (a) {
                    a->explode();
                }
            }
        }
    }

    // 🔹 очищення пам’яті
    for (Workstation* s : stations)
        delete s;

    return 0;
}