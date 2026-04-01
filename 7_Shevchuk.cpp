#include <iostream>
using namespace std;

// Базовий клас
class B {
    char a;
public:
    B(char x) {
        a = x;
        cout << "Constructor B\n";
    }

    ~B() {
        cout << "Destructor B\n";
    }

    void show_B() {
        cout << "B = " << a << endl;
    }
};

// D1
class D1 : public B {
    char b;
public:
    D1(char x, char y) : B(y) {
        b = x;
        cout << "Constructor D1\n";
    }

    ~D1() {
        cout << "Destructor D1\n";
    }

    void show_D1() {
        cout << "D1 = " << b << endl;
        show_B();
    }
};

// D2
class D2 : private B {
    char c;
public:
    D2(char x, char y) : B(y) {
        c = x;
        cout << "Constructor D2\n";
    }

    ~D2() {
        cout << "Destructor D2\n";
    }

    void show_D2() {
        cout << "D2 = " << c << endl;
        show_B();
    }
};

// D3
class D3 : private D1, public D2 {
    char d;
public:
    D3(char x, char y, char z, char i, char j)
        : D1(y, z), D2(i, j) {
        d = x;
        cout << "Constructor D3\n";
    }

    ~D3() {
        cout << "Destructor D3\n";
    }

    void show_D3() {
        cout << "D3 = " << d << endl;
        show_D1();
        show_D2();
    }
};

// D4
class D4 : public D2, private D1 {
    char e;
public:
    D4(char x, char y, char z, char i, char j)
        : D1(y, z), D2(i, j) {
        e = x;
        cout << "Constructor D4\n";
    }

    ~D4() {
        cout << "Destructor D4\n";
    }

    void show_D4() {
        cout << "D4 = " << e << endl;
        show_D1();
        show_D2();
    }
};

int main() {
    D3 obj3('A', 'B', 'C', 'D', 'E');
    D4 obj4('F', 'G', 'H', 'I', 'J');

    cout << "\nD3:\n";
    obj3.show_D3();

    cout << "\nD4:\n";
    obj4.show_D4();

    return 0;
}