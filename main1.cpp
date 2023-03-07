#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Person {
protected:
    string name;
    int age;
    char sex;
    double weight;

public:
    Person(string name, int age, char sex, double weight) :
            name(std::move(name)),
            age(age),
            sex(sex),
            weight(weight) {}

    string getName() {
        return name;
    }

    int getAge() const {
        return age;
    }

    char getSex() const {
        return sex;
    }

    double getWeight() const {
        return weight;
    }
};

class Student : public Person {
private:
    int yearsStudying;

public:
    Student(string name, int age, char sex, double weight) : Person(std::move(name), age, sex, weight) {
        this->yearsStudying = 0;
    }

    void study(int years) {
        this->yearsStudying += years;
        this->age += years; // increase age after studying
        this->weight += (years * 0.5); // gain weight after studying
    }

    int getYearsStudying() const {
        return yearsStudying;
    }
};

int main() {
    Student s("John", 18, 'M', 70.0);
    s.study(4);
    cout << s.getName() << " has been studying for " << s.getYearsStudying() << " years." << endl;
    cout << "After " << s.getYearsStudying() << " years, " << s.getName() << " (" << s.getSex() << ") is now "
         << s.getAge() << " years old and weighs " << s.getWeight() << "kg." << endl;
    return 0;
}
