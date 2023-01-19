#include <iostream>
#include <string>

using namespace std;

enum Sex { male,
           female };

class Person {
private:
  string name;
  Sex sex;
  unsigned int age;

public:
  Person(string name, Sex sex, unsigned int age) {
    this->name = name;
    this->sex = sex;
    this->age = age;
  }
  void setName(string name) {
    this->name = name;
  }
  string getName() {
    return this->name;
  }
  void setAge(unsigned int age) {
    this->age = age;
  }
  unsigned int getAge() {
    return this->age;
  }
  void setSex(Sex sex) {
    this->sex = sex;
  }
  Sex getSex() {
    return this->sex;
  }
  string getSexStr() {
    if (this->sex == Sex::male) {
      return "Male";
    } else if (this->sex == Sex::female) {
      return "Female";
    } else {
      return "Somebody";
    }
  }
};

class Student : public Person {
private:
  int year;

public:
  Student(string name, Sex sex, unsigned int age, int year) : Person(name, sex, age) {
    this->year = year;
  }

  void setYear(int year) {
    this->year = year;
  }

  int getYear() {
    return this->year;
  }
};

int main(int argc, char const *argv[]) {
  cout << "Task 1. Person class" << endl;
  Person p("The Man", Sex::male, 20);

  cout << p.getName() << " " << p.getSexStr() << " " << p.getAge() << endl;
  p.setName("Jane");
  p.setSex(Sex::female);
  p.setAge(19);
  cout << p.getName() << " " << p.getSexStr() << " " << p.getAge() << endl;

  cout << endl
       << "Task 2. Student class" << endl;
  Student s("John", Sex::male, 33, 2022);
  cout << s.getName() << " " << s.getSexStr() << " " << s.getAge() << " " << s.getYear() << endl;
  s.setYear(2023);
  cout << s.getName() << " " << s.getSexStr() << " " << s.getAge() << " " << s.getYear() << endl;

  return 0;
}
