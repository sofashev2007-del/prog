#include <iostream>
#include <string>

using namespace std;

// БАЗОВИЙ КЛАС
class Employee{
public:
    string name;
    double salary;

    // конструктор
    Employee(string n, double s){
        name = n;
        salary = s;
        cout << "Employee created\n";
    }

    // деструктор
    ~Employee(){
        cout << "Employee deleted\n";
    }

    // метод
    void work(){
        cout << name << " працює\n";
    }

    // set
    void setName(string n){
        name = n;
    }

    void setSalary(double s){
        salary = s;
    }

    // get
    string getName(){
        return name;
    }

    double getSalary(){
        return salary;
    }

    // вивід
    void printEmployee(){
        cout << name << " " << salary << endl;
    }
};

// ПОХІДНИЙ КЛАС
class Manager : public Employee{
public:
    int teamSize;

    // конструктор
    Manager(string n, double s, int t) : Employee(n, s){
        teamSize = t;
        cout << "Manager created\n";
    }

    // деструктор
    ~Manager(){
        cout << "Manager deleted\n";
    }

    // перевизначення
    void work(){
        cout << name << " керує командою з " << teamSize << " людей\n";
    }

    // set
    void setTeamSize(int t){
        teamSize = t;
    }

    // get
    int getTeamSize(){
        return teamSize;
    }

    // вивід
    void printManager(){
        cout << name << " " << salary << " " << teamSize << endl;
    }
};

int main(){

    Employee e1("Іван", 15000);
    Manager m1("Олена", 30000, 5);

    cout << endl;

    e1.printEmployee();
    e1.work();

    cout << endl;

    m1.printManager();
    m1.work();

    return 0;
}