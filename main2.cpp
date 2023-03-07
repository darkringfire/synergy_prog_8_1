#include <iostream>
#include <string>
#include <utility>

class Pass {
public:
    Pass(int level, double discount)
            : level_(level), discount_(discount) {}

    int getLevel() const { return level_; }
    double getDiscount() const { return discount_; }

private:
    int level_;
    double discount_;
};

class University {
public:
    static const int LAB_ACCESS_LEVEL = 1;
    static const int FACULTY_ACCESS_LEVEL = 2;
    static const int OFFICE_ACCESS_LEVEL = 3;

    static bool hasLabAccess(const Pass& pass) {
        return pass.getLevel() >= LAB_ACCESS_LEVEL;
    }

    static bool hasFacultyAccess(const Pass& pass) {
        return pass.getLevel() >= FACULTY_ACCESS_LEVEL;
    }
    static bool hasOfficeAccess(const Pass& pass) {
        return pass.getLevel() >= OFFICE_ACCESS_LEVEL;
    }
};

class Person {
public:
    Person(std::string name, int id, const Pass& pass)
            : name_(std::move(name)), id_(id), pass_(pass) {}

    std::string getName() const { return name_; }
    int getID() const { return id_; }
    const Pass& getPass() const { return pass_; }

    bool canEnterLab() const {
        return University::hasLabAccess(getPass());
    }

    bool canEnterFaculty() const {
        return University::hasFacultyAccess(getPass());
    }

    bool canEnterOffice() const {
        return University::hasOfficeAccess(getPass());
    }

    double getDiscountRate() const {
        return getPass().getDiscount();
    }

private:
    std::string name_;
    int id_;
    Pass pass_;
};

class Student : public Person {
public:
    Student(std::string name, int id, const Pass& pass)
            : Person(std::move(name), id, pass) {}
};

class Teacher : public Person {
public:
    Teacher(std::string name, int id, const Pass& pass)
            : Person(std::move(name), id, pass) {}
};

class Staff : public Person {
public:
    Staff(std::string name, int id, const Pass& pass)
            : Person(std::move(name), id, pass) {}
};

int main() {
    // Создание экземпляров классов
    Pass studentPass(1, 0.2);
    Student student("Ivan", 12345, studentPass);

    Pass teacherPass(2, 0.5);
    Teacher teacher("John", 67890, teacherPass);

    Pass staffPass(3, 0.1);
    Staff staff("Olga", 24680, staffPass);

    // Проверка уровня доступа
    std::cout << student.getName() << " can enter lab: " << student.canEnterLab() << std::endl;
    std::cout << teacher.getName() << " can enter faculty: " << teacher.canEnterFaculty() << std::endl;
    std::cout << staff.getName() << " can enter office: " << staff.canEnterOffice() << std::endl;

    // Проверка скидки в столовой
    std::cout << "Staff discount rate: " << staff.getDiscountRate() << std::endl;

    return 0;
}