#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//  БАЗОВИЙ КЛАС
class Mob {
protected:
    int hp; // здоров'я моба

public:
    //  конструктор
    Mob(int h) {
        hp = h;
    }

    //  віртуальний метод отримання шкоди
    virtual int takeDamage(int damage) {
        hp -= damage;

        if (hp < 0)
            hp = 0;

        return hp;
    }

    //  getter
    int getHp() {
        return hp;
    }

    //  віртуальний деструктор
    virtual ~Mob() {}
};

// =====================================================

//  КЛАС ЗОМБІ
class Zombie : public Mob {
public:
    Zombie() : Mob(20) {}

    int takeDamage(int damage) override {
        cout << "Zombie: Urrrr...\n";

        // виклик базового методу
        return Mob::takeDamage(damage);
    }
};

// =====================================================

// 🔹КЛАС СКЕЛЕТ
class Skeleton : public Mob {
public:
    Skeleton() : Mob(15) {}

    int takeDamage(int damage) override {
        cout << "Skeleton: Clack!\n";

        return Mob::takeDamage(damage);
    }
};

// =====================================================

// КЛАС КРІПЕР
class Creeper : public Mob {
public:
    Creeper() : Mob(10) {}

    int takeDamage(int damage) override {
        cout << "Creeper: Ssssss...\n";

        return Mob::takeDamage(damage);
    }

    //  особливий метод
    void explode() {
        cout << "BOOM!!!\n";
    }
};

// =====================================================

//  ФУНКЦІЯ СПАВНУ
vector<Mob*> spawnMobs() {

    vector<Mob*> mobs;

    for (int i = 0; i < 5; i++) {

        int r = rand() % 3;

        if (r == 0)
            mobs.push_back(new Zombie());

        else if (r == 1)
            mobs.push_back(new Skeleton());

        else
            mobs.push_back(new Creeper());
    }

    return mobs;
}

// =====================================================

int main() {

    srand(time(0));

    //  створення мобів
    vector<Mob*> mobs = spawnMobs();

    cout << "=== DAMAGE ===\n";

    //  проходимо по масиву
    for (Mob* m : mobs) {

        int hpLeft = m->takeDamage(7);

        cout << "HP left: " << hpLeft << endl;

        // перевірка чи це Creeper
        Creeper* c = dynamic_cast<Creeper*>(m);

        // якщо hp < 5 → вибух
        if (c && c->getHp() < 5) {
            c->explode();
        }

        cout << "----------------\n";
    }

    //  очищення пам'яті
    for (Mob* m : mobs) {
        delete m;
    }

    return 0;
}
