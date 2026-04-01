#include <iostream>
using namespace std;

// Базовий клас
class baseClass {
public:
    int c;

    baseClass() {
        cout << "Constructor baseClass\n";
    }

    ~baseClass() {
        cout << "Destructor baseClass\n";
    }
};

// virtual успадкування
class IndustrialRobot : virtual public baseClass {
public:
    int d;

    IndustrialRobot() {
        cout << "Constructor IndustrialRobot\n";
    }

    ~IndustrialRobot() {
        cout << "Destructor IndustrialRobot\n";
    }

    void moveObject() {
        cout << "IndustrialRobot moves object\n";
    }
};

//  virtual успадкування
class HumanoidRobot : virtual public baseClass {
public:
    int f;

    HumanoidRobot() {
        cout << "Constructor HumanoidRobot\n";
    }

    ~HumanoidRobot() {
        cout << "Destructor HumanoidRobot\n";
    }

    void makeConclusions() {
        cout << "HumanoidRobot thinks\n";
    }
};

// Похідний клас
class AIAndroid : public IndustrialRobot, public HumanoidRobot {
public:
    int sum;

    AIAndroid() {
        cout << "Constructor AIAndroid\n";
    }

    ~AIAndroid() {
        cout << "Destructor AIAndroid\n";
    }

    // перевизначення
    void moveObject() {
        cout << "AIAndroid smart moves object\n";
    }

    void makeConclusions() {
        cout << "AIAndroid smart conclusions\n";
    }
};

int main() {
    AIAndroid obj;

    //   один c (без неоднозначності)
    obj.c = 10;
    obj.d = 20;
    obj.f = 30;

    obj.sum = obj.c + obj.d + obj.f;

    cout << "\nValues:\n";
    cout << obj.c << " ";
    cout << obj.d << " " << obj.f << " ";
    cout << obj.sum << endl;

    cout << "\nMethods:\n";
    obj.moveObject();
    obj.makeConclusions();

    return 0;
}