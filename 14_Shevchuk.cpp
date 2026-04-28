#include <iostream>
using namespace std;

// 🔹 КЛАС (для перевірки з об’єктами)
class MyNumber {
public:
    int x;

    MyNumber(int v = 0) { x = v; }

    // 🔹 оператори для порівняння
    bool operator < (const MyNumber& other) const {
        return x < other.x;
    }

    bool operator == (const MyNumber& other) const {
        return x == other.x;
    }
};


// 🔹 ЗАВДАННЯ 1: спадна послідовність


template <typename T>
bool isDecreasing(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (!(arr[i] > arr[i + 1]))  // якщо не строго спадна
            return false;
    }
    return true;
}


// 🔹 ЗАВДАННЯ 2: різносторонній трикутник


template <typename T>
bool Triangle(T a, T b, T c) {
    // 🔹 перевірка існування трикутника
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;

    // 🔹 різносторонній (всі різні)
    if (a != b && a != c && b != c)
        return true;

    return false;
}


int main() {

    // 🔹 int
    int arr1[] = {9, 7, 5, 3};
    cout << "int: " << isDecreasing(arr1, 4) << endl;

    // 🔹 double
    double arr2[] = {5.5, 4.4, 3.3};
    cout << "double: " << isDecreasing(arr2, 3) << endl;

    // 🔹 char
    char arr3[] = {'z', 'y', 'x'};
    cout << "char: " << isDecreasing(arr3, 3) << endl;

    // 🔹 об’єкти
    MyNumber arr4[] = {9, 6, 2};
    cout << "object: " << isDecreasing(arr4, 3) << endl;

    // 🔹 Triangle
    cout << "Triangle(3,4,5): " << Triangle(3,4,5) << endl; // 1
    cout << "Triangle(2,2,3): " << Triangle(2,2,3) << endl; // 0

    return 0;
}