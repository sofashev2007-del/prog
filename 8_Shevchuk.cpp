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

// IndustrialRobot
class IndustrialRobot : public baseClass {
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

// HumanoidRobot
class HumanoidRobot : public baseClass {
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

// AIAndroid (множинне успадкування)
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

    //  усуваємо неоднозначність (вказуємо через який клас)
    obj.IndustrialRobot::c = 10;
    obj.HumanoidRobot::c = 5;

    obj.d = 20;
    obj.f = 30;

    obj.sum = obj.IndustrialRobot::c + obj.d + obj.f;

    cout << "\nValues:\n";
    cout << obj.IndustrialRobot::c << " ";
    cout << obj.d << " " << obj.f << " ";
    cout << obj.sum << endl;

    cout << "\nMethods:\n";
    obj.moveObject();
    obj.makeConclusions();

    return 0;
}